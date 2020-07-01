//
// Created by hash on 2020/7/1.
//
#include "../../../include/glad/glad.h"
#include "iostream"
#include "glfw3.h"
#include "cmath"

using namespace std;

const unsigned int src_width = 400;

const unsigned int src_height = 400;

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location=0) in vec3 aPos;"
                                 "void main()\n"
                                 "{\n"
                                 "  gl_Position = vec4(aPos,1.0);\n"
                                 "}\n\0";
const char *fragShaderSource = "#version 330 core\n"
                               "out vec4 FragColor;\n"
                               "uniform vec4 uniformColor;\n" //处理这个uniform 1。 如何赋值，2。如何更新
                               "void main()\n"
                               "{\n"
                               "  FragColor = uniformColor;\n"
                               "}\n\0";

void processInput(GLFWwindow *window);

void framebuffer_size_callback(GLFWwindow *window, int width, int height);


int main() {

    //glfw init
    glfwInit();

    //configure fw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    //create window
    GLFWwindow *window = glfwCreateWindow(src_width, src_height, "hello uniform", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create glFw window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //load gl function
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << "Failed to load gl function" << endl;
        return -1;
    }

    int success;
    char checkInfo[111];
    //create vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //attach source to shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    //compile shader
    glCompileShader(vertexShader);
    //check compile status
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 111, NULL, checkInfo);
        cout << "compile vertex shader error " << checkInfo << endl;
    }

    //create frag shader
    int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    //attach source to shader
    glShaderSource(fragShader, 1, &fragShaderSource, NULL);
    //compile frag shader
    glCompileShader(fragShader);
    //check compile status
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShader, 111, NULL, checkInfo);
        cout << "compile frag shader error " << checkInfo << endl;

    }

    //create shader program
    int shaderProgram = glCreateProgram();
    //attach shader to program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    //link the shader to program
    glLinkProgram(shaderProgram);
    //check the link status
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 111, NULL, checkInfo);
        cout << "link the program error " << checkInfo << endl;
    }

    //delete shader
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);

    //set up vertex data
    float vertices[] = {
            0.5, -0.5f, 0.0f,
            0.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f,0.5f,0.0f,
            0.0f,0.0f,0.0f,
            0.5f,0.5f,0.0f
    };

    unsigned int VBO, VAO;
    //create vertex array obj
    glGenVertexArrays(1, &VAO);
    //create vertex buffer obj
    glGenBuffers(1, &VBO);

    //bind vertex array
    glBindVertexArray(VAO);

    //bind buffer, bind the vertices array data to the buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //copy the vertices array data to the buffer obj
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //  we copy the vertices data to the buffer, the next
    //  we should tell the gpu how to handle the data, and the data should attach the attribute pointer
    //  we can use glVertexAttribPointer to tell the gpu the meaningful of the data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    // enable the attrib
    glEnableVertexAttribArray(0);


    while (!glfwWindowShouldClose(window)) {
        //register input event
        processInput(window);

        //clear screen
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.4f, 0.3f, 0.1f, 1.0f);

        //use program
        glUseProgram(shaderProgram);

        //update shader uniform and update uniform
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 1.34f + 0.1f;
        //find the location of uniform variable int the program
        int uniformColorLocation = glGetUniformLocation(shaderProgram, "uniformColor");
        glUniform4f(uniformColorLocation, 1.0f, greenValue, 0.02f, 0.4f);

        //draw some thing
        glDrawArrays(GL_TRIANGLES, 0, 6);
        //swap buffer
        glfwSwapBuffers(window);

        //poll event
        glfwPollEvents();

    }
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);

}