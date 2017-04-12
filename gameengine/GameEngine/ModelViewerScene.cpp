#include "ModelViewerScene.h"

#include "Math\MathEngine.h"
#include "Game.h"
#include "ShaderObject.h"
#include "GraphicsObject.h"
#include "FlatTextureGraphicsObject.h"
#include "TextureManager.h"
#include "InputMan.h"
#include "Camera.h"
#include "CameraMan.h"
#include "ShaderMan.h"
#include "GraphicsSystem.h"
#include "TransformSystem.h"
#include "CameraControls.h"
#include "SolidShadeGraphicsObject.h"
#include "ModelMan.h"
#include "Entity.h"
#include <memory>
#include "GridGraphicsObject.h"

ModelViewerScene::ModelViewerScene(int width, int height)
{
	const float PI = 3.14159265359f;
	//create 4 cameras
	Camera* camera1 = CameraMan::CreateCamera();
	camera1->SetViewport(0, 0, width, height);
	camera1->SetPerspective(35.0f, float(camera1->GetScreenWidth()) / float(camera1->GetScreenHeight()), 4.0f, 10000.0f);
	camera1->SetOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f, 1.0f), Vect(0.0f, 5.0f, 8.0f, 1.0f));
	camera1->Update();

	Camera* camera2 = CameraMan::CreateCamera();
	camera2->SetViewport(0, 0, width, height);
	camera2->SetPerspective(35.0f, float(camera2->GetScreenWidth()) / float(camera2->GetScreenHeight()), 4.0f, 1000.0f);
	camera2->SetOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(10.0f, 0.0f, 0.0f, 1.0f), Vect(10.0f, 5.0f, 8.0f, 1.0f));
	camera2->Update();

	Camera* camera3 = CameraMan::CreateCamera();
	camera3->SetViewport(0, 0, width, height);
	camera3->SetPerspective(35.0f, float(camera3->GetScreenWidth()) / float(camera3->GetScreenHeight()), 4.0f, 1000.0f);
	camera3->SetOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(20.0f, 0.0f, 0.0f, 1.0f), Vect(20.0f, 5.0f, 8.0f, 1.0f));
	camera3->Update();

	Camera* camera4 = CameraMan::CreateCamera();
	camera4->SetViewport(0, 0, width, height);
	camera4->SetPerspective(35.0f, float(camera4->GetScreenWidth()) / float(camera4->GetScreenHeight()), 4.0f, 1000.0f);
	camera4->SetOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(30.0f, 0.0f, 0.0f, 1.0f), Vect(40.0f, 2.0f, 3.0f, 1.0f));
	camera4->Update();

	CameraMan::SetActive(camera1);


	//create systems
	transformSystem.reset(new TransformSystem());
	graphicsSystem.reset(new GraphicsSystem());
	entitySystem.reset(new EntitySystem());



	//Load models and textures
	Model* astroboyModel = ModelMan::LoadMesh("Models/Astroboy.mesh");
	Model* buggyModel = ModelMan::LoadMesh("Models/Buggy.mesh");
	Model* spaceFrigateModel = ModelMan::LoadMesh("Models/SpaceFrigate.mesh");
	Model* warbearModel = ModelMan::LoadMesh("Models/Warbear.mesh");

	Texture* astroboyTex = TextureMan::LoadTexture("Textures/Astroboy.tga");
	Texture* buggyTex = TextureMan::LoadTexture("Textures/Buggy.tga");
	Texture* spaceFrigateTex = TextureMan::LoadTexture("Textures/SpaceFrigate.tga");
	Texture* warbearTex = TextureMan::LoadTexture("Textures/Warbear.tga");

	ComponentFactory<FlatTextureGraphicsObject>* textureFactory = new ComponentFactory<FlatTextureGraphicsObject>();
	graphicsSystem->AddFactory(std::unique_ptr<GraphicsFactory>(textureFactory));

	//Made this a lambda to take advantage of capture semantics instead of passing 
	//in all the necessary setup objects
	auto CreateTexturedModel = [&](Model* model, Texture* texture, float scale, const Vect& pos, const Quat& rot)
	{
		ComponentHandle<Transform>* transform = transformSystem->CreateTransform(pos, rot, Vect(scale, scale, scale));
		ComponentHandle<FlatTextureGraphicsObject>* textureGrahpicsObject = textureFactory->CreateGraphicsObject(model, transform, texture);

		Entity* entity = entitySystem->CreateEntity();
		entity->AddComponent(transform);
		entity->AddComponent(textureGrahpicsObject);
	};



	//Create models
	//space frigate
	float scale = 0.06f;
	Vect pos(0.0f, 0.0f, 0.0f, 1.0f);
	Quat rot(ROT_Y, PI/2);
	CreateTexturedModel(spaceFrigateModel, spaceFrigateTex, scale, pos, rot);

	//buggy
	scale = 0.008f;
	pos = Vect(20.0f, -1.0f, 0.0f, 1.0f);
	rot = Quat(ROT_Y, PI);
	CreateTexturedModel(buggyModel, buggyTex, scale, pos, rot);

	//astroboy
	scale = 0.03f;
	pos = Vect(10.0f, 0.0f, 0.0f, 1.0f);
	rot = Quat(ROT_X, -PI / 2);
	CreateTexturedModel(astroboyModel, astroboyTex, scale, pos, rot);

	//warbear
	scale = 0.02f;
	pos = Vect(30.0f, 0.0f, 0.0f, 1.0f);
	CreateTexturedModel(warbearModel, warbearTex, scale, pos, rot);
}

void ModelViewerScene::Update()
{
	UpdateCameraControls();

	transformSystem->Run();
	entitySystem->Run(); //not strictly necessary since it doesn't actually do anything

	Keyboard* board = InputMan::GetKeyboard();
	if (board->IsOnKeyRelease(KEY_C))
	{
		CameraMan::CycleCamera();
	}
}

void ModelViewerScene::Draw()
{
	graphicsSystem->Run();
}

void ModelViewerScene::Clean()
{
	transformSystem->Clean();
	graphicsSystem->Clean();
	entitySystem->Clean();
}

