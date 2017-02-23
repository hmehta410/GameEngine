#include "Animation.h"
#include "AnimationSystem.h"

Animation::Animation(AnimationClip* clip, ComponentHandle<Skeleton>* skeleton)
	: clip(clip), skeleton(skeleton), keyframeIndex(0), timeScale(1.0f)
{
}

void Animation::SetTimeScale(float scale)
{
	this->timeScale = scale;
}

void Animation::SetTime(const Time& time)
{
	this->localTime = time;
}

float Animation::GetTimeScale() const
{
	return this->timeScale;
}

Time Animation::GetTime() const
{
	return this->localTime;
}
