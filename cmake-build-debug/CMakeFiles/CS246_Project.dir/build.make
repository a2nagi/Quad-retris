# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Harkamal\SE\3B\CS246\CS246_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Harkamal\SE\3B\CS246\CS246_Project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CS246_Project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CS246_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CS246_Project.dir/flags.make

CMakeFiles/CS246_Project.dir/main.cpp.obj: CMakeFiles/CS246_Project.dir/flags.make
CMakeFiles/CS246_Project.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Harkamal\SE\3B\CS246\CS246_Project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CS246_Project.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CS246_Project.dir\main.cpp.obj -c C:\Users\Harkamal\SE\3B\CS246\CS246_Project\main.cpp

CMakeFiles/CS246_Project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS246_Project.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Harkamal\SE\3B\CS246\CS246_Project\main.cpp > CMakeFiles\CS246_Project.dir\main.cpp.i

CMakeFiles/CS246_Project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS246_Project.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Harkamal\SE\3B\CS246\CS246_Project\main.cpp -o CMakeFiles\CS246_Project.dir\main.cpp.s

CMakeFiles/CS246_Project.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/CS246_Project.dir/main.cpp.obj.requires

CMakeFiles/CS246_Project.dir/main.cpp.obj.provides: CMakeFiles/CS246_Project.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\CS246_Project.dir\build.make CMakeFiles/CS246_Project.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/CS246_Project.dir/main.cpp.obj.provides

CMakeFiles/CS246_Project.dir/main.cpp.obj.provides.build: CMakeFiles/CS246_Project.dir/main.cpp.obj


# Object files for target CS246_Project
CS246_Project_OBJECTS = \
"CMakeFiles/CS246_Project.dir/main.cpp.obj"

# External object files for target CS246_Project
CS246_Project_EXTERNAL_OBJECTS =

CS246_Project.exe: CMakeFiles/CS246_Project.dir/main.cpp.obj
CS246_Project.exe: CMakeFiles/CS246_Project.dir/build.make
CS246_Project.exe: CMakeFiles/CS246_Project.dir/linklibs.rsp
CS246_Project.exe: CMakeFiles/CS246_Project.dir/objects1.rsp
CS246_Project.exe: CMakeFiles/CS246_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Harkamal\SE\3B\CS246\CS246_Project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CS246_Project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CS246_Project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CS246_Project.dir/build: CS246_Project.exe

.PHONY : CMakeFiles/CS246_Project.dir/build

CMakeFiles/CS246_Project.dir/requires: CMakeFiles/CS246_Project.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/CS246_Project.dir/requires

CMakeFiles/CS246_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CS246_Project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CS246_Project.dir/clean

CMakeFiles/CS246_Project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Harkamal\SE\3B\CS246\CS246_Project C:\Users\Harkamal\SE\3B\CS246\CS246_Project C:\Users\Harkamal\SE\3B\CS246\CS246_Project\cmake-build-debug C:\Users\Harkamal\SE\3B\CS246\CS246_Project\cmake-build-debug C:\Users\Harkamal\SE\3B\CS246\CS246_Project\cmake-build-debug\CMakeFiles\CS246_Project.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CS246_Project.dir/depend

