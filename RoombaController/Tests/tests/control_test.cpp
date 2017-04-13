//
// Created by Victor on 13-4-2017.
//

#include "SystemControl/roomba_control.h"
#include "gtest/gtest.h"

TEST(control_test, motors){
    systemcontrol::RoombaControl control("/dev/ttyUSB0",systemcontrol::RoombaControl::b57600);
    EXPECT_EQ(control.setMotors(control.main, true), 4);

    EXPECT_EQ(control.setMotors(control.all, true), 15);

    EXPECT_EQ(control.setMotors(control.main, false), 11);
}

