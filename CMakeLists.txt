cmake_minimum_required(VERSION 3.12)
project(OpenGL_Demo)

set(CMAKE_CXX_STANDARD 11)

#添加头文件
set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.3/include/GLFW)
set(GLAD_H ../include/glad)
set(OPENGL_H ../include/learnopengl)
set(STB_H ../include/stb)
set(GLM_H ../include/glm)
include_directories(${GLEW_H} ${GLFW_H} ${GLAD_H} ${OPENGL_H} ${GLM_H})
#添加目标连接
set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLFW_LINK} ${GLEW_LINK})
add_library(STB_IMAGE "src/stb_image.cpp")
set(LIBS ${LIBS} STB_IMAGE)
add_library(GLAD "src/glad.c")
set(LIBS ${LIBS} GLAD)
#通过configure_file命令指定生成root_directory.h头文件
configure_file(configuration/root_directory.h.in configuration/root_directory.h)
include_directories(${CMAKE_BINARY_DIR}/configuration)
#set(SOURCE_FILES "src/glad.c" "src/01_first_view.cpp")

#add_executable(OpenGL_Demo ${SOURCE_FILES})
#执行编译命令
add_executable(OpenGL_Demo1
        src/glad.c
        src/01_first_view.cpp)
add_executable(OpenGl_Demo2
        src/02_test.cpp)

add_executable(OpenGL_Demo_1_1_hello_window
        src/1.getting_started/1.1.hello_window/hello_window.cpp
        src/glad.c)

add_executable(OpenGL_Demo_2_1_hello_triangle
        src/1.getting_started/2.1.hello_triangle/hello_triagnle.cpp
        src/glad.c)

add_executable(OpenGL_Demo_2_2_hello_triangle_index
        src/1.getting_started/2.2.hello_triangle_index/hello_triangle_index.cpp
        src/glad.c)

add_executable(OpenGL_Demo_2_3_hello_triangle_exercise1
        src/1.getting_started/2.3.hello_triangle_exercise1/hello_triangle_exercise1.cpp
        src/glad.c)
add_executable(OpenGL_Demo_2_4_hello_triangle_exercise2
        src/1.getting_started/2.4.hello_triangle_exercise2/hello_triangle_exercise2.cpp
        src/glad.c)

add_executable(OpenGL_Demo_2_5_hello_triangle_exercise3
        src/1.getting_started/2.5.hello_triangle_exercise3/hello_triangle_exercise3.cpp
        src/glad.c)
add_executable(OpenGL_Demo_3_1_shaders_uniform
        src/1.getting_started/3.1.shaders_uniform/shaders_uniform.cpp
        src/glad.c)

add_executable(OpenGL_Demo_3_2_shaders_interpolation
        src/1.getting_started/3.2.shaders_interpolation/shaders_interpolation.cpp
        src/glad.c)
add_executable(OpenGL_Demo_3_3_shaders_class
        src/1.getting_started/3.3.shaders_class/shaders_class.cpp
        src/glad.c)

add_executable(OpenGL_Demo_4_1_texture
        src/1.getting_started/4.1.textures/textures.cpp
        src/glad.c
        src/stb_image.cpp
        )

add_executable(OpenGL_Demo_4_2_textures_combined
        src/1.getting_started/4.2.textures_combined/textures_combined.cpp
        src/glad.c
        src/stb_image.cpp
        )

add_executable(OpenGL_Demo_4_3_textures_exercise1
        src/1.getting_started/4.3.textures_exercise1/textures_exercise1.cpp
        src/glad.c
        src/stb_image.cpp)

add_executable(OpenGL_Demo_4_4_textures_exercise2
        src/1.getting_started/4.4.textures_exercise2/textures_exercise2.cpp
        src/glad.c
        src/stb_image.cpp)

add_executable(OpenGL_Demo_4_5_textures_exercise3
        src/1.getting_started/4.5.textures_exercise3/textures_exercise3.cpp
        src/glad.c
        src/stb_image.cpp
        )
add_executable(OpenGL_Demo_5_1_transform
        src/1.getting_started/5.1.transformations/transformations.cpp
        src/glad.c
        src/stb_image.cpp)
add_executable(OpenGL_Demo_5_2_transform_exercise
        src/1.getting_started/5.2.transformations_exercise/transformations_exercise.cpp
        src/glad.c
        src/stb_image.cpp
        )
add_executable(OpenGL_Demo_6_1_coordinate_system
        src/1.getting_started/6.1.coordinate_systems/coordinate_systems.cpp
        src/glad.c
        src/stb_image.cpp)
add_executable(OpenGL_Demo_6_2_coordinate_system_depth
        src/1.getting_started/6.2.coordinate_system_depth/coordinate_system_depth.cpp
        src/glad.c
        src/stb_image.cpp)
add_executable(OpenGL_Demo_6_3_coordinate_multiple
        src/1.getting_started/6.3.coordinate_system_multiple/coordinate_system_multiple.cpp
        src/glad.c
        src/stb_image.cpp)

add_executable(OpenGL_Demo2_2_1_lighting_color
        src/2.lighting/1.colors/colors.cpp
        src/glad.c
        )

add_executable(OpenGL_Demo2_2_2_1_light_diffuse
        src/2.lighting/2.1.basic_lighting_diffuse/basic_lighting_diffuse.cpp
        src/glad.c
        )

add_executable(OpenGL_Demo2_2_2_2_light_specular
        src/2.lighting/2.2.basic_lighting_specular/basic_lighting_specular.cpp
        src/glad.c
        )

add_executable(OpenGL_Demo2_3_1_material
        src/2.lighting/3.1.materials/materials.cpp
        src/glad.c
        )
add_executable(OpenGL_Demo2_3_2_material_exercise
        src/2.lighting/3.2.materials_exercise1/materials_exercise.cpp
        src/glad.c
        )
add_executable(OpenGL_Demo2_4_1_map_diffuse
        src/2.lighting/4.1.lighting_maps_diffuse_map/lighting_maps_diffuse.cpp
        src/glad.c
        src/stb_image.cpp
        )

add_executable(OpenGL_Demo2_4_2_map_specular
        src/2.lighting/4.2.lighting_maps_specular/lighting_maps_specular.cpp
        src/glad.c
        src/stb_image.cpp

        )
add_executable(OpenGL_Demo2_4_3_map_specular_exercise
        src/2.lighting/4.3.lighting_maps_exercise/lighting_maps_specular.cpp
        src/glad.c
        src/stb_image.cpp

        )
if (APPLE)
    # 链接的执行程序上比如OpenGL_Demo1 中使用了OpenGL相关的头文件，就需要指定同样名称的执行程序
    target_link_libraries(OpenGL_Demo1 "-framework OpenGL")
    target_link_libraries(OpenGL_Demo1 "-framework GLUT")

    #1.1 hello window
    target_link_libraries(OpenGL_Demo_1_1_hello_window "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_1_1_hello_window "-framework GLUT")
    #2.1 hello triangle
    target_link_libraries(OpenGL_Demo_2_1_hello_triangle "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_2_1_hello_triangle "-framework GLUT")
    #2.2 hello triangle index
    target_link_libraries(OpenGL_Demo_2_2_hello_triangle_index "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_2_2_hello_triangle_index "-framework GLUT")
    #2.3 hello triangle exercise 1
    target_link_libraries(OpenGL_Demo_2_3_hello_triangle_exercise1 "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_2_3_hello_triangle_exercise1 "-framework GLUT")
    #2.4 hello triangle exercise 2
    target_link_libraries(OpenGL_Demo_2_4_hello_triangle_exercise2 "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_2_4_hello_triangle_exercise2 "-framework GLUT")
    #2.5 hello triangle exercise 3
    target_link_libraries(OpenGL_Demo_2_5_hello_triangle_exercise3 "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_2_5_hello_triangle_exercise3 "-framework GLUT")
    #3.1 shaders uniform
    target_link_libraries(OpenGL_Demo_3_1_shaders_uniform "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_3_1_shaders_uniform "-framework GLUT")
    #3.2 shader interpolation
    target_link_libraries(OpenGL_Demo_3_2_shaders_interpolation "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_3_2_shaders_interpolation "-framework GLUT")
    #3.3 shader class
    target_link_libraries(OpenGL_Demo_3_3_shaders_class "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_3_3_shaders_class "-framework GLUT")
    #4.1 texture
    target_link_libraries(OpenGL_Demo_4_1_texture "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_4_1_texture "-framework GLUT")
    #4.2 textures combined
    target_link_libraries(OpenGL_Demo_4_2_textures_combined "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_4_2_textures_combined "-framework GLUT")
    #4.3 textures_exercise1
    target_link_libraries(OpenGL_Demo_4_3_textures_exercise1 "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_4_3_textures_exercise1 "-framework GLUT")
    #4.4 textures_exercise2
    target_link_libraries(OpenGL_Demo_4_4_textures_exercise2 "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_4_4_textures_exercise2 "-framework GLUT")
    #4.5 textures_exercise3
    target_link_libraries(OpenGL_Demo_4_5_textures_exercise3 "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_4_5_textures_exercise3 "-framework GLUT")
    #5.1 transform
    target_link_libraries(OpenGL_Demo_5_1_transform "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_5_1_transform "-framework GLUT")
    #5.2 transform exercise
    target_link_libraries(OpenGL_Demo_5_2_transform_exercise "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_5_2_transform_exercise "-framework GLUT")
    #6.1 coordinate system
    target_link_libraries(OpenGL_Demo_6_1_coordinate_system "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_6_1_coordinate_system "-framework GLUT")
    #6.2 coordinate system depth
    target_link_libraries(OpenGL_Demo_6_2_coordinate_system_depth "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_6_2_coordinate_system_depth "-framework GLUT")
    #6.3 coordinate multiple
    target_link_libraries(OpenGL_Demo_6_3_coordinate_multiple "-framework OpenGL")
    target_link_libraries(OpenGL_Demo_6_3_coordinate_multiple "-framework GLUT")
    # 2 /1 color
    target_link_libraries(OpenGL_Demo2_2_1_lighting_color "-framework OpenGL")
    target_link_libraries(OpenGL_Demo2_2_1_lighting_color "-framework GLUT")
    # 2/ 2.1 basic_lighting_diffuse
    target_link_libraries(OpenGL_Demo2_2_2_1_light_diffuse "-framework OpenGL")
    target_link_libraries(OpenGL_Demo2_2_2_1_light_diffuse "-framework GLUT")
    # 2 /2.2 basic_lighting_specular
    target_link_libraries(OpenGL_Demo2_2_2_2_light_specular "-framework OpenGL")
    target_link_libraries(OpenGL_Demo2_2_2_2_light_specular "-framework GLUT")
    # 2 /3.1 materials
    target_link_libraries(OpenGL_Demo2_3_1_material "-framework OpenGL")
    target_link_libraries(OpenGL_Demo2_3_1_material "-framework GLUT")
    # 2 /3.2 materials_exercise
    target_link_libraries(OpenGL_Demo2_3_2_material_exercise "-framework OpenGL")
    target_link_libraries(OpenGL_Demo2_3_2_material_exercise "-framework GLUT")
    #2 /4.1 map diffuse
    target_link_libraries(OpenGL_Demo2_4_1_map_diffuse "-framework OpenGL")
    target_link_libraries(OpenGL_Demo2_4_1_map_diffuse "-framework GLUT")

    #2 /4.2 map specular
    target_link_libraries(OpenGL_Demo2_4_2_map_specular "-framework OpenGL")
    target_link_libraries(OpenGL_Demo2_4_2_map_specular "-framework GLUT")
    #2 /4.3 map specular exercise
    target_link_libraries(OpenGL_Demo2_4_3_map_specular_exercise "-framework OpenGL")
    target_link_libraries(OpenGL_Demo2_4_3_map_specular_exercise "-framework GLUT")





endif ()