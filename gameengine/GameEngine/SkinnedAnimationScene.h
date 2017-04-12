#pragma once

#include "Scene.h"
#include "Array\Array.h"
#include <memory>

class SystemBase;
class SkeletalSystem;

//A scene showing off skinned animation of the teddy and humanoid rigs/meshes
class SkinnedAnimationScene : public Scene
{
public:
	SkinnedAnimationScene(int width, int height);
	
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

private:

	Array<std::unique_ptr<SystemBase>> systems;
	std::unique_ptr<SkeletalSystem> skeletalSystem;
};