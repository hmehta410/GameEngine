#ifdef UNIT_TESTS
#include "..\catch.hpp"
#include "include\StaticPerFrameAllocator.h"

//Initialized in the main.cpp file

TEST_CASE("Allocate large block", "[StaticPerFrameAllocator]")
{
	int blockSize = mem::StaticPerFrameAllocator::kLocalAllocatorSize;
	const mem::LinkedList* list = mem::StaticPerFrameAllocator::GetAllocatorList();
	int listSize = list->GetSize();

	void* p = mem::StaticPerFrameAllocator::Allocate(blockSize + 1, 1);
	REQUIRE(p != nullptr);
	REQUIRE(list->GetSize() == listSize + 1);

	mem::StaticPerFrameAllocator::ThreadLocalRestart();
}

TEST_CASE("Allocate will first check existing blocks for space", "[StaticPerFrameAllocator]")
{
	int blockSize = mem::StaticPerFrameAllocator::kLocalAllocatorSize;
	const mem::LinkedList* list = mem::StaticPerFrameAllocator::GetAllocatorList();

	//get one new local block
	mem::StaticPerFrameAllocator::Allocate(blockSize / 2, 1);
	int listSize = list->GetSize();

	//get a second local block
	mem::StaticPerFrameAllocator::Allocate(blockSize / 2 + 1, 1);
	REQUIRE(listSize + 1 == list->GetSize());
	listSize = list->GetSize();

	//fill the second local block
	mem::StaticPerFrameAllocator::Allocate(blockSize / 4 + 1, 1);
	REQUIRE(listSize == list->GetSize());

	//go back to the first block
	mem::StaticPerFrameAllocator::Allocate(blockSize / 4 + 1, 1);
	REQUIRE(listSize == list->GetSize());

	//get a third block
	mem::StaticPerFrameAllocator::Allocate(blockSize / 4 + 1, 1);
	REQUIRE(listSize + 1 == list->GetSize());

	mem::StaticPerFrameAllocator::ThreadLocalRestart();
}

TEST_CASE("ContiguousAllocate fails when there is no contiguous space, Allocate does not", "[StaticPerFrameAllocator]")
{
	int size = mem::StaticPerFrameAllocator::kLocalAllocatorSize / 10;
	
	//gets a new block for contiguous allocate to get next;
	mem::StaticPerFrameAllocator::Allocate(1, 1);

	int count = 0;
	void* ptr = nullptr;
	do 
	{
		ptr = mem::StaticPerFrameAllocator::ContiguousAllocate(size);
		count++;
	} while (ptr != nullptr);

	mem::StaticPerFrameAllocator::ThreadLocalRestart();

	for (int i = 0; i < count; i++)
	{
		ptr = mem::StaticPerFrameAllocator::Allocate(size, 1);
	}

	//we're checking that while contiguous_allocate can run out of space from a local block.
	//regular allocate will go to the backend and get another block to allocate from.
	//we want contiguous_allocate to fail when there isn't contiguous space
	REQUIRE(ptr != nullptr);

	mem::StaticPerFrameAllocator::ThreadLocalRestart();
}


TEST_CASE("ContiguousAllocate keeps alignment", "[StaticPerFrameAllocator]")
{
	for (int i = 1; i < 7; i++)
	{
		int alignment = 1 << i;
		void* p = mem::StaticPerFrameAllocator::Allocate(alignment, alignment);
		REQUIRE((uintptr_t)p%alignment == 0);

		p = mem::StaticPerFrameAllocator::ContiguousAllocate(alignment);
		REQUIRE((uintptr_t)p%alignment == 0);

		p = mem::StaticPerFrameAllocator::ContiguousAllocate(alignment);
		REQUIRE((uintptr_t)p%alignment == 0);

		p = mem::StaticPerFrameAllocator::ContiguousAllocate(alignment);
		REQUIRE((uintptr_t)p%alignment == 0);

		mem::StaticPerFrameAllocator::ThreadLocalRestart();
	}
}

#endif