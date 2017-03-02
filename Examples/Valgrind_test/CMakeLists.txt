cmake_minimum_required(VERSION 3.6)
project(Valgrind_test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(Valgrind_test ${SOURCE_FILES})