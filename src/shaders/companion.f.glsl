#version 330 core
in vec2 fuv;

out vec4 FragColor;
uniform sampler2D companionTexture;

void main()
{
    FragColor = texture(companionTexture, fuv);
}