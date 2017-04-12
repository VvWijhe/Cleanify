//
// Created by raymon on 11-3-17.
//

#ifndef FEMALE_REPLACEMENT_SERIALPORT_H
#define FEMALE_REPLACEMENT_SERIALPORT_H

#include <iostream>
#include <array>
#include <vector>
#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions
#include <vector>
#include <future>

namespace io {
    using byteVector = std::vector<unsigned char>;

    class SerialPort {
    public:
        SerialPort(std::string portname, speed_t baud) : port_(portname),
                                                         baud_(baud) {}

        int connect();

        int disconnect();

        int writeByte(unsigned char data);

        int writeVector(const std::vector<unsigned char> &data);

        int readAll(byteVector &buffer, int limit = 255) const;

        int getStatus() { return usbState_; }

    private:
        std::string port_;
        speed_t baud_;
        int usbState_{};
    };
}

#endif //FEMALE_REPLACEMENT_SERIALPORT_H
