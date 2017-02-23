#include "GraphicsSystem.h"
#include "GraphicsObject.h"

GraphicsSystem::~GraphicsSystem()
{
	this->factories.DeleteList();
}

void GraphicsSystem::Run(float)
{
	LinkedIterator it = this->factories.GetIterator();
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		GraphicsFactory* shaderGroup = (GraphicsFactory*)link;
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
	LinkedIterator it = this->factories.GetIterator();
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		GraphicsFactory* factory = (GraphicsFactory*)link;
		factory->Clean();
	}
}
