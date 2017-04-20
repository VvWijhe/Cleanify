//
// Created by bas on 20-4-17.
//

#include "src/sensorparser.hpp"
#include "gtest/gtest.h"

TEST(sensorparser_test, parsing_vector){
    sensors testsensors;
    EXPECT_EQ(testsensors.ParseData({19, 5, 29, 2, 25, 13, 0, 163}), 1);
}

TEST(sensorparser_test, create_vector){
    sensors testsensors;
    vector<sensor> input = {Wall, Cliff_front_left, Cliff_front_left_signal, Virtual_wall};
    vector<unsigned char> expected_output = {149, 4, Wall, Cliff_front_left, Cliff_front_left_signal, Virtual_wall};
    EXPECT_EQ(testsensors.CreateVector(input), expected_output);
    expected_output.at(0) = 148;
    EXPECT_EQ(testsensors.CreateVectorStream(input), expected_output);
    EXPECT_EQ(testsensors.CreateVector(Wall), vector<unsigned char>({142, Wall}));

}