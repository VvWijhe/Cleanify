cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)



find_package (Threads)

## restbed library
add_subdirectory(restbed)
include_directories(restbed/source)

## source files
set(SOURCE_FILES
        IO/serial.cpp IO/serial.h
        Server/server.h Server/server.cpp
<<<<<<< Updated upstream
        main.cpp Server/responses.h Server/responses.cpp Server/file_handler.h SystemControl/processing.h SystemControl/roomba_contol.h SystemControl/sensordata.h Subsystems/devices.h)
=======
        main.cpp Server/responses.h Server/responses.cpp io/roombaio.h io/roombacontroller.h io/roombacontroller.cpp)
>>>>>>> Stashed changes

## directory for testing
add_subdirectory(Tests)

add_executable(RoombaController ${SOURCE_FILES})

target_link_libraries(RoombaController ${CMAKE_THREAD_LIBS_INIT} restbed)