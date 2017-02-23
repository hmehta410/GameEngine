#pragma once

#include "UniqueId.h"
#include "List\Link.h"
#include "List\DList.h"

class Component;
class RequirementNode;
class Entity;

class ComponentHandleBase : public DLink
{
public:
	ComponentHandleBase();
	virtual ~ComponentHandleBase();
	virtual bool MatchesID(UniqueID id) const = 0;

	virtual Component* GetValue() = 0;
	Entity* GetEntity();
	
	virtual void MarkForDelete() = 0;
	virtual bool IsMarkedForDelete() const = 0;

	void AddRequirement(ComponentHandleBase* handle);

protected:
	//useful for removing self from entity on deletion
	Entity* entity;

	//A list of things I depend on
	DList requirements;

	//A list of things that depend on me
	DList dependants;

private:
	//Mark components that depend on me for delete
	void MarkDependantsForDelete();

	//You're about to delete yourself so you need to tell every required node 
	//that you no longer depend on them
	void BecomeIndependent();

	//If this component handle is associated with an entity, remove itself.
	void RemoveFromEntity();

	template <typename T1, typename T2>
	friend class ComponentFactory;
};