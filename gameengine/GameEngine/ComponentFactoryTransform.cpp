#include "ComponentFactoryTransform.h"

ComponentFactory<Transform, typename Transform::FactorySpecialization>::~ComponentFactory()
{
	this->transformHandleHierarchy.DeleteTree();
}

void ComponentFactory<Transform, typename Transform::FactorySpecialization>::RemoveHandle(ComponentHandleBase* handle)
{
	this->markedForDelete.Remove(handle);

	//this will delete all children from the tree as well
	//this wil cause an error if a child has been marked for delete. or has any interdependence with other components
	this->transformHandleHierarchy.DeleteSubtree((ComponentHandle<Transform>*)handle);
}

void ComponentFactory<Transform, typename Transform::FactorySpecialization>::CleanUp()
{
	bool handleIsReadyToBeRemoved = false;
	auto it = this->markedForDelete.GetIterator();

	auto handle = it.First();
	while (!it.IsDone())
	{
		//if handle has no components that depend on it
		if (handle->dependants.IsEmpty())
		{
			//it is ready to be removed
			handleIsReadyToBeRemoved = true;
		}
		else
		{
			//I need to delete any component that depends on me before I 
			//delete myself to prevent dangling pointers.
			handle->MarkDependantsForDelete();
		}

		handle = it.Next(); //move to the next component that needs to be deleted

		if (handleIsReadyToBeRemoved)
		{
			handle->RemoveFromEntity();

			//I need to tell everyone who thinks I'm dependent on them that
			//I won't exist and that I don't depend on them anymore
			handle->BecomeIndependent();

			this->RemoveHandle(handle);
			handleIsReadyToBeRemoved = false;
		}
	}
}

bool ComponentFactory<Transform, typename Transform::FactorySpecialization>::IsMarkedForDelete(const ComponentHandle<Transform>* handle) const
{
	const ComponentHandleBase* base = handle;
	return base->GetContainer() == &this->markedForDelete;
}

void ComponentFactory<Transform, typename Transform::FactorySpecialization>::MarkForDelete(ComponentHandle<Transform>* handle)
{
	this->markedForDelete.PushBack(handle);
}

int ComponentFactory<Transform, typename Transform::FactorySpecialization>::Size() const
{
	return transformHandleHierarchy.GetSize();
}

ForwardIterator<PCSNode> ComponentFactory<Transform, typename Transform::FactorySpecialization>::GetHandles()
{
	return transformHandleHierarchy.GetIterator();
}

ComponentHandle<Transform>* ComponentFactory<Transform, typename Transform::FactorySpecialization>::CreateComponent(const Vect& position, const Quat& rotation, const Vect& scale, ComponentHandle<Transform>* parent /*= nullptr*/)
{
	ComponentHandle<Transform>* handle = new ComponentHandle<Transform>(position, rotation, scale);

	handle->factory = this;

	transformHandleHierarchy.Insert(handle, parent);

	return handle;
}


const ComponentHandle<Transform>* ComponentFactory<Transform, typename Transform::FactorySpecialization>::GetParent(const ComponentHandle<Transform>* transform) const
{
	const PCSNode* root = transformHandleHierarchy.GetRoot();
	const PCSNode* parent = ((PCSNode*)transform)->GetParent();
	if (root != parent)
	{
		return (ComponentHandle<Transform>*)parent;
	}

	return nullptr;
}
