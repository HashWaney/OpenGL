//
// Created by hash on 2020/7/14.
//

#include "../../../include/glad/glad.h"
#include "glfw3.h"
#include "../../../include/stb/stb_image.h"
#include "../../../include/learnopengl/filesystem.h"
#include "../../../include/learnopengl/shader_s.h"
#include "../../../include/glm/glm.hpp"
#include "../../../include/glm/gtc/matrix_transform.hpp"
#include "../../../include/glm/gtc/type_ptr.hpp"
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

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    Shader shaderTool(
            "/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/1.getting_started/5.1.transformations/5.1.transform.vs",
            "/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/1.getting_started/5.1.transformations/5.1.transform.fs");

    //set up vertex data (and buffer(s)) and configure vertex attributes
    float vertices[] = {
            // positions      // texture coords
            0.5f, 0.5f, 0.0f, 2.f, 2.0f,  // top right
            0.5f, -0.5f, 0.0f, 2.0f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
            -0.5f, 0.5f, 0.0f, 0.0f, 2.0f// top left
    };
    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
    };
    unsigned int VBO, VAO, EBO;
    //generate
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    //bind
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    //data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int texture1, texture2;

    //generate texture
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    //s --- >x 轴 再说白点就是左右
    //t ---> y轴 再说白点就是上下
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //set filtering  放大和缩小的过滤方式 邻近（锯齿）和线性过滤（平滑）
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, channels;
    //y轴翻转
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(FileSystem::getPath("resources/textures/container.jpg").c_str(),
                                    &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                     GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        cout << "texture1 failed to load image" << endl;
    }
    //free image
    stbi_image_free(data);

    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    data = stbi_load(FileSystem::getPath("resources/textures/awesomeface.png").c_str(),
                     &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RGB,
                width,
                height,
                0,
                GL_RGBA,
                GL_UNSIGNED_BYTE,
                data
        );
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        cout << "texture2 failed load image" << endl;
    }
    stbi_image_free(data);


    shaderTool.use();
    shaderTool.setInt("texture1", 0);
    shaderTool.setInt("texture2", 1);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        ////// first transformation ////


        //create transformations 参考  <a href=" https://juejin.im/post/5f0907466fb9a07e9b1abaa8">GLM</a>
        glm::mat4 transform = glm::mat4(1.0f); // 定义一个单位矩阵
        transform = glm::translate(transform, glm::vec3(0.5, 0.5, 0.0f)); // 变换为位移矩阵
        //通过定义一个vec3(0.0,0.0,1.0)可知是绕Z轴旋转 角度为时间戳弧度
        transform = glm::rotate(transform, (float) glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        shaderTool.use();
        unsigned int transformLoc = glGetUniformLocation(shaderTool.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //////second transformation//////

        transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(-0.5f, 0.5f, 0.0f));
        float scaleAmount = sin(glfwGetTime());
        transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
        //this time take the matrix value array's first element as its memory pointer value
        //将矩阵值数组的第一个元素作为其内存指针值 &transform[0][0]
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &transform[0][0]);
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
    glViewport(0, 0, width, height);
}