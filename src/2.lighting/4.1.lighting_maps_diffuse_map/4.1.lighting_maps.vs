// #version 330 core
// layout (location = 0) in vec3 aPos;
// layout (location = 1) in vec3 aNormal;
// layout (location = 2) in vec2 aTexCoords;

// out vec3 FragPos;
// out vec3 Normal;
// out vec2 TexCoords;

// uniform mat4 model;
// uniform mat4 view;
// uniform mat4 projection;

// void main() {
//     //片段的位置
//     //FragPos = vec3(model * vec4(aPos, 1.0));
//     FragPos = vec3(model * vec4(aPos,1.0));
//     //将法向矩阵转换为法向量
//     //    Normal = mat3(transpose(inverse(model))) * aNormal;
//     Normal = mat3(transpose(inverse(model)))*aNormal;
//     //纹理坐标
//     TexCoords = aTexCoords;
//     gl_Position = projection * view * vec4(FragPos, 1.0);

// }

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;  
    TexCoords = aTexCoords;
    
    gl_Position = projection * view * vec4(FragPos, 1.0);
}