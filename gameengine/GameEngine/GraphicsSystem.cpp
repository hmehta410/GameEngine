#include "GraphicsSystem.h"
#include "GraphicsObject.h"

GraphicsSystem::~GraphicsSystem()
{
	this->factories.DeleteList();
}

void GraphicsSystem::Run()
{
	auto it = this->factories.GetIterator();
	for (GraphicsFactory* shaderGroup = it.First(); !it.IsDone(); shaderGroup = it.Next())
	{
		shaderGroup->Draw();
	}
}

void GraphicsSystem::AddFactory(std::unique_ptr<GraphicsFactory> group)
{
	this->factories.PushBack(group.release());
}

void GraphicsSystem::RemoveFactory(GraphicsFactory* group)
{
	this->factories.Remove(group);
}

void GraphicsSystem::Reload()
{
	//Reload is unnecessary 
}

void GraphicsSystem::Clean()
{
	auto it = this->factories.GetIterator();
	for (auto factory = it.First(); !it.IsDone(); factory = it.Next())
	{
		factory->Clean();
	}
}
