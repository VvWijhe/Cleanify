# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/bas/Downloads/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/bas/Downloads/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bas/CLionProjects/Cleanify/RoombaController

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bas/CLionProjects/Cleanify/RoombaController/Build

# Include any dependencies generated for this target.
include Tests/tests/CMakeFiles/runTests.dir/depend.make

# Include the progress variables for this target.
include Tests/tests/CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/tests/CMakeFiles/runTests.dir/flags.make

Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o: Tests/tests/CMakeFiles/runTests.dir/flags.make
Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o: ../Tests/tests/serial_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bas/CLionProjects/Cleanify/RoombaController/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/serial_tests.cpp.o -c /home/bas/CLionProjects/Cleanify/RoombaController/Tests/tests/serial_tests.cpp

Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/serial_tests.cpp.i"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bas/CLionProjects/Cleanify/RoombaController/Tests/tests/serial_tests.cpp > CMakeFiles/runTests.dir/serial_tests.cpp.i

Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/serial_tests.cpp.s"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bas/CLionProjects/Cleanify/RoombaController/Tests/tests/serial_tests.cpp -o CMakeFiles/runTests.dir/serial_tests.cpp.s

Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o.requires:

.PHONY : Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o.requires

Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o.provides: Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o.requires
	$(MAKE) -f Tests/tests/CMakeFiles/runTests.dir/build.make Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o.provides.build
.PHONY : Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o.provides

Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o.provides.build: Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o


Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o: Tests/tests/CMakeFiles/runTests.dir/flags.make
Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o: ../IO/serial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bas/CLionProjects/Cleanify/RoombaController/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o -c /home/bas/CLionProjects/Cleanify/RoombaController/IO/serial.cpp

Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/__/__/IO/serial.cpp.i"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bas/CLionProjects/Cleanify/RoombaController/IO/serial.cpp > CMakeFiles/runTests.dir/__/__/IO/serial.cpp.i

Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/__/__/IO/serial.cpp.s"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bas/CLionProjects/Cleanify/RoombaController/IO/serial.cpp -o CMakeFiles/runTests.dir/__/__/IO/serial.cpp.s

Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o.requires:

.PHONY : Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o.requires

Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o.provides: Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o.requires
	$(MAKE) -f Tests/tests/CMakeFiles/runTests.dir/build.make Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o.provides.build
.PHONY : Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o.provides

Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o.provides.build: Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o


Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o: Tests/tests/CMakeFiles/runTests.dir/flags.make
Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o: ../Tests/tests/devices.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bas/CLionProjects/Cleanify/RoombaController/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/devices.cpp.o -c /home/bas/CLionProjects/Cleanify/RoombaController/Tests/tests/devices.cpp

Tests/tests/CMakeFiles/runTests.dir/devices.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/devices.cpp.i"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bas/CLionProjects/Cleanify/RoombaController/Tests/tests/devices.cpp > CMakeFiles/runTests.dir/devices.cpp.i

Tests/tests/CMakeFiles/runTests.dir/devices.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/devices.cpp.s"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bas/CLionProjects/Cleanify/RoombaController/Tests/tests/devices.cpp -o CMakeFiles/runTests.dir/devices.cpp.s

Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o.requires:

.PHONY : Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o.requires

Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o.provides: Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o.requires
	$(MAKE) -f Tests/tests/CMakeFiles/runTests.dir/build.make Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o.provides.build
.PHONY : Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o.provides

Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o.provides.build: Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o


# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/serial_tests.cpp.o" \
"CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o" \
"CMakeFiles/runTests.dir/devices.cpp.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

runTests: Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o
runTests: Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o
runTests: Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o
runTests: Tests/tests/CMakeFiles/runTests.dir/build.make
runTests: Tests/lib/googletest/googlemock/gtest/libgtest.a
runTests: Tests/lib/googletest/googlemock/gtest/libgtest_main.a
runTests: Tests/lib/googletest/googlemock/gtest/libgtest.a
runTests: Tests/tests/CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bas/CLionProjects/Cleanify/RoombaController/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../runTests"
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/tests/CMakeFiles/runTests.dir/build: runTests

.PHONY : Tests/tests/CMakeFiles/runTests.dir/build

Tests/tests/CMakeFiles/runTests.dir/requires: Tests/tests/CMakeFiles/runTests.dir/serial_tests.cpp.o.requires
Tests/tests/CMakeFiles/runTests.dir/requires: Tests/tests/CMakeFiles/runTests.dir/__/__/IO/serial.cpp.o.requires
Tests/tests/CMakeFiles/runTests.dir/requires: Tests/tests/CMakeFiles/runTests.dir/devices.cpp.o.requires

.PHONY : Tests/tests/CMakeFiles/runTests.dir/requires

Tests/tests/CMakeFiles/runTests.dir/clean:
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests && $(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : Tests/tests/CMakeFiles/runTests.dir/clean

Tests/tests/CMakeFiles/runTests.dir/depend:
	cd /home/bas/CLionProjects/Cleanify/RoombaController/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bas/CLionProjects/Cleanify/RoombaController /home/bas/CLionProjects/Cleanify/RoombaController/Tests/tests /home/bas/CLionProjects/Cleanify/RoombaController/Build /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests /home/bas/CLionProjects/Cleanify/RoombaController/Build/Tests/tests/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/tests/CMakeFiles/runTests.dir/depend

