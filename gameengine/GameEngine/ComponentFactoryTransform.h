#pragma once

#include "ComponentFactory.h"
#include "Transform.h"
#include "List/DList.h"
#include "PCSTree/Tree.h"
#include "ComponentHandleTransform.h"
#include "List/LinkedIterator.h"

/*
Specialized ComponentFactory. Creates TransformHandles and places them in a tree.

*/
template<>
class ComponentFactory<Transform, typename Transform::FactorySpecialization>
{
public:
	virtual ~ComponentFactory();

	//Create a ComponentHandle<Transform>
	ComponentHandle<Transform>* CreateComponent(const Vect& position, const Quat& rotation, const Vect& scale, ComponentHandle<Transform>* parent = nullptr);

	//returns a forward iterator to the transform's hierarchy
	ForwardIterator<PCSNode> GetHandles();	
	
	//Gets the parent for a given transform Handle
	const ComponentHandle<Transform>* GetParent(const ComponentHandle<Transform>* transform) const;

	//number of ComponentHandle<Transform>s
	int Size() const;

	//marks a handle for delete
	void MarkForDelete(ComponentHandle<Transform>* handle);

	//checks if a handle has been marked for delete
	bool IsMarkedForDelete(const ComponentHandle<Transform>* handle) const;

	void CleanUp();

	template <typename Function>
	void Apply(Function& function)
	{
		auto it = transformHandleHierarchy.GetIterator();
		for (auto link = it.First(); !it.IsDone(); link = it.Next())
		{
			auto transform = (ComponentHandle<Transform>*)link;
			function(transform->GetReference());
		}
	}

private:
	//they are both ComponentHandle<Transform>s but it'll get confused if it's a PCSNode or DLink
	Tree<PCSNode> transformHandleHierarchy;     
	DList<ComponentHandleBase> markedForDelete;

	void RemoveHandle(ComponentHandleBase* handle);
};
