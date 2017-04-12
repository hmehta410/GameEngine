#ifndef BONE_AIMATION_SCENE_H
#define BONE_AIMATION_SCENE_H

#include "Scene.h"
#include "Time\Timer.h"
#include "Array\Array.h"
#include "SystemBase.h"
#include <memory>

class AnimationClip;
class BoneGameObject;
class GraphicsSystem;

//showing animation of a humanoid and teddy skeleton bone by bone.
class BoneAnimationScene : public Scene
{
public:
	BoneAnimationScene(int width, int height);

	void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

private:
	AnimationClip* loadAnimationClip(const char* file, const char* skeletonName);

	Array<std::unique_ptr<SystemBase>> systems;
	std::unique_ptr<GraphicsSystem> graphicsSystem; 
};

#endif BONE_AIMATION_SCENE_H