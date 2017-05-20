#pragma once
#include "SystemBase.h"

/*
A system is just a container and a function. The function is applied to each element
in the container. This should allow for the most efficient instruction and data cache
access. 

Container needs an Apply(Function&) method that can accept Function as the parameter and a Clean()
method
EXAMPLE: 
class Container
{
public:
	template <typename Function>
	void Apply(Function& function)
	{
		for(auto& element : elements)
		{
			function(element);
		}
	}

	void Clean() {}

	std::vector elements;
}

Function is assumed to be some callable type that takes a type T similar to the type
held by Container. Any return value has no effect.
EXAMPLE: 
class Function
{
	void operator()(T& t) {}
}
*/
template <typename Container, typename Function>
class System : public SystemBase
{
public:
	System(Container* c, const Function& fun)
		:container(c), function(fun)
	{
	}

	template <typename... Args>
	System(Container* c, Args&&... args)
		: container(c), function(args...)
	{
	}

	virtual void Run() override
	{
		container->Apply(function);
	}

	virtual void Clean() override 
	{
		container->Clean();
	};

	void SetContainer(Container* c) { container = c; }
	Container* GetContainer() { return container; }

	Function& GetFunction() { return function; }

private:
	Function function;
	Container* container;
};


template <typename Container, typename Function>
System<Container, Function> CreateSystem(Container* container, const Function& f)
{
	return System<Container, Function>(container, f);
}

template <typename Container, typename Function>
System<Container, Function>* CreateNewSystem(Container* container, const Function& f)
{
	return new System<Container, Function>(container, f);
}