#pragma once

//simply a tag. Do not store or delete objects of this type.
//empty base class optimization when possible. It does not prevent the creation 
//of trivial components
class Component
{
public:
	typedef Component FactorySpecialization; //used for ComponentFactory specialization
};