#include "UniqueID.h"

int UniqueID::nextID = 0;

UniqueID::UniqueID() 
{
	id = nextID++;
}

UniqueID::UniqueID(const UniqueID& orig)
{
	id = orig.id;
}

UniqueID& UniqueID::operator=(const UniqueID& orig)
{
	id = orig.id;
	return *this;
}

bool UniqueID::operator==(const UniqueID& other) const
{
	return id == other.id;
}

UniqueID::operator int() const
{
	return id;
}
