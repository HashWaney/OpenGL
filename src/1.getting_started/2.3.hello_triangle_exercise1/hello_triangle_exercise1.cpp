//
// Created by hash on 2020/6/30.
//
#include "../../../include/glad/glad.h"
#include "glfw3.h"
#include "iostream"

using namespace std;

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location=0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "  gl_Position=vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
                                 "}\0";

const char *fragShaderSource = "#version 330 core\n"
                               "out vec4 FragColor;\n"
                               "void main()\n"
                               "{\n"
                               " FragColor = vec4(1.0f,0.3f,0.4f,1.0f);\n"
                               "}\n\0";

const unsigned int src_width = 500;
const unsigned int src_height = 400;

void processInput(GLFWwindow *window);

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main() {

    //init glfw
    glfwInit();
    //configure glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // 1.create window
    GLFWwindow *window = glfwCreateWindow(src_width, src_height, "hello triangle exercise one ", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create GLFW window " << endl;
        glfwTerminate();
        return -1;
    }
    //TODO 1. 首先指定OpenGL的上下文环境，
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    //TODO important，2. 如果这个是优先于makeContextCurrent优先调用，
    // 会抛出异常，因为加载的函数不知道具体的上下文环境
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << " Failed to initialize Glad " << endl;
        return -1;
    }


    cout << " create shader start  " << endl;
    //create shader todo glCreateShader 函数无法直接使用，需要通过glad加载函数指针才能使用
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    cout << " create shader  end " << endl;
    //attach shader source to vertexShader
    cout << " shader source vertex " << endl;
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    //compile shader
    cout << " vertex shader compile " << endl;
    glCompileShader(vertexShader);
    cout << " compile vertex shader" << endl;
    //check compile
    int success;
    char shaderInfo[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, shaderInfo);
        cout << " compile vertex shader error " << shaderInfo << endl;
    }

    cout << "create frag shader" << endl;
    //create frag shader
    int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    //attach shader source to fragShader
    glShaderSource(fragShader, 1, &fragShaderSource, NULL);
    //compile frag shader
    glCompileShader(fragShader);
    //check compile frag
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShader, 512, NULL, shaderInfo);
        cout << "compile frag shader error " << shaderInfo << endl;
    }
    //create shader program
    int shaderProgram = glCreateProgram();
    // link the shader to program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    int su;
    char programInfo[512];
    //check the program
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &su);

    if (!su) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, programInfo);
        cout << "link program error " << programInfo << endl;
    }
    //delete the shader after link to the program
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);

    float vertices[] = {
            //first triangle
            -0.9f, -0.5f, 0.0f,
            -0.0f, -0.5f, 0.0f,
            -0.45f, 0.5f, 0.0f,
            //second triangle
            0.0f, -0.5f, 0.0f,
            0.9f, -0.5f, 0.0f,
            0.45f, 0.5f, 0.0f
    };

    //create vbo vao
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind vertex data to VAO
    glBindVertexArray(VAO);
    // bind buffer type to the vbo
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //store the vertices to the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //bind pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    //enable vertex attrib
    glEnableVertexAttribArray(0);
    cout << " start render " << endl;
    // render loop
    while (!glfwWindowShouldClose(window)) {

        cout << " join render " << endl;
        //input register
        processInput(window);

        //clear screen and clear color buffer
        glClearColor(0.3f, 0.2f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //use program to render the screen
        glUseProgram(shaderProgram);
        // draw something
        glDrawArrays(GL_TRIANGLES, 0, 6);
        //swap the buffer
        glfwSwapBuffers(window);
        //poll the render and input event
        glfwPollEvents();
    }

    //unbind the vao vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    //delete the vao vbo
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    //delete program
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