#ifdef UNIT_TESTS
#include "catch.hpp"
#include "..\include\PerFrameBackend.h"

TEST_CASE("Single allocation returns enough space PerFrameBackend", "[PerFrameBackend]")
{
	int backendSize = 100;
	char* memory = new char[backendSize];
	char* end = memory + backendSize;

	mem::PerFrameBackend backend(memory, backendSize);
	int freeSpace = backend.RemainingSpace();

	int size = 50;
	void* ptr = backend.Malloc(size, 1);
	memset(ptr, 0xAA, 50);
	//test that the allocated memory is inside the original boundaries
	REQUIRE((uintptr_t)ptr >= (uintptr_t)memory);
	REQUIRE((uintptr_t)ptr < (uintptr_t)end - size);
	REQUIRE(backend.RemainingSpace() <= freeSpace - size);


	delete[] memory;
}

TEST_CASE("ContiguousMalloc", "[PerFrameBackend]")
{
	int backendSize = 1000;
	char* memory = new char[backendSize];
	char* end = memory + backendSize;

	mem::PerFrameBackend backend(memory, backendSize);
	int size = 64;
	char* ptrA = (char*)backend.Malloc(size, 16);
	char* ptrB = (char*)backend.ContiguousMalloc(size);
	REQUIRE(ptrA + size == ptrB);
	char* ptrC = (char*)backend.ContiguousMalloc(size);
	REQUIRE(ptrB + size == ptrC);
	char* ptrD = (char*)backend.ContiguousMalloc(size);
	REQUIRE(ptrC + size == ptrD);
	char* ptrE = (char*)backend.ContiguousMalloc(size);
	REQUIRE(ptrD + size == ptrE);

	delete[] memory;
}

TEST_CASE("Allocate properly alligns data PerFrameBackend", "[PerFrameBackend]")
{
	int backendSize = 1000;
	char* memory = new char[backendSize];
	mem::PerFrameBackend backend(memory, backendSize);

	void* ptr = backend.Malloc(10, 1);
	REQUIRE(((uintptr_t)ptr % 1) == 0);

	ptr = backend.Malloc(10, 2);
	REQUIRE(((uintptr_t)ptr % 2) == 0);

	ptr = backend.Malloc(10, 4);
	REQUIRE(((uintptr_t)ptr % 4) == 0);

	ptr = backend.Malloc(10, 8);
	REQUIRE(((uintptr_t)ptr % 8) == 0);

	ptr = backend.Malloc(10, 16);
	REQUIRE(((uintptr_t)ptr % 16) == 0);

	ptr = backend.Malloc(10, 32);
	REQUIRE(((uintptr_t)ptr % 32) == 0);

	ptr = backend.Malloc(10, 64);
	REQUIRE(((uintptr_t)ptr % 64) == 0);

	ptr = backend.Malloc(10, 128);
	REQUIRE(((uintptr_t)ptr % 128) == 0);

	ptr = backend.Malloc(10, 256);
	REQUIRE(((uintptr_t)ptr % 256) == 0);
	delete[] memory;
}

TEST_CASE("allocate till out of space, free all space, then reallocate the same amount PerFrameBackend", "[PerFrameBackend]")
{
	int backendSize = 1000;
	char* memory = new char[backendSize];
	mem::PerFrameBackend backend(memory, backendSize);

	void* ptr = nullptr;
	int count = 0;
	int mallocSize = 25;
	do
	{
		ptr = backend.Malloc(mallocSize, 1);
		count++;
	} while (ptr != nullptr);

	int freeSpace = backend.RemainingSpace();

	//random will usually be the same for each run of the test
	//because it will use the default seed. It may change on
	//standard library updates.
	backend.Clear();

	for (int i = 0; i < count - 1; i++)
	{
		ptr = backend.Malloc(mallocSize, 1);
	}

	REQUIRE((uintptr_t)ptr >= (uintptr_t)memory);
	REQUIRE((uintptr_t)ptr < (uintptr_t)memory + backendSize);

	REQUIRE(freeSpace == backend.RemainingSpace());
	delete[] memory;
}


#endif