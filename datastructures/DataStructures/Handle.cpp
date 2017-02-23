#include "Handle.h"

Handle::Handle(void* ptr) 
	: ptr(ptr) 
{
}

Handle::~Handle()
{
}

void Handle::SetValue(void* ptr)
{
	this->ptr = ptr;
}

void* Handle::operator->() const
{
	return ptr;
}

void* Handle::GetValue() const
{
	return ptr;
}