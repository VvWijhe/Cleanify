cmake_minimum_required(VERSION 3.6)
project(Dataframes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dataframe.cpp Dataframe.h)
add_executable(Dataframes ${SOURCE_FILES})