#version  330 core

out vec4 FragColor;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;

};

struct Light {
   vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


in vec3 FragPos;
in vec3 Normal;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main(){

    //ambient 
    vec3 ambient = light.ambient * material.ambient;

    //diffuse 
    vec3 norm  = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    //光照对物体的漫反射影响
    float diff = max(dot(norm,lightDir),0.0);
    //所以这里需要进行物体材质的漫反射分量*漫反射影响
    vec3 diffuse = light.diffuse * (diff * material.diffuse);

    //specular 
    vec3 viewDir = normalize(viewPos - FragPos);
    //镜面反射 是法线量和光照的方向向量作用的结果
    vec3 reflectDir = reflect(-lightDir,norm);
    float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result ,1.0);
} 