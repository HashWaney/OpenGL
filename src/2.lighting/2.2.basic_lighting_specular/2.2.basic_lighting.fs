// #version 330 core
//
// out vec4 FragColor; // 用于接收经过变换以及光照处理之后的片段颜色,然后进行输出渲染
//
// in vec3 Normal; // 法向量
//
// in vec3 FragPos; // 片段的位置
//
// uniform vec3 lightPos; //光源的位置
// uniform vec3 viewPos; // 观察者的位置
// uniform vec3 lightColor; // 光源的颜色
// uniform vec3 objectColor;//被观测目标的颜色
//
// void main(){
//
//     // 处理环境光
//     float ambientStrength = 0.1;
//     vec3 ambient = ambientStrength * lightColor;
//
//     // 处理漫反射
//     vec3 normal = normalize(Normal);
//     vec3 lightDir = normalize(lightPos - FragPos);
//     float diff = max( dot(normal, lightDir),0.0);
//     vec3 diffuse = diff * lightColor;
//
//     //specular 镜面反射光强
//     float specularStrength = 0.5;
//     // 观察视线方向
//     vec3  viewDir = normalize(viewPos - FragPos);
//     //反射分量
//     vec3 reflectDir = reflect(-lightDir,normal);
//     //求出观察视线与反射分量反光度
//     float spec = pow( max(dot(viewDir,reflectDir),0.0),32);
//     //镜面反射的光强分量
//     vec3 specular =specularStrength * spec * lightColor;
//
//     vec3 result = ambient + diffuse + specular;
//
//     FragColor = vec4 (result ,1.0);
// }

#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}