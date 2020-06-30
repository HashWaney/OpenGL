//
// Created by hash on 2020/6/30.
//
#include "../../../include/glad/glad.h"
#include "glfw3.h"
#include "iostream"

using namespace std;
const unsigned int src_width = 400;
const unsigned int src_height = 400;

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout(location=0) in vec3 vPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "    gl_Position=vec4(vPos.x,vPos.y,vPos.z,1.0);\n"
                                 "}\n\0";

const char *fragShaderSourceOne = "#version 330 core\n"
                                  "out vec4 FragColor;\n"
                                  "void main()\n"
                                  "{\n"
                                  "  FragColor=vec4(1.0f,0.5f,0.3f,1.0f);\n"
                                  "}\n\0";

const char *fragShaderSourceTwo = "#version 330 core\n"
                                  "out vec4 FragColor;\n"
                                  "void main()\n"
                                  "{\n"
                                  "  FragColor=vec4(1.0f,0.3f,0.3f,1.0f);\n"
                                  "}\n\0";

void processInput(GLFWwindow *window);

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main() {

    //This function initializes the GLFW library.  Before most GLFW functions can
    // be used, GLFW must be initialized
    glfwInit();
    //configure glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    //create glfw window
    GLFWwindow *window = glfwCreateWindow(src_width, src_height, "hello opengl triangle!!", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << " FBI WARNING !!! Failed to load glad" << endl;
    }
    int success;
    char checkInfo[128];


    //creat vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //attach shader source
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    //compile shader
    glCompileShader(vertexShader);
    //check compile status
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 128, NULL, checkInfo);
        cout << "vertex compile error " << checkInfo << endl;
    }
    //create fragment shader
    int fragShaderOne = glCreateShader(GL_FRAGMENT_SHADER);
    //attach shader source
    glShaderSource(fragShaderOne, 1, &fragShaderSourceOne, NULL);
    //compile fragOne shader
    glCompileShader(fragShaderOne);
    //check compile status
    glGetShaderiv(fragShaderOne, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShaderOne, 128, NULL, checkInfo);
        cout << " frag one compile error " << checkInfo << endl;
    }

    //create fragment two shader
    int fragShaderTwo = glCreateShader(GL_FRAGMENT_SHADER);
    //attach shader source
    glShaderSource(fragShaderTwo, 1, &fragShaderSourceTwo, NULL);
    //compile fragTwo Shader
    glCompileShader(fragShaderTwo);
    //check compile status
    glGetShaderiv(fragShaderTwo, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShaderTwo, 128, NULL, checkInfo);
        cout << " frag two compile error " << checkInfo << endl;
    }

    //create program
    int shaderProgramOne = glCreateProgram();
    int shaderProgramTwo = glCreateProgram();
    //link shader to program
    glAttachShader(shaderProgramOne, vertexShader);
    glAttachShader(shaderProgramOne, fragShaderOne);
    glAttachShader(shaderProgramTwo, vertexShader);
    glAttachShader(shaderProgramTwo, fragShaderTwo);
    //link the shader
    glLinkProgram(shaderProgramOne);
    glLinkProgram(shaderProgramTwo);
    //check program link status
    glGetProgramiv(shaderProgramOne, GL_LINK_STATUS, &success);
    glGetProgramiv(shaderProgramTwo, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramOne, 128, NULL, checkInfo);
        cout << "program one  link error " << checkInfo << endl;
    }
    if (!success) {
        glGetProgramInfoLog(shaderProgramTwo, 128, NULL, checkInfo);
        cout << "program two link error " << checkInfo << endl;
    }

    //delete shader
    glDeleteShader(vertexShader);
    glDeleteShader(fragShaderOne);
    glDeleteShader(fragShaderTwo);


    float firstTriangle[] = {
            -0.9f, -0.5f, 0.0f,  // left
            -0.0f, -0.5f, 0.0f,  // right
            -0.45f, 0.5f, 0.0f,  // top
    };
    float secondTriangle[] = {
            0.0f, -0.5f, 0.0f,  // left
            0.9f, -0.5f, 0.0f,  // right
            0.45f, 0.5f, 0.0f   // top
    };
    unsigned int VBOs[2], VAOs[2];
    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);

    //first triangle setup
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    //second triangle setup
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    //render loop

    while (!glfwWindowShouldClose(window)) {

        //register input event
        processInput(window);

        //clear screen and setup render background color
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.3f, 0.2f, 1.f, 0.5f);

        //use program  one  --> so u can see the benefit of the VAO
        glUseProgram(shaderProgramOne);
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //use program two
        glUseProgram(shaderProgramTwo);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //swap buffer
        glfwSwapBuffers(window);
        //poll event
        glfwPollEvents();

    }

    // unbind vao vbo
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //delete vao vbo
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteProgram(shaderProgramOne);
    glDeleteProgram(shaderProgramTwo);

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0,0,width,height);
}