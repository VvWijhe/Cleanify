cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        SerialPort.cpp
        SerialPort.h)

add_executable(RoombaController ${SOURCE_FILES})