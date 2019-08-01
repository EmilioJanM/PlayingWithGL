#version 330 core

in VERTIOUT {
    vec3 position;
		vec3 color;
		vec3 normal;
} verticeIn;

out vec4 out_Color;

uniform vec3 pointLight;
uniform vec3 ambient;

uniform float Kd, Ks, Ka;
uniform float n_specular;

uniform vec3 lightPos;
uniform vec3 eyePosition;

void main(void)
{
	vec3 P = verticeIn.position;//ex_Position;
	vec3 N = normalize(verticeIn.normal);//ex_Normal);

	vec3 ambientCon = ambient * Ka;
	vec3 L = normalize(lightPos - P);
	vec3 diffuseCon = Kd * verticeIn.color * max(dot(N, L), 0);

	vec3 V = normalize(eyePosition - P);
	vec3 H = normalize(L + V);
	
	vec3 specularCon = Ks * vec3(1.0,1.0,1.0) * pow(max(dot(N, H), 0), n_specular);

	if(length(diffuseCon) == 0)
		specularCon = vec3(0.0, 0.0, 0.0);

	vec3 addColor = ambientCon + diffuseCon + specularCon;

	float intensity;
	vec4 color;
	color = vec4(addColor,1.0);
	intensity = dot(addColor,verticeIn.normal)+0.5;

	if (intensity > 0.95)
		color = vec4(1.0,0.5,0.5,1.0);
	else if (intensity > 0.5)
		color = vec4(0.6,0.3,0.3,1.0);
	else if (intensity > 0.25)
		color = vec4(0.4,0.2,0.2,1.0);
	else
		color = vec4(0.2,0.1,0.1,1.0);
	out_Color = color;
}
