#include "..\include\HeapBackend.h"
#include "BlockHeader.h"
#include "..\include\Util.h"
#include <assert.h>
#include <memory.h>

namespace mem
{
	namespace
	{
		struct GreaterThan
		{
			GreaterThan(int aSize) : size(aSize) {}

			bool operator()(Link* link)
			{
				return ((FreeHeader*)link)->GetSize() >= size;
			}

			int size;
		};

		FreeHeader* GetFreeBlock(LinkedList& freeList, int size)
		{
			FreeHeader* freeBlock = (FreeHeader*)freeList.FindNext(GreaterThan(size));

			if (freeBlock == nullptr)
			{
				return nullptr;
			}

			freeList.Remove(freeBlock);

			return freeBlock;
		}

		FreeHeader* Coalesce(FreeHeader* aboveFreeBlock, FreeHeader* belowFreeBlock)
		{
			int newSize = aboveFreeBlock->GetSize() + belowFreeBlock->GetSize();
			aboveFreeBlock->SetSize(newSize);
			return aboveFreeBlock;
		}

		void ResetLowerBlocksAbovePtr(BlockHeader* block, void* lastAddress)
		{
			char* lowerBlock = (char*)block + block->GetSize();

			if (lowerBlock < lastAddress)
			{
				((UsedHeader*)lowerBlock)->SetAboveBlock(block);
			}
		}

		UsedHeader* GetUsedHeader(void* ptr)
		{
			UsedHeader** usedHeaderPtr = (UsedHeader**)((char*)ptr - sizeof(UsedHeader*));
			return *usedHeaderPtr;
		}

		//Splits the freeblock into a free and used block
		//returns the used portion of the split space
		void* Split(FreeHeader* freeBlock, int freeSize, int usedSize, int alignment, LinkedList& freeList)
		{
			//we align from the bottom up to save the most space after alignment
			char* bottomOfFreeSpace = (char*)freeBlock + freeSize;

			//align the actual used space
			char* unalignedUsedSpace = bottomOfFreeSpace - usedSize - alignment;
			char* alignedUsedSpace = (char*)mem_util::Align(unalignedUsedSpace, alignment);

			//align the usedHeader
			char* unalignedUsedHeader = alignedUsedSpace - sizeof(UsedHeader) - __alignof(UsedHeader);
			UsedHeader* usedHeader = (UsedHeader*)mem_util::Align(unalignedUsedHeader, __alignof(UsedHeader));

			//set Used Block
			usedHeader->SetAboveBlock(freeBlock);
			usedHeader->SetSize(bottomOfFreeSpace - (char*)usedHeader);
			usedHeader->SetUsed();

			int freeSpace = (char*)usedHeader - (char*)freeBlock;

			//add free block back into the list
			freeBlock->SetSize(freeSpace);
			freeList.PushFront(freeBlock);

			return alignedUsedSpace;
		}
	}

	HeapBackend::HeapBackend(void* memory, int sizeInBytes)
		: memoryPool(memory), endAddress((char*)memory + sizeInBytes)
	{
		FreeHeader* header = (FreeHeader*)memory;
		header->SetSize(sizeInBytes);
		header->SetFree();
		freeList.PushBack(header);
	}

	void* HeapBackend::Calloc(int aSize, int alignment)
	{
		void* ptr = Malloc(aSize, alignment);
		if (ptr)
		{
			memset(ptr, 0, aSize);
		}
		return ptr;
	}

	void* HeapBackend::Malloc(int aSize, int alignment)
	{
		assert(alignment != 0);
		assert(aSize != 0);

		//calculate maximum needed space
		int usedSize = aSize + alignment - 1;
		int headerSize = sizeof(UsedHeader) + __alignof(BlockHeader)-1;
		int requiredSize = headerSize + usedSize;

		//get freeBlock
		FreeHeader* freeBlock = GetFreeBlock(freeList, requiredSize);
		if (freeBlock == nullptr)
		{
			return nullptr;
		}

		int freeSize = freeBlock->GetSize();
		int leftoverSpace = freeSize - requiredSize;

		UsedHeader* usedBlock;
		void* ptr; //ptr is the pointing to the space I return below the usedblock

		//if there is any leftover space then we'll have to split the freeblock
		//into 2 pieces
		if (leftoverSpace > 0)
		{
			ptr = Split(freeBlock, freeSize, aSize, alignment, freeList);
			usedBlock = (UsedHeader*)((char*)freeBlock + freeBlock->GetSize());
		}
		else
		{
			//overwrite the whole free block with a used block header
			usedBlock = (UsedHeader*)freeBlock;
			usedBlock->SetUsed();

			//This is very hacky but I can't figure where the block above me is.
			//Luckily I know that it is Used or it doesn't exist. If it was free, it
			//would have been coalesced with the free block I'm overwriting.
			//And since the block above me is used, I won't have to coalesce with it 
			//until it becomes free. At which point it will reset my aboveBlockIndex.
			usedBlock->SetAboveBlock(nullptr);

			ptr = mem_util::Align(usedBlock + 1, alignment); //(usedBlock + 1) points to the free space right below the header
		}

		ResetLowerBlocksAbovePtr(usedBlock, endAddress); //it resets the lower block's abovePtr
		
		//make sure the used space can point back to the UsedHeader
		UsedHeader** above = (UsedHeader**)((char*)ptr - sizeof(UsedHeader*));
		*above = usedBlock;

		return ptr;
	}

	void HeapBackend::Dealloc(void* ptr)
	{
		if (ptr == nullptr)
		{
			return;
		}

		UsedHeader* used = GetUsedHeader(ptr);
		BlockHeader* aboveBlock = used->GetAboveBlock();

		//free the returned block
		FreeHeader* free = (FreeHeader*)used;
		free->SetFree();

		//try to coalesce with the block above you
		if (aboveBlock != nullptr)
		{
			if (aboveBlock->IsFree())
			{
				freeList.Remove((FreeHeader*)aboveBlock);
				free = Coalesce((FreeHeader*)aboveBlock, free);
			}
		}

		//try to coalesce with the block below you
		BlockHeader* below = (BlockHeader*)((char*)used + used->GetSize());
		if (below < endAddress)
		{
			if (below->IsFree())
			{
				freeList.Remove((FreeHeader*)below);
				free = Coalesce(free, (FreeHeader*)below);
			}
		}

		//push final free block back into the list
		freeList.PushFront(free);
		ResetLowerBlocksAbovePtr(free, endAddress); //it resets the lower block's abovePtr
	}

	char* HeapBackend::GetMemoryPool()
	{
		return (char*)memoryPool;
	}

	int HeapBackend::GetFirstSpace()
	{
		FreeHeader* free = (FreeHeader*)freeList.Top();
		if (free == nullptr)
		{
			return 0;
		}

		return free->GetSize();
	}
}

