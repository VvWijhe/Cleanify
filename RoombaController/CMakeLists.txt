cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

find_package (Threads)

## restbed library
add_subdirectory(dependencies/restbed)
include_directories(dependencies/restbed/source)

## source files
set(SOURCE_FILES
        src/main.cpp
        src/serial.cpp src/serial.h
        src/json.hpp
        src/server.h src/server.cpp
        src/responses.h src/responses.cpp src/file_handler.h
        src/roomba_statemachine.h src/roomba_control.h src/sensorparser.h
        src/roomba_control.cpp src/roomba_statemachine.cpp src/globals.cpp src/globals.h)

## directory for testing
add_subdirectory(tests)

add_executable(RoombaController ${SOURCE_FILES})

target_link_libraries(RoombaController ${CMAKE_THREAD_LIBS_INIT} restbed)