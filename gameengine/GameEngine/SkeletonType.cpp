#include "SkeletonType.h"

SkeletonType::SkeletonType(const char* name) : name(name)
{
}

SkeletonType::~SkeletonType()
{
	this->bones.DeleteTree();
}

const PCSNode* SkeletonType::GetRoot()
{
	return this->bones.GetRoot();
}

void SkeletonType::Deserialize(const char* buffer, const PCSSerializer* deserializer)
{
	bones.Deserialize(buffer, deserializer);
}

bool SkeletonType::Matches(const char* str)
{
	return this->name == str;
}

bool SkeletonType::Matches(String str)
{
	return this->name == str;
}

const String SkeletonType::GetName() const
{
	return name;
}

int SkeletonType::NumBones() const
{
	return bones.GetSize();
}
