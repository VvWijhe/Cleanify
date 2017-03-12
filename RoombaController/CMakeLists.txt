cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Dataframe/DataFrames.cpp Dataframe/DataFrames.h
        serial/SerialPort.cpp serial/SerialPort.h
        main.cpp)

add_executable(RoombaController ${SOURCE_FILES})