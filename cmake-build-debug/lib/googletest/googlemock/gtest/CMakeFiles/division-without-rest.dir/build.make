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
include lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/depend.make

# Include the progress variables for this target.
include lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/flags.make

# Object files for target division-without-rest
division__without__rest_OBJECTS =

# External object files for target division-without-rest
division__without__rest_EXTERNAL_OBJECTS =

lib/googletest/googlemock/gtest/division-without-rest: lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/build.make
lib/googletest/googlemock/gtest/division-without-rest: lib/googletest/googlemock/gtest/libgtest_maind.a
lib/googletest/googlemock/gtest/division-without-rest: lib/googletest/googlemock/gtest/libgtestd.a
lib/googletest/googlemock/gtest/division-without-rest: lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alright/dev/c++/study_c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX executable division-without-rest"
	cd /home/alright/dev/c++/study_c/cmake-build-debug/lib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/division-without-rest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/build: lib/googletest/googlemock/gtest/division-without-rest

.PHONY : lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/build

lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/requires:

.PHONY : lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/requires

lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/clean:
	cd /home/alright/dev/c++/study_c/cmake-build-debug/lib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/division-without-rest.dir/cmake_clean.cmake
.PHONY : lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/clean

lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/depend:
	cd /home/alright/dev/c++/study_c/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alright/dev/c++/study_c /home/alright/dev/c++/study_c/lib/googletest/googletest /home/alright/dev/c++/study_c/cmake-build-debug /home/alright/dev/c++/study_c/cmake-build-debug/lib/googletest/googlemock/gtest /home/alright/dev/c++/study_c/cmake-build-debug/lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/googletest/googlemock/gtest/CMakeFiles/division-without-rest.dir/depend

