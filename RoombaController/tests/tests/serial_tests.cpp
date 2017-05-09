//
// Created by victor on 13.03.17.
//

#include "src/serial.h"
#include "src/sensorparser.h"
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

TEST(serial_test, timeout) {
    io::SerialPort serial("/dev/ttyUSB0", B115200);
    condition_variable cv;
    mutex mut;
    io::byteVector buffer;
    Sensors tmpSensor;

    EXPECT_EQ(serial.connect(), 1);

    // test no time out
    thread t([&serial, &buffer, &cv, &mut]{
        serial.readAll(buffer);

        unique_lock<mutex> lk(mut);
        cv.notify_one();
    });

    unique_lock<mutex> lk(mut);
    ASSERT_EQ(cv.wait_for(lk, chrono::milliseconds(800)), cv_status::timeout);

    t.detach();

    serial.disconnect();
}
