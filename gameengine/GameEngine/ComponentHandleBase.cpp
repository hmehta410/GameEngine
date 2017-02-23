#include "ComponentHandleBase.h"
#include "Component.h"
#include "ComponentDependencyNode.h"
#include "Assert.h"
#include "Entity.h"

ComponentHandleBase::ComponentHandleBase()
{
}

ComponentHandleBase::~ComponentHandleBase()
{
	requirements.DeleteList();
}

Entity* ComponentHandleBase::GetEntity()
{
	return entity;
}

/*
The reasoning for this function is confusing but is necessary when components
rely on other components. For example the graphicsComponent relies on the
TransformComponent so if I delete the transformComponent, I need to make sure
the graphicsComponent is also deleted or has been made aware of any potentially dangling
component handles.
*/
void ComponentHandleBase::AddRequirement(ComponentHandleBase* handle)
{
	RequirementNode* node = new RequirementNode();
	node->requirement = handle;
	node->dependantNode.dependant = this;

	handle->dependants.PushFront(&node->dependantNode);
	this->requirements.PushFront(node);
}

void ComponentHandleBase::MarkDependantsForDelete()
{
	LinkedIterator it = this->dependants.GetIterator();
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		DependantNode* node = (DependantNode*)link;
		node->dependant->MarkForDelete();
	}
}

void ComponentHandleBase::BecomeIndependent()
{
	LinkedIterator it = this->requirements.GetIterator();
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		RequirementNode* node = (RequirementNode*)link;
		node->requirement->dependants.Remove(&node->dependantNode);
		assert(node->dependantNode.dependant == this);
	}
}

void ComponentHandleBase::RemoveFromEntity()
{
	this->entity->RemoveComponent(this);
}

