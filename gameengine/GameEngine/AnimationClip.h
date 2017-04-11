#ifndef ANIMATION_CLIP_H
#define ANIMATION_CLIP_H

#include "Keyframe.h"
#include "GL\glew.h"
#include "Array\Array.h"
#include "String\String.h"
#include "List\Link.h"

/*
An AnimationClip is the source for animations. It contains the keyframes used in
the Animation components. The same clip can be used in multiple Animation components
since they are never changed after being loaded.
*/
class AnimationClip : public DLink
{
public:
	AnimationClip(int numKeyframes, int numBones);

	AnimationClip(const AnimationClip& other) = delete;
	AnimationClip& operator=(const AnimationClip& other) = delete;

	int FindKeyframe(Time &time, int startKeyframe = 0);

//Data
	Array<Keyframe> keyframes;

	int numKeyframes;
	int numBones;
	String name;
}; 

#endif