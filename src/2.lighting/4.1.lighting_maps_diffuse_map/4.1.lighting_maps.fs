#version 330 core
out vec4 FragColor;

// struct Material {
//     // 代替漫反射分量，使用纹理方式来区分物体各个部分的材质不同的漫反射影响
//    sampler2D diffuse;
//     vec3 specular;   //镜面光照分量
//      float shininess; //反光度
// };

struct Material {
    sampler2D diffuse;
    vec3 specular;
    float shininess;
};

//
// struct Light {
//
//      vec3 position; // 光源位置
//      vec3 ambient; // 环境光分量
//      vec3 diffuse; // 漫反射分量
//      vec3 specular; // 镜面光照分量
//
// };

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

// in vec3 FragPos;
// in vec3 Normal;
// in vec2 TexCoords;
//
// uniform vec3 viewPos;
// uniform Material material;
// uniform Light light;


in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

//
// void main(){
//
//     //利用纹理获取漫反射分量并且取出纹理的rbg分量然后与光源的环境光分量进行叉乘得出环境光分量
//     vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;
//
//
//     //法向量的标准化
//     vec3 norm = normalize(Normal);
//     //光线的方向向量 = 光源的位置 - 片段的位置
//    vec3 lightDir = normalize(light.position - FragPos);
//
//    float diff = max(dot(norm, lightDir), 0.0);
//    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;
//
//     //镜面光照
//     //观察者的方向向量
//     vec3 viewDir = normalize(viewPos - FragPos);
//     //反射向量
//     vec3 reflectDir = reflect(-lightDir, norm);
//     float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//     vec3 specular = light.specular * (spec * material.specular);
//
//
//     vec3 result = ambient + diffuse + specular;
//     FragColor = vec4(result, 1.0);
// }

void main()
{
    // ambient
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;

    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}