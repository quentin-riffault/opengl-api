#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;

uniform mat4 pvm;

out vec4 fcolor;

void main()
{
    gl_Position = pvm*vec4(aPos, 1.0);
    fcolor = color;
}