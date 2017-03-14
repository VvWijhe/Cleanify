cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

find_package (Threads)

set(SOURCE_FILES
        Sci/commands.h
        Sci/serialport.cpp Sci/serialport.h
        main.cpp)

add_executable(RoombaController ${SOURCE_FILES})

target_link_libraries(RoombaController ${CMAKE_THREAD_LIBS_INIT})