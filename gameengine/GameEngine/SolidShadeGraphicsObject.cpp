#include "Assert.h"
#include "Math\MathEngine.h"
#include "Model.h"
#include "SolidShadeGraphicsObject.h"
#include "Camera.h"
#include "CameraMan.h"
#include "ShaderMan.h"
#include "LightSource.h"
#include <stdio.h>
SolidShadeGraphicsObject::SolidShadeGraphicsObject(const Model* model, ComponentHandle<Transform>* transform, const LightSource& light, const Vect& color)
	: GraphicsObject(model, transform), color(new Vect(color)), lightSource(light)
{
	this->SetShaderObject(ShaderMan::LoadShader("pointLightDiffuse"));

	this->projMatrixIndex = this->GetShaderObject()->GetUniformLocation("proj_matrix");
	this->viewMatrixIndex = this->GetShaderObject()->GetUniformLocation("view_matrix");
	this->worldMatrixIndex = this->GetShaderObject()->GetUniformLocation("world_matrix");
	this->lightPosIndex = this->GetShaderObject()->GetUniformLocation("vLightPos");
	this->lightColorIndex = this->GetShaderObject()->GetUniformLocation("vLightColor");
	this->diffuseColorIndex = this->GetShaderObject()->GetUniformLocation("vDiffuseColor");
}

SolidShadeGraphicsObject::SolidShadeGraphicsObject(SolidShadeGraphicsObject&& o)
	: GraphicsObject(std::move(o)), lightSource(std::move(o.lightSource)), color(std::move(o.color)),
	lightColorIndex(o.lightColorIndex), lightPosIndex(o.lightPosIndex), projMatrixIndex(o.projMatrixIndex),
	viewMatrixIndex(o.viewMatrixIndex), worldMatrixIndex(o.worldMatrixIndex), diffuseColorIndex(o.diffuseColorIndex)
{
}

SolidShadeGraphicsObject& SolidShadeGraphicsObject::operator=(SolidShadeGraphicsObject&& o)
{
	if (this != &o)
	{
		GraphicsObject::operator=(std::move(o));
		this->lightSource = std::move(o.lightSource);
		this->color = std::move(o.color);
		this->lightColorIndex = o.lightColorIndex;
		this->lightPosIndex = o.lightPosIndex;
		this->projMatrixIndex = o.projMatrixIndex;
		this->viewMatrixIndex = o.viewMatrixIndex;
		this->worldMatrixIndex = o.worldMatrixIndex;
		this->diffuseColorIndex = o.diffuseColorIndex;
	}
	return *this;
}

void SolidShadeGraphicsObject::SetState()
{
	glDisable(GL_CULL_FACE);
	this->GetShaderObject()->UseProgram();
}

void SolidShadeGraphicsObject::SetGPUData()
{
	glBindVertexArray(this->GetModel()->vao);

	Camera* pCam = CameraMan::GetActive();

	Matrix world = this->GetTransform()->GetValue()->GetGlobalWorld();
	Matrix view = pCam->GetViewMatrix();
	Matrix proj = pCam->GetProjMatrix();

	glUniformMatrix4fv(this->projMatrixIndex, 1, GL_FALSE, (float *)&proj);
	glUniformMatrix4fv(this->viewMatrixIndex, 1, GL_FALSE, (float *)&view);
	glUniformMatrix4fv(this->worldMatrixIndex, 1, GL_FALSE, (float *)&world);

	const Vect& lightColor = lightSource.GetColor();
	const Vect& meshColor = *this->color;
	const Vect& pos = lightSource.GetPosition();
	glUniform4fv(this->lightColorIndex, 1, (float*)&lightColor);
	glUniform3fv(this->lightPosIndex, 1, (float*)&pos);
	glUniform4fv(this->diffuseColorIndex, 1, (float*)&meshColor);
}

void SolidShadeGraphicsObject::Draw()
{
	// draw
	//glDrawArrays(GL_LINES, 0, (3 * this->getModel()->numVerts));
	//The starting point of the IBO
	glDrawElements(GL_TRIANGLES, 3 * this->GetModel()->numTris, GL_UNSIGNED_INT, 0);
}

void SolidShadeGraphicsObject::RestoreState()
{
	glEnable(GL_CULL_FACE);
}