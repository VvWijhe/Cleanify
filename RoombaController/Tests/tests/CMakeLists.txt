include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../../)

add_executable(runTests
        sci_tests.cpp
        ../../io/SerialPort.cpp)

target_link_libraries(runTests gtest gtest_main)