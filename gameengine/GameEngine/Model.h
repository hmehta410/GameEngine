#ifndef MODEL_H
#define MODEL_H

#include "GL\glew.h"

class Model
{
public:
	Model();
	~Model();

	//we don't want to allow copying the vao and vbos
	//and accidently release them too early.
	Model(const Model&) = delete;
	Model& operator=(const Model&) = delete;

	// Data
	//bounding sphere data
	float x; //centerX
	float y; //centerY
	float z; //centerZ
	float radius;

	int numVerts;
	int numTris;

	GLuint vao;
	GLuint vbo[2];
};

#endif