#pragma once

/*
Custom string class. Functionality has been added as necessary
*/

class String
{
public:
	String();
	String(int capacity);
	String(const char* cstring);

	//does not copy capacity from input string
	String(const String& string);
	String(String&& string);
	~String();

	//does not copy capacity from input string
	String& operator=(const String& string);
	String& operator=(String&& string);

	//appends 
	String operator+(const String& append);
	String operator+(const char* append);
	String& operator+=(const String& append);
	String& operator+=(const char* append);

	//implicit conversion to const char*
	operator const char*() const;

	char& operator[](int i);

	//equality operator
	bool operator==(const String& string) const;
	bool operator==(const char* string) const;

	//returns length
	int Length() const;

	//an alternative to operator=
	void Set(const char* string);

	//only increases capacity
	void SetCapacity(int cap);

private:
	char* cString; //null-terminated string
	int length;
	int capacity; //capacity should always be at least length + 1

	void Set(const char* string, int size);
	void Append(const char* cString, int appendLength);
};
