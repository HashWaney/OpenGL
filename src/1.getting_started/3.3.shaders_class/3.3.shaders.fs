#version 330 core
out vec4 FragColor;

in vec3 shareColor;

void main()
{
    FragColor=vec4(shareColor,1.0f);

}