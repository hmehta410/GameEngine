#pragma once

//Helps encapsulate the idea of a unique id. At least the first 4 billion times...
class UniqueID
{
public:
	UniqueID();
	UniqueID(const UniqueID& orig);
	UniqueID& operator=(const UniqueID& orig);

	bool operator==(const UniqueID& other) const;
	
	explicit operator int() const;
private:
	static int nextID; //can make nextID atomic to ensure thread-safety
	int id;
};

//Is a useful function that gives each type a unique id consistent across a 
//single run
template <typename T> UniqueID GetTypeID()
{
	static const UniqueID id;
	return id;
}