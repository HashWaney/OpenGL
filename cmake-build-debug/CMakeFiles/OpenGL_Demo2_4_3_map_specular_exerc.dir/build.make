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
include CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/flags.make

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.o: CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/flags.make
CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.o: ../src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.o -c /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp > CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.i

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp -o CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.s

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.o: CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/flags.make
CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.o: ../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.o   -c /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/glad.c

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/glad.c > CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.i

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/glad.c -o CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.s

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.o: CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/flags.make
CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.o: ../src/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.o -c /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/stb_image.cpp

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/stb_image.cpp > CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.i

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/stb_image.cpp -o CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.s

# Object files for target OpenGL_Demo2_4_3_map_specular_exerc
OpenGL_Demo2_4_3_map_specular_exerc_OBJECTS = \
"CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.o" \
"CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.o" \
"CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.o"

# External object files for target OpenGL_Demo2_4_3_map_specular_exerc
OpenGL_Demo2_4_3_map_specular_exerc_EXTERNAL_OBJECTS =

OpenGL_Demo2_4_3_map_specular_exerc: CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp.o
OpenGL_Demo2_4_3_map_specular_exerc: CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/glad.c.o
OpenGL_Demo2_4_3_map_specular_exerc: CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/src/stb_image.cpp.o
OpenGL_Demo2_4_3_map_specular_exerc: CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/build.make
OpenGL_Demo2_4_3_map_specular_exerc: /usr/local/Cellar/glfw/3.3/lib/libglfw.3.dylib
OpenGL_Demo2_4_3_map_specular_exerc: /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib
OpenGL_Demo2_4_3_map_specular_exerc: CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable OpenGL_Demo2_4_3_map_specular_exerc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/build: OpenGL_Demo2_4_3_map_specular_exerc

.PHONY : CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/build

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/clean

CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/depend:
	cd /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangqing/Desktop/JNI/CPP/OpenGl /Users/wangqing/Desktop/JNI/CPP/OpenGl /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/OpenGl/cmake-build-debug/CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGL_Demo2_4_3_map_specular_exerc.dir/depend

