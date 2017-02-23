#ifndef SKELETON_MAN_H
#define SKELETON_MAN_H

#include "List\DList.h"
#include "SkeletonType.h"
#include "InverseBindPose.h"

//Used to contain the various types of skeletons
//i.e. human, teddy, etc
//It also makes sure skeletons aren't loaded multiple times
class SkeletonMan
{
public:
	~SkeletonMan();
	static SkeletonType* LoadSkeleton(const char* filename);
	static InverseBindPose* LoadInverseSkeleton(const char* filename);

	static SkeletonType* FindSkeleton(const char* filename);
	static InverseBindPose* FindInverseSkeleton(const char* filename);

private:
	SkeletonMan();

	static SkeletonMan* GetInstance();

	DList skeletonTypes;
	DList invBindPoses;
};

#endif SKELETON_MAN_H