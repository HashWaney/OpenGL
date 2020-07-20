//#version 330 core
//layout (location = 0 ) in vec3 aPos;
//layout (location = 1 ) in vec3 aNormal; // 单位矩阵

//out vec3 FragPos; // 用于输出到片段着色器中的片段位置
//out vec3 Normal; //  用于处理漫反射的法向量

//uniform mat4 model; // 模型矩阵
//uniform mat4 view; // 视图矩阵
//uniform mat4 projection; // 投影矩阵

//void main(){

 // FragPos = vec3(model * vec4 (1.0));
  //Normal = mat3(transpose(inverse(model)))*aNormal;
 // gl_Position = projection * view * vec4(FragPos,1.0);

//}

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;

    gl_Position = projection * view * vec4(FragPos, 1.0);
}

