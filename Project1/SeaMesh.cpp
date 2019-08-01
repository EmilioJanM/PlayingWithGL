#include "SeaMesh.h"

SeaMesh::SeaMesh(int _x, int _y, int _z, float _w, float _h) : w(_w), h(_h) {
	x = _x; y = _y; z = _z;
	shaderColor3D = new Shader("Shaders/Sea/HeightPlay/SeaHeight.vs", "Shaders/Sea/HeightPlay/SeaHeight.fs");

	srand(time(NULL));
	float length = h / 2; float wide = w / 2;
	if (h == 1) 
		length = 0.5f;
	if (w == 1)
		wide = 0.5f;
	int count = 0;
	for (float i = -length; i != length + 1; i++) {
		for (float j = -wide; j != wide + 1; j++) {
			Node *n = new Node();
			n->x = i;
			n->z = j;
			n->vertexInt = count;
			nodes.push_back(n);
			mesh.push_back(n->x); 	mesh.push_back(n->y);	mesh.push_back(n->z);
			mesh.push_back(.0f);
			mesh.push_back(.2f);
			mesh.push_back(.5f);
			vel.push_back((static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*0.04f);
		}
	}
	int wBuff = w; int size = ((h + 1)*(w + 1))-w-1;
	meshTotalVertex = ((h + 1)*(w + 1));
	cout << meshTotalVertex;
	for (size_t i = 0; i != size; i++) {
		if (i != wBuff) {
			meshEBO.push_back(i);	meshEBO.push_back(i+1);	meshEBO.push_back(i + w + 1);
			meshEBO.push_back(i + w + 1);	meshEBO.push_back(i + w + 2);	meshEBO.push_back(i + 1);
		}
		else
			wBuff += w+1;
	}
}
SeaMesh::~SeaMesh() {}

void SeaMesh::Init() {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, mesh.size() * sizeof(GLuint), mesh.data(), GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshEBO.size() * sizeof(GLuint), meshEBO.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	shaderColor3D->setFloat("altura", 0.5f);

	init = true;
}

void SeaMesh::Update() {
	cam = MainCamera;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	shaderColor3D->use();

	cam.view = glm::lookAt(cam.cameraPos, cam.cameraPos + cam.cameraFront, cam.cameraUp);

	// pass transformation matrices to the shader
	glm::mat4 model(1); glm::mat4 rotation(1);
	model = glm::translate(model, glm::vec3(x, y, z)) * glm::rotate(rotation, glm::radians(rot), glm::vec3(1, 0, 0));

	shaderColor3D->setMat4("projection", cam.projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	shaderColor3D->setMat4("view", cam.view);
	shaderColor3D->setMat4("model", model);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, mesh.size() * sizeof(GLuint), mesh.data(), GL_STATIC_DRAW);
	glDrawElements(GL_TRIANGLES, meshEBO.size(), GL_UNSIGNED_INT, 0);
}

void SeaMesh::ModVertex(short int vert)
{
	short int vertex = (vert * 3) + 1;
	mesh[vertex] += 0.01f;

	glBufferData(GL_ARRAY_BUFFER, mesh.size() * sizeof(GLuint), mesh.data(), GL_STATIC_DRAW);
}

void SeaMesh::SeaMove()
{
	unsigned int vertex;
	for (size_t i = 0; i != meshTotalVertex; i++) {
		vertex = (i * 6) + 1;
		mesh[vertex] += vel[i];
		if(mesh[vertex] > 2.f)
			vel[i] *= -1;
		else if(mesh[vertex] < 0)
			vel[i] *= -1;
	}
}

