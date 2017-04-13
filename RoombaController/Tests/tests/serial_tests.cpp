//
// Created by victor on 13.03.17.
//

#include <Serial/serial.h>
#include "gtest/gtest.h"

TEST(serial_test, connect) {
    io::SerialPort serial("/dev/ttyUSB0", B115200);

    EXPECT_GT(serial.connect(), 0);

    serial.disconnect();
}

TEST(serial_test, read_write) {
    io::SerialPort serial("/dev/ttyUSB0", B115200);
    io::byteVector vrec{}, vsent{100, 200, '\r'};

    EXPECT_GT(serial.connect(), 0);

    serial.writeVector({100, 200, '\r'});
    serial.readAll(vrec, 255);
    EXPECT_EQ(vrec, vsent);

    serial.writeVector({100, 201, '\r'});
    serial.readAll(vrec, 255);
    EXPECT_NE(vrec, vsent);

    serial.disconnect();
}
