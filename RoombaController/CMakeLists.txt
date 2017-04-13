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
        main.cpp
        Serial/serial.cpp Serial/serial.h
        json.hpp
        Server/server.h Server/server.cpp
        Server/responses.h Server/responses.cpp Server/file_handler.h
        SystemControl/roomba_statemachine.h SystemControl/roomba_control.h SystemControl/sensorparser.h
        SystemControl/roomba_control.cpp SystemControl/roomba_statemachine.cpp globals.cpp globals.h)

## directory for testing
add_subdirectory(Tests)

add_executable(RoombaController ${SOURCE_FILES})

target_link_libraries(RoombaController ${CMAKE_THREAD_LIBS_INIT} restbed)