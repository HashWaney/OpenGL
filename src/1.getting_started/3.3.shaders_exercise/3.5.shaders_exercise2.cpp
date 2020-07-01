//
// Created by hash on 2020/7/1.
//
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 shareColor;

uniform float offset;

void main()
{
    // x方向偏移offset
    gl_Position = vec4(aPos.x + offset , aPos.y, aPos.z,1.0);
    shareColor =aColor;
}
