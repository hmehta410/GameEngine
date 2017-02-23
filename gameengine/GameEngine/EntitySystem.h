#pragma once
#include "System.h"
#include "List\DList.h"

class Entity;

/*
Doesn't actually do anything other than manage the lifetime of an entity.
*/
class EntitySystem : public System
{
public:
	EntitySystem();
	~EntitySystem();

	//DLists are not copyable. 
	//Systems shouldn't really be moving around too much anyway
	EntitySystem(const EntitySystem& o) = delete;
	EntitySystem& operator=(const EntitySystem& o) = delete;

	Entity* CreateEntity();
	void MarkForDelete(Entity* entity);

	//does nothing
	virtual void Reload() override;

	//does nothing
	virtual void Run(float time) override;

	//Cleans up any entities marked for delete
	virtual void Clean() override;

private:
	DList entities;
	DList markedForDelete;
};

