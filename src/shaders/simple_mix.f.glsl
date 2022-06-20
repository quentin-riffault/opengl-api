#version 330 core
in vec4 fcolor;
in vec2 fuv;

out vec4 FragColor;

uniform sampler2D tex1;
uniform sampler2D tex2;
void main()
{
    FragColor = mix(texture(tex1, fuv), texture(tex2, fuv*vec2(1.0f, -1.0f)), 0.5)*fcolor;
}