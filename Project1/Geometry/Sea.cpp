#include "Sea.h"

Sea::Sea(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
Sea::~Sea() {}

void Sea::Init() {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	init = true;
}

void Sea::Update() {
	Camera cam = MainCamera;
	shaderColor3D->use();

	cam.view = glm::lookAt(cam.cameraPos, cam.cameraPos + cam.cameraFront, cam.cameraUp);

	// pass transformation matrices to the shader
	glm::mat4 model(1); glm::mat4 rotation(1);
	model = glm::translate(model, glm::vec3(x, y, z)) * glm::rotate(rotation, glm::radians(rot), glm::vec3(0, 0, 1));

	shaderColor3D->setMat4("projection", cam.projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	shaderColor3D->setMat4("view", cam.view);
	shaderColor3D->setMat4("model", model);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

}