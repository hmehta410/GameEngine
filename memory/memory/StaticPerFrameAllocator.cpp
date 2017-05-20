#include "..\include\StaticPerFrameAllocator.h"
#include "LinkedList.h"

namespace mem
{
	StaticPerFrameAllocator::Backend* StaticPerFrameAllocator::backend = nullptr;
	StaticPerFrameAllocator::Allocator StaticPerFrameAllocator::empty(nullptr,0);
	mem::LinkedList* StaticPerFrameAllocator::allocators = nullptr;

	StaticPerFrameAllocator::StaticPerFrameAllocator()
	{
	}

	void StaticPerFrameAllocator::Initialize(Backend* back)
	{
		StaticPerFrameAllocator::backend = back;
	}

	void StaticPerFrameAllocator::ThreadLocalInitialize()
	{
		void* memoryBlock = backend->Malloc(sizeof(LinkedList), __alignof(LinkedList));
		allocators = new(memoryBlock)LinkedList();
		allocators->PushBack(&empty);
	}

	StaticPerFrameAllocator::Allocator* StaticPerFrameAllocator::NewAllocator(int size)
	{
		//get a big enough block from the backend
		char* memoryBlock = (char*)backend->Malloc(size + sizeof(Allocator), __alignof(Allocator));
		//place a new Allocator at the top of the new block
		Allocator* al = new(memoryBlock)Allocator(memoryBlock + sizeof(Allocator), size);
		return al;
	}

	//pass in the top allocator
	void StaticPerFrameAllocator::ReSortTopAllocator(Allocator* top)
	{
		//remove the top allocator
		allocators->Remove(top);

		//find the first allocator smaller than the top allocator
		//I initialize the list with a zero sized allocator so I don't have to 
		//check for an empty list
		Link* smaller = allocators->Find([&](Link* link)
		{
			return top->RemainingSpace() >= ((Allocator*)link)->RemainingSpace();
		}
		);

		//insert before the smaller allocator
		allocators->InsertBefore(top, smaller);
	}

	void* StaticPerFrameAllocator::Allocate(int sizeInBytes, int alignment)
	{
		Allocator* al = (Allocator*)allocators->Top();
		void* memory = al->Malloc(sizeInBytes, alignment);

		if (memory == nullptr)
		{
			//if we want to allocate something larger than 'AllocatorSize', then head
			//straight to the backend and create a special block of the exact size needed
			if (sizeInBytes + alignment > kLocalAllocatorSize - sizeof(Allocator))
			{
				al = NewAllocator(sizeInBytes + alignment);
				allocators->InsertBefore(al, &empty);

				memory = al->Malloc(sizeInBytes, alignment); 
				assert(memory != nullptr); //there should always be the perfect amount of space
			}
			else
			{
				//remove the top allocator and place it back into the list in sorted order
				ReSortTopAllocator(al);

				//check if one of the previously allocated blocks has enough space
				al = (Allocator*)allocators->Top();
				memory = al->Malloc(sizeInBytes, alignment);

				//if it doesn't, then get a new allocator
				if (memory == nullptr)
				{
					al = NewAllocator(kLocalAllocatorSize);
					allocators->PushFront(al);

					memory = al->Malloc(sizeInBytes, alignment);
					assert(memory != nullptr);
				}
			}
		}
		
		return memory;
	}

	void* StaticPerFrameAllocator::ContiguousAllocate(int sizeInBytes)
	{
		Allocator* al = (Allocator*)allocators->Top();
		return al->ContiguousMalloc(sizeInBytes);
	}

	void StaticPerFrameAllocator::ThreadLocalRestart()
	{
			Link* link = allocators->Top();
			Link* next = nullptr;
			while (link != &empty)
			{
				next = link->next;
				backend->Dealloc((Allocator*)link);
				link = next;
			}
			allocators->Clear();
			allocators->PushBack(&empty);
	}

	const mem::LinkedList* StaticPerFrameAllocator::GetAllocatorList()
	{
		return allocators;
	}

	void StaticPerFrameAllocator::Deallocate(void*)
	{

	}

}

