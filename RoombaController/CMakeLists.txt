cmake_minimum_required(VERSION 3.6)
project(RoombaController)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

find_package (Threads)

# find boost
find_package(Boost 1.55 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

## restbed library
add_subdirectory(dependencies/restbed)
include_directories(dependencies/restbed/source)

# set the POCO paths and libs
set(POCO_PREFIX      "/usr/local") # the directory containing "include" and "lib"
set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR     "${POCO_PREFIX}/lib")
set(POCO_LIBS        "${POCO_LIB_DIR}/libPocoFoundationd.so")
include_directories(${POCO_INCLUDE_DIR})

## source files
set(SOURCE_FILES
        src/main.cpp
        src/serial.cpp
        dependencies/json.hpp
        src/server.cpp
        src/responses.cpp
        src/roomba_control.cpp
        src/roomba_statemachine.cpp
        src/glb_session.cpp
        src/sensorparser.cpp
        src/glb_server_context.cpp
        src/roomba_algorithm.cpp)

## directory for testing
add_subdirectory(tests)

## check if doxygen is available
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(Documentation ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/docs
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

add_executable(RoombaController ${SOURCE_FILES})

target_link_libraries(RoombaController ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${POCO_LIBS} restbed)
