#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float altura;

out vec3 ourColor;
out float h;
out float posy;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
	ourColor = color;
	posy = aPos.y;
	h = altura;
}