# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/alright/Downloads/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/alright/Downloads/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alright/dev/c++/study_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alright/dev/c++/study_c/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Palindrom.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Palindrom.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Palindrom.dir/flags.make

CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o: CMakeFiles/Palindrom.dir/flags.make
CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o: ../Tests/Palindrom.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alright/dev/c++/study_c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o -c /home/alright/dev/c++/study_c/Tests/Palindrom.cc

CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alright/dev/c++/study_c/Tests/Palindrom.cc > CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.i

CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alright/dev/c++/study_c/Tests/Palindrom.cc -o CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.s

CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o.requires:

.PHONY : CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o.requires

CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o.provides: CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o.requires
	$(MAKE) -f CMakeFiles/Palindrom.dir/build.make CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o.provides.build
.PHONY : CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o.provides

CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o.provides.build: CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o


# Object files for target Palindrom
Palindrom_OBJECTS = \
"CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o"

# External object files for target Palindrom
Palindrom_EXTERNAL_OBJECTS =

Palindrom: CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o
Palindrom: CMakeFiles/Palindrom.dir/build.make
Palindrom: lib/googletest/googlemock/gtest/libgtest_maind.a
Palindrom: lib/googletest/googlemock/gtest/libgtestd.a
Palindrom: CMakeFiles/Palindrom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alright/dev/c++/study_c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Palindrom"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Palindrom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Palindrom.dir/build: Palindrom

.PHONY : CMakeFiles/Palindrom.dir/build

CMakeFiles/Palindrom.dir/requires: CMakeFiles/Palindrom.dir/Tests/Palindrom.cc.o.requires

.PHONY : CMakeFiles/Palindrom.dir/requires

CMakeFiles/Palindrom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Palindrom.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Palindrom.dir/clean

CMakeFiles/Palindrom.dir/depend:
	cd /home/alright/dev/c++/study_c/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alright/dev/c++/study_c /home/alright/dev/c++/study_c /home/alright/dev/c++/study_c/cmake-build-debug /home/alright/dev/c++/study_c/cmake-build-debug /home/alright/dev/c++/study_c/cmake-build-debug/CMakeFiles/Palindrom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Palindrom.dir/depend

