cmake_minimum_required(VERSION 3.6)
project(Tests)

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
        ../Sci/commands.h
        ../Sci/serialport.cpp ../Sci/serialport.h
        ../Server/server.h ../Server/server.cpp ../Server/http_server.hpp
        test.h test.cpp)

add_executable(Tests ${SOURCE_FILES})

target_link_libraries(Tests ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})