#include "..\include\PerFrameBackend.h"
#include "..\include\Util.h"
#include <memory.h>

namespace mem
{
	PerFrameBackend::PerFrameBackend(void* memory, int sizeInBytes)
		: memoryStack((char*)memory), size(sizeInBytes), index(0)
	{
	}

	void* PerFrameBackend::Malloc(int aSize, int alignment)
	{
		if (aSize + alignment > RemainingSpace())
		{
			return nullptr;
		}

		char* unalignedPtr = &memoryStack[index];
		char* alignedPtr = (char*)mem_util::Align(unalignedPtr, alignment);

		index += alignedPtr - unalignedPtr + aSize;
		return alignedPtr;
	}

	void* PerFrameBackend::ContiguousMalloc(int aSize)
	{
		if (aSize > RemainingSpace())
		{
			return nullptr;
		}

		int i = index;
		index += aSize;
		return &memoryStack[i];
	}

	void PerFrameBackend::Clear()
	{
		index = 0;
	}

	int PerFrameBackend::RemainingSpace()
	{
		return size - index;
	}

}

