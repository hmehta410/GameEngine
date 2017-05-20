#pragma once
#include "StaticPerFrameAllocator.h"

namespace mem
{
	template <typename T>
	class PerFrameAllocator
	{
	public:
		T* allocate(std::size_t n)
		{
			//UPDATE: need to change __alignof(T) to alignof(T)
			return (T*)StaticPerFrameAllocator::Allocate(n*sizeof(T), __alignof(T));
		}

		T* contiguous_allocate(std::size_t n)
		{
			return (T*)StaticPerFrameAllocator::ContiguousAllocate(n*sizeof(T));
		}

		void deallocate(T* p, std::size_t n)
		{
			StaticPerFrameAllocater::Deallocate(p);
		}
	};
}