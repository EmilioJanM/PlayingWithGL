#version 330 core
uniform mat4 worldMatrix;
uniform mat4 viewMatrix, projMatrix;

in vec3 in_Position;
in vec3 in_Color;
in vec3 in_Normal;

out VERTIOUT {
    vec3 position;
		vec3 color;
		vec3 normal;
} verticeOut;

void main(void)
{
	gl_Position = projMatrix * viewMatrix * worldMatrix * vec4(in_Position, 1.0);
	verticeOut.position = gl_Position.xyz;
	verticeOut.normal = in_Normal;
	verticeOut.color = vec3(1.0,0.0,1.0);
}