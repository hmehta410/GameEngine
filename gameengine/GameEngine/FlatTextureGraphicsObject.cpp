#include "Assert.h"

#include "FlatTextureGraphicsObject.h"
#include "TextureManager.h"
#include "Model.h"
#include "Camera.h"
#include "CameraMan.h"
#include "ShaderMan.h"

FlatTextureGraphicsObject::FlatTextureGraphicsObject(const Model* model, ComponentHandle<Transform>* transform, Texture* node)
	: GraphicsObject(model, transform), textureID(node->GetTextureID())
{
	this->SetShaderObject(ShaderMan::LoadShader("textureRender"));

	this->projMatrixIndex = this->GetShaderObject()->GetUniformLocation("proj_matrix");
	this->viewMatrixIndex = this->GetShaderObject()->GetUniformLocation("view_matrix");
	this->worldMatrixIndex = this->GetShaderObject()->GetUniformLocation("world_matrix");
}

FlatTextureGraphicsObject::FlatTextureGraphicsObject(FlatTextureGraphicsObject&& o)
	: GraphicsObject(std::move(o)), textureID(o.textureID), projMatrixIndex(o.projMatrixIndex),
	viewMatrixIndex(o.viewMatrixIndex), worldMatrixIndex(o.worldMatrixIndex)
{
}

FlatTextureGraphicsObject& FlatTextureGraphicsObject::operator=(FlatTextureGraphicsObject&& o)
{
	if (this != &o)
	{
		GraphicsObject::operator=(std::move(o));
		this->textureID = o.textureID;
		this->projMatrixIndex = o.projMatrixIndex;
		this->viewMatrixIndex = o.viewMatrixIndex;
		this->worldMatrixIndex = o.worldMatrixIndex;
	}
	return *this;
}

void FlatTextureGraphicsObject::SetState()
{
	glActiveTexture(GL_TEXTURE0);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	// use this shader
	this->GetShaderObject()->UseProgram();
}

void FlatTextureGraphicsObject::SetGPUData()
{
	// Bind the texture
	//This is a little bothersome because the same texture may be rebound.
	//One solution would be to move this into SetState and create a separate GraphicsFactory
	//for each texture used.
	glBindTexture(GL_TEXTURE_2D, textureID); 

	// set the vao
	glBindVertexArray(this->GetModel()->vao);

	Camera* pCam = CameraMan::GetActive();
	Matrix world = this->GetTransform()->GetValue()->GetGlobalWorld();
	Matrix view = pCam->GetViewMatrix();
	Matrix proj = pCam->GetProjMatrix();

	glUniformMatrix4fv(projMatrixIndex, 1, GL_FALSE, (float *)&proj);
	glUniformMatrix4fv(viewMatrixIndex, 1, GL_FALSE, (float *)&view);
	glUniformMatrix4fv(worldMatrixIndex, 1, GL_FALSE, (float *)&world);;
}

void FlatTextureGraphicsObject::Draw()
{
	glDrawElements(GL_TRIANGLES, 3 * this->GetModel()->numTris, GL_UNSIGNED_INT, 0);
}

void FlatTextureGraphicsObject::RestoreState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}
