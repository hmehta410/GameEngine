#pragma once
#include "Engine.h"
#include "Scene.h"
#include <memory>

class Game : public Engine
{
public:
	Game(const char* windowName, int width, int height);

	virtual void Initialize() override;
	virtual void LoadContent() override;
	virtual void Update(float currentTime) override;
	virtual void Draw() override;
	virtual void Clean() override;
	virtual void UnloadContent() override;

	virtual void ClearBufferFunc() override;

	virtual void onResize(int w, int h) override;


private:
	std::unique_ptr<Scene> scene;
};

