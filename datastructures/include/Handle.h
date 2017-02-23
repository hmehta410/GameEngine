#pragma once

#include "List\Link.h"

class Handle : public DLink
{
public:
	Handle(void* ptr);
	virtual ~Handle();

	void SetValue(void* ptr);

	void* operator->() const;

	void* GetValue() const;

protected:
	void *ptr;
};