#pragma once

#define STB_IMAGE_IMPLEMENTATION
#define MAINCAMERA_DEF

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <windows.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


#include "stb_image.h"

#include "GameObject.h"
#include "Shadern.h"
#include "Camera/Camera.h"
#include "SeaMesh.h"
#include "Geometry/SkyBox/SkyBoxC.h"
#include "Time.h"
//Classes

using std::cout; using std::cerr; using std::endl;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void processInputCam(GLFWwindow *window, float &var);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

unsigned int SCR_WIDTH = 1000;
unsigned int SCR_HEIGHT = 800;