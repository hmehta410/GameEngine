#pragma once

#include "Iterator.h"

//A standard forward iterator over an array.
//Usefull when needing a container-independent way to iterate
//The method call overhead during iteration seems like an unavoidable
//	  perfomance hit though
class ArrayIterator : public Iterator
{
public:
	ArrayIterator(void* start, void* end, int sizeOfType);
	int GetSizeOfType() const;

private:
	void* start;
	void* iter;
	void* end;
	int sizeOfType;

protected:
	virtual void* privFirst() override;
	virtual void* privNext() override;
	virtual bool privIsDone() const override;
	virtual void* privCurrentItem() const override;
};