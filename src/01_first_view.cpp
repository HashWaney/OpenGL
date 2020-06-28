//
// Created by hash on 2020/6/28.
//
#include "glew.h"
#include "glfw3.h"
#include "iostream"

using namespace std;

void key_callback(GLFWwindow *window, int key,
                  int scancode, int action, int mode) {
    //如果按下ESC，把windowShouldClose设置为True，外面的循环会关闭应用
    if(key==GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    std::cout<<"ESC\n"<<mode<<endl;

}

int main(void) {
    //初始化GLFW库
    if (!glfwInit()) {
        return -1;
    }

    // 创建窗口以及上下文
    GLFWwindow *window = glfwCreateWindow(600, 480, "hello opengl", NULL, NULL);
    if (!window) {
        //创建失败
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    //设置
    glfwSetKeyCallback(window, key_callback);

    //循环，直至用户关闭窗口
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.2, 0.3, 0.3, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0); // red
        glVertex3f(0, 1, 1);

        glColor3f(0, 1, 0); //Green
        glVertex3f(-1, -1, 0);

        glColor3f(0, 0, 1); //Blue
        glVertex3f(1, -1, 0);
        //结束一个画图步骤
        glEnd();

        glBegin(GL_POLYGON);
        //再画个梯形，需要注意笔顺
        glColor3f(0.5, 0.5, 0.5); //Grey
        glVertex2d(0.5, 0.5);
        glVertex2d(1, 1);
        glVertex2d(1, 0);
        glVertex2d(0.5, 0);
        glEnd();


        /******交换缓冲区，更新window上的内容******/
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;

}
