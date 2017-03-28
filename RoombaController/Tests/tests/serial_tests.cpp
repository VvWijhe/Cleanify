//
// Created by victor on 13.03.17.
//

#include <IO/serial.h>
#include "gtest/gtest.h"

TEST(serial_test, connect) {
    io::SerialPort serial("/dev/ttyUSB0", B115200);

    EXPECT_GT(serial.connect(), 0);
}

TEST(serial_test, read_write) {
    io::SerialPort serial("/dev/ttyUSB0", B115200);
    io::byteVector v, v2{100, 200, '\r'};

    EXPECT_GT(serial.connect(), 0);

    serial.writeVector({100, 200, '\r'});
    serial.readAll(v, 255);
    EXPECT_EQ(v, v2);

    serial.writeVector({100, 201, '\r'});
    serial.readAll(v, 255);
    EXPECT_NE(v, v2);
}
