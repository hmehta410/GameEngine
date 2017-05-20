#include "Assert.h"

#include "GraphicsObject.h"
#include "Math\MathEngine.h"
#include "UniqueId.h"
#include "Model.h"

GraphicsObject::GraphicsObject(const Model* model, ComponentHandle<Transform>* transform)
	: model(model), transform(transform)
{
}

GraphicsObject::GraphicsObject(const Model* model, ShaderObject *_pShaderObj, ComponentHandle<Transform>* transform)
	: model(model), shaderObj(_pShaderObj), transform(transform)
{
	assert(_pShaderObj);
}

void GraphicsObject::Render()
{
	this->SetState();
	this->SetGPUData();
	this->Draw();
	this->RestoreState();
}

const Model* GraphicsObject::GetModel() const
{
	return this->model;
}

void GraphicsObject::SetModel(const Model* aModel)
{
	this->model = aModel;
}

void GraphicsObject::SetTransform(ComponentHandle<Transform>* aTransform)
{
	this->transform = aTransform;
}

ComponentHandle<Transform>* GraphicsObject::GetTransform()
{
	return this->transform;
}

void GraphicsObject::SetShaderObject(ShaderObject* object)
{
	this->shaderObj = object;
}

const ShaderObject* GraphicsObject::GetShaderObject() const
{
	return this->shaderObj;
}
