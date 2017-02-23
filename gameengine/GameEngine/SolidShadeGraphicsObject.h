#pragma once

#include "GraphicsObject.h"
#include "GL\glew.h"
#include "Math\Align16.h"
#include "LightSource.h"
#include <memory>

class Model;

//Draws a static mesh of a given color with a single point light.
class SolidShadeGraphicsObject : public GraphicsObject
{
public:
	SolidShadeGraphicsObject(const Model* model, ComponentHandle<Transform>* transform, const LightSource& light, const Vect& color);

	SolidShadeGraphicsObject(SolidShadeGraphicsObject&& other);
	SolidShadeGraphicsObject& operator=(SolidShadeGraphicsObject&& other);

	virtual void SetState() override;
	virtual void SetGPUData() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

private:
	LightSource lightSource; 
	std::unique_ptr<Vect> color;

	//uniform indices
	GLuint lightColorIndex;
	GLuint lightPosIndex;
	GLuint projMatrixIndex;
	GLuint viewMatrixIndex;
	GLuint worldMatrixIndex;
	GLuint diffuseColorIndex;
};