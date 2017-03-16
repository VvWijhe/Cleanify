include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runTests
        roombatests.cpp)

target_link_libraries(runTests gtest gtest_main)