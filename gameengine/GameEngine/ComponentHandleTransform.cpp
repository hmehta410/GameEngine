#include "ComponentHandleTransform.h"
#include "ComponentFactory.h"

UniqueID ComponentHandle<Transform>::transformID = GetTypeID<Transform>();

ComponentHandle<Transform>::ComponentHandle(const Vect& pos, const Quat& rot, const Vect& scale)
	: transform(pos, rot, scale)
{
}

bool ComponentHandle<Transform>::MatchesID(UniqueID id) const 
{
	return transformID == id;
}

const ComponentHandle<Transform>* ComponentHandle<Transform>::GetParent() const
{
	return this->factory->GetParent(this);
}

//Transform* ComponentHandle<Transform>::operator->()

Transform* ComponentHandle<Transform>::GetValue()
{
	return &this->transform;
}


const Transform& ComponentHandle<Transform>::GetValue() const
{
	return this->transform;
}

void ComponentHandle<Transform>::SetValue(const Transform& trans)
{
	this->transform = trans;
}

bool ComponentHandle<Transform>::IsMarkedForDelete() const
{
	return factory->IsMarkedForDelete(this);
}

void ComponentHandle<Transform>::MarkForDelete()
{
	factory->MarkForDelete(this);
}