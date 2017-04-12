#include "BoneAnimationScene.h"

#include <assert.h>
#include "File\File.h"
#include "SkeletonMan.h"
#include "TextureManager.h"
#include "Camera.h"
#include "CameraMan.h"
#include "InputMan.h"
#include "AnimationClip.h"
#include "Time.h"
#include "CameraControls.h"
#include "TransformSystem.h"
#include "SkeletalSystem.h"
#include "AnimationSystem.h"
#include "GraphicsSystem.h"
#include "SolidShadeGraphicsObject.h"
#include "EntitySystem.h"
#include "Entity.h"
#include "LightSource.h"
#include "AnimationClipMan.h"
#include "ModelMan.h"
#include "GridGraphicsObject.h"

namespace
{
	//create the graphical component for each bone in the skeleton
	void CreateGraphicalSkeletonRepresentation(ComponentHandle<Skeleton>* skeleton, ComponentFactory<SolidShadeGraphicsObject>* factory, const Vect& color)
	{
		LightSource light(Vect(0.0f, 1.0f, 0.0f, 1.0f), Vect(1.0f, 1.0f, 1.0f));
		Model* boneModel = ModelMan::LoadMesh("Models/Bone.mesh"); //will return previously loaded mesh

		//we start at 2 so that we don't get a bone pointing to the 
		//root and the root's parent
		for (int i = 2; i < (*skeleton)->GetNumBones(); i++)
		{
			auto transform = (*skeleton)->GetBoneTransform(i);
			factory->CreateGraphicsObject(boneModel, transform, light, color);
		}
	}
}

BoneAnimationScene::BoneAnimationScene(int width, int height)
{
	const float PI = 3.14159265359f;
	Camera* pCam1 = CameraMan::CreateCamera();
	pCam1->SetViewport(0, 0, width, height);
	pCam1->SetPerspective(35.0f, float(pCam1->GetScreenWidth()) / float(pCam1->GetScreenHeight()), 1.0f, 10000.0f);
	pCam1->SetOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 5.0f, 0.0f, 1.0f), Vect(0.0f, 15.0f, 40.0f, 1.0f));
	pCam1->Update();

	//Load Meshes
	ModelMan::LoadMesh("Models/Bone.mesh");

	//Load SkeletonTypes
	SkeletonType* humanType = SkeletonMan::LoadSkeleton("Models/humanoid.skel");
	SkeletonType* teddyType = SkeletonMan::LoadSkeleton("Models/teddy.skel");

	//Load Animations
	//teddy animations
	AnimationClip* teddyIdle = AnimationClipMan::LoadClip("Animations/idle.anim");
	AnimationClip* teddyWalk = AnimationClipMan::LoadClip("Animations/walk.anim");

	//humanoid animations
	AnimationClip* humanRun = AnimationClipMan::LoadClip("Animations/run.anim");
	AnimationClip* humanShot = AnimationClipMan::LoadClip("Animations/shot.anim");
	AnimationClip* humanPunch = AnimationClipMan::LoadClip("Animations/punch.anim");



	//Create Various Systems Used
	TransformSystem* transformSystem = new TransformSystem();
	SkeletalSystem* skeletalSystem = new SkeletalSystem(transformSystem);
	AnimationSystem* animationSystem = new AnimationSystem();
	EntitySystem* entitySystem = new EntitySystem();
	this->graphicsSystem.reset(new GraphicsSystem());

	systems.EmplaceBack(transformSystem);
	systems.EmplaceBack(skeletalSystem);
	systems.EmplaceBack(animationSystem);
	systems.EmplaceBack(entitySystem);



	//Create a factory for SolidShadeGraphicsObject and add it to the Graphics System
	ComponentFactory<SolidShadeGraphicsObject>* solidShadeFactory = new ComponentFactory<SolidShadeGraphicsObject>();
	graphicsSystem->AddFactory(std::unique_ptr<GraphicsFactory>(solidShadeFactory));

	//Create a grid for easier visualization
	ComponentFactory<GridGraphicsObject>* gridFactory = new ComponentFactory<GridGraphicsObject>();
	graphicsSystem->AddFactory(std::unique_ptr<GraphicsFactory>(gridFactory));

	Model* grid = ModelMan::LoadGrid(50, 50);
	auto trans = transformSystem->CreateTransform();
	gridFactory->CreateGraphicsObject(grid, trans, Vect(1.0, 1.0, 1.0));



	//Created a lambda to help capture all of the variables already created without having
	//to pass them in again. The arguments are the only variables visibly changing from call to call
	auto CreateHumanAnimation = [&](AnimationClip* clip, const Vect& pos, const Quat& rot, const Vect& color)
	{
		const float scaleMag = 0.01f;
		Vect scale(scaleMag, scaleMag, scaleMag);

		//Creating useful components
		ComponentHandle<Transform>* humanTransform = transformSystem->CreateTransform(pos, rot, scale);
		ComponentHandle<Skeleton>* humanSkeleton = skeletalSystem->CreateSkeleton(humanType, humanTransform);

		CreateGraphicalSkeletonRepresentation(humanSkeleton, solidShadeFactory, color);

		ComponentHandle<Animation>* humanRunAnimation = animationSystem->CreateAnimation(clip, humanSkeleton);

		Entity* human = entitySystem->CreateEntity();
		human->AddComponent(humanTransform);
		human->AddComponent(humanSkeleton);
		human->AddComponent(humanRunAnimation);
		human->GetComponentHandle<Animation>();
	};

	//Created a teddy version that is very similar just with all the variables named teddy.
	auto CreateTeddyAnimation = [&](AnimationClip* clip, const Vect& pos, const Quat& rot, const Vect& color)
	{
		const float scaleMag = 1.0f;
		Vect scale(scaleMag, scaleMag, scaleMag);

		ComponentHandle<Transform>* teddyTransform = transformSystem->CreateTransform(pos, rot, scale);
		ComponentHandle<Skeleton>* teddySkeleton = skeletalSystem->CreateSkeleton(teddyType, teddyTransform);

		//I lock root position because the teddy animations have the root moving all over the place
		auto rootTransform = (*teddySkeleton)->GetBoneTransform(1);
		(*rootTransform)->LockPosition(true);

		CreateGraphicalSkeletonRepresentation(teddySkeleton, solidShadeFactory, color);

		ComponentHandle<Animation>* teddyIdleAnimation = animationSystem->CreateAnimation(clip, teddySkeleton);

		Entity* teddy = entitySystem->CreateEntity();
		teddy->AddComponent(teddyTransform);
		teddy->AddComponent(teddySkeleton);
		teddy->AddComponent(teddyIdleAnimation);
	};



	//human running
	Vect pos(0, 0, -10, 1);
	Quat rot = Quat(RotType::ROT_Z, PI / 2) * Quat(RotType::ROT_X, -PI / 2);
	Vect color(1.0f, 0.3f, 0.3f);
	CreateHumanAnimation(humanRun, pos, rot, color);

	//human shot
	pos = Vect(0, 0, 0, 1);
	rot *= Quat(RotType::ROT_Y, -PI / 2);
	color = Vect(0, 0, 1);
	CreateHumanAnimation(humanShot, pos, rot, color);

	//human punch
	pos = Vect(-10, 0, 0, 1);
	color = Vect(0, 1, 0);
	CreateHumanAnimation(humanPunch, pos, rot, color);

	//teddy idle
	pos = Vect(5.0f, 2.5f, 0.0f, 1.0f);
	rot = Quat(RotType::ROT_Z, PI / 2) * Quat(RotType::ROT_X, -PI / 2) * Quat(RotType::ROT_Y, PI);
	color = Vect(1, 1, 0);
	CreateTeddyAnimation(teddyIdle, pos, rot, color);

	//teddy walk
	pos = Vect(13.0f, 2.5f, 0.0f, 1.0f);
	color = Vect(0, 1, 1);
	CreateTeddyAnimation(teddyWalk, pos, rot, color);
}

void BoneAnimationScene::Update()
{
	UpdateCameraControls();

	for (auto& system : this->systems)
	{
		system->Run();
	}
}

void BoneAnimationScene::Draw()
{
	graphicsSystem->Run();
}

void BoneAnimationScene::Clean()
{
	for (auto& system : this->systems)
	{
		system->Clean();
	}

	graphicsSystem->Clean();
}
