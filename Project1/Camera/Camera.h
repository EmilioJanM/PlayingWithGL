#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#define MainCamera Camera::MainCam

class Camera {
public:

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)1000 / (float)800, 0.1f, 1100.f);
	glm::mat4 rotation{ 0 };
	glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));
	float cameraSpeed = 0.05f;

	static Camera MainCam;

	void SetPos(int x, int y, int z){ cameraPos = glm::vec3(x, y, z); }
	void SetRot(const float angle,const float x, const float y, const float z) { rotation = glm::rotate(rotation, glm::radians(angle), glm::vec3(x, y, z)); }
	void ParentPos(int x, int y, int z) {
		cameraPos.x = x;
		cameraPos.y = y;
		cameraPos.z = z;
	}

};


#ifdef MAINCAMERA_DEF
	Camera Camera::MainCam = Camera();
#endif
