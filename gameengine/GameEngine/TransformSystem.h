#pragma once

#include "System.h"
#include <vector>
#include "List\DList.h"
#include "Transform.h"
#include "ComponentHandleTransform.h"
#include "ComponentFactory.h"

//Creates and holds ComponentHandle<Transform>'s
//It also runs through the hierarchy of transforms calculating the 
//localWorld matrix from the transform's pos, rot, and scale
//and the globalWorld Matrix from the local and parent's world matrix.
//The hierarchy is actually implemented in the specialized factory.
class TransformSystem : public System
{
public: 
	 
	void Run(float time) override;
	virtual void Reload() override;
	virtual void Clean() override;

	ComponentHandle<Transform>* CreateTransform(ComponentHandle<Transform>* parent = nullptr);
	ComponentHandle<Transform>* CreateTransform(const Vect& position, const Quat& rotation, const Vect& scale, ComponentHandle<Transform>* parent = nullptr);
	
private:
	ComponentFactory<Transform> transformFactory;

	friend class ComponentHandle<Transform>;
};