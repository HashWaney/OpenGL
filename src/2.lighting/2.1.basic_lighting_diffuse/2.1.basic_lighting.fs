#version 330 core

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main(){

   // ambient
   float ambientStrength =0.1; // 环境光强度
   vec3 ambient = ambientStrength * lightColor;

   //diffuse
   vec3 normal = normalize(Normal);
   vec3 lightDirection = normalize(lightPos - FragPos); // 光源位置-片段位置 ==  光源的方向向量
   float diff = max(dot(normal,lightDirection),0.0); // dot 点乘 计算漫反射的强度
   vec3 diffuse = diff * lightColor ;

   vec3 result = (ambient + diffuse )*objectColor;
   FragColor = vec4(result ,1.0);

}
