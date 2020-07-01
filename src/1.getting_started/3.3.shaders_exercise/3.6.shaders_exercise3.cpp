//
// Created by hash on 2020/7/1.
//

//Vertex Shader;
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

//out vec3 shareColor;
out vec3 shareColor;

void main(){
    gl_Position = vec4(aPos,1.0);
    shareColor = aPos;
}

// Fragment Shader
#version 330 core
out vec4 FragColor;
in vec3 shareColor;
void main(){
    FragColor = vec4(shareColor,1.0);
}