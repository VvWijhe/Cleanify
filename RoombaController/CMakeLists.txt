cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

find_package (Threads)

set(BOOST_COMPONENTS system thread filesystem date_time)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
        set(BOOST_COMPONENTS ${BOOST_COMPONENTS} regex)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_BOOST_REGEX")
    endif()
endif()
find_package(Boost 1.53.0 COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIR})

set(SOURCE_FILES
        Sci/commands.h
        Sci/SerialPort.cpp Sci/SerialPort.h
        Server/server.h Server/server.cpp Server/http_server.hpp
        main.cpp Server/responses.h Server/responses.cpp)

## directory for testing
add_subdirectory(Tests)

add_executable(RoombaController ${SOURCE_FILES})

target_link_libraries(RoombaController ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})