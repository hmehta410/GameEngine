#pragma once

#include "Component.h"
#include "Time/Time.h"
#include "AnimationClip.h"
#include "ComponentHandle.h"

//forward declare
class AnimationSystem;
class Skeleton;

/*
An animation takes an animation clip and interpolates between two of it's keyframes.
The result is then outputted into the associated skeleton effectively animating it's bones
*/
class Animation : public Component
{
public:
	Animation(AnimationClip* clip, ComponentHandle<Skeleton>* skeleton);

	void SetTimeScale(float scale);
	void SetTime(const Time& time);

	float GetTimeScale() const;
	Time GetTime() const;

private:
	Time localTime; //time in the current animation loop
	AnimationClip* clip;
	ComponentHandle<Skeleton>* skeleton;

	//if last animation was between frame0 and frame1 then keyframeIndex == frame0
	int keyframeIndex;
	float timeScale;

	friend class AnimationSystem;
};