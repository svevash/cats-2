# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Svetlana\CLionProjects\cats_2\2B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Svetlana\CLionProjects\cats_2\2B\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2B.dir/flags.make

CMakeFiles/2B.dir/main.cpp.obj: CMakeFiles/2B.dir/flags.make
CMakeFiles/2B.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Svetlana\CLionProjects\cats_2\2B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2B.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2B.dir\main.cpp.obj -c C:\Users\Svetlana\CLionProjects\cats_2\2B\main.cpp

CMakeFiles/2B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2B.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Svetlana\CLionProjects\cats_2\2B\main.cpp > CMakeFiles\2B.dir\main.cpp.i

CMakeFiles/2B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2B.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Svetlana\CLionProjects\cats_2\2B\main.cpp -o CMakeFiles\2B.dir\main.cpp.s

# Object files for target 2B
2B_OBJECTS = \
"CMakeFiles/2B.dir/main.cpp.obj"

# External object files for target 2B
2B_EXTERNAL_OBJECTS =

2B.exe: CMakeFiles/2B.dir/main.cpp.obj
2B.exe: CMakeFiles/2B.dir/build.make
2B.exe: CMakeFiles/2B.dir/linklibs.rsp
2B.exe: CMakeFiles/2B.dir/objects1.rsp
2B.exe: CMakeFiles/2B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Svetlana\CLionProjects\cats_2\2B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2B.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2B.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2B.dir/build: 2B.exe

.PHONY : CMakeFiles/2B.dir/build

CMakeFiles/2B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2B.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2B.dir/clean

CMakeFiles/2B.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Svetlana\CLionProjects\cats_2\2B C:\Users\Svetlana\CLionProjects\cats_2\2B C:\Users\Svetlana\CLionProjects\cats_2\2B\cmake-build-debug C:\Users\Svetlana\CLionProjects\cats_2\2B\cmake-build-debug C:\Users\Svetlana\CLionProjects\cats_2\2B\cmake-build-debug\CMakeFiles\2B.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2B.dir/depend

