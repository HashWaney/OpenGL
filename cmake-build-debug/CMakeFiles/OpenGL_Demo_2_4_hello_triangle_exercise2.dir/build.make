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
include CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/flags.make

CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.o: CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/flags.make
CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.o: ../src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.o -c /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp

CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp > CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.i

CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp -o CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.s

CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.o: CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/flags.make
CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.o: ../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.o   -c /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/glad.c

CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/glad.c > CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.i

CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/glad.c -o CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.s

# Object files for target OpenGL_Demo_2_4_hello_triangle_exercise2
OpenGL_Demo_2_4_hello_triangle_exercise2_OBJECTS = \
"CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.o" \
"CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.o"

# External object files for target OpenGL_Demo_2_4_hello_triangle_exercise2
OpenGL_Demo_2_4_hello_triangle_exercise2_EXTERNAL_OBJECTS =

OpenGL_Demo_2_4_hello_triangle_exercise2: CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp.o
OpenGL_Demo_2_4_hello_triangle_exercise2: CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/src/glad.c.o
OpenGL_Demo_2_4_hello_triangle_exercise2: CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/build.make
OpenGL_Demo_2_4_hello_triangle_exercise2: /usr/local/Cellar/glfw/3.3/lib/libglfw.3.dylib
OpenGL_Demo_2_4_hello_triangle_exercise2: /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib
OpenGL_Demo_2_4_hello_triangle_exercise2: CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OpenGL_Demo_2_4_hello_triangle_exercise2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/build: OpenGL_Demo_2_4_hello_triangle_exercise2

.PHONY : CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/build

CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/clean

CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/depend:
	cd /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangqing/Desktop/JNI/CPP/OpenGl /Users/wangqing/Desktop/JNI/CPP/OpenGl /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGL_Demo_2_4_hello_triangle_exercise2.dir/depend

