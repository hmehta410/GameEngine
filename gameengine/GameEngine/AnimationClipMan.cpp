#include "AnimationClipMan.h"
#include "File\File.h"
#include <assert.h>

AnimationClipMan::AnimationClipMan()
{
}

AnimationClipMan* AnimationClipMan::GetInstance()
{
	static AnimationClipMan man;
	return &man;
}

AnimationClipMan::~AnimationClipMan()
{
	animationClips.DeleteList();
}

AnimationClip* AnimationClipMan::LoadClip(const char* fileName)
{
	//search to see if animation clip was previously loaded
	AnimationClipMan* man = GetInstance();
	LinkedIterator it = man->animationClips.GetIterator();
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		AnimationClip* clip = (AnimationClip*)link;
		if (clip->name == fileName)
		{
			return clip;
		}
	}

	//if not then load it
	AnimationClip* clip = man->privLoadAnimationClip(fileName).release();
	man->animationClips.PushBack(clip);
	return clip;
}

namespace
{
	struct AnimationHeader
	{
		static const int kAnimationNameLength = 32;
		static const int kBoneNameLength = 32;
		char name[kAnimationNameLength];
		int numKeyframes;
		int numBones;
	};

	//returns a unique_ptr because AnimationClip is dynamically allocated and has no owner
	std::unique_ptr<AnimationClip> DigestAnimation(const char* fileBuffer, const char* fileName)
	{
		const char *buffer = fileBuffer;

		//cast buffer to header
		AnimationHeader header;
		memcpy(&header, buffer, sizeof(AnimationHeader));
		buffer += sizeof(AnimationHeader);

		//create clip
		std::unique_ptr<AnimationClip> clip(new AnimationClip(header.numKeyframes, header.numBones));
		clip->name = fileName;
		
		//skip the boneHierarchy names. It is currently unused but can be added 
		//to AnimationClip as an extra field if desired
		const char *boneHierarchy = buffer;
		buffer += AnimationHeader::kBoneNameLength * clip->numBones;
		boneHierarchy;

		//keyframes are stored by all translations, followed by all rotations, 
		//followed by all scales with the intention of making it easier to load 
		//onto GPU-side buffers.
		for (int i = 0; i < clip->numKeyframes; i++)
		{
			Keyframe& keyframe = clip->keyframes[i];

			int timeInMs;
			memcpy(&timeInMs, buffer, sizeof(int));
			buffer += sizeof(int);
			keyframe.time = Time(Duration::TIME_ONE_MILLISECOND)*timeInMs;

			Vect* translations = (Vect*)(buffer);
			buffer += sizeof(Vect)*clip->numBones;

			Quat* rotations = (Quat*)(buffer);
			buffer += sizeof(Quat)*clip->numBones;

			Vect* scales = (Vect*)(buffer);
			buffer += sizeof(Vect)*clip->numBones;

			for (int j = 0; j < clip->numBones; j++)
			{
				keyframe.boneTransforms[j].translation = translations[j];
				keyframe.boneTransforms[j].rotation = rotations[j];
				scales[j].w() = 0; //for some reason scale.w tends to be 1...
				keyframe.boneTransforms[j].scale = scales[j];
			}
		}

		return clip;
	}
}

std::unique_ptr<AnimationClip> AnimationClipMan::privLoadAnimationClip(const char* fileName)
{
	File file(fileName, FileMode::READ);
	assert(file.GetError() == FileError::NONE);

	int fileSize = file.GetSize();
	std::unique_ptr<char[]> animationBuffer(new char[fileSize]);

	file.Read(animationBuffer.get(), fileSize);
	std::unique_ptr<AnimationClip> clip = DigestAnimation(animationBuffer.get(), fileName);

	return clip;
}

