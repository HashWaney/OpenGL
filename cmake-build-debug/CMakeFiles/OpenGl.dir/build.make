# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangqing/Desktop/JNI/CPP/OpenGl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenGl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGl.dir/flags.make

CMakeFiles/OpenGl.dir/main.cpp.o: CMakeFiles/OpenGl.dir/flags.make
CMakeFiles/OpenGl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGl.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGl.dir/main.cpp.o -c /Users/wangqing/Desktop/JNI/CPP/OpenGl/main.cpp

CMakeFiles/OpenGl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGl.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqing/Desktop/JNI/CPP/OpenGl/main.cpp > CMakeFiles/OpenGl.dir/main.cpp.i

CMakeFiles/OpenGl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGl.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqing/Desktop/JNI/CPP/OpenGl/main.cpp -o CMakeFiles/OpenGl.dir/main.cpp.s

# Object files for target OpenGl
OpenGl_OBJECTS = \
"CMakeFiles/OpenGl.dir/main.cpp.o"

# External object files for target OpenGl
OpenGl_EXTERNAL_OBJECTS =

OpenGl: CMakeFiles/OpenGl.dir/main.cpp.o
OpenGl: CMakeFiles/OpenGl.dir/build.make
OpenGl: CMakeFiles/OpenGl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OpenGl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGl.dir/build: OpenGl

.PHONY : CMakeFiles/OpenGl.dir/build

CMakeFiles/OpenGl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGl.dir/clean

CMakeFiles/OpenGl.dir/depend:
	cd /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangqing/Desktop/JNI/CPP/OpenGl /Users/wangqing/Desktop/JNI/CPP/OpenGl /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles/OpenGl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGl.dir/depend

