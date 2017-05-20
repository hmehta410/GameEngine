#pragma once

namespace mem_util
{
	inline void* Align(void* ptr, int alignment)
	{
		return (void*)(((uintptr_t)ptr + (alignment - 1)) & ~(alignment - 1));
	}
}