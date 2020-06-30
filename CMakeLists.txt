cmake_minimum_required(VERSION 3.12)
project(OpenGL_Demo)

set(CMAKE_CXX_STANDARD 11)

#添加头文件
set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.3/include/GLFW)
set(GLAD_H ../include/glad)
include_directories(${GLEW_H} ${GLFW_H} ${GLAD_H})
#添加目标连接
set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLFW_LINK} ${GLEW_LINK})


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
endif ()