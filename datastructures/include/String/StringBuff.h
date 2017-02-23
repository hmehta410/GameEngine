#pragma once

#include "String.h"
#include "FundamentalTypedefs.h"
#include <cstring>

template <int maxSize>
class StringBuff
{
public:
	StringBuff() :
		size(0)
	{
		buffer[0] = 0;
	}

	//copies the first size-1 chars in str
	StringBuff(const char* str)
	{
		strncpy_s(buffer, maxSize, str, maxSize - 1);
	}

	//copies the first size-1 chars in str
	StringBuff(const String& str)
	{
		int length = str.Size() > maxSize ? maxSize-1 : str.Size();
		memcpy(this->buffer, (char*)str, length);
		buffer[length] = 0;
		this->size = length;
	}

	StringBuff(const StringBuff& other) :
		size(other.size)
	{
		memcpy(buffer, other.buffer, other.size+1);
	}

	~StringBuff(){}

	StringBuff& operator=(const StringBuff& other)
	{
		if (this != &other)
		{
			this->size = other.size;
			memcpy(this->buffer, other.buffer, size + 1);
		}
		return *this;
	}
	
	operator char*() const
	{
		return (char*)buffer;
	}

	bool operator==(const StringBuff& other) const
	{
		if (size == other.size)
		{
			if (memcmp(buffer, other.buffer, size) == 0)
			{
				return true;
			}
		}
		return false;
	}

	bool operator==(const char* other) const
	{
		int len = strlen(other);
		if (size == len)
		{
			if (memcmp(buffer, other, size) == 0)
			{
				return true;
			}
		}
		return false;
	}

	void Set(const char* str)
	{
		strncpy_s(buffer,maxSize, str, maxSize - 1);
	}

	void Set(const String& str)
	{
		int length = str.Size() > maxSize ? maxSize - 1 : str.Size();
		memcpy(buffer, (char*)str, length);
		buffer[length] = 0;
		this->size = length;
	}

	//returns length of the string; 
	uint32  Length()
	{
		return size;
	}

	//returns size of the buffer not length of the string;
	uint32 Size()
	{
		return maxSize;
	}

private:
	char buffer[maxSize];
	uint32 size;
};