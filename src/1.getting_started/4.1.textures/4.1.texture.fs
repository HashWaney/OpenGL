#version 330 core

out vec4 FragColor;

in vec3 shareColor;

in vec2 texCoord;

//一个采样器
uniform sampler2D texture1;

void main(){
//GLSL内置的函数texture来采样纹理的颜色，第一个参数就是纹理采样器，第二个参数就是对应的纹理坐标。
//通过纹理采样器采样对应纹理坐标上的颜色，得到了我需要需要绘制的着色器的颜色。
// 这个函数还是将一个顶点坐标2D经过变换为4D的空间向量。
    FragColor = texture(texture1,texCoord);
}