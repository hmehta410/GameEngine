#pragma once
#include "StaticHeapAllocator.h"

namespace mem
{
	template <typename T>
	class HeapAllocator
	{
	public:
		T* allocate(std::size_t n)
		{
			//UPDATE: need to change __alignof(T) to alignof(T)
			return (T*)StaticHeapAllocator::Allocate(n*sizeof(T), __alignof(T));
		}

		void deallocate(T* p, std::size_t n)
		{
			StaticHeapAllocator::Deallocate(p);
		}
	};
}