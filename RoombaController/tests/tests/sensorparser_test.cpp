//
// Created by bas on 20-4-17.
//

#include "src/sensorparser.h"
#include "gtest/gtest.h"

TEST(sensorparser_test, parsing_vector){
    Sensors testsensors;
    EXPECT_EQ(testsensors.parsedata({19, 5, 29, 2, 25, 13, 0, 163}), 1);
    EXPECT_EQ(testsensors.getvalue<unsigned short>(Cliff_front_left_signal),
              static_cast<unsigned short>(537));
}

TEST(sensorparser_test, create_vector){
    Sensors testsensors;
    vector<sensorID> input = {Wall, Cliff_front_left, Cliff_front_left_signal, Virtual_wall};
    vector<unsigned char> expected_output = {149, 4, Wall, Cliff_front_left, Cliff_front_left_signal, Virtual_wall};
    EXPECT_EQ(testsensors.createvector(input), expected_output);
    expected_output.at(0) = 148;
    EXPECT_EQ(testsensors.createvectorstream(input), expected_output);
    EXPECT_EQ(testsensors.createvector(Wall), vector<unsigned char>({142, Wall}));

}