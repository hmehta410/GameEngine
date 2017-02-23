#include "Entity.h"
#include "EntitySystem.h"

void Entity::RemoveComponent(ComponentHandleBase* componentHandle)
{
	auto it = std::find(this->components.begin(), this->components.end(), componentHandle);
	if (it != this->components.end())
	{
		int index = std::distance(this->components.begin(), it);
		this->components.RemoveAndSwap(index);
	}
}

void Entity::AddComponent(ComponentHandleBase* componentHandle)
{
	this->components.PushBack(componentHandle);
}

ComponentHandleBase* Entity::GetComponentHandle(UniqueID id)
{
	for (auto component : this->components)
	{
		if (component->MatchesID(id))
		{
			return component;
		}
	}
	return nullptr;
}

void Entity::MarkForDelete(bool hardDelete /*= false*/)
{
	//TODO: implement hard delete
	hardDelete;
	this->system->MarkForDelete(this);
}

void Entity::MarkComponentsForDelete()
{
	for (ComponentHandleBase* handle : this->components)
	{
		handle->MarkForDelete();
	}
}

