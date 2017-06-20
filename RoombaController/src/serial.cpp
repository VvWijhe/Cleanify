//
// Created by raymon on 11-3-17.
//
#include "serial.h"

using namespace io;

SerialPort::SerialPort(std::string portname, speed_t baud) : port_(portname),
                                                             baud_(baud) {

}

int SerialPort::connect() {
    fd_ = open(port_.c_str(), O_RDWR | O_NOCTTY);

    struct termios tty;
    memset(&tty, 0, sizeof tty);

    if (tcgetattr(fd_, &tty) != 0) {
        return errno;
    }

    cfsetospeed(&tty, baud_);
    cfsetispeed(&tty, baud_);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    tty.c_iflag &= ~IGNBRK;         // disable break processing
    tty.c_lflag = 0;                // no signaling chars, no echo,
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN] = 0;            // pure timed read
    tty.c_cc[VTIME] = 1;            // read timeout

    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl
    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= 0; // no blocking
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr(fd_, TCSANOW, &tty) != 0) {
        perror("serial error");
        return errno;
    }

    return 1;
}

int SerialPort::disconnect() {
    return close(fd_) < 0 ? errno : 1;
}

int SerialPort::readAll(byteVector &buffer, size_t limit) const {
    unsigned char c[limit];

    auto nRead = read(fd_, c, limit);
    std::cout << nRead << std::endl;
    if(nRead <= 0) {
        return -1;
    }

    for (int i = 0; i < nRead; i++) {
        //std::cout << static_cast<int>(c[i]) << std::endl;
        buffer.push_back(c[i]);
    }

    return 0;
}

int SerialPort::writeByte(unsigned char data) {
    if (fd_ < 0) {
        return errno;
    }

    if (write(fd_, &data, 1) < 0) {
        return errno;
    }

    return 1;
}

int SerialPort::writeVector(const std::vector<unsigned char> &data) {
    if (fd_ < 0) {
        return errno;
    }

    for (const auto byte : data) {
        if (write(fd_, &byte, 1) < 0) {
            return errno;
        }
    }

    usleep(static_cast<useconds_t>(data.size() * 100));

    return 1;
}
