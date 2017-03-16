cmake_minimum_required(VERSION 3.6)
project(Tests)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(tests)
add_subdirectory(lib/googletest)

#include_directories(lib/googletest/googletest/include)
#include_directories(lib/googletest/googlemock/include)

#set(SOURCE_FILES  main.cpp tests/TestFunctions.cpp tests/TestFunctions.h)

#add_executable(Tests ${SOURCE_FILES} tests/TestFunctions.cpp tests/TestFunctions.h)
#target_link_libraries(Tests gtest gtest_main)