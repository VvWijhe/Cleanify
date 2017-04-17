cmake_minimum_required(VERSION 3.6)
project(Tests)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(tests)
add_subdirectory(lib/googletest)
