#pragma once

#include "Array/Array.h"
#include "List/DLinkedList.h"
#include "ComponentHandleBase.h"
#include <assert.h>

//forward declare
template <typename T>
class ComponentHandle;

/*
ComponentFactories are not a required aspect of ECS programming and the component
lifetime can be managed however it's corresponding system desires. ComponentFactories 
are usually used internally by their system to create Components and their handles.
Factories can be specialized on a type T1 or on types FactorySpecialization T2. 
This was meant to allow easy specialization on base/derived classes. (i.e. all derived
GraphicsObject's inherit a FactorySpecialization from their base class GraphicsObject.)
*/

/*
This defualt ComponentFactory template stores Components contiguously to allow for 
potentially more cache efficient processing by a system. It also attempts to handle
cleaning up handles marked for delete.
*/
template <typename T1, typename T2 = typename T1::FactorySpecialization>
class ComponentFactory
{
public:
	virtual ~ComponentFactory()
	{
		for (ComponentHandleBase* handle : this->handles)
		{
			delete handle;
		}
	}

	ComponentHandle<T1>* AddComponent(const T1& component)
	{
		this->components.PushBack(component);
		
		//Get the pointer to newly added component
		T1* lastComponent = &this->components[this->Size() - 1];

		//Add new handle pointing to new component;
		ComponentHandle<T1>* handle = this->AddNewHandle(lastComponent);
		return handle;
	}

	template <typename ...Args>
	ComponentHandle<T1>* CreateComponent(Args&&... args)
	{
		this->components.EmplaceBack(std::forward<Args>(args)...);
		T1* lastComponent = &this->components[this->Size() - 1];

		ComponentHandle<T1>* handle = this->AddNewHandle(lastComponent);
		return handle;
	}

	void MarkForDelete(T1* component)
	{
		//find handle corresponding to the given component
		ComponentHandle<T1>* handle = this->GetHandle(component);
		this->MarkForDelete(handle);
	}

	void MarkForDelete(ComponentHandle<T1>* handle)
	{
		//important: handles in the 'marked for delete' list are still in the 
		//handle array too. They need to remain at the same index as their component
		this->handlesMarkedForDelete.PushBack(handle);
	}

	void CleanUp()
	{
		bool handleIsReadyToBeRemoved = false;
		LinkedIterator it = this->handlesMarkedForDelete.GetIterator();

		Link* link = it.First();
		while (!it.IsDone())
		{
			ComponentHandleBase* handle = (ComponentHandleBase*)link;

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

			link = it.Next(); //move to the next component that needs to be deleted

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

	int Size() const 
	{
		return this->components.Size();
	}

	Array<T1>& GetComponents()
	{
		return this->components;
	}

	Array<ComponentHandle<T1>*>& GetHandles()
	{
		return this->handles;
	}

	bool IsMarkedForDelete(const ComponentHandleBase* handle) const
	{
		return handle->GetContainer() == &handlesMarkedForDelete;
	}

	template <typename Function>
	void Apply(Function& function)
	{
		components.Apply(function);
	}

private:
	Array<T1> components;
	Array<ComponentHandle<T1>*> handles;

	DLinkedList handlesMarkedForDelete;

private: //methods
	void RemoveHandle(ComponentHandleBase* handle)
	{
		//remove handle from marked list
		this->handlesMarkedForDelete.Remove(handle);

		//find index of handle and component. Related component and handle 
		//should always be at the same index.
		int dist = (int)handle - (int)this->handles.begin();
		int index = dist / sizeof(ComponentHandle<T1>*);
		assert(index < this->handles.Size() && index > 0);

		//remove and swap the handle and components with the last ones in the lists
		handles.RemoveAndSwap(index);
		components.RemoveAndSwap(index);

		//point the handle to the new location of the component
		(handles[index])->SetValue(&components[index]);

		//finally we can delete the handle
		delete handle;
	}

	//handles and components are always at the same index in their respective arrays
	ComponentHandle<T1>* GetHandle(T1* component)
	{
		int index = std::distance(this->components.begin(), component);
		assert(index < this->components.Size() && index > 0);
		return this->handles[index];
	}

	//if (this->WillResize())
	bool WillResize()
	{
		return this->handles.Size() == this->handles.Capacity();
	}

	ComponentHandle<T1>* AddNewHandle(T1* component)
	{
		bool needToReassociateHandles = false;
		if (this->WillResize())
		{
			needToReassociateHandles = true;
		}

		ComponentHandle<T1>* handle = new ComponentHandle<T1>(component);
		handles.PushBack(handle);

		if (needToReassociateHandles)
		{
			for (int i = 0; i < this->Size(); i++)
			{
				this->handles[i]->SetValue(&this->components[i]);
			}
		}

		return handle;
	}
};

#include "ComponentHandle.h"