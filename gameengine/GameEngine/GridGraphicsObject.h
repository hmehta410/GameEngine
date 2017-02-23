#pragma once

#include "GraphicsObject.h"
#include "GL\glew.h"
#include <memory>

class Model;

/*
Draws a grid. It is meant to be used exclusively with the Model* created from 
ModelMan::LoadGrid(int, int);
*/
class GridGraphicsObject : public GraphicsObject, public Align16
{
public:
	GridGraphicsObject(const Model* model, ComponentHandle<Transform>* transform, const Vect& color);
	GridGraphicsObject(GridGraphicsObject&& other);

	GridGraphicsObject& operator=(GridGraphicsObject&& other);

	virtual void SetState() override;
	virtual void SetGPUData() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

private:
	std::unique_ptr<Vect> gridColor;

	GLuint gridColorIndex;
	GLuint projMatrixIndex;
	GLuint viewMatrixIndex;
	GLuint worldMatrixIndex;
};