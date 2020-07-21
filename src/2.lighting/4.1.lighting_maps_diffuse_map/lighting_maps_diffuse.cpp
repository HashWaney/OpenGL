#include "../../../include/glad/glad.h"
#include "glfw3.h"
#include "../../../include/glm/glm.hpp"
#include "../../../include/stb/stb_image.h"
#include "../../../include/glm/gtc/matrix_transform.hpp"
#include "../../../include/glm/gtc/type_ptr.hpp"
#include "../../../include/learnopengl/shader_s.h"
#include "../../../include/learnopengl/camera.h"
#include "../../../include/learnopengl/shader_m.h"
#include "../../../include/learnopengl/filesystem.h"
#include "iostream"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);
unsigned int loadTexture(const char *path);


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

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);


    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH,SCR_HEIGHT,"hello map diffuse",NULL
    ,NULL);
    if(window==NULL){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
    glfwSetCursorPosCallback(window,mouse_callback);
    glfwSetScrollCallback(window,scroll_callback);

    glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout<< "load GL function error " <<endl;
        return -1;
    }
    cout<<"load shader"<<endl;
    glEnable(GL_DEPTH_TEST);
// /Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/4.1.lighting_maps_diffuse_map
    Shader lightMapShader(
        "/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/4.1.lighting_maps_diffuse_map/4.1.lighting_maps.vs"
        ,"/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/4.1.lighting_maps_diffuse_map/4.1.lighting_maps.fs");
    cout<<"load shader between "<<endl;
    Shader lightLampShader(
        "/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/4.1.lighting_maps_diffuse_map/4.1.light_cube.vs",
        "/Users/wangqing/Desktop/JNI/CPP/OpenGl/src/2.lighting/4.1.lighting_maps_diffuse_map/4.1.light_cube.fs");
    cout<<"load shader end "<<endl;
    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };


    unsigned int VBO,mapVAO;
    glGenVertexArrays(1,&mapVAO);
    glGenBuffers(1,&VBO);


    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),
    vertices,GL_STATIC_DRAW);


    glBindVertexArray(mapVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    unsigned int lightVAO;
    glGenVertexArrays(1,&lightVAO);
    glBindVertexArray(lightVAO);

    glBindBuffer(GL_ARRAY_BUFFER,VBO);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //textureId 
    unsigned int diffuseMap = loadTexture(FileSystem::getPath("resources/textures/container2.png").c_str());
    cout<< "### textureId## "<< diffuseMap <<endl;
    lightMapShader.use();
    //设置纹理Id
    lightMapShader.setInt("material.diffuse",0);

    cout<<"start to render "<<endl;
    while(!glfwWindowShouldClose(window)){

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.1f,0.1f,0.1f,0.1f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ///////////处理材质//////////////
        lightMapShader.use();
        lightMapShader.setVec3("light.position",lightPos);
        lightMapShader.setVec3("viewPos",camera.Position);

        // 光源光照模型分量设置
        lightMapShader.setVec3("light.ambient",0.2f,0.2f,0.2f);
        lightMapShader.setVec3("light.diffuse",0.5f,0.5f,0.5f);
        lightMapShader.setVec3("light.specular",1.0f,1.0f,1.0f);

        // 材质光照属性设置
        lightMapShader.setVec3("material.specular",0.5f,0.5f,0.5f);
        lightMapShader.setFloat("material.shininess",64.0f);

        //矩阵变换
        glm::mat4 projection = glm::perspective(
            glm::radians(camera.Zoom),
            (float)SCR_WIDTH/(float)SCR_HEIGHT,
            0.1f,100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        lightMapShader.setMat4("projection",projection);
        lightMapShader.setMat4("view",view);

        glm::mat4 model = glm::mat4(1.0f);
        lightMapShader.setMat4("model",model);

        // 激活纹理
        glActiveTexture(GL_TEXTURE0);
        //纹理id
        glBindTexture(GL_TEXTURE_2D,diffuseMap);

        // 绘制
        glBindVertexArray(mapVAO);
        glDrawArrays(GL_TRIANGLES,0,36);

        ///////////处理光照////////////////
        lightLampShader.use();
        lightLampShader.setMat4("projection",projection);
        lightLampShader.setMat4("view",view);
        model = glm::mat4(1.0f);
        //将光源位置进行位移到世界空间
        model = glm::translate(model,lightPos);
        //将光源位置进行缩放处理，使得看起来是一个比较小的点光源
        model = glm::scale(model,glm::vec3(0.2f));
        lightLampShader.setMat4("model",model);

        glBindVertexArray(lightVAO);
        glDrawArrays(GL_TRIANGLES,0,36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1,&lightVAO);
    glDeleteVertexArrays(1,&mapVAO);
    glDeleteBuffers(1,&VBO);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow * window){

    if(glfwGetKey(window, GLFW_KEY_ESCAPE)==GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }
    if(glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS){
        camera.ProcessKeyboard(FORWARD ,deltaTime);
    }
     if(glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS){
        camera.ProcessKeyboard(BACKWARD ,deltaTime);
    }
     if(glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS){
        camera.ProcessKeyboard(LEFT ,deltaTime);
    }
     if(glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS){
        camera.ProcessKeyboard(RIGHT ,deltaTime);
    }
}

void framebuffer_size_callback(GLFWwindow * window ,int w,int h ){

    glViewport(0,0,w,h);
}


void mouse_callback(GLFWwindow * window,double xPos,double yPos){

    if(firstMouse){
        lastX  = xPos;
        lastY = yPos;
        firstMouse=false;
    }
    double xOffset = xPos - lastX;
    double yOffset = lastY - yPos;
    //更新鼠标坐标
    lastX = xPos;
    lastY = yPos;

    camera.ProcessMouseMovement(xOffset,yOffset);

}

void scroll_callback(GLFWwindow * window,double xOffset, double yOffset){
    camera.ProcessMouseScroll(yOffset);
}

unsigned int loadTexture(char const* path){
//    unsigned int textureId;
//    glGenTextures(1,&textureId);
//    cout<< "#### load Texture begin ## " <<endl;
//    int width , height ,channels;
//    unsigned char * data = stbi_load(path,&width,&height,&channels,0);
//    if(data){
//        GLenum format;
//        if(channels ==1 ){
//            format = GL_RED;
//        }else if(channels ==3 ){
//            format = GL_RGB;
//        } else if(channels ==4 ){
//            format = GL_RGBA;
//        }
//        glBindTexture(GL_TEXTURE_2D,textureId);
//        glTexImage2D(GL_TEXTURE_2D,
//        0,format,width,height,0,format,GL_UNSIGNED_BYTE,data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//
//        stbi_image_free(data);
//
//    }else{
//        cout<<"Texture failed to load image "<<endl;
//        stbi_image_free(data);
//    }
//
//    return textureId;
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}
