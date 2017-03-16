cmake_minimum_required(VERSION 3.6)
project(Tests)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)



set(SOURCE_FILES  main.cpp tests/TestFunctions.cpp tests/TestFunctions.h)

add_executable(Tests ${SOURCE_FILES} tests/TestFunctions.cpp tests/TestFunctions.h)
target_link_libraries(Tests gtest gtest_main)