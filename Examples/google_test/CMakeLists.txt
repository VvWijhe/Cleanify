cmake_minimum_required(VERSION 3.6)
project(google_test)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(../../Libs/googletest-master)
include_directories(../../Libs/googletest-master/googletest/include)
include_directories(../../googletest-master/googlemock/include)



set(SOURCE_FILES main.cpp tests/ClassName.h tests/test.cpp)
add_executable(google_test ${SOURCE_FILES} tests/ClassName.h tests/test.cpp)
target_link_libraries(google_test gtest gtest_main)