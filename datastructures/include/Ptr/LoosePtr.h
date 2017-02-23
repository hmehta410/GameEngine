#pragma once

//This class represents a loose pointer. 
//The user will need to manually clean up this pointer or pass it on to another 
//		function that handles loose pointers
template <typename T>
class LoosePtr
{
public:
	LoosePtr(T* t) : ptr(t) {}

	T* GetPtr() const { return ptr; }

	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
	bool operator==(const LoosePtr& other) const { return ptr == other.ptr; }
	bool operator!=(const LoosePtr& other) const { return ptr != other.ptr; }
	bool operator<(const LoosePtr& other) const { return ptr < other.ptr; }
	bool operator<=(const LoosePtr& other) const { return ptr <= other.ptr; }
	bool operator>(const LoosePtr& other) const { return ptr > other.ptr; }
	bool operator>=(const LoosePtr& other) const { return ptr >= other.ptr; }

	void Delete() { delete ptr; ptr = nullptr; }

private:
	T* ptr;
};
