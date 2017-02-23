#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include "Math\MathEngine.h"
#include "Component.h"
#include "ShaderObject.h"
#include "Transform.h"
#include "ComponentHandle.h"
#include "Model.h"
#include <memory>

/*
The main class for rendering combines the mesh, shader, and transform(pos, rot, scale)
*/
class GraphicsObject : public Component
{
public:
	typedef GraphicsObject FactorySpecialization;  //used for ComponentFactory specialization

public:
	GraphicsObject(const Model* model, ComponentHandle<Transform>* transform);
	GraphicsObject(const Model* model, ShaderObject *pShaderObj, ComponentHandle<Transform>* transform);

	virtual void SetState() = 0;
	virtual void SetGPUData() = 0;
	virtual void Draw() = 0;
	virtual void RestoreState() = 0;
	void Render();
	
	const Model* GetModel() const;
	void SetModel(const Model* model);

	void SetTransform(ComponentHandle<Transform>* transform);
	ComponentHandle<Transform>* GetTransform();

	const ShaderObject* GetShaderObject() const;

protected:
	//A different shader object can't be set publicly
	void SetShaderObject(ShaderObject* object); 

private: //dependency injected
	ShaderObject *shaderObj;
	ComponentHandle<Transform>	*transform;
	const Model* model;
};

#endif