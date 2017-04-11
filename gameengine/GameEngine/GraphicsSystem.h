#pragma once
#include "System.h"
#include "UniqueId.h"
#include "ComponentFactoryGraphicsObject.h"
#include "List/DList.h"

class GraphicsObject;

/*
The Graphics System works a little differently from most other systems in that rather 
than having a single type of component to work with there are many types all derived 
from a base GraphicsObject. So instead of owning a factory, it is up to the user to 
add factories for any of the derived graphics objects used. The user will instantiate
components through the factories and then the system will act on the factories' pool
of components.
*/
class GraphicsSystem : public System
{
public:
	~GraphicsSystem();

	virtual void Reload() override;
	void Run(float time) override;
	virtual void Clean() override;

	void AddFactory(std::unique_ptr<GraphicsFactory> group);
	void RemoveFactory(GraphicsFactory* group);
	
	//Returns the first found ShaderGroup of type T or otherwise returns nullptr.
	//You generally will use Foo as type T not ComponentHandle<Foo>
	template <typename T>
	ComponentFactory<T>* GetComponentFactory() const
	{
		auto it = factories.GetIterator();
		for (GraphicsFactory* factory = it.First(); !it.IsDone(); factory = it.Next())
		{
			if (factory->MatchesID(GetTypeID<T>()))
			{
				return (ComponentFactory<T>*)factory;
			}
		}

		return nullptr;
	}

private:
	DList<GraphicsFactory> factories;
};