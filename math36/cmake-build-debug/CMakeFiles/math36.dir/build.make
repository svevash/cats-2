# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/math36.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/math36.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/math36.dir/flags.make

CMakeFiles/math36.dir/main.cpp.o: CMakeFiles/math36.dir/flags.make
CMakeFiles/math36.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/math36.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/math36.dir/main.cpp.o -c /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/main.cpp

CMakeFiles/math36.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math36.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/main.cpp > CMakeFiles/math36.dir/main.cpp.i

CMakeFiles/math36.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math36.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/main.cpp -o CMakeFiles/math36.dir/main.cpp.s

CMakeFiles/math36.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/math36.dir/main.cpp.o.requires

CMakeFiles/math36.dir/main.cpp.o.provides: CMakeFiles/math36.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/math36.dir/build.make CMakeFiles/math36.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/math36.dir/main.cpp.o.provides

CMakeFiles/math36.dir/main.cpp.o.provides.build: CMakeFiles/math36.dir/main.cpp.o


# Object files for target math36
math36_OBJECTS = \
"CMakeFiles/math36.dir/main.cpp.o"

# External object files for target math36
math36_EXTERNAL_OBJECTS =

math36: CMakeFiles/math36.dir/main.cpp.o
math36: CMakeFiles/math36.dir/build.make
math36: CMakeFiles/math36.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable math36"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/math36.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/math36.dir/build: math36

.PHONY : CMakeFiles/math36.dir/build

CMakeFiles/math36.dir/requires: CMakeFiles/math36.dir/main.cpp.o.requires

.PHONY : CMakeFiles/math36.dir/requires

CMakeFiles/math36.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/math36.dir/cmake_clean.cmake
.PHONY : CMakeFiles/math36.dir/clean

CMakeFiles/math36.dir/depend:
	cd /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36 /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36 /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/cmake-build-debug /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/cmake-build-debug /mnt/c/Users/Svetlana/CLionProjects/cats_2/math36/cmake-build-debug/CMakeFiles/math36.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/math36.dir/depend
