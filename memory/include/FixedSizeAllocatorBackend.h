#pragma once

namespace mem
{
	class FixedSizeAllocatorBackend
	{
	public:
		FixedSizeAllocatorBackend(void* memory, int sizeInBytes);
		FixedSizeAllocatorBackend(FixedSizeAllocatorBackend&) = delete;
		FixedSizeAllocatorBackend& operator=(FixedSizeAllocatorBackend&) = delete;

		void* Calloc(int aSize, int alignment);
		void* Malloc(int aSize, int alignment);
		void Dealloc(void* ptr);

		char* GetMemoryPool();

		int GetFirstSpace();

	private:
		LinkedList freeList;
		void* memoryPool;
		void* endAddress;
	};
}