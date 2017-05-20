#pragma once
#include "LinkedList.h"

namespace mem
{
	class BlockHeader
	{
	public:
		void SetFree()
		{
			free = true;
		}
		void SetUsed()
		{
			free = false;
		}

		bool IsFree() const
		{
			return free;
		}
		bool IsUsed() const
		{
			return !IsFree();
		}

		int GetSize() const
		{
			return size;
		}

		void SetSize(int aSize)
		{
			this->size = aSize;
		}

	private:
		int size;
		bool free;
	};

	class FreeHeader : public BlockHeader, public Link
	{
	};

	class UsedHeader : public BlockHeader
	{
	public:
		void SetAboveBlock(BlockHeader* above) 
		{
			this->aboveBlock = above; 
		}

		BlockHeader* GetAboveBlock() const 
		{ 
			return this->aboveBlock; 
		}

	private:
		BlockHeader* aboveBlock; //helps for coalescing
		UsedHeader* header; //points to this header. It is used on deallocation
	};
}