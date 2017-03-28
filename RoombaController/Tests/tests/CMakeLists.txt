include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../../)

add_executable(runTests
        serial_tests.cpp
        ../../IO/serial.cpp)

target_link_libraries(runTests gtest gtest_main)