#pragma once

#include "Scene.h"
#include "GraphicsObject.h"
#include <memory>
#include "EntitySystem.h"
#include "TransformSystem.h"
#include "GraphicsSystem.h"

class GameObject;
class GraphicsObject;
class Model;
class SystemBase;

//showing off some textured models over a couple different cameras
class ModelViewerScene : public Scene
{
public:
	ModelViewerScene(int width, int height);
	void Update() override;
	void Draw() override;
	void Clean() override;

private:

	std::unique_ptr<TransformSystem> transformSystem;
	std::unique_ptr<GraphicsSystem> graphicsSystem;
	std::unique_ptr<EntitySystem> entitySystem;
};
