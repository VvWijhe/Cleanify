//
// Created by raymon on 11-3-17.
//
#include "SerialPort.h"

using namespace io;

int SerialPort::connect() {
    struct termios tty;
    memset(&tty, 0, sizeof tty);

    // open: read/write, no control, no blocking
    usbState_ = open(port_.c_str(), O_RDWR | O_NOCTTY);

    if (usbState_ < 0) {
        std::cerr << "error opening port: " << strerror(errno) << " in path " << port_ << std::endl;
        return -1;
    }

    /* Error Handling */
    if (tcgetattr(usbState_, &tty) != 0) {
        std::cerr << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
        return -1;
    }

    /* Set Baud Rate */
    cfsetospeed(&tty, baud_);
    cfsetispeed(&tty, baud_);

    /* Setting other Port Stuff */
    tty.c_cflag &= ~PARENB;            // Make 8n1
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;

    tty.c_cflag &= ~ICANON;           // no flow control
    tty.c_cc[VMIN] = 1;                  // read doesn't block
    tty.c_cc[VTIME] = 30;                  // 0.5 seconds read timeout
    tty.c_cflag |= CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

    /* Make raw */
    cfmakeraw(&tty);

    /* Flush Port, then applies attributes */
    tcflush(usbState_, TCIFLUSH);
    if (tcsetattr(usbState_, TCSANOW, &tty) != 0) {
        std::cerr << "Error " << errno << " from tcsetattr" << std::endl;
        return -1;
    }

    return 1;
}

int SerialPort::disconnect() {
    if ((usbState_ = close(usbState_)) < 0) {
        std::cerr << "error closing: " << strerror(errno) << std::endl;
        return -1;
    }

    return 1;
}

int SerialPort::readAll(byteVector &buffer, int limit) const {
    ssize_t n{};
    int index{};
    unsigned char c{};

    /* Whole response*/
    do {
        n = read(usbState_, &c, 1);

        if (n < 0 || index++ > limit) {
            break;
        }

        buffer.push_back(c);
    } while (c != '\r');

    if (n < 0) {
        std::cerr << "Error reading: " << strerror(errno) << std::endl;
        return -1;
    }

    return 1;
}

int SerialPort::writeVector(const std::vector<unsigned char> &data) {
    if (usbState_ < 0) {
        std::cerr << "please connect before write" << std::endl;
        return -1;
    }

    for (const auto byte : data) {
        if (write(usbState_, &byte, 1) < 0) {
            std::cerr << "error writing: " << strerror(errno) << std::endl;
            return -1;
        }
    }

    return 1;
}