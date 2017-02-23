#ifndef FBX_BONE_H
#define FBX_BONE_H

#include "PCSTree\PCSNode.h"
#include "Math\MathEngine.h"
#include <string>

class FbxBone : public PCSNode
{
public:
	FbxBone() : local(new Matrix(MatrixSpecialType::IDENTITY)) {}
	~FbxBone()
	{
		delete local;
	}

	Matrix* local;
	String name;
private:
	FbxBone(const FbxBone& other) = delete;
	FbxBone& operator=(const FbxBone& other) = delete;
};

#endif