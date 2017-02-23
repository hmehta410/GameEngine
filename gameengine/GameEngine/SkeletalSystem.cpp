#include "SkeletalSystem.h"
#include "TransformSystem.h"
#include "FbxBone.h"
#include <assert.h>


SkeletalSystem::SkeletalSystem(TransformSystem* system)
	: transforms(system)
{
}

namespace
{
	//we need to reverse the order because of the way pcstree is serialized
	//causes things to be flipped somewhere along the way
	PCSNode* GetLastSibling(PCSNode* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		PCSNode* sibling = node;
		PCSNode* next = sibling->GetNextSibling();
		while (next != nullptr)
		{
			sibling = next;
			next = sibling->GetNextSibling();
		}
		return sibling;
	}
}

void SkeletalSystem::SkeletonBuilder(ComponentHandle<Transform>* parent, const PCSNode* node, Skeleton* skeleton)
{
	PCSNode* sibling = GetLastSibling(node->GetChild());

	while (sibling != nullptr)
	{
		ComponentHandle<Transform>* transformNode = this->GetTransformSystem()->CreateTransform(Vect(0.0f, 0.0f, 0.0f, 1.0f), Quat(), Vect(1.0f, 1.0f, 1.0f), parent);
		FbxBone* bone = (FbxBone*)sibling;
		skeleton->AddBone(transformNode, bone->name);

		SkeletonBuilder(transformNode, sibling, skeleton);
		sibling = sibling->GetPrevSibling();
	}
}

ComponentHandle<Skeleton>* SkeletalSystem::CreateSkeleton(SkeletonType* type, ComponentHandle<Transform>* parent /*= nullptr*/)
{
	const PCSNode* root = type->GetRoot();
	Skeleton skeleton(type->NumBones());

	SkeletonBuilder(parent, root, &skeleton);

	return skeletonFactory.CreateComponent(skeleton);
}

void SkeletalSystem::Reload()
{
	//nothing to reload
}

namespace
{
	Vect ExtractPosition(const Matrix& world)
	{
		return world.GetRow(ROW_3);
	}

	//rewrote this rather than using the in-built Vect::Normalize()
	//because we already know the magnitude
	Vect Normalize(const Vect& vector, float magnitude)
	{
		Vect normalized;
		if (magnitude > 0.0f) 
		{
			normalized = vector * (1 / magnitude);
		}

		return normalized;
	}
}

//This is a weird operation used to modify each bone transform so that the graphical 
//representation of the bone will be large enough to stretch from one joint to another.
//This alters the world transform of each bone purely for visualization purposes.
//It must be run after the transform systems corresponding to each skeleton.
void SkeletalSystem::Run(float /*time*/)
{
	Array<Skeleton> skeletons = skeletonFactory.GetComponents();
	for (auto& skeleton : skeletons)
	{
		//I start the loop at 1 since the first bone points to a parent that is
		//not part of the animation (i.e. (0,0,0)) and will not move along with
		//the rest of skeleton, creating a stretchy root bone.
		for (int i = 0; i < skeleton.GetNumBones(); i++)
		{
			ComponentHandle<Transform>* transform = skeleton.GetBoneTransform(i);
			const ComponentHandle<Transform>* parent = transform->GetParent();

			Vect myPos = ExtractPosition((*transform)->GetGlobalWorld());
			Vect parentPos = ExtractPosition((*parent)->GetGlobalWorld());
			Vect distance = parentPos - myPos;

			//scale each bone be long enough to reach parent.
			float mag = distance.Magnitude();
			Vect scale(mag, mag, mag);

			//rotate each bone to point towards its parent
			Vect dir = Normalize(distance, mag);
			Matrix rot(ROT_ORIENT, dir, Vect(0.0f, 1.0f, 0.0f));
			
			(*transform)->SetGlobalWorld(Matrix(WORLD, scale, rot, myPos));
		}
	}
}

void SkeletalSystem::Clean()
{
	skeletonFactory.CleanUp();
}

TransformSystem* SkeletalSystem::GetTransformSystem() const
{
	return transforms;
}

void SkeletalSystem::SetTransformSystem(TransformSystem* val)
{
	transforms = val;
}
