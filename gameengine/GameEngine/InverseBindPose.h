#pragma once
#include "Array\Array.h"
#include "String\String.h"
#include "List\Link.h"
#include "Math\Matrix.h"

//This holds the inv bind pose of a skeleton as expected from the name.
//It's purpose is mainly only used for skinning on the gpu. 
//It may make sense to eventually have this data placed with the SkeletonType class
//however for now it is split up in the same way the data in the files are split up.
struct InverseBindPose : public DLink
{
	Array<Matrix> invBindPose;
	String name;
};