#pragma once
#include "..\Memory\LinkedList.h"

namespace mem
{
	class HeapBackend : public Link
	{
	public:
		HeapBackend(void* memory, int sizeInBytes);
		HeapBackend(HeapBackend&) = delete;
		HeapBackend& operator=(HeapBackend&) = delete;

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