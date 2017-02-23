#include "Assert.h"

#include "CameraMan.h"
#include "List\LinkedIterator.h"

int CameraMan::cameraID = 0;

CameraMan::CameraMan()
	: cameras(), it(cameras), activeCam(nullptr)
{
}

CameraMan::~CameraMan()
{
	LinkedIterator it = cameras.GetIterator();

	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		delete link;
	}
}

Camera* CameraMan::CreateCamera()
{
	Camera* camera = new Camera(cameraID++);
	Add(camera);
	return camera;
}

CameraMan* CameraMan::GetInstance()
{
	static CameraMan cameraMan;
	return &cameraMan;
}

Camera* CameraMan::CycleCamera()
{
	CameraMan* man = CameraMan::GetInstance();

	man->activeCam = (Camera*)man->it.Next(); 

	if (man->it.IsDone())
	{
		man->activeCam = (Camera*)man->it.First();
	}

	return man->activeCam;
}

void CameraMan::Add(Camera* camera)
{
	CameraMan* man = CameraMan::GetInstance();

	man->cameras.PushBack(camera);
	man->it = man->cameras.GetIterator();
	man->activeCam = (Camera*)man->it.First();
}

void CameraMan::Remove(Camera* camera)
{
	CameraMan* man = CameraMan::GetInstance();
	man->cameras.Remove(camera);
	delete camera;
}

void CameraMan::Draw(void)
{
}

void CameraMan::Update(float currentTime)
{
	currentTime;
	CameraMan* man = CameraMan::GetInstance();
	if (man->activeCam != nullptr)
	{
		man->activeCam->Update();
	}
}

Camera* CameraMan::GetActive()
{
	CameraMan* man = CameraMan::GetInstance();
	return man->activeCam;
}

void CameraMan::SetActive(Camera* camera)
{
	CameraMan* man = CameraMan::GetInstance();
	man->activeCam = camera;

	Camera* match = nullptr;

	do
	{
		match = CycleCamera();
	} while (match->GetId() != camera->GetId());
}
