#pragma once

#include "Handle.h"

template <typename T> 
class HandleOn : public Handle
{
public:
	HandleOn(T* ptr) : Handle(ptr) {}

	T* operator->() const
	{
		return (T*)ptr;
	}

	void SetValue(T* t)
	{
		this->ptr = t;
	}

	T* GetValue() const
	{
		return (T*)this->ptr;
	}

private:
};