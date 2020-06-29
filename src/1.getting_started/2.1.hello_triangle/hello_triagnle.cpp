//
// Created by hash on 2020/6/28.
//
#include "../../../include/glad/glad.h"
#include "iostream"
#include "glfw3.h"

using namespace std;

const unsigned int src_width = 400;
const unsigned int src_height = 400;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);

const char *vertexShaderSource = "#version 330 core\n "
                                 "layout (location=0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "     gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "  FragColor = vec4(1.0f,0.5f,0.3f,1.0f);\n"
                                   "}\n\0";

int main() {
    //glfw 初始化和配置
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    //glfw window create
    GLFWwindow *window = glfwCreateWindow(src_width, src_height, "Hello Triangle", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glBindBuffer 这个函数是不能直接调用，需要通过gladLoadGLLoader将这些函数加载进来才能被调用
    // #define glBindBuffer glad_glBindBuffer 注意实际调用的glBindBuffer其实是调用glad_glBindBuffer
    //typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) { //拿到对应的函数地址，并且将其加载进来。
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    //1. create shader and compile shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glShaderSource(fragShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(vertexShader);
    glCompileShader(fragShader);
    // 2.check the compile status
    int verSuccess;
    char verInfo[1024];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &verSuccess);
    if (!verSuccess) {
        glGetShaderInfoLog(verSuccess, 1024, NULL, verInfo);
        cout << "compile vert shader error " << verInfo << endl;
    }

    int fragSuccess;
    char fragInfo[1024];
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &fragSuccess);
    if (!fragSuccess) {
        glGetShaderInfoLog(fragShader, 1024, NULL, fragInfo);
        cout << "compile frag shader error " << fragInfo << endl;
    }

    //3.link the shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);

    //4.check the program link status
    int programSuccess;
    char programInfo[1024];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &programSuccess);
    if (!programSuccess) {
        glGetProgramInfoLog(shaderProgram, 1024, NULL, programInfo);
        cout << "link the program error " << programInfo << endl;
    }

    //5.delete the shader cause the shader already link to the program
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);


    //6.set up vertex data and configure vertex attributes
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };

    unsigned int VBO, VAO;
    // 生成一个VAO对象
    glGenVertexArrays(1, &VAO);
    //生成一个VBO对象
    glGenBuffers(1, &VBO);
    //将顶点属性添加到顶点数组对象中，方便后续绑定顶点属性和顶点缓冲对象
    //1.首先绑定顶点数组对象，
    glBindVertexArray(VAO);
    //2.然后绑定并设置顶点缓冲区，
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //3.在配置顶点属性。 顶点属性为0
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    //4.开启顶点属性，以便将顶点属性与VBO进行绑定
    glEnableVertexAttribArray(0);

    // 请注意，这是允许的，对glVertexAttribPointer的调用将VBO注册为顶点属性的绑定顶点缓冲区对象
    // 因此之后我们可以安全地解除绑定

    // 解绑VBO
//    glBindBuffer(GL_ARRAY_BUFFER, 0);


    // 您可以在以后取消绑定VAO，这样其他VAO调用就不会意外修改此VAO，但是这种情况很少发生。
    // 修改其他VAO始终需要调用glBindVertexArray，因此通常在不需要直接取消绑定VAO（也没有VBO）的情况下，
    // 我们通常不会取消绑定。

    //解绑VAO
//    glBindVertexArray(0);

    // loop render
    while (!glfwWindowShouldClose(window)) { // 窗口未关闭

        // input
        processInput(window);

        //clear window
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //use program
        glUseProgram(shaderProgram);
        //??? why not set can not show the triangle
        // thinking!!
        //to see the out of loop ,then unbind the vbo and vao, so that we also unbind after the loop
//        glBindVertexArray(VAO); //
        //1.三角形 2.起始点 3.点的个数
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //swap buffers and poll IO event
        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    //unbind VBO
    glBindBuffer(GL_ARRAY_BUFFER,0);
    //unbind VAO
    glBindVertexArray(0);
    // recycle allocate resource
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;

}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}