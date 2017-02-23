#include "String\String.h"
#include <cstring>
#include <assert.h>
#include <utility>

String::String()
	: cString(nullptr), length(0), capacity(0)
{
}

String::String(int capacity)
	: length(0), capacity(capacity)
{
	cString = new char[capacity];
	*cString = '\0'; //null terminator 
}

String::String(const char* str)
{
	this->length = strlen(str);
	this->capacity = this->length + 1;
	this->cString = new char[capacity];
	memcpy(cString, str, capacity);
}

String::String(const String& string)
	: length(string.length), capacity(string.length+1)
{
	this->cString = new char[capacity];
	memcpy(cString, string.cString, capacity);
}

String::String(String&& string)
	: cString(string.cString), length(string.length), capacity(string.capacity)
{
	string.cString = nullptr;
	string.length = 0;
	string.capacity = 0;
}

String::~String()
{
	delete[] this->cString;
}

String& String::operator=(const String& string)
{
	if (this != &string)
	{
		this->Set(string.cString, string.length);
	}
	return *this;
}

String& String::operator=(String&& string)
{
	if (this != &string)
	{
		std::swap(this->cString, string.cString);
		this->length = string.length;
		this->capacity = string.capacity;
	}
	return *this;
}

String String::operator+(const String& append)
{
	//set capacity
	String newString(this->length + append.length + 1);

	newString = *this;
	newString += append;

	return newString;
}

String String::operator+(const char* append)
{
	//set capacity
	String newString(this->length + strlen(append) + 1);

	newString = *this;
	newString += append;

	return newString;
}

String& String::operator+=(const String& append)
{
	this->Append(append.cString, append.length);
	return *this;
}

String& String::operator+=(const char* append)
{
	this->Append(append, strlen(append));
	return *this;
}

String::operator const char*() const
{
	return this->cString;
}

char& String::operator[](int i)
{
	assert(i < capacity);
	return this->cString[i];
}

bool String::operator==(const String& string) const
{
	if (this->length == string.length)
	{
		if (0 == memcmp(this->cString, string.cString, this->length))
		{
			return true;
		}
	}
	return false;
}

bool String::operator==(const char* string) const
{
	int len = strlen(string);
	if (length == len)
	{
		if (memcmp(this->cString, string, length) == 0)
		{
			return true;
		}
	}
	return false;
}

int String::Length() const
{
	return length;
}

void String::Set(const char* string)
{
	this->Set(string, strlen(string));
}

void String::SetCapacity(int cap)
{
	if (cap > this->capacity)
	{
		this->capacity = cap;
		char* newString = new char[capacity];
		
		//+1 copies the null terminator
		memcpy(newString, this->cString, this->length + 1);

		delete[] cString;
		cString = newString;
	}
}

void String::Set(const char* string, int strLen)
{
	if (strLen < this->capacity) //or if(strlen+1 <= capacity)
	{
		this->length = strLen;
		memcpy(this->cString, string, length + 1); //+1 copies null terminator
	}
	else
	{
		delete[] cString;
		this->length = strLen;
		this->capacity = length + 1;
		this->cString = new char[capacity];
		memcpy(cString, string, capacity);
	}
}

void String::Append(const char* cStr, int appendLength)
{
	int newSize = this->length + appendLength;
	SetCapacity(newSize + 1); //+1 for null terminator

	//this memcpy appends the new string
	memcpy(this->cString + this->length, cStr, appendLength + 1); //+1 copies null terminator. This is an internal method so we can be sure we only pass valid C Strings in
	this->length = newSize;
}
