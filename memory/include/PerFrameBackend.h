#pragma once 
#include "..\Memory\LinkedList.h"

namespace mem
{
	class PerFrameBackend : public Link
	{
	public:
		PerFrameBackend(void* memory, int sizeInBytes);
		PerFrameBackend(PerFrameBackend&) = delete;
		PerFrameBackend& operator=(PerFrameBackend&) = delete;

		void* Malloc(int aSize, int alignment);
		void* ContiguousMalloc(int aSize);
		void Clear(); //we don't need to use it.

		int RemainingSpace();
	private:
		char* memoryStack;
		int size;
		int index;
	};
}