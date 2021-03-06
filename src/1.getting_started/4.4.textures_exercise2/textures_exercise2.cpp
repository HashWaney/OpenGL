//
// Created by hash on 2020/7/13.
//

#include "../../../include/glad/glad.h"
#include "glfw3.h"
#include "../../../include/stb/stb_image.h"
#include "../../../include/learnopengl/filesystem.h"
#include "../../../include/learnopengl/shader_s.h"
#include "iostream"

using namespace std;


void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "hello textures 2", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        return -1;
    }
    //4.4.textures_exercise2

    Shader shaderTool(
            "/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/1.getting_started/4.4.textures_exercise2/4.3.textures.vs",
            "/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/1.getting_started/4.4.textures_exercise2/4.3.textures.fs");

    float vertices[] = {
            //position              // color        //texture coords 如果将纹理坐标设置为2.0,会将纹理均匀的贴在物体的顶点上。值越大，贴图会等分的形式来铺满整个物体的表面。
                                                    // 设置为2 就会将贴图进行4等份进行铺满物体表面
            0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 2.f, 2.f, //top right
            0.5, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 2.f, 0.0f, //bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //bottom left
            -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,2.f //top left
    };

    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3 // second triangle
    };

    unsigned int VBO, VAO, EBO;

    //gen
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    //bind  data
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //attribute position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    unsigned int texture1, texture2;

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    // set the texture wrapping parameter
    // GL_LINEAR 线性
    //GL_CLAMP_TO_EDGE 拉伸效果
    //GL_MIRRORED_REPEAT 超出纹理的坐标为用户指定的边缘颜色
    //GL_NEAREST：邻近
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //set up the texture filtering parameter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //load image
    int width, height, channels;
    //
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(FileSystem::getPath("resources/textures/container.jpg").c_str(),
                                    &width, &height, &channels, 0);

//    border
    if (data) {
        // 用来将载入的图片数据生成一个纹理
        //load image data for gen a texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                     GL_UNSIGNED_BYTE, data);
        //用来生成多级渐远纹理
        // gen a mipmap texture
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        cout << "failed to load texture" << endl;
    }

    //free image
    stbi_image_free(data);

    //texture2
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    //set up the texture wrapping parameter
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    data = stbi_load(FileSystem::getPath("resources/textures/awesomeface.png").c_str(),
                     &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        cout << "failed to load image" << endl;
    }
    stbi_image_free(data);
    //active the shader the texture unit pass to the shader
    shaderTool.use();
    glUniform1i(glGetUniformLocation(shaderTool.ID, "texture1"), 0);
    shaderTool.setInt("texture2", 1);

    while (!glfwWindowShouldClose((window))) {
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.1f, 0.1f);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        shaderTool.use();
        glBindVertexArray(VAO);
        //通过EBO来进行元素绘制，
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    //the final step: ViewPort Transform
    glViewport(0, 0, width, height);
}