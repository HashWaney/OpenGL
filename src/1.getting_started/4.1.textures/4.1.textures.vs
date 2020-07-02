#version 330 core
layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aColor;
layout (location = 2) in vec2 TexCoord;

out vec3 shareColor;

out vec2 texCoord;

void main(){
    gl_Position = vec4(aPos ,1.0);
    shareColor = aColor;
    texCoord = vec2(TexCoord.x,TexCoord.y);
}