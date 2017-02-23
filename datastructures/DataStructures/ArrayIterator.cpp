#include "Array/ArrayIterator.h"

ArrayIterator::ArrayIterator(void* start, void* end, int sizeOfType) : 
	start(start), iter(start), end(end), sizeOfType(sizeOfType)
{
}

int ArrayIterator::GetSizeOfType() const
{
	return sizeOfType;
}

void* ArrayIterator::privFirst()
{
	iter = start;
	return start;
}

void* ArrayIterator::privNext()
{
	iter = (void*)((int)iter + sizeOfType);
	return iter;
}

bool ArrayIterator::privIsDone() const
{
	return iter == end;
}

void* ArrayIterator::privCurrentItem() const
{
	return iter;
}
