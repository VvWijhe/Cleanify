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

    /**
     * @brief Provides support for the linux serial interface.
     */
    class SerialPort {
    public:
        /**
         * @brief Empty constructor. Sets the baudrate and path to the port.
         * @param portname Path to the port.
         * @param baud Baudrate that is supported by the linux system.
         */
        SerialPort(std::string portname, speed_t baud);

        /**
         * @brief Opens the serial port.
         * @return errno
         */
        int connect();

        /**
         * @brief closes the serial port
         * @return errno
         */
        int disconnect();

        /**
         * @brief Writes a byte.
         * @param data An unsigned char.
         * @return errno
         */
        int writeByte(unsigned char data);

        /**
         * @brief Writes a vector of unsiged chars.
         * @param data A vector of unsigned chars.
         * @return errno
         */
        int writeVector(const byteVector &data);

        /**
         * @brief Reads a stream of bytes. Blocks till a byte is received. Returns if after the first byte, no other
         * byte is received after some milliseconds.
         * @param buffer Vector where the received data will be stored.
         * @param limit Maximum number to be read. Default is 255.
         * @return errno
         */
        int readAll(byteVector &buffer, size_t limit = 255) const;

    private:
        std::string port_;
        speed_t baud_;
        int fd_{};
    };
}

#endif //FEMALE_REPLACEMENT_SERIALPORT_H
