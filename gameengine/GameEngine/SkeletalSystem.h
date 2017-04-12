#pragma once

#include "SystemBase.h"
#include "ComponentFactory.h"
#include "ComponentHandle.h"
#include "Skeleton.h"
#include "SkeletonMan.h"
#include "SkeletonType.h"

/*
The SkeletonSystem creates and retain ownership to Skeletons and passes out
handles so that other services may use them. The run method reconfigures the bones
of each skeleton to be of the correct size and rotation to directly point and attach 
to the parent bone. This is only necessary when trying to visualize the bones of a skeleton
and should othwise not be run. It must run after the TransformSystem to work correctly.

TODO: It may be a good idea to break out that functionality into a SkeletonVisualizationSystem
in the future
*/
class SkeletalSystem : public SystemBase
{
public:
	SkeletalSystem(TransformSystem* system);

	ComponentHandle<Skeleton>* CreateSkeleton(SkeletonType* type, ComponentHandle<Transform>* parent = nullptr);

	virtual void Reload() override;
	virtual void Run() override;
	virtual void Clean() override;

	//You can get or set which transform system newly created skeletons will be
	//attached to
	TransformSystem* GetTransformSystem() const;
	void SetTransformSystem(TransformSystem* val);

private:
	ComponentFactory<Skeleton> skeletonFactory;
	TransformSystem* transforms;

	void SkeletonBuilder(ComponentHandle<Transform>* parent, const PCSNode* node, Skeleton* skeleton);
};