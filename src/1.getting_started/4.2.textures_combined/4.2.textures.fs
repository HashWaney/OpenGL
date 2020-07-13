#version 330 core

out vec4 FragColor;

in vec3 shareColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec4 uniformColor;

void main(){
    // mix(x,y,a) == x*(1-a)+y*a; x,y的线性混合，也就是利用了x的(1-a)的倍 与y的a倍来进行线性的插值
    //mix performs a linear interpolation between x and y using a to weight between them.
    //The return value is computed as follows: x⋅(1−a)+y⋅a.

   //For the variants of mix where a is genBType, elements for which a[i] is false,
   //the result for that element is taken from x, and where a[i] is true,
   //it will be taken from y. Components of x and y that are not selected
   //are allowed to be invalid floating point values and will have no effect on the results.


    FragColor = mix(texture(texture1,TexCoord),texture(texture2,TexCoord),0.2)*uniformColor;

}