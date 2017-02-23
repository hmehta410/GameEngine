#include "Skeleton.h"

Skeleton::Skeleton(int size /*= 0*/)
{
	bones.Reserve(size);
}

int Skeleton::GetNumBones() const
{
	return bones.Size();
}

const String& Skeleton::GetBoneName(int i)
{
	return bones[i].name;
}

ComponentHandle<Transform>* Skeleton::GetBoneTransform(int i)
{
	return bones[i].transform;
}

ComponentHandle<Transform>* Skeleton::GetBoneTransform(const String& name)
{
	for (Bone& bone : bones)
	{
		if (bone.name == name)
		{
			return bone.transform;
		}
	}
	return nullptr;
}

void Skeleton::AddBone(ComponentHandle<Transform>* transform,const String& name)
{
	Bone bone{ transform, name };
	bones.PushBack(bone);
}
