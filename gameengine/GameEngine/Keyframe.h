#ifndef KEYFRAME_H
#define KEYFRAME_H

#include "Time\Time.h"
#include "KeyframeData.h"
#include "Array\Array.h"

//a keyframe holds a snapshot of each position of a bone during an animation
class Keyframe
{
public:
	Keyframe(){};
	Keyframe(int numBones) : boneTransforms(numBones) {};

	Time time;
	Array<KeyframeData> boneTransforms; //an array of bone transforms
};

#endif