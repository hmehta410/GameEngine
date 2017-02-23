#pragma once
#include <assert.h>

template <typename T>
class ArrayPtr
{
public:
	ArrayPtr(int size) : ptr(new T[size]), size(size) {}
	ArrayPtr(T* t, int size) : ptr(t), size(size) {}
	ArrayPtr(const ArrayPtr& other) : ptr(other.ptr), size(other.size) {}

	T* GetPtr() const { return ptr; }
	int Size() const { return size; }

	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
	T& operator[](int i) { assert(i < size);  return ptr[i]; }
	const T& operator[](int i) const { assert(i < size); return ptr[i]; }

	bool operator==(const ArrayPtr& other) const { return ptr == other.ptr; }
	bool operator!=(const ArrayPtr& other) const { return ptr != other.ptr; }
	bool operator<(const ArrayPtr& other) const { return ptr < other.ptr; }
	bool operator<=(const ArrayPtr& other) const { return ptr <= other.ptr; }
	bool operator>(const ArrayPtr& other) const { return ptr > other.ptr; }
	bool operator>=(const ArrayPtr& other) const { return ptr >= other.ptr; }

	void Delete(){ delete[] ptr; ptr = nullptr; }

private:
	T* ptr;
	int size;
};