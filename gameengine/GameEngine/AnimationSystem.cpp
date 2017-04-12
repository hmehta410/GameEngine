#include "AnimationSystem.h"
#include "Array\Array.h"
#include "Animation.h"
#include "Math\VectApp.h"
#include "Skeleton.h"
#include "ComponentHandle.h"
#include "Animation.h"
#include "Math\QuatApp.h"
#include "TimeMan.h"

void AnimationSystem::Run()
{
	Array<Animation>& components = animationFactory.GetComponents();
	for (Animation& animation : components)
	{
		this->Run(animation, TimerMan::GetDeltaTime());
	}
}

namespace
{
	void Interpolate(AnimationClip* clip, int frameA, float t, Skeleton& skeleton)
	{
		assert(t >= 0.0f && t < 1.0f);

		int frameB = frameA + 1;
		for (int i = 0; i < clip->numBones; i++)
		{
			KeyframeData &boneA = clip->keyframes[frameA].boneTransforms[i];
			KeyframeData &boneB = clip->keyframes[frameB].boneTransforms[i];

			//interpolate pos, scale, and rot
			Vect scale = VectApp::Lerp(boneA.scale, boneB.scale, t);
			Vect trans = VectApp::Lerp(boneA.translation, boneB.translation, t);
			Quat rot = QuatApp::Slerp( boneA.rotation, boneB.rotation, t);

			//copy over to skeleton. The +1 is to skip the root bone of the skeleton
			//tree. skeleton.numBones == clip.numBones + 1
			(*skeleton.GetBoneTransform(i+1))->SetScale(scale);
			(*skeleton.GetBoneTransform(i+1))->SetPosition(trans);
			(*skeleton.GetBoneTransform(i+1))->SetRotation(rot);
		}
	}
}

void AnimationSystem::Run(Animation& animation, Time deltaTime)
{
	//scale the time and add it to the current running time.
	animation.localTime += deltaTime * animation.timeScale;

	//find the two keyframes based on the time
	animation.keyframeIndex = animation.clip->FindKeyframe(animation.localTime, animation.keyframeIndex);

	//calculate the ratio to find the amount to interpolate between the two frames
	Time frame0 = animation.clip->keyframes[animation.keyframeIndex].time;
	Time frame1 = animation.clip->keyframes[animation.keyframeIndex + 1].time;
	float deltaT = ((animation.localTime - frame0)) /
		((frame1 - frame0));

	Interpolate(animation.clip, animation.keyframeIndex, deltaT, *animation.skeleton->GetValue());
}

void AnimationSystem::Clean()
{
	this->animationFactory.CleanUp();
}

void AnimationSystem::Reload()
{

}