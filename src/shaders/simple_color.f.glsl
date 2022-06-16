#version 330 core
in vec 4 fcolor;
out vec4 FragColor;

void main()
{
    FragColor = fcolor;
    //FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}