//
// Created by Victor on 13-4-2017.
//

#include "SystemControl/roomba_control.h"
#include "gtest/gtest.h"

TEST(control_test, motors){
    systemcontrol::RoombaControl control("/dev/ttyUSB0",systemcontrol::RoombaControl::b57600);


}