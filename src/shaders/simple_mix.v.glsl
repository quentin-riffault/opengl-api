#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 uv;

out vec4 fcolor;
out vec2 fuv;
uniform vec4 color_modifier;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    fcolor = color*color_modifier;
    fuv = uv;
}