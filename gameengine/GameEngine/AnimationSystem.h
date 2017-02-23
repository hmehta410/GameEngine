#pragma once

#include "System.h"
#include "ComponentFactory.h"
#include "ComponentHandle.h"
#include "Time/Time.h"
#include "Animation.h"

/*
AnimationSystem creates ComponentHandle<Animation> and passes them out. It runs by
interpolating between two keyframes from a clip in each Animation. It then outputs
the interpolated keyframe into the skeleton of the Animation.
*/
class AnimationSystem : public System
{
public:

	template <typename... Args>
	ComponentHandle<Animation>* CreateAnimation(Args&&... args)
	{
		return animationFactory.CreateComponent(args...);
	}

	//maybe some other params like transition time, etc
	ComponentHandle<Animation>* Blend( ComponentHandle<Animation>* animationA,
		ComponentHandle<Animation>* animationB); 

	virtual void Reload() override;
	virtual void Run(float time) override;

	virtual void Clean() override;

private: //functions
	void Run(Animation& animation, Time deltaTime);

private: //variables
	ComponentFactory<Animation> animationFactory;
};