#pragma once
#include "HeapBackend.h"
#include <mutex>

namespace mem
{
	class LockedHeapBackend
	{
	public:
		LockedHeapBackend(void* memory, int sizeInBytes) : backend(memory, sizeInBytes)
		{}

		LockedHeapBackend(LockedHeapBackend&) = delete;
		LockedHeapBackend& operator=(LockedHeapBackend&) = delete;

		void* Calloc(int aSize, int alignment)
		{
			std::lock_guard<std::mutex> lg(mtx);
			return backend.Calloc(aSize, alignment);
		}

		void* Malloc(int aSize, int alignment)
		{
			std::lock_guard<std::mutex> lg(mtx);
			return backend.Malloc(aSize, alignment);
		}

		void Dealloc(void* ptr)
		{
			std::lock_guard<std::mutex> lg(mtx);
			return backend.Dealloc(ptr);
		}

		char* GetMemoryPool()
		{
			return backend.GetMemoryPool();
		}

		int LargestSpace()
		{
			return backend.GetFirstSpace();
		}

	private:
		HeapBackend backend;
		std::mutex mtx;
	};
}