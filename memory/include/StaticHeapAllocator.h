#pragma once
#include "LockedHeapBackend.h"
#include "HeapBackend.h"

namespace mem
{
	//I couldn't think of a way to safely prevent any threading collisions
	//from deallocating from any thread even with thread-local allocations
	class StaticHeapAllocator
	{
		typedef LockedHeapBackend Backend;
		//typedef HeapBackend Allocator;
	public:
		static void Initialize(Backend* backend)
		{ 
			GetInstance()->PrivInitialize(backend); 
		}

		static void* Allocate(int sizeInBytes, int alignment)
		{ 
			return GetInstance()->PrivAllocate(sizeInBytes, alignment); 
		}

		static void Deallocate(void* p) 
		{ 
			GetInstance()->Deallocate(p);
		}

	private:
		static StaticHeapAllocator* GetInstance();

		StaticHeapAllocator();

		void PrivInitialize(Backend* backend);
		void* PrivAllocate(int sizeInBytes, int alignment);
		void PrivDeallocate(void* p);

		Backend* backend;
		//LinkedList* allocator; //array of lists of type Allocator
	};
}