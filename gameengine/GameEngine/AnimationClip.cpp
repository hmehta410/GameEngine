#include "AnimationClip.h"

AnimationClip::AnimationClip(int numKeyframes, int numBones)
	: keyframes(numKeyframes, Keyframe(numBones)), numKeyframes(numKeyframes), numBones(numBones)
{
}

//there is an infinite loop so that if there was an animation that lasted 1 second.
//and our Time time == 10000 seconds we could eventually find our way back to the
//correct frame one step at a time.
int AnimationClip::FindKeyframe(Time &time, int startKeyframe)
{
	//if there are 80 keyframes then numFrames == 78; keyframes[78] < time < keyframes[79]
	//we are always between frame i and i+1
	//if i = lastframe (i.e. 79) than i+1 (i.e. 80) will be out of bounds
	int lastValidFrame = this->numKeyframes - 2;
	int index = startKeyframe; //startKeyframe equals best guess

#pragma warning(suppress: 4127)
	while (true)
	{
		//if(time is greater or equal to current frames time)
		if (time >= keyframes[index].time)
		{
			//then check
			//if(we are on the last valid frame)
			if (index == lastValidFrame)
			{
				//then jump back to the beginning
				time -= keyframes[index].time;
				index = 0;
			}
			//or if(we are past the next frame's time) 
			else if (time >= keyframes[index + 1].time)
			{
				//then increase our frame index by 1 and start loop again
				index++;
			}
			else //time is inbetween keyframes[i] and keyframes[i+1]
			{
				//base case. 
				return index;
			}
		}
		else //time is less than current frame. (our animation may be going in reverse)
		{
			//if(we are at the first frame)
			if (index == 0)
			{
				//jump to the end
				time += keyframes[lastValidFrame].time;
				index = lastValidFrame;
			}
			else //decrease our frame index by 1 and start loop again
			{
				index--;
			}
		}
	}
}