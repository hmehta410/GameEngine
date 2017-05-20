#ifdef UNIT_TESTS
#include "catch.hpp"
#include "..\include\HeapBackend.h"
#include <algorithm>
#include <random>


TEST_CASE("Single allocation returns enough space", "[HeapBackend]") 
{
	int backendSize = 100;
	char* memory = new char[backendSize];
	char* end = memory + backendSize;

	mem::HeapBackend backend(memory, backendSize);
	int freeSpace = backend.GetFirstSpace();

	int size = 50;
	void* ptr = backend.Malloc(size, 1);
	memset(ptr, 0xAA, 50);
	//test that the allocated memory is inside the original boundaries
	REQUIRE((uintptr_t)ptr >= (uintptr_t)memory);
	REQUIRE((uintptr_t)ptr < (uintptr_t)end - size);
	REQUIRE(backend.GetFirstSpace() <= freeSpace - size);

	memset(ptr, 0, size);
	backend.Dealloc(ptr);

	delete[] memory;
}

TEST_CASE("single deallocation frees all space", "[HeapBackend]")
{
	int backendSize = 100;
	char* memory = new char[backendSize];
	char* end = memory + backendSize;
	mem::HeapBackend backend(memory, backendSize);

	int freeSpace = backend.GetFirstSpace();

	void* ptr = backend.Malloc(50, 1);
	backend.Dealloc(ptr);

	//freespace before and after allocation are equal
	REQUIRE(backend.GetFirstSpace() == freeSpace);

	delete[] memory;
}

TEST_CASE("coalesce", "[HeapBackend]")
{
	int backendSize = 1000;
	char* memory = new char[backendSize];
	char* end = memory + backendSize;

	mem::HeapBackend backend(memory, backendSize);
	int freeSpace = backend.GetFirstSpace();

	void* a = backend.Malloc(10, 1);
	REQUIRE(backend.GetFirstSpace() < freeSpace - 10);
	void* b = backend.Malloc(20, 1);
	REQUIRE(backend.GetFirstSpace() < freeSpace - 30);
	void* c = backend.Malloc(30, 1);
	REQUIRE(backend.GetFirstSpace() < freeSpace - 60);

	SECTION("free a, b, c")
	{
		backend.Dealloc(a);
		backend.Dealloc(b);
		backend.Dealloc(c);

		REQUIRE(backend.GetFirstSpace() == freeSpace);
	}
	SECTION("free a, c, b")
	{
		backend.Dealloc(a);
		backend.Dealloc(c);
		backend.Dealloc(b);

		REQUIRE(backend.GetFirstSpace() == freeSpace);
	}
	SECTION("free b, c, a")
	{
		backend.Dealloc(b);
		backend.Dealloc(c);
		backend.Dealloc(a);

		REQUIRE(backend.GetFirstSpace() == freeSpace);
	}
	SECTION("free b, a, c")
	{
		backend.Dealloc(b);
		backend.Dealloc(a);
		backend.Dealloc(c);

		REQUIRE(backend.GetFirstSpace() == freeSpace);
	}
	SECTION("free c, a, b")
	{
		backend.Dealloc(c);
		backend.Dealloc(a);
		backend.Dealloc(b);

		REQUIRE(backend.GetFirstSpace() == freeSpace);
	}
	SECTION("free c, b, a")
	{
		backend.Dealloc(c);
		backend.Dealloc(b);
		backend.Dealloc(a);

		REQUIRE(backend.GetFirstSpace() == freeSpace);
	}
	delete[] memory;
}

TEST_CASE("Allocate too large","[HeapBackend]")
{
	int backendSize = 100;
	char* memory = new char[backendSize];
	char* end = memory + backendSize;

	mem::HeapBackend backend(memory, backendSize);
	int freeSpace = backend.GetFirstSpace();

	int size = 101;
	void* ptr = backend.Malloc(size, 1);

	REQUIRE(ptr == nullptr);

	//if allocation failed then backend should be unchanged
	REQUIRE(backend.GetFirstSpace() == freeSpace);

	delete[] memory;
}

TEST_CASE("Allocate properly alligns data", "[HeapBackend]")
{
	int backendSize = 1000;
	char* memory = new char[backendSize];
	mem::HeapBackend backend(memory, backendSize);

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

TEST_CASE("allocate till out of space, individually free all ptrs, then reallocate the same amount", "[HeapBackend]")
{
	int backendSize = 1000;
	char* memory = new char[backendSize];
	mem::HeapBackend backend(memory, backendSize); 

	void* ptr = nullptr;
	std::vector<void*> ptrs;
	int mallocSize = 25;
	do 
	{
		ptr = backend.Malloc(mallocSize, 1);
		ptrs.push_back(ptr);
	} while (ptr != nullptr);

	int count = ptrs.size();
	int freeSpace = backend.GetFirstSpace();

	//random will usually be the same for each run of the test
	//because it will use the default seed. It may change on
	//standard library updates.
	auto engine = std::default_random_engine{};
	std::shuffle(std::begin(ptrs), std::end(ptrs), engine);

	for (int i = 0; i < count; i++)
	{
		backend.Dealloc(ptrs[i]);
	}

	for (int i = 0; i < count; i++)
	{
		backend.Malloc(mallocSize, 1);
	}

	REQUIRE(freeSpace == backend.GetFirstSpace());
	delete[] memory;
}

TEST_CASE("deallocating nullptr does nothing", "[HeapBackend]")
{
	int backendSize = 1000;
	char* memory = new char[backendSize];
	mem::HeapBackend backend(memory, backendSize);
	int freeSpace = backend.GetFirstSpace();

	backend.Dealloc(nullptr);

	REQUIRE(backend.GetFirstSpace() == freeSpace);

	backend.Malloc(10, 1);
	void* ptrB = backend.Malloc(30, 1);
	backend.Malloc(15, 1);
	
	backend.Dealloc(ptrB);

	freeSpace = backend.GetFirstSpace();

	backend.Dealloc(nullptr);

	REQUIRE(backend.GetFirstSpace() == freeSpace);

	delete[] memory;
}

#endif