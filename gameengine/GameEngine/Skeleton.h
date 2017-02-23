#pragma once

#include "ComponentHandle.h"
#include "Transform.h"
#include "Array/Array.h"
#include "String/String.h"

/*
The Skeleton component contains a set of bones mainly used for animation.
Each bone just holds a ComponentHandle<Transform> which already have the ability to 
be set up hierarchically. On construction, the transforms are parented to each other
based on the SkeletonTypes blueprint. This means the bones themselves don't need 
to be placed in a tree. 
*/
class Skeleton : public Component
{
public:
	Skeleton(int size = 0);
	void AddBone(ComponentHandle<Transform>* transform, const String& name);

	int GetNumBones() const;

	const String& GetBoneName(int i);
	ComponentHandle<Transform>* GetBoneTransform(int i);
	ComponentHandle<Transform>* GetBoneTransform(const String& name);

private:	
	struct Bone
	{
		ComponentHandle<Transform>* transform;
		String name;
	};

	Array<Bone> bones;
};