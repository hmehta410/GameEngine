#include "SkeletonMan.h"
#include "File\File.h"
#include <assert.h>
#include "FbxBoneSerializer.h"
#include <memory>

SkeletonMan::SkeletonMan()
{
}

SkeletonMan::~SkeletonMan()
{
	this->skeletonTypes.DeleteList();
	this->invBindPoses.DeleteList();
}

SkeletonMan* SkeletonMan::GetInstance()
{
	static SkeletonMan man;
	return &man;
}

SkeletonType* SkeletonMan::LoadSkeleton(const char* filename)
{
	SkeletonType* type = FindSkeleton(filename);

	if (type == nullptr)
	{
		File file(filename, FileMode::READ);
		assert(file.GetError() == FileError::NONE);

		int size = file.GetSize();

		std::unique_ptr<char[]> buffer(new char[size]);
		file.Read(buffer.get(), size);

		assert(file.GetError() == FileError::NONE);

		FbxBoneSerializer deserializer;
		type = new SkeletonType(filename);
		type->Deserialize(buffer.get(), &deserializer);

		SkeletonMan* man = SkeletonMan::GetInstance();
		man->skeletonTypes.PushBack(type);
	}
	return type;
}

InverseBindPose* SkeletonMan::LoadInverseSkeleton(const char* filename)
{
	InverseBindPose* pose = FindInverseSkeleton(filename);
	if (pose == nullptr)
	{
		File file(filename, FileMode::READ);
		int fileSize = file.GetSize();

		std::unique_ptr<char[]> buffer(new char[fileSize]);
		file.Read(buffer.get(), fileSize);
		assert(file.GetError() == FileError::NONE);



		unsigned int numBones;
		memcpy(&numBones, buffer.get(), sizeof(numBones));

		Matrix* invBindData = (Matrix*)(buffer.get() + sizeof(numBones));

		pose = new InverseBindPose();
		pose->invBindPose.Reserve(numBones);
		for (unsigned int i = 0; i < numBones; i++)
		{
			pose->invBindPose.EmplaceBack(invBindData[i]);
		}

		pose->name = filename;

		SkeletonMan* man = SkeletonMan::GetInstance();
		man->invBindPoses.PushBack(pose);
	}

	return pose;
}

SkeletonType* SkeletonMan::FindSkeleton(const char* filename)
{
	SkeletonMan* man = SkeletonMan::GetInstance();

	auto it = man->skeletonTypes.GetIterator();
	for (SkeletonType* type = it.First(); !it.IsDone(); type = it.Next())
	{
		if (type->Matches(filename))
		{
			return type;
		}
	}

	return nullptr;
}

InverseBindPose* SkeletonMan::FindInverseSkeleton(const char* filename)
{

	SkeletonMan* man = SkeletonMan::GetInstance();

	auto it = man->invBindPoses.GetIterator();
	for (auto* pose = it.First(); !it.IsDone(); pose = it.Next())
	{
		if (pose->name == filename)
		{
			return pose;
		}
	}
	
	return nullptr;
}
