cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

include_directories(../Libs/googletest-master)
include_directories(../Libs/googletest-master/googletest/include)
include_directories(../googletest-master/googlemock/include)

set(SOURCE_FILES
        Dataframe/DataFrames.cpp Dataframe/DataFrames.h
        serial/SerialPort.cpp serial/SerialPort.h
        Tests/test.cpp Tests/test.h
        main.cpp)

add_executable(RoombaController ${SOURCE_FILES})