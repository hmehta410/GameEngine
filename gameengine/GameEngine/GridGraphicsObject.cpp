#include "GridGraphicsObject.h"

#include "Model.h"
#include "ShaderMan.h"
#include "CameraMan.h"

GridGraphicsObject::GridGraphicsObject(const Model* model, ComponentHandle<Transform>* transform, const Vect& color)
	: GraphicsObject(model, transform), gridColor(new Vect(color))
{
	this->SetShaderObject(ShaderMan::LoadShader("gridShader"));

	this->projMatrixIndex = this->GetShaderObject()->GetUniformLocation("proj_matrix");
	this->viewMatrixIndex = this->GetShaderObject()->GetUniformLocation("view_matrix");
	this->worldMatrixIndex = this->GetShaderObject()->GetUniformLocation("world_matrix");
	this->gridColorIndex = this->GetShaderObject()->GetUniformLocation("grid_color");
}


GridGraphicsObject::GridGraphicsObject(GridGraphicsObject&& o)
	:GraphicsObject(std::move(o)), gridColor(std::move(o.gridColor)), gridColorIndex(o.gridColorIndex),
	projMatrixIndex(o.projMatrixIndex), viewMatrixIndex(o.viewMatrixIndex), worldMatrixIndex(o.worldMatrixIndex)
{
}

GridGraphicsObject& GridGraphicsObject::operator=(GridGraphicsObject&& o)
{
	if (this != &o)
	{
		GraphicsObject::operator=(std::move(o));
		this->gridColor = std::move(o.gridColor);
		this->gridColorIndex = o.gridColorIndex;
		this->projMatrixIndex = o.projMatrixIndex;
		this->viewMatrixIndex = o.viewMatrixIndex;
		this->worldMatrixIndex = o.worldMatrixIndex;
	}
	return *this;
}

void GridGraphicsObject::SetState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	this->GetShaderObject()->UseProgram();
}

void GridGraphicsObject::SetGPUData()
{
	glBindVertexArray(this->GetModel()->vao);

	Camera* pCam = CameraMan::GetActive();
	Matrix world = this->GetTransform()->GetValue()->GetGlobalWorld();
	Matrix view = pCam->GetViewMatrix();
	Matrix proj = pCam->GetProjMatrix();

	glUniformMatrix4fv(projMatrixIndex, 1, GL_FALSE, (float *)&proj);
	glUniformMatrix4fv(viewMatrixIndex, 1, GL_FALSE, (float *)&view);
	glUniformMatrix4fv(worldMatrixIndex, 1, GL_FALSE, (float *)&world);

	glUniform4fv(gridColorIndex, 1, (float *)(gridColor.get()));
}

void GridGraphicsObject::Draw()
{
	glDrawArrays(GL_LINES, 0, this->GetModel()->numVerts);
}

void GridGraphicsObject::RestoreState()
{
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);
}