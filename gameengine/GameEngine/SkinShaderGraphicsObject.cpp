#include "SkinShaderGraphicsObject.h"
#include "Assert.h"
#include "Math\MathEngine.h"
#include "Model.h"
#include "Camera.h"
#include "CameraMan.h"
#include "ShaderMan.h"

SkinShaderGraphicsObject::SkinShaderGraphicsObject(
	const Model* model, ComponentHandle<Transform>* transform,
	const Vect &BaseColor, const LightSource& light,
	const InverseBindPose* invBones, ComponentHandle<Skeleton>* skeleton)
	: GraphicsObject(model, transform), baseColor(BaseColor), light(light),
	bones(invBones), skeleton(skeleton)
{
	this->SetShaderObject(ShaderMan::LoadShader("skinningShader"));

	this->projMatrixIndex = this->GetShaderObject()->GetUniformLocation("proj_matrix");
	this->viewMatrixIndex = this->GetShaderObject()->GetUniformLocation("view_matrix");
	this->worldMatrixIndex = this->GetShaderObject()->GetUniformLocation("world_matrix");
	this->lightPosIndex = this->GetShaderObject()->GetUniformLocation("vLightPos");
	this->lightColorIndex = this->GetShaderObject()->GetUniformLocation("vColor");
	this->baseColorIndex = this->GetShaderObject()->GetUniformLocation("baseColor");
	this->invBoneIndex = this->GetShaderObject()->GetUniformLocation("invBone");
	this->globalBoneIndex = this->GetShaderObject()->GetUniformBlockIndex("worldBlock");

	glGenBuffers(1, &this->worldBoneMatrixBuffer);
	glBindBuffer(GL_UNIFORM_BUFFER, this->worldBoneMatrixBuffer);
	glBufferData(GL_UNIFORM_BUFFER, (*skeleton)->GetNumBones()*sizeof(Matrix), nullptr, GL_DYNAMIC_DRAW);
}

SkinShaderGraphicsObject::SkinShaderGraphicsObject(SkinShaderGraphicsObject&& o)
	: GraphicsObject(std::move(o)), baseColor(o.baseColor), light(o.light),
	bones(o.bones), skeleton(o.skeleton), worldBoneMatrixBuffer(o.worldBoneMatrixBuffer),
	lightColorIndex(o.lightColorIndex), lightPosIndex(o.lightPosIndex), 
	projMatrixIndex(o.projMatrixIndex), viewMatrixIndex(o.viewMatrixIndex), 
	worldMatrixIndex(o.worldMatrixIndex), baseColorIndex(o.baseColorIndex),
	invBoneIndex(o.invBoneIndex), globalBoneIndex(o.globalBoneIndex)
{
	o.worldBoneMatrixBuffer = 0;
}

SkinShaderGraphicsObject::~SkinShaderGraphicsObject()
{
	glDeleteBuffers(1, &this->worldBoneMatrixBuffer);
}

SkinShaderGraphicsObject& SkinShaderGraphicsObject::operator=(SkinShaderGraphicsObject&& o)
{
	if (this != &o)
	{
		GraphicsObject::operator=(std::move(o));
		worldBoneMatrixBuffer = o.worldBoneMatrixBuffer;
		this->baseColor = std::move(o.baseColor);
		this->light = std::move(o.light);
		this->bones = o.bones;
		this->skeleton = o.skeleton;
		worldBoneMatrixBuffer = o.worldBoneMatrixBuffer;
		lightColorIndex = o.lightColorIndex;
		lightPosIndex = o.lightPosIndex;
		projMatrixIndex = o.projMatrixIndex;
		viewMatrixIndex = o.viewMatrixIndex;
		worldMatrixIndex = o.worldMatrixIndex;
		baseColorIndex = o.baseColorIndex;
		invBoneIndex = o.invBoneIndex;
		globalBoneIndex = o.globalBoneIndex;
		o.worldBoneMatrixBuffer = 0;
	}
	return *this;
}

void SkinShaderGraphicsObject::SetState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	this->GetShaderObject()->UseProgram();
}

void SkinShaderGraphicsObject::SetGPUData()
{
	glBindVertexArray(this->GetModel()->vao);

	Camera* pCam = CameraMan::GetActive();

	Matrix world = this->GetTransform()->GetValue()->GetGlobalWorld();
	Matrix view = pCam->GetViewMatrix();
	Matrix proj = pCam->GetProjMatrix();

	glUniformMatrix4fv(projMatrixIndex, 1, GL_FALSE, (float *)&proj);
	glUniformMatrix4fv(viewMatrixIndex, 1, GL_FALSE, (float *)&view);
	glUniformMatrix4fv(worldMatrixIndex, 1, GL_FALSE, (float *)&world);

	glUniform3fv(lightPosIndex, 1, (float *)&this->light.GetPosition());
	glUniform4fv(lightColorIndex, 1, (float *)&this->light.GetColor());
	glUniform4fv(baseColorIndex, 1, (float *)&baseColor);

	const int numBones = (*skeleton)->GetNumBones();

	glUniformMatrix4fv(invBoneIndex, numBones, GL_FALSE, (float*)bones->invBindPose.begin());

	Array<Matrix> arr;
	arr.Reserve(numBones);

	for (int i = 0; i < numBones; i++)
	{
		arr.EmplaceBack((*(*skeleton)->GetBoneTransform(i))->GetGlobalWorld());
	}

	glBindBuffer(GL_UNIFORM_BUFFER, this->worldBoneMatrixBuffer);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, (numBones - 1)*sizeof(Matrix), &arr[1]);
	glBindBufferBase(GL_UNIFORM_BUFFER, globalBoneIndex, this->worldBoneMatrixBuffer);
}

void SkinShaderGraphicsObject::Draw()
{
	glDrawElements(GL_TRIANGLES, 3 * this->GetModel()->numTris, GL_UNSIGNED_INT, 0);
}

void SkinShaderGraphicsObject::RestoreState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}