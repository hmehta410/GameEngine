#pragma once

#include "GraphicsObject.h"
#include "Skeleton.h"
#include "LightSource.h"
#include "InverseBindPose.h"

/*
This GraphicsObject uses a shader to implement animation skinning on the gpu.
It also provides a single color, single point light material for the mesh.
*/
class SkinShaderGraphicsObject : public GraphicsObject
{
public:
	SkinShaderGraphicsObject(const Model* model, ComponentHandle<Transform>* transform,
		const Vect &BaseColor, const LightSource& light,
		const InverseBindPose* invBoneArray, ComponentHandle<Skeleton>* skeleton);
	~SkinShaderGraphicsObject();

	//move operator is for worldBoneMatrixBuffer
	SkinShaderGraphicsObject(SkinShaderGraphicsObject&& o);
	SkinShaderGraphicsObject& operator=(SkinShaderGraphicsObject&& o);

	virtual void SetState() override;
	virtual void SetGPUData() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

private:
	Vect baseColor;
	LightSource light;

	const InverseBindPose *bones;
	ComponentHandle<Skeleton>* skeleton;

	//id for uniform_buffer object
	GLuint worldBoneMatrixBuffer;

	//Uniform indices
	GLuint lightColorIndex;
	GLuint lightPosIndex;
	GLuint projMatrixIndex;
	GLuint viewMatrixIndex;
	GLuint worldMatrixIndex;
	GLuint baseColorIndex;
	GLuint invBoneIndex;
	GLuint globalBoneIndex;
};
