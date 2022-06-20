#version 330 core
in vec4 fcolor;
in vec2 fuv;

out vec4 FragColor;
uniform sampler2D ObjectTexture;

void main()
{
    FragColor = texture(ObjectTexture, fuv)*fcolor;
}