#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;

out vec4 fcolor;
uniform vec4 color_modifier;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    fcolor = color*color_modifier;
}