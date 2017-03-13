//
// Created by raymon on 11-3-17.
//
#include "SerialPort.h"

int SerialPort::connect() {
    struct termios tty;
    memset(&tty, 0, sizeof tty);

    usbState_ = open(port_.c_str(), O_RDWR | O_NOCTTY);

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

    tty.c_cflag &= ~CRTSCTS;           // no flow control
    tty.c_cc[VMIN] = 1;                  // read doesn't block
    tty.c_cc[VTIME] = 5;                  // 0.5 seconds read timeout
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

void SerialPort::disconnect() {
    close(usbState_);
}

byteVector SerialPort::sread() const {
    ssize_t n{};
    int index{};
    unsigned char c{};

    /* Whole response*/
    byteVector buffer;

    do {
        if ((n = read(usbState_, &c, 1)) < 0) {
            break;
        }

        buffer[index] = c;
        index += n;
    } while (c != '\r' && n > 0 && index < buffer.size());

    if (n < 0) {
        std::cerr << "Error reading: " << strerror(errno) << std::endl;
    } else if (n == 0) {
        std::cerr << "Read nothing!" << std::endl;
    } else {
        std::cout << "Response: " << buffer.data() << std::endl;
    }

    return buffer;
}

int SerialPort::swrite(const std::vector<unsigned char> &data) {
    for (const auto byte : data) {
        /// TBD
//        if (write(usbState_, &byte, 1) < 0) {
//            std::cerr << "error: " << strerror(errno) << std::endl;
//            return -1;
//        }
        std::cout << static_cast<int>(byte) << std::endl;
    }

    return 1;
}