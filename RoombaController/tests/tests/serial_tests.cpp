//
// Created by victor on 13.03.17.
//

#include "src/serial.h"
#include "gtest/gtest.h"

TEST(serial_test, connect) {
    io::SerialPort serial("/dev/ttyUSB0", B115200);

    EXPECT_EQ(serial.connect(), 1);

    serial.disconnect();
}

TEST(serial_test, read_write) {
    io::SerialPort serial("/dev/ttyUSB0", B115200);
    io::byteVector vrec{}, vsent{100, 200};

    EXPECT_EQ(serial.connect(), 1);

    serial.writeVector({100, 200});

    serial.readAll(vrec, 255);
    EXPECT_EQ(vrec, vsent);

    serial.disconnect();
}
