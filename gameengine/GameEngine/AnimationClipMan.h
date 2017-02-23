#pragma once

#include "AnimationClip.h"
#include "List\DList.h"
#include <memory>

/*
AnimationClipMan is used to load and manage AnimationClips.
*/
class AnimationClipMan
{
public:
	~AnimationClipMan();

	static AnimationClip* LoadClip(const char* fileName);

private:
	AnimationClipMan();
	static AnimationClipMan* GetInstance();

	std::unique_ptr<AnimationClip> privLoadAnimationClip(const char* fileName);

	DList animationClips; //type animation clip.
};
