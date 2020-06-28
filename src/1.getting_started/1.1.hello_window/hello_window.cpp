//
// Created by hash on 2020/6/28.
//

#include "glfw3.h"
#include "iostream"

using namespace std;

int main() {
    // 1.创建GLFW窗口
    glfwInit();
    // 2.使用glfwWindowHint配置GLFW,
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL版本支持，主版本
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 次版本
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// 核心模式
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //前后兼容

    //3.创建一个窗口对象,设置宽高，以及标题
    GLFWwindow *window = glfwCreateWindow(300, 300, "hello glWindow",
                                          NULL, NULL);
    if (window == nullptr) {
        cout << " Failed to create GLFW Window" << endl;
        glfwTerminate();
        return -1;
    }
    //创建完窗口就可以通知GLFW将窗口的上下文设置为当前线程的主上下文
    glfwMakeContextCurrent(window);

    // GLAD
    // 定义函数原型:如果调用OpenGL的函数就需要先定义一个函数的原型，
    // 然后找到正确的函数并且赋值给函数指针，这个时候才能去调用函数；不能直接去调用OpenGL的函数
    // 而将找到正确匹配的OpenGL函数，赋值给我们定义的函数指针，通过函数指针来调用OpenGl的函数。

    typedef void(*GL_GENBUFFERS)(GLsizei,GLuint*);
    //找到正确的函数并赋值给函数指针
    GL_GENBUFFERS glGenbuffers =(GL_GENBUFFERS)glfwGetProcAddress("glGenBuffers")
    //现在函数可以被正常调用了
    GLuint  buffer;
    glGenBuffers(1,&buffer);

    return 0;
}
