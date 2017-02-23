#pragma once

#include "PCSTree\PCSTree.h"
#include "List\Link.h"
#include "String\String.h"

/*
Skeleton type holds a pcstree that represents a skeletons hierarchy. There aren't 
any values for the bones. It just shows the connections that each bone makes. It is
a blueprint for the actual Skeleton component class
*/
class SkeletonType : public DLink
{
public:
	SkeletonType(const char* name);
	~SkeletonType();

	const PCSNode* GetRoot();

	void Deserialize(const char* buffer, const PCSSerializer* deserializer);
	bool Matches(const char* name);
	bool Matches(String name);

	const String GetName() const;
	
	int NumBones() const;

private:
	PCSTree bones; //FBXNode
	String name;
};