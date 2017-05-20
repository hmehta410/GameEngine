#include "..\include\StaticHeapAllocator.h"

namespace mem
{
	StaticHeapAllocator::StaticHeapAllocator(){}

	StaticHeapAllocator* StaticHeapAllocator::GetInstance()
	{
		static StaticHeapAllocator heap;
		return &heap;
	}

	void StaticHeapAllocator::PrivInitialize(Backend* aBackend)
	{
		this->backend = aBackend;
	}

	void* StaticHeapAllocator::PrivAllocate(int sizeInBytes, int alignment)
	{
		return backend->Malloc(sizeInBytes, alignment);
	}

	void StaticHeapAllocator::PrivDeallocate(void* p)
	{
		backend->Dealloc(p);
	}

}