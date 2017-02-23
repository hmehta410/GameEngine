#pragma once

#include "Scene.h"
#include "Array\Array.h"
#include <memory>

class System;
class SkeletalSystem;

//A scene showing off skinned animation of the teddy and humanoid rigs/meshes
class SkinnedAnimationScene : public Scene
{
public:
	SkinnedAnimationScene(int width, int height);
	
	virtual void Update(float time) override;
	virtual void Draw(float time) override;
	virtual void Clean() override;

private:

	Array<std::unique_ptr<System>> systems;
	std::unique_ptr<SkeletalSystem> skeletalSystem;
};