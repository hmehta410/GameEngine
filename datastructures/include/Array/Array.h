#pragma once

#include <vector>


//I kind of cheated here by using an std::vector but I didn't feel like 
//rewriting one. And the option is always there if I want to write one later
template <typename T>
class Array
{
public:

	Array() {};

	Array(int size, const T& value = T()) : elements(size,value) {}
	
	const T* begin() const
	{
		return this->elements.data();
	}

	const T* end() const
	{
		return this->begin() + this->Size();
	}

	T* begin()
	{
		return this->elements.data();
	}

	T* end()
	{
		return this->begin() + this->Size();
	}

	void PushBack(const T& t)
	{
		this->elements.push_back(t);
	}

	template <class... Args>
	T& EmplaceBack(Args&&... args)
	{
		this->elements.emplace_back(std::forward<Args>(args)...);
		return this->elements.back();
	}

	void PopBack()
	{
		this->elements.pop_back();
	}

	int Size() const
	{
		return this->elements.size();
	}

	int Capacity() const
	{
		return this->elements.capacity();
	}

	void Reserve(int capacity)
	{
		elements.reserve(capacity);
	}

	//T must be default constructible
	void Resize(int size)
	{
		elements.resize(size);
	}

	//removes the element and replaces it with the last element in the array,
	//and then decreases array size by 1.
	void RemoveAndSwap(const T& element)
	{
		//it's implemented more like a SwapAndPop() but in a custom array, 
		//I would destruct the element first then copy over it for improved performance
		std::swap(element, this->elements.back());
		this->PopBack();
	}

	void RemoveAndSwap(int i)
	{
		std::swap(this->elements[i], this->elements.back());
		this->PopBack();
	}

	T& operator[](int index)
	{
		return this->elements[index];
	}

	const T& operator[](int index) const
	{
		return this->elements[index];
	}

private:
	std::vector<T> elements;
};