// #version 330 core 

// out vec4 FragColor;

// // 物体的材质，包含一些反射率等光照模型作用
// struct Material {
//     vec3 ambient;
//     vec3 diffuse;
//     vec3 specular;
//     float shininess;

// };

// // 光的属性:通过调节对物体的光照分量的强度来呈现更好的视觉效果，使得物体看起来明亮错落有致。
// struct Light {

//      vec3 position;
//      vec3 ambient;
//      vec3 diffuse;
//      vec3 specular;

// };

// in vec3 FragPos; //片段的位置信息
// in vec3 Normal; // 法向量 作用于漫反射

// uniform vec3 viewPos;
// uniform Material material;
// uniform Light light;

// void main(){

//     // ambient 环境光分量
//     vec3 ambient = light.ambient * material.ambient;
    
//     //diffuse 
//     vec3 norm = normalize(Normal);
//     //光源的方向向量 
//     vec3 lightDir = normalize(light.position - FragPos);
//     float diff = max(dot(norm,lightDir),0.0);
//     vec3 diffuse = light.diffuse * (diff* material.diffuse);

//     //specular 
//     // 观察者的方向向量
//     vec3 viewDir =  normalize(viewPos - FragPos);
//     //反射向量
//     vec3 reflectDir = reflect(-lightDir,norm);
//     float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
//     vec3  specular = light.specular * (spec * material.specular);

//     vec3 result = ambient + diffuse + specular;
//     FragColor = vec4(result,1.0);

// }




// layout (location = 0 )in vec3 aPos;

// uniform mat4 model;
// uniform mat4 view;
// uniform mat4 projection;

// void main(){
//     gl_Position = projection * view * model * vec4 (aPos,1.0);
// }

#version 330 core
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

void main()
{
    // ambient
    vec3 ambient = light.ambient * material.ambient;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);
    
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);  
        
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
} 