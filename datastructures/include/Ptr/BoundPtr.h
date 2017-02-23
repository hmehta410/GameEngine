#pragma once

//this class represents a ptr that another class will clean up.
//you do not need to delete it or worry about it in anyway
template <typename T>
class BoundPtr
{
public:
	BoundPtr(T* t) : ptr(t) {}

	T* GetPtr() const { return ptr; }

	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
	bool operator==(const BoundPtr& other) const { return ptr == other.ptr; }
	bool operator!=(const BoundPtr& other) const { return ptr != other.ptr; }
	bool operator<(const BoundPtr& other) const { return ptr < other.ptr; }
	bool operator<=(const BoundPtr& other) const { return ptr <= other.ptr; }
	bool operator>(const BoundPtr& other) const { return ptr > other.ptr; }
	bool operator>=(const BoundPtr& other) const { return ptr >= other.ptr; }

	void Delete(){ delete ptr; ptr = nullptr; }

private:
	T* ptr;
};