#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in float h;
in float posy;
in vec4 position;

void main()
{
	FragColor = vec4(ourColor,1);
	if(posy > 0.0f)
		FragColor = vec4(0.5f,0,0,1);
	else
		FragColor = vec4(0,0,0.5f,1);

}