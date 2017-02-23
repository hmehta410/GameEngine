#pragma once

#include "ComponentHandleBase.h"
#include "UniqueId.h"
#include "Array/Array.h"
#include "List/Link.h"
#include "EntitySystem.h"
#include "ComponentHandle.h"

/*
An entiy is effectively nothing more than a collection of related components. It
is non-essential but may come in handy.
*/
class Entity : public DLink
{
public:
	void RemoveComponent(ComponentHandleBase* componentHandle);
	void AddComponent(ComponentHandleBase* componentHandle);

	//This will only return the first occurrence of a handle of type T
	template<typename T>
	ComponentHandle<T>* GetComponentHandle();

	//TODO: implement HardDelete feature

	//HardDelete gaurantees the entity will be removed at the end of the frame.
	//i.e. Component dependencies will be ignored.
	//SoftDelete will let the entity by removed once all of its dependants are removed.
	void MarkForDelete(bool hardDelete = false);

private:
	EntitySystem* system;
	Array<ComponentHandleBase*> components;

	void MarkComponentsForDelete();
	ComponentHandleBase* GetComponentHandle(UniqueID id);

	friend class EntitySystem;
};

template<typename T>
ComponentHandle<T>* Entity::GetComponentHandle()
{
	UniqueID id = GetTypeID<T>(); //Get id for type T
	return (ComponentHandle<T>*)GetComponentHandle(id); //search for handle by id
}
