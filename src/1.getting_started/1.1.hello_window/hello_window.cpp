//
// Created by hash on 2020/6/28.
//

#include "../../../include/glad/glad.h"
#include "glfw3.h"
#include "glew.h"
#include "iostream"


// 将glad.h文件放在所有的头文件之前，不然会报如下错误。
//#include <glad/glad.h>必须放在所有头文件之前，不管在哪里，不管在.h还是.cpp;
//error: C1189: #error: OpenGL header already included, remove this include, glad already provides it.
void processInput(GLFWwindow *window);

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

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
    //根据缓冲区的大小来调整所谓的窗口大小
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


//
//    typedef void(*GL_GENBUFFERS)(GLsizei, GLuint *);
//    //找到正确的函数并赋值给函数指针
//    GL_GENBUFFERS glGenbuffers = (GL_GENBUFFERS) glfwGetProcAddress("glGenBuffers");
//    //现在函数可以被正常调用了
//    GLuint buffer;

//    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    // glad: load all OpenGL function pointers
    // ---------------------------------------
// GLAD
    // 定义函数原型:如果调用OpenGL的函数就需要先定义一个函数的原型，
    // 然后找到正确的函数并且赋值给函数指针，这个时候才能去调用函数；不能直接去调用OpenGL的函数
    // 而将找到正确匹配的OpenGL函数，赋值给我们定义的函数指针，通过函数指针来调用OpenGl的函数。
    //GLAD传入了用来加载系统相关的OpenGL函数指针地址的函数
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD " << endl;
        return -1;
    }
    //清屏颜色
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    //清屏颜色缓冲区 用上面指定的清屏颜色来填充，这样做有助于加快渲染，然后避免了闪屏
    glClear(GL_COLOR_BUFFER_BIT);
    // 渲染循环
    while (!glfwWindowShouldClose(window)) {
        // 处理所有输入：查询GLFW是否在此帧中按下/释放了相关的按键并做出相应的反应
        processInput(window);

        //交换缓冲区数据并将颜色显示到屏幕上,并且轮训IO事件（按键点击或被释放，鼠标移动等等）
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        cout << "clear color\n " << endl;
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        cout << "poll event\n" << endl; //
        glfwPollEvents(); // 我一直调用你 ，就是为了去获取你的一些与系统窗口交互的事件来阻断我的判断条件
        //说白了就是去  glfwSetWindowShouldClose(window, GL_TRUE); 拿这个函数，
        // 也就是说glfwPollEvents 这个函数一定是与processInput这个函数中的glfwGetKey()是对应的
    }
    //清空GLFW分配的资源
    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow *window) {
    // 左上角的ESC按键
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        // 如果被按下，设置程序窗口的关闭状态为true
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

// 当操作或者说用户操作导致的窗口大戏变化，这个函数就会被回调
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);

}