//
// Created by hash on 2020/7/1.
//
#include "../../../include/glad/glad.h"
#include "iostream"
#include "glfw3.h"

using namespace std;
const unsigned int src_width = 400;
const unsigned int src_height = 400;

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location=0) in vec3 aPos;\n"
                                 "layout (location=1) in vec3 aColor;\n"
                                 "out vec3 frag_Color;\n"
                                 "void main()\n"
                                 "{\n"
                                 " gl_Position = vec4(aPos,1.0);\n"
                                 " frag_Color = aColor;\n "
                                 "}\n\0";
const char *fragShaderSource = "#version 330 core\n"
                               "out vec4 FragColor;\n"
                               "in vec3 frag_Color;\n"
                               "void main()\n"
                               "{\n"
                               "    FragColor = vec4(frag_Color,1.0f);\n"
                               "}\n\0";

void processInput(GLFWwindow *window);

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    //creat window
    GLFWwindow *window = glfwCreateWindow(src_width, src_height, "hello uniform window", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create glfw window " << endl;
        glfwTerminate();
        return -1;
    }
    //set up opengl context
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << "can't load gl address" << endl;
        return -1;
    }

    int success;
    char checkInfo[123];
    //create shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 123, NULL, checkInfo);
        cout << "compile vertex shader error: " << checkInfo << endl;
    }

    int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragShaderSource, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShader, 123, NULL, checkInfo);
        cout << "compile frag shader error :" << checkInfo << endl;
    }

    //create program
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 123, NULL, checkInfo);
        cout << " link the program error :" << checkInfo << endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);


    float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f   // top
    };
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    //color attribute  between color1 and color 2 three pointer offset
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //cause we only has one shader, we can active shader once
    glUseProgram(shaderProgram);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.f, 0.f, 0.f, 0.1f);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
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