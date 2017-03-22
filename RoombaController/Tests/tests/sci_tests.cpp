//
// Created by victor on 13.03.17.
//

#include <Sci/roombasci.h>
#include "gtest/gtest.h"

using namespace io;

TEST(sciTest, commands) {
    Commands cmds;

    auto cmd = cmds.getCommand("Start");
    EXPECT_EQ(cmd->second, 128);

    cmd = cmds.getCommand("Stop");
    EXPECT_EQ(cmd->second, 173);
}

// Precondition: roomba must be connected to the computer
TEST(sciTest, connect) {
    RoombaSCI roomba("/dev/ttyUSB0", B115200);

    EXPECT_GT(roomba.connect(), 0);
}

// Precondition: a serial device must be connected to the computer, RX and TX must be connected with each other
TEST(sciTest, sendReceive) {
    RoombaSCI roomba("/dev/ttyUSB0", B115200);
    byteVector v;
    byteVector v2 = {128, 1, 2, 3, '\r'};

    EXPECT_GT(roomba.connect(), 0);
    EXPECT_GT(roomba.sendCommand("Start", {1, 2, 3, '\r'}), 0);
    EXPECT_GT(roomba.readSensors(v), 0);
    EXPECT_TRUE(v == v2);
}
