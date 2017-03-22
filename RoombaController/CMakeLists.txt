cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

find_package (Threads)

## restbed library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../dependency/restbed ${CMAKE_CURRENT_BINARY_DIR}/restbed)
include_directories(../dependency/restbed/source)

## source files
set(SOURCE_FILES
        Sci/commands.h
        Sci/SerialPort.cpp Sci/SerialPort.h
        Server/server.h Server/server.cpp
        main.cpp Server/responses.h Server/responses.cpp)

## directory for testing
add_subdirectory(Tests)

add_executable(RoombaController ${SOURCE_FILES})

target_link_libraries(RoombaController ${CMAKE_THREAD_LIBS_INIT} restbed)