# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/jamie/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.3780.121/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jamie/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.3780.121/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jamie/Documents/Project4/Cleanify/RoombaController

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jamie/Documents/Project4/Cleanify/RoombaController/Build

# Include any dependencies generated for this target.
include Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make
Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: ../Tests/lib/googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jamie/Documents/Project4/Cleanify/RoombaController/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o"
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o -c /home/jamie/Documents/Project4/Cleanify/RoombaController/Tests/lib/googletest/googletest/src/gtest-all.cc

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i"
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jamie/Documents/Project4/Cleanify/RoombaController/Tests/lib/googletest/googletest/src/gtest-all.cc > CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s"
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jamie/Documents/Project4/Cleanify/RoombaController/Tests/lib/googletest/googletest/src/gtest-all.cc -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires:

.PHONY : Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/build.make Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build
.PHONY : Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o


Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make
Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../Tests/lib/googletest/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jamie/Documents/Project4/Cleanify/RoombaController/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /home/jamie/Documents/Project4/Cleanify/RoombaController/Tests/lib/googletest/googlemock/src/gmock-all.cc

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jamie/Documents/Project4/Cleanify/RoombaController/Tests/lib/googletest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jamie/Documents/Project4/Cleanify/RoombaController/Tests/lib/googletest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires:

.PHONY : Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/build.make Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build
.PHONY : Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o


# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

Tests/lib/googletest/googlemock/libgmock.a: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o
Tests/lib/googletest/googlemock/libgmock.a: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
Tests/lib/googletest/googlemock/libgmock.a: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/build.make
Tests/lib/googletest/googlemock/libgmock.a: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jamie/Documents/Project4/Cleanify/RoombaController/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgmock.a"
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/build: Tests/lib/googletest/googlemock/libgmock.a

.PHONY : Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/build

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/requires: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/requires: Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

.PHONY : Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/requires

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/clean

Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /home/jamie/Documents/Project4/Cleanify/RoombaController/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jamie/Documents/Project4/Cleanify/RoombaController /home/jamie/Documents/Project4/Cleanify/RoombaController/Tests/lib/googletest/googlemock /home/jamie/Documents/Project4/Cleanify/RoombaController/Build /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock /home/jamie/Documents/Project4/Cleanify/RoombaController/Build/Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend

