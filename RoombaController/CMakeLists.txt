cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Sci/commands.h
        Sci/serialport.cpp Sci/serialport.h
        main.cpp)

add_executable(RoombaController ${SOURCE_FILES})