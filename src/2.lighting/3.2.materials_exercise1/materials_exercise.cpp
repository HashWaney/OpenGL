
#include "../../../include/glad/glad.h"
#include "glfw3.h"
#include "../../../include/glm/glm.hpp"
#include "../../../include/glm/gtc/matrix_transform.hpp"
#include "../../../include/glm/gtc/type_ptr.hpp"
#include "../../../include/learnopengl/shader_s.h"
#include "../../../include/learnopengl/camera.h"
#include "../../../include/learnopengl/shader_m.h"
#include "../../../include/learnopengl/filesystem.h"
#include "iostream"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main(){


    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);


    Shader lightLampShader("/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/3.2.materials_exercise1/3.2.light_cube.vs",
    "/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/3.2.materials_exercise1/3.2.light_cube.fs");

    Shader lightMaterialShader("/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/3.2.materials_exercise1/3.2.materials.vs",
    "/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/3.2.materials_exercise1/3.2.materials.fs"
    );

     float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

    unsigned int VBO, materialVAO;
    glGenVertexArrays(1,&materialVAO);
    glGenBuffers(1,&VBO);

    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    glBindVertexArray(materialVAO); 

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int lightLampVAO;
    glGenVertexArrays(1,&lightLampVAO);

    glBindVertexArray(lightLampVAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);

    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    while(!glfwWindowShouldClose(window)){

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        // 更新上一次记录的时间
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.1f,0.1f,0.1f,0.1f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //使用shader呈现激活shader 用于接收uniform所设置的值
        lightMaterialShader.use();
        lightMaterialShader.setVec3("light.position",lightPos);
        lightMaterialShader.setVec3("viewPos",camera.Position);

        //关于光照的属性配置
        lightMaterialShader.setVec3("light.ambient",1.0f,1.0f,1.f);
        lightMaterialShader.setVec3("light.diffuse",1.0f,1.0f,1.0f);
        lightMaterialShader.setVec3("light.specular",1.0f,1.0f,1.0f);

        //关于物体材质的属性配置
        lightMaterialShader.setVec3("material.ambient",0.0f,0.1f,0.05f);
        lightMaterialShader.setVec3("material.diffuse",0.0f,0.539941f,0.5043155f);
        lightMaterialShader.setVec3("material.specular",0.503291f,0.501221f,0.501241f);
        lightMaterialShader.setFloat("material.shininess",32.0f);

        //进行矩阵变换
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom),
        (float)SCR_WIDTH/(float)SCR_HEIGHT,0.1f,100.f);
        glm::mat4 view = camera.GetViewMatrix();
        lightMaterialShader.setMat4("projection",projection);
        lightMaterialShader.setMat4("view",view);

        glm::mat4 model = glm::mat4(1.0f);
        lightMaterialShader.setMat4("model",model);

        //渲染物体
        glBindVertexArray(materialVAO);
        glDrawArrays(GL_TRIANGLES,0,36);


        //关于光源shader配置
        lightLampShader.use();
        lightLampShader.setMat4("projection",projection);
        lightLampShader.setMat4("view",view);
        model = glm::mat4(1.0f);
        //光源的方向向量进行位移操作
        model = glm::translate(model,lightPos);
        model = glm::scale(model,glm::vec3(0.3f));
        lightLampShader.setMat4("model",model);

        glBindVertexArray(lightLampVAO);
        glDrawArrays(GL_TRIANGLES,0,36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1,&lightLampVAO);
    glDeleteVertexArrays(1,&materialVAO);
    glDeleteBuffers(1,&VBO);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }

    if(glfwGetKey(window,GLFW_KEY_W)==GLFW_PRESS){
        camera.ProcessKeyboard(FORWARD,deltaTime);
    }

    if(glfwGetKey(window,GLFW_KEY_S) ==GLFW_PRESS){
        camera.ProcessKeyboard(BACKWARD,deltaTime);
    }

    if(glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS){
        camera.ProcessKeyboard(LEFT,deltaTime);
    }
    if(glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS){
        camera.ProcessKeyboard(RIGHT,deltaTime);
    }
}

void framebuffer_size_callback(GLFWwindow* window,int w,int h){
    glViewport(0,0,w,h);
}

void mouse_callback(GLFWwindow* window, double xPos, double yPos){
    if(firstMouse){
        lastX = xPos;
        lastY = yPos;
        firstMouse=false;
    }

    float xOffset = xPos  - lastX;
    float yOffset = lastY - yPos;

    //更新鼠标坐标点
    lastX = xPos;
    lastY = yPos;

    camera.ProcessMouseMovement(xOffset,yOffset);

}

void scroll_callback(GLFWwindow * window, double xOffset, double yOffset){
    camera.ProcessMouseScroll(yOffset);
}