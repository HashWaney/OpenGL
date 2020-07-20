#ifndef CAMERA_H
#define CAMERA_H

#include "../glad/glad.h"
#include "../glm/glm.hpp"

#include "../glm/gtc/matrix_transform.hpp"

#include <vector>

// Defines several possible options for camera movement.
//Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const float YAW         = -90.0f; // 偏航角 从左 从右
const float PITCH       =  0.0f;  // 俯仰角 从上 从下
const float SPEED       =  2.5f;  //
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
    // camera Attributes
    glm::vec3 Position; // 摄像机的位置向量
    glm::vec3 Front; // 目标的位置向量
    // position 与 front 其实求出摄像机的方向向量
    glm::vec3 Up;  //上向量
    glm::vec3 Right; // 右向量 通过上向量叉乘方向向量得出的。
    glm::vec3 WorldUp; // z轴向量
    // euler Angles
    float Yaw; // 俯仰角
    float Pitch; // 偏航角
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // constructor with vectors 向量构造
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),  //位置向量
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), // 上向量
            float yaw = YAW,    // 俯仰角 （往上，往下）
            float pitch = PITCH) // 偏航角 （往左，往右）

            //给定一个俯仰角和偏航角，我们可以把它们转换为一个代表新的方向向量的3D向量
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }
    // constructor with scalar values  标量构造
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = glm::vec3(posX, posY, posZ); // 通过标量来构造一个向量
        WorldUp = glm::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix()
    {
        return glm::lookAt(Position, Position + Front, Up);
    }

    // processes input received from any keyboard-like input system.
    // Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    // 接收键盘输入的指定来不断的改变摄像机的位置向量从而更新观察目标的位置
    void ProcessKeyboard(Camera_Movement direction, float deltaTime)
    {
        float velocity = MovementSpeed * deltaTime;
        if (direction == FORWARD)
            Position += Front * velocity;
        if (direction == BACKWARD)
            Position -= Front * velocity;
        if (direction == LEFT)
            Position -= Right * velocity;
        if (direction == RIGHT)
            Position += Right * velocity;
    }

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw   += xoffset;
        Pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        // 确保当俯仰角超出范围，屏幕不会翻转
        if (constrainPitch){
            if (Pitch > 89.0f){
                Pitch = 89.0f;
            }

            if (Pitch < -89.0f){
                Pitch = -89.0f;
            }
        }

        // update Front, Right and Up Vectors using the updated Euler angles
        // 使用更新的欧拉角来更新右和上向量
        updateCameraVectors();
    }

    // processes input received from a mouse scroll-wheel event.
    // Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset)
    {
        Zoom -= (float)yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f; 
    }

    //观察位置
    //摄像机的
private:
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors()
    {
        // calculate the new Front vector
        glm::vec3 front;

        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        // also re-calculate the Right and Up vector
        // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Right = glm::normalize(glm::cross(Front, WorldUp));  // 右轴  = 上轴叉乘Z轴 Front * WorldUp 向量乘积 cross  计算两个向量的乘积    叉乘，就为了计算得出正交与这两个向量的第三维向量。
        Up    = glm::normalize(glm::cross(Right, Front)); // 上轴 = 右轴叉乘Z轴
    }
};
#endif