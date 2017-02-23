#pragma once

#include <type_traits>
#include "HandleOn.h"
#include "Component.h"
#include "UniqueId.h"
#include "Assert.h"
#include "ComponentHandleBase.h"
#include "ComponentFactoryTemplate.h"

template <typename T>
class ComponentHandle : public ComponentHandleBase
{
public:
	ComponentHandle(T* component) : component(component)
	{
		static_assert(std::is_base_of<Component, T>::value, "Class T is not a component. Use ?Handle? instead of ComponentHandle.");
	}

	bool MatchesID(UniqueID id) const override
	{
		return componentID == id;
	}
	 
	T* operator->()
	{
		return component;
	}

	void SetValue(T* t)
	{
		component = t;
	}

	virtual T* GetValue() override
	{
		return component;
	}

	virtual void MarkForDelete() override
	{
		factory->MarkForDelete(this);
	}

	virtual bool IsMarkedForDelete() const override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

private:
	static UniqueID componentID; 
	T* component;

	ComponentFactory<T>* factory;
};

template <typename T> 
UniqueID ComponentHandle<T>::componentID = GetTypeID<T>();
