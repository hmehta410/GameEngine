#ifndef FBX_BONE_SERIALIZER_H
#define FBX_BONE_SERIALIZER_H

#include "PCSTree\PCSSerializer.h"
#include "FbxBone.h"
#include <cstring>

class FbxBoneSerializer : public PCSSerializer
{
	static const int kNameLength = 64;
public:
	PCSSerialNode serialize(PCSNode* node) const override
	{
		node;
		//FbxBone* bone = (FbxBone*)node;
		//const int size = kNameLength + sizeof(Matrix);

		char *buffer = new char[kNameLength];

		//bone->GetName(buffer, size);
		//memcpy(buffer + kNameLength, bone->local, sizeof(Matrix));*/

		PCSSerialNode sNode;
		sNode.buffer = buffer;
		sNode.size = kNameLength;
		//sNode.num_children = bone->getNumChildren();*/

		return sNode;
	}

	PCSNode* deserialize(const PCSSerialNode& serialNode) const override
	{
		serialNode;
		FbxBone* bone = new FbxBone();
		
		const char* name = serialNode.buffer;
		bone->name = name;
	  /*
	  memcpy(bone->local, serialNode.buffer + kNameLength, sizeof(Matrix));*/

		return bone;
	}

};

#endif PCS_BONE_SERIALIZER_H