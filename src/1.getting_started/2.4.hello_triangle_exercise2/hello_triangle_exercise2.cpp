//
// Created by hash on 2020/6/30.
//

#include "../../../include/glad//glad.h"
#include "glfw3.h"
#include "iostream"

using namespace std;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout(location =1) in vec3 aPos;\n"
                                 "void main(){\n"
                                 "  gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
                                 "}\n\0";
const char *fragShaderSource = "#version 330 core\n"
                               "out vec4 FragColor;\n"
                               "void main(){\n"
                               "  FragColor=vec4(1.0f,0.4f,0.2f,0.4f);\n"
                               "}\n\0";

void processInput(GLFWwindow *window);

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main() {

    // glfw init
    glfwInit();
    //configure
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_TRUE);
//  向前兼容
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //create window
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "hello triangle test", NULL, NULL);
    //check window
    if (window == NULL) {
        cout << "can't create window " << endl;
        glfwTerminate();
        return -1;
    }
    //make opengl context
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << "Failed to initialize glad" << endl;
        return -1;
    }

    //create  vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //attach shader source to shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    //compile shader
    glCompileShader(vertexShader);
    //check vertex shader compile status
    int success;
    char info[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, info);
        cout << "vertex shader compile error " << info << endl;
    }

    //create fragment shader
    int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    //attach frag source to shader
    glShaderSource(fragShader, 1, &fragShaderSource, NULL);
    //compile frag shader
    glCompileShader(fragShader);
    //check frag shader compile status
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShader, 512, NULL, info);
        cout << "frag shader compile error" << info << endl;
    }
    //create program
    int shaderProgram = glCreateProgram();
    //attach shader to program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    //link the program
    glLinkProgram(shaderProgram);
    //check the link status
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, info);
        cout << "link the program error" << info << endl;
    }

    //delete the shader
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);


    //vbo vao relate
    float firstTriangle[] = {
            -0.9f, -0.5f, 0.0f,
            -0.0f, -0.5f, 0.0f,
            -0.45f, 0.5f, 0.0f
    };

    float secondTriangle[] = {
            0.0f, -0.5f, 0.0f,
            0.9f, -0.5f, 0.0f,
            0.45f, 0.5f, 0.0f
    };
    unsigned int VBOs[2], VAOs[2];

    //create vao
    glGenVertexArrays(2, VAOs);
    //creat vbo
    glGenBuffers(2, VBOs);

    //bind data  first triangle
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    //enable vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    //second triangle
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    //vertexAttribute：绑定对应的数据，定义了OpenGL如何去解释这些顶点数据，步长，顶点类型计算，
    //第一个参数为顶点属性，由shader源码中的location指定 比如指定为1 你去看上面定义的vertexShaderSource中的location
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    //顶点属性开启，使得shaderSource中location声明的1生效
    glEnableVertexAttribArray(1);


    //render loop
    while (!glfwWindowShouldClose(window)) {
        //register input event
        processInput(window);
        //clear screen
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.3f, 0.1f, 0.4f, 1.0f);
        //use program
        glUseProgram(shaderProgram);
        // draw something
        //1.draw the first triangle using the data from fist vao
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //2.then draw the second triangle using the data from second vao
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //swap buffer
        glfwSwapBuffers(window);
        //poll event
        glfwPollEvents();
    }
    //unbind the vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    //delete VAO VBO
    glDeleteBuffers(2, VBOs);
    glDeleteVertexArrays(2, VAOs);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
