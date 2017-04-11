cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build")

find_package (Threads)

## restbed library
add_subdirectory(restbed)
include_directories(restbed/source)

## source files
set(SOURCE_FILES
        IO/serial.cpp IO/serial.h
        json.hpp
        Server/server.h Server/server.cpp
        main.cpp Server/responses.h Server/responses.cpp Server/file_handler.h SystemControl/main_process.h SystemControl/roomba_control.h SystemControl/sensordata.h Subsystems/devices.h SystemControl/roomba_control.cpp SystemControl/main_process.cpp)

## directory for testing
add_subdirectory(Tests)

add_executable(RoombaController ${SOURCE_FILES})

target_link_libraries(RoombaController ${CMAKE_THREAD_LIBS_INIT} restbed)