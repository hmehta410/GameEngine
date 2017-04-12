#include "SkinnedAnimationScene.h"
#include "SystemBase.h"
#include "GraphicsSystem.h"
#include "Camera.h"
#include "CameraMan.h"
#include "SkinShaderGraphicsObject.h"
#include "TransformSystem.h"
#include "EntitySystem.h"
#include "SkeletalSystem.h"
#include "AnimationSystem.h"
#include "ModelMan.h"
#include "Entity.h"
#include "AnimationClipMan.h"
#include "LightSource.h"
#include "CameraControls.h"
#include "GridGraphicsObject.h"

SkinnedAnimationScene::SkinnedAnimationScene(int width, int height)
{
	static const float PI = 3.14159265359f;
	Camera* pCam1 = CameraMan::CreateCamera();
	pCam1->SetViewport(0, 0, width, height);
	pCam1->SetPerspective(35.0f, float(pCam1->GetScreenWidth()) / float(pCam1->GetScreenHeight()), 1.0f, 10000.0f);
	pCam1->SetOrientAndPosition(Vect(0.0f, 1.0f, 0.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f, 1.0f), Vect(0.0f, 15.0f, 40.0f, 1.0f));
	pCam1->Update();

	//Load Meshes
	Model* humanModel = ModelMan::LoadMesh("models/human.mesh");
	Model* teddyModel = ModelMan::LoadMesh("models/teddy.mesh");

	//Load Skeletons
	SkeletonType* humanType = SkeletonMan::LoadSkeleton("models/humanoid.skel");
	SkeletonType* teddyType = SkeletonMan::LoadSkeleton("Models/teddy.skel");

	InverseBindPose* humanInvPose = SkeletonMan::LoadInverseSkeleton("models/human.invbindpose");
	InverseBindPose* teddyInvPose = SkeletonMan::LoadInverseSkeleton("models/teddy.invbindpose");

	//Load Animations
	//teddy animations
	AnimationClip* teddyIdle = AnimationClipMan::LoadClip("Animations/idle.anim");
	AnimationClip* teddyWalk = AnimationClipMan::LoadClip("Animations/walk.anim");

	//humanoid animations
	AnimationClip* humanRun = AnimationClipMan::LoadClip("Animations/run.anim");
	AnimationClip* humanShot = AnimationClipMan::LoadClip("Animations/shot.anim");
	AnimationClip* humanPunch = AnimationClipMan::LoadClip("Animations/punch.anim");



	//Create the Various Systems
	TransformSystem* transformSystem = new TransformSystem();
	AnimationSystem* animationSystem = new AnimationSystem();
	EntitySystem* entitySystem = new EntitySystem();
	GraphicsSystem* graphicsSystem = new GraphicsSystem();
	skeletalSystem.reset(new SkeletalSystem(transformSystem));

	systems.EmplaceBack(transformSystem);
	systems.EmplaceBack(animationSystem);
	systems.EmplaceBack(entitySystem);
	systems.EmplaceBack(graphicsSystem);



	//Create a factory for SkinShaderGraphicsObject and add it to the Graphics System
	//the SkinShader is where all the magic happens
	ComponentFactory<SkinShaderGraphicsObject>* skinningFactory = new ComponentFactory<SkinShaderGraphicsObject>();
	graphicsSystem->AddFactory(std::unique_ptr<GraphicsFactory>(skinningFactory));

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
		LightSource light(Vect(0.0f, 1.0f, 0.0f, 1.0f), Vect(1.0f, 1.0f, 1.0f));
		float scale = 0.1f;
		ComponentHandle<Transform>* transform = transformSystem->CreateTransform(pos, rot, Vect(scale, scale, scale));
		ComponentHandle<Skeleton>* skeleton = skeletalSystem->CreateSkeleton(humanType, transform);
		ComponentHandle<Animation>* animation = animationSystem->CreateAnimation(clip, skeleton);
		(*animation)->SetTimeScale(0.9f);
		ComponentHandle<SkinShaderGraphicsObject>* graphicsObject = skinningFactory->CreateGraphicsObject(humanModel, transform, color, light, humanInvPose, skeleton);

		Entity* human = entitySystem->CreateEntity();
		human->AddComponent(transform);
		human->AddComponent(skeleton);
		human->AddComponent(animation);
		human->AddComponent(graphicsObject);
	};

	auto CreateTeddyAnimation = [&](AnimationClip* clip, const Vect& pos, const Quat& rot, const Vect& color)
	{
		LightSource light(Vect(0.0f, 1.0f, 0.0f, 1.0f), Vect(1.0f, 1.0f, 1.0f));
		float scale = 0.75f;
		ComponentHandle<Transform>* transform = transformSystem->CreateTransform(pos, rot, Vect(scale, scale, scale));
		ComponentHandle<Skeleton>* skeleton = skeletalSystem->CreateSkeleton(teddyType, transform);
		ComponentHandle<Animation>* animation = animationSystem->CreateAnimation(clip, skeleton);
		ComponentHandle<SkinShaderGraphicsObject>* graphicsObject = skinningFactory->CreateGraphicsObject(teddyModel, transform, color, light, teddyInvPose, skeleton);

		(*animation)->SetTimeScale(0.9f);

		//I lock root position because the teddy animations have the root moving all over the place
		auto rootTransform = (*skeleton)->GetBoneTransform(1);
		(*rootTransform)->LockPosition(true);

		Entity* teddy = entitySystem->CreateEntity();
		teddy->AddComponent(transform);
		teddy->AddComponent(skeleton);
		teddy->AddComponent(animation);
		teddy->AddComponent(graphicsObject);
	};



	//human running
	Vect pos(0, 0.6f, -10, 1);
	Quat rot = Quat(RotType::ROT_X, -PI / 4); 
	Vect color(1.0f, 0.3f, 0.3f);
	CreateHumanAnimation(humanRun, pos, rot, color);

	//human punch
	pos = Vect(5, 0.6f, -8, 1); 
	color = Vect(0, 1, 0);
	CreateHumanAnimation(humanPunch, pos, rot, color);

	//human shot
	pos = Vect(-7, 0.6f, -8, 1);
	color = Vect(0, 0, 1);
	CreateHumanAnimation(humanShot, pos, rot, color);

	//teddy idle
	pos = Vect(10, 5.7f, -1.0f, 1);	
	color = Vect(1, 1, 0);
	rot = Quat(RotType::ROT_Y, -PI / 2) * Quat(RotType::ROT_Z, -PI / 4) * Quat(RotType::ROT_X, PI / 4);
	CreateTeddyAnimation(teddyIdle, pos, rot, color);

	//teddy walk
	pos = Vect(5, 5.7f, -10.0f, 1);
	color = Vect(0, 1, 1);
	rot = Quat(RotType::ROT_Y, -PI / 2) * Quat(RotType::ROT_Z, -PI / 4) * Quat(RotType::ROT_X, PI / 4);
	CreateTeddyAnimation(teddyWalk, pos, rot, color);
}

void SkinnedAnimationScene::Update()
{
	UpdateCameraControls();

	for (auto& system : systems)
	{
		system->Run();
	}
}

void SkinnedAnimationScene::Draw()
{
}

void SkinnedAnimationScene::Clean()
{
	for (auto& system : systems)
	{
		system->Clean();
	}
	skeletalSystem->Clean();
}
