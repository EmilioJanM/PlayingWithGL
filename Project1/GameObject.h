#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "stb_image.h"
#include "Shadern.h"
#include "Camera/Camera.h"

using std::cout; using std::endl;

class GameObject
{
protected:
	Camera cam = MainCamera;
	unsigned int VAO, VBO, EBO;
	float x, y, z;
public:
	Shader * shaderColor3D;
	GameObject() {}
	~GameObject() {}


};
