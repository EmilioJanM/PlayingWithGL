#include "SkyBoxC.h"



SkyBoxC::SkyBoxC() { 
	x = 0; y = 10; z = 0;
	shaderColor3D = new Shader("Shaders/SkyBox/SkyBox.vs", "Shaders/SkyBox/SkyBox.fs");
}
SkyBoxC::SkyBoxC(int _x, int _y, int _z) {
	x = _x; y = _y; z = _z;
	shaderColor3D = new Shader("Shaders/SkyBox/SkyBox.vs", "Shaders/SkyBox/SkyBox.fs");
}
SkyBoxC::~SkyBoxC(){}

void SkyBoxC::Init() {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	std::cout << "Init" << std::endl;
}

void SkyBoxC::Update() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	cam = MainCamera;

	shaderColor3D->use();

	cam.view = glm::lookAt(cam.cameraPos, cam.cameraPos + cam.cameraFront, cam.cameraUp);

	// pass transformation matrices to the shader

	glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
	glm::mat4 model(1); glm::mat4 rotation(1);
	model = glm::translate(model, glm::vec3(x, y, z)) * glm::rotate(rotation, glm::radians(180.f), glm::vec3(1, 0, 0));
	shaderColor3D->setMat4("model", model);
	shaderColor3D->setMat4("view", cam.view);
	shaderColor3D->setMat4("projection", cam.projection);
	// skybox cube
	glBindVertexArray(VAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthFunc(GL_LESS);
}
void SkyBoxC::ParentPos(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}