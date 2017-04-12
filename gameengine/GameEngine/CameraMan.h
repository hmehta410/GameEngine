#ifndef SUPER_CAMERA_MAN_H
#define SUPER_CAMERA_MAN_H

#include "List\DList.h"
#include "Camera.h"
#include "List\LinkedIterator.h"

/*
This class is a look back from my first college game engine course where things where 
largely handled by Singleton Managers. I never got around to switching Cameras over to an 
Entity-Component-System style. That's not to say this was a bad piece of design, 
just a different one...
*/

class CameraMan
{
public:
	~CameraMan();

	static Camera* CreateCamera();
	static void Remove(Camera* camera);
	static void Draw(void);
	static void Update();
	static Camera* CycleCamera();
	static Camera* GetActive();
	static void SetActive(Camera* camera);

private:
	CameraMan();
	static CameraMan* GetInstance();
	static void Add(Camera* camera);
	static int cameraID;

	DList<Camera> cameras; //typename Camera
	ForwardIterator<Camera> it;

	Camera* activeCam;
};

#endif