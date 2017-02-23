#include "catch.hpp"
#include "String\String.h"
#include <utility>

TEST_CASE("String Constructor", "[String]")
{
	//default constructor
	String str;
	REQUIRE((char*)str == 0);
	REQUIRE(0 == (char*)str);

	//takes a const char*
	String str1("test sentence");
	REQUIRE(strcmp((char*)str1,"test sentence") == 0);
	REQUIRE(strlen((char*)str1) == strlen("test sentence"));

	//Sets the capacity of str2
	//String str2(13);
	//REQUIRE((char*)str2 == 0);
	//REQUIRE(0 == strlen((char*)str2));

	//copy constructor
	String str3(str1);
	REQUIRE(strcmp((char*)str3, "test sentence") == 0);
	REQUIRE(strlen((char*)str3) == strlen("test sentence"));

	//move constructor
	String str4(std::move(str1));
	REQUIRE(strcmp((char*)str4, "test sentence") == 0);
	REQUIRE(strlen((char*)str4) == strlen("test sentence"));

	REQUIRE((char*)str1 == nullptr);
	REQUIRE(0 == (char*)str1);
}

TEST_CASE("String Size()", "[String]")
{
	String str;
	String str1("short sentence");
	String str2("a very very super omega ultra long sentence that still isn't actually that long but is good enough for this test");

	REQUIRE(0 == str.Size());
	REQUIRE(strlen((char*)str1) == str1.Size());
	REQUIRE(strlen((char*)str2) == str2.Size());
}

TEST_CASE("String copy assignment", "[String]")
{
	String str;
	const char* str1Contents = "a sentence";
	String str1(str1Contents);
	String str2("a longer sentence");

	SECTION("copy a string longer than original")
	{
		str = str1;

		//after
		REQUIRE(str.Size() == str1.Size());
		REQUIRE(strcmp((char*)str, (char*)str1) == 0);
	}

	SECTION("copy a string shorter than original")
	{
		//before
		REQUIRE(str1.Size() != str2.Size());
		REQUIRE(strcmp((char*)str1, (char*)str2) != 0);

		str2 = str1;

		//after
		REQUIRE(str1.Size() == str2.Size());
		REQUIRE(strcmp((char*)str1, (char*)str2) == 0);
	}

	SECTION("copy yourself")
	{
		//before
		REQUIRE(str1.Size() == strlen(str1Contents));
		REQUIRE(strcmp((char*)str1, str1Contents) == 0);

		str1 = str1;

		//after
		REQUIRE(str1.Size() == strlen(str1Contents));
		REQUIRE(strcmp((char*)str1, str1Contents) == 0);
	}
}

TEST_CASE("String move assignment", "[String]")
{
	String str;
	const char* str1Contents = "a sentence";
	String str1(str1Contents);
	
	SECTION("move a string into an empty string")
	{
		str = std::move(str1);

		REQUIRE(str.Size() == strlen(str1Contents));
		REQUIRE(strcmp((char*)str, str1Contents) == 0);

		//ensure valid state for str1
		if (((char*)str1) != 0)
		{
			REQUIRE(str1.Size() == strlen((char*)str1));
		}
		else
		{
			REQUIRE(str1.Size() == 0);
		}
	}

	SECTION("move an empty string into a string")
	{
		str1 = std::move(str);

		REQUIRE(str1.Size() == 0);
		REQUIRE((char*)str1 == nullptr);

		//ensure valid state for str
		if (((char*)str) != 0)
		{
			REQUIRE(str.Size() == strlen((char*)str));
		}
		else
		{
			REQUIRE(str.Size() == 0);
		}
	}

	SECTION("move yourself into yourself")
	{
		str1 = std::move(str1);

		REQUIRE(str1.Size() == strlen(str1Contents));
		REQUIRE(strcmp((char*)str1, str1Contents) == 0);
	}
}