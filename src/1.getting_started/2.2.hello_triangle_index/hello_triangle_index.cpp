//
// Created by hash on 2020/6/29.
//
#include "../../../include/glad/glad.h"
#include "iostream"
#include "glfw3.h"

using namespace std;


void framebuffer_size_callback(GLFWwindow *window, int width,
                               int height);

void processInput(GLFWwindow *window);

const unsigned int src_width = 800;
const unsigned int src_height = 600;

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location=0) in vec3 vPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 " gl_Position=vec4(vPos.x,vPos.y,vPos.z,1.0);\n"
                                 "}\n";

const char *fragShaderSource = "#version 330 core\n"
                               "out vec4 FragColor;\n"
                               "void main()\n"
                               "{\n"
                               "    FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
                               "}\n\0";


int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(src_width, src_height, "hello rect triangle", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create GLFW Window " << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << "Failed to initialize Glad" << endl;
        return -1;
    }

    //1. vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // 1.1 check vertex shader
    int success;
    char vertexInfo[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, vertexInfo);
        cout << " vertex shader compile error " << vertexInfo << endl;
    }

    //2. frag shader

    int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragShaderSource, NULL);
    glCompileShader(fragShader);
    //2.1 check compile frag shader
    int su;
    char fragInfo[512];
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &su);
    if (!su) {
        glGetShaderInfoLog(fragShader, 512, NULL, fragInfo);
        cout << " frag shader compile error" << fragInfo << endl;
    }

    //3. link shader
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);

    int sus;
    char programInfo[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &sus);
    if (!sus) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, programInfo);
        cout << " link program error " << programInfo << endl;
    }
    //4. delete the shader
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);


    float vertices[] = {
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
    };
    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    unsigned int VBO, VAO, EBO;
    //create VAO
    glGenVertexArrays(1, &VAO);
    //create VBO
    glGenBuffers(1, &VBO);
    //create EBO
    glGenBuffers(1, &EBO);
    // first blood bind the VAO
    glBindVertexArray(VAO);

    // second blood bind other buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // then bind vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    // enable the attribute pointer
    glEnableVertexAttribArray(0);

    //render loop
    cout << "begin to render" << endl;
    while (!glfwWindowShouldClose(window)) {
        // register the input event during the whole render life cycle;
        processInput(window);
        // clear the screen to speed-up the render
        glClearColor(0.4f, 0.1f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // use the program to render the vertex data
        glUseProgram(shaderProgram);
        // draw some thing include the shape and the num of vertex
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //swap the data to display in the screen
        glfwSwapBuffers(window);
        // 如果该函数加，无法调出页面
        // poll event to get the event of the screen
        glfwPollEvents();

    }
    cout << "end  to render " << endl;
    // unbind buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    // delete buffer
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    //terminate
    glfwTerminate();
    return 0;

}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
