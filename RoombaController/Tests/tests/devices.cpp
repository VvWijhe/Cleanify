//
// Created by jamie on 3/29/17.
//
#include <iostream>

#include "Subsystems/devices.h"
#include "gtest/gtest.h"

using namespace std;

TEST(devices_test, sendData) {
    io::SerialPort serialPort("/dev/ttyUSB0", B115200);
    subsystems::Motor m(&serialPort, 100); // 100 for testing
    io::byteVector vrec{},
            vsent{1, 2, 3, 4, 5, '\r'},
            vexp{128, 100, 1, 2, 3, 4, 5, '\r'};

    serialPort.connect();

    m.sendData(vsent);
    serialPort.readAll(vrec);

    EXPECT_EQ(vrec, vexp);

    serialPort.disconnect();
}
