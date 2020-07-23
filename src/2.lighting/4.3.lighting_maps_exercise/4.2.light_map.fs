#version 330 core
out vec4 FragColor;

struct Material {
    // sample2D  就和纹理有关系了，意味着对应着不同的纹理id以及纹理贴图。
    sampler2D diffuse;  // 反射光贴图
    sampler2D specular; // 镜面光贴图
    sampler2D emission; // 放射光贴图 ： 存储每个片段的发光值的贴图，发光值是指一个包含了（假设）光源的物体发光时可能显现的颜色。
    float shininess;  // 反光度
};

struct Light {
    vec3 position; // 光源位置

    vec3 ambient; // 环境光
    vec3 diffuse; // 漫反射
    vec3 specular; // 镜面光照
};

in vec3 FragPos; // 片段位置
in vec3 Normal;  //法向量
in vec2 TexCoords; // 纹理坐标

uniform vec3 viewPos;  // 视图位置
uniform Material material;
uniform Light light;

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
    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;

    //emission 放射光分量
    vec3 emission = texture(material.emission,TexCoords).rgb;

    vec3 result = ambient + diffuse + specular + emission;
    FragColor = vec4(result, 1.0);
}