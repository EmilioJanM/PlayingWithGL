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
out vec4 position;

void main()
{
	vec4 position = projection * view * model * vec4(aPos, 1.0);
	gl_Position = position;
	if(position.x > 0){
		gl_Position = vec4(0,0,0,0);
	}else{
		gl_Position = position;
	}
	ourColor = color;
	posy = position.y;
	h = altura;
}