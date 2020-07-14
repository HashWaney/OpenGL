//
// Created by hash on 2020/7/13.
//

#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture1;

uniform sampler2D ourTexture2;

void main(){
    FragColor = mix(texture())
}