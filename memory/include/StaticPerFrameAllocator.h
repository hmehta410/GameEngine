#pragma once
#include "LockedHeapBackend.h"
#include "PerFrameBackend.h"

namespace mem
{
	class StaticPerFrameAllocator
	{
		typedef LockedHeapBackend Backend;
		typedef PerFrameBackend Allocator;

	public:
		static const int kLocalAllocatorSize = (1 << 21) - sizeof(Allocator) - __alignof(Allocator); //2 MB

		static void Initialize(Backend* back);

		static void ThreadLocalInitialize();

		static void* Allocate(int sizeInBytes, int alignment);

		static void* ContiguousAllocate(int sizeInBytes);
		
		static void Deallocate(void* p);

		static void ThreadLocalRestart();

		static const LinkedList* GetAllocatorList();

	private:
		StaticPerFrameAllocator();

		static Allocator* NewAllocator(int size);
		static void ReSortTopAllocator(Allocator* top);

		static Backend* backend;
		static Allocator empty; 
		__declspec(thread) static LinkedList* allocators; 
	};
}