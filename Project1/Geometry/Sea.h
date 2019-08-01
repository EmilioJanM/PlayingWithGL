#pragma once

#include <iostream>
#include <string>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Shadern.h"
#include "../Camera/Camera.h"


class Sea
{
public:
	Sea(int _x, int _y, int _z);
	~Sea();

	float x, y, z, rot;
	bool init = false;
	Shader * shaderColor3D = new Shader("Shaders/shader.vs", "Shaders/shader.fs");

	void Init();
	void Update();

private:
	unsigned int VAO, VBO, EBO;

	float vertices[18]{
		0.0f,  0.5f,  -1.5f, 0.0f, 0.0f, 1.f,  //front
		-1.f, 0.5f, 1.5f, 0.0f, 0.0f, 0.3f,
		1.f,  0.5f ,  1.5f, 0.0f, 0.0f, 0.3f
	};
	unsigned int indices[3]{
		0,1,2
	};
};