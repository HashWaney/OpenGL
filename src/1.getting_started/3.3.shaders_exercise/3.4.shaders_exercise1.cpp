//
// Created by hash on 2020/7/1.
//
#version 330 core

layout (location=0) in vec3 aPos;
layout (location =1) in vec3 aColor;

out vec3 shareColor;

void main()
{
    //上下翻转
    gl_Position = vec4(aPos.x,-aPos.y,aPos.z,1.0);
    shareColor = aColor;
}
