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
CMAKE_COMMAND = /home/victor/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/victor/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin"

# Include any dependencies generated for this target.
include tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/flags.make

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/flags.make
tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: ../tests/lib/googletest/googletest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/tests/lib/googletest/googlemock/gtest" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/tests/lib/googletest/googletest/src/gtest_main.cc"

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/tests/lib/googletest/googlemock/gtest" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/tests/lib/googletest/googletest/src/gtest_main.cc" > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/tests/lib/googletest/googlemock/gtest" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/tests/lib/googletest/googletest/src/gtest_main.cc" -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:

.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/build.make tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o


# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

tests/lib/googletest/googlemock/gtest/libgtest_main.a: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
tests/lib/googletest/googlemock/gtest/libgtest_main.a: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/build.make
tests/lib/googletest/googlemock/gtest/libgtest_main.a: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/tests/lib/googletest/googlemock/gtest" && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/tests/lib/googletest/googlemock/gtest" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/build: tests/lib/googletest/googlemock/gtest/libgtest_main.a

.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/build

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/requires: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/requires

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/clean:
	cd "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/tests/lib/googletest/googlemock/gtest" && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/clean

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/depend:
	cd "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController" "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/tests/lib/googletest/googletest" "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin" "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/tests/lib/googletest/googlemock/gtest" "/media/victor/harde schijf/school/HBO2/semester_2/Cleanify/RoombaController/bin/tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/depend

