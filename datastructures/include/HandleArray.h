#pragma once

#include <vector>
#include "Handle.h"
#include "HandleOn.h"
#include "List\DList.h"

template <typename T>
class HandleArray
{
public:

	T* begin()
	{
		return &elements.front();
	}

	T* end()
	{
		return &elements.back();
	}

	HandleOn<T>* PushBack(const T& t)
	{
		if (elements.size() == elements.capacity())
		{
			elements.push_back(t);
			LinkedIterator it(list);
			T* element = &elements.front();
			for (Link* link = it.First(); !it.IsDone(); link = it.Next())
			{
				HandleOn<T>* handle = (HandleOn<T>*)link;
				handle->SetValue(element);
				element++;
			}
		}
		else
		{
			elements.push_back(t);
		}
		HandleOn<T>* handle = new HandleOn<T>(&elements.back());
		handles.PushBack(handle);
		return handle;
	}

	HandleOn<T>* PushBack(T&& t)
	{
		if (elements.size() == elements.capacity())
		{
			elements.push_back(t);
			LinkedIterator it(handles);
			T* element = &elements.front();
			for (Link* link = it.First(); !it.IsDone(); link = it.Next())
			{
				HandleOn<T>* handle = (HandleOn<T>*)link;
				handle->SetValue(element);
				element++;
			}
		}
		else
		{
			elements.push_back(t);
		}
		HandleOn<T>* handle = new HandleOn<T>(&elements.back());
		handles.PushBack(handle);
		return handle;
	}

	template <class... Args>
	HandleOn<T>* EmplaceBack(Args&&... args)
	{
		if (elements.size() == elements.capacity())
		{
			elements.emplace_back(args...);
			LinkedIterator it(handles);
			T* element = &elements.front();
			for (Link* link = it.First(); !it.IsDone(); link = it.Next())
			{
				HandleOn<T>* handle = (HandleOn<T>*)link;
				handle->SetValue(element);
				element++;
			}
		}
		else
		{
			elements.emplace_back(args...);
		}
		HandleOn<T>* handle = new HandleOn<T>(&elements.back());
		handles.PushBack(handle);
		return handle;
	}

	void PopBack()
	{
		elements.pop_back();
	}

	int Size()
	{
		return elements.size();
	}

	void Reserve(int capacity)
	{
		if (capacity > elements.capacity())
		{
			elements.reserve(capacity);
			LinkedIterator it(list);
			T* element = element.front();
			for (Link* link = it.First(); !it.IsDone(); link = it.Next())
			{
				Handle<T>* handle = (Handle<T>*)link;
				handle->Set(element);
				element++;
			}
		}
	}

	T operator[](int index)
	{
		return elements[index];
	}

	const T operator[](int index) const
	{
		return elements[index];
	}

private:
	std::vector<T> elements;
	DList handles;
};