#pragma once

#include "GameObject.h"
#include "Node.h"

class SeaMesh : public GameObject
{
public:
	SeaMesh(int _x, int _y, int _z, float _w, float _h);
	~SeaMesh();

	float w, h, rot;
	bool init = false;

	void Init();
	void Update();
	void ModVertex(short int vert);
	void SeaMove();
	std::vector<GLfloat> mesh;
	std::vector<GLfloat> meshExtra;
	std::vector<GLuint> meshEBO;
	std::vector<Node*> nodes;
	std::vector<float> vel;

private:
	unsigned int meshTotalVertex;
};
