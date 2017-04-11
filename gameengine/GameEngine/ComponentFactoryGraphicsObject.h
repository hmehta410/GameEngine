#pragma once

#include "ComponentFactoryTemplate.h"
#include "GraphicsObject.h"

//A base class for the GraphicsObjects type of factories. So that they can all
//be uniformly processed in the GraphicsSystem
class GraphicsFactory : public DLink
{
public:
	virtual bool MatchesID(UniqueID id) const = 0;
	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual int Size() const = 0;
};

//Specialized ComponentFactory that is identical to the default implementation but
//also fulfills the contract of a GraphicsFactory
template <typename T1>
class ComponentFactory < T1, GraphicsObject > : public GraphicsFactory
{
public:
	template <typename... Args>
	ComponentHandle<T1>* CreateGraphicsObject(Args&&... args)
	{
		return factory.CreateComponent(std::forward<Args>(args)...);
	}

	void MarkForDelete(T1* component)
	{
		factory.MarkForDelete(component);
	}

	void MarkForDelete(ComponentHandle<T1>* handle)
	{
		factory.MarkForDelete(handle);
	}

	//the draw methods is the major edition that allows the GraphicsSystem to tell each
	//type of GraphicsObject to draw itself.
	virtual void Draw() override
	{
		Array<T1>& components = factory.GetComponents();
		if (components.Size() == 0)
		{
			return;
		}

		//I use the first shader as a representative of all shaders of the same type
		//with regards to setting the GPU state.
		GraphicsObject* representative = (GraphicsObject*)components.begin();
		representative->SetState();

		for (T1& graphics : components)
		{
			graphics.SetGPUData(); //this is object specific data generally specified through uniforms
			graphics.Draw();
		}
		representative->RestoreState();
	}

	virtual void Clean() override
	{
		factory.CleanUp();
	}

	virtual bool MatchesID(UniqueID id) const override
	{
		return GetTypeID<T1>() == id;
	}

	virtual int Size() const override
	{
		return factory.Size();
	}

	Array<T1>& GetComponents()
	{
		return factory.GetComponents();
	}

	Array<ComponentHandle<T1>*>& GetHandles()
	{
		return factory.GetHandles();
	}

	bool IsMarkedForDelete(const ComponentHandleBase* handle) const
	{
		return factory.IsMarkedForDelete(handle);
	}

	template <typename Function>
	void Apply(Function& function)
	{
		factory.Apply(function);
	}

private:
	ComponentFactory<T1, Component> factory;
};