#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in float h;
in float posy;

void main()
{
	float hh = 0.2f + posy / 2;
    FragColor = vec4(hh,0,0,1);
}