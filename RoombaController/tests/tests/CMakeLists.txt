include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../../)

add_executable(runTests
        #serial_tests.cpp
        #control_test.cpp
        sensorparser_test.cpp
        ../../src/serial.cpp
        ../../src/roomba_control.cpp
        ../../src/sensorparser.cpp algorithms.cpp)

target_link_libraries(runTests gtest gtest_main ${Boost_LIBRARIES} ${POCO_LIBS})