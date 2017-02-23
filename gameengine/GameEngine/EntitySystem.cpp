#include "EntitySystem.h"
#include "Entity.h"

EntitySystem::~EntitySystem()
{
	//if there are entites in either list then either the program is closing or 
	//you messed up
	entities.DeleteList();
	markedForDelete.DeleteList();
}

EntitySystem::EntitySystem()
{
}

Entity* EntitySystem::CreateEntity()
{
	Entity* entity = new Entity();
	this->entities.PushBack(entity);
	return entity;
}

void EntitySystem::MarkForDelete(Entity* entity)
{
	this->entities.Remove(entity);
	this->markedForDelete.PushBack(entity);
}

void EntitySystem::Reload()
{
}

void EntitySystem::Run(float)
{
}

void EntitySystem::Clean()
{
	LinkedIterator it = this->markedForDelete.GetIterator();

	bool entityIsReadyToBeDeleted = false;
	Link* link = it.First();
	while (!it.IsDone())
	{
		Entity* entity = (Entity*)link;

		if (entity->components.Size() == 0)
		{
			entityIsReadyToBeDeleted = true;
		}
		else
		{
			entity->MarkComponentsForDelete();
		}

		link = it.Next();

		if (entityIsReadyToBeDeleted)
		{
			this->markedForDelete.Remove(entity);
			delete entity;
			entityIsReadyToBeDeleted = false;
		}
	}
}