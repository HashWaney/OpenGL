#version 330 core
layout (location = 0 ) in vec3 aPos;
layout (location = 1 ) in vec3 aNormal;

out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
    FragPos = vec3(model *vec4(aPos,1.0)); // 将局部空间物体的坐标通过模型转换到世界空间中，因此片段的位置是处于世界空间中。
    Normal = aNormal;

    gl_Position = projection * view * vec4(FragPos,1.0); // gl_Position 处于屏幕空间中 因此需要经历视图变换，投影变换
}