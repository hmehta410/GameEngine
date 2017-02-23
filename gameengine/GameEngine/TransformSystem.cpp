#include "TransformSystem.h"
#include "ComponentFactoryTransform.h"
#include "List/LinkedIterator.h"

void TransformSystem::Run(float)
{
	LinkedIterator it = this->transformFactory.GetHandles();
	for (Link* node = it.First(); !it.IsDone(); node = it.Next())
	{
		auto handle = (ComponentHandle<Transform>*)(PCSNode*)node;
		assert((*handle)->GetPosition().IsPoint());
		assert((*handle)->GetScale().IsVector());
		const Vect& scale = (*handle)->GetScale();
		const Quat& rot = (*handle)->GetRotation();
		const Vect& trans = (*handle)->GetPosition();

		(*handle)->SetLocalWorld(Matrix(WORLD, scale, rot, trans));

		const ComponentHandle<Transform>* parent = (*handle).GetParent();
		if (parent != nullptr)
		{
			(*handle)->SetGlobalWorld((*handle)->GetLocalWorld() * (*parent)->GetGlobalWorld());
		}
		else
		{
			(*handle)->SetGlobalWorld((*handle)->GetLocalWorld());
		}
	}
}

ComponentHandle<Transform>* TransformSystem::CreateTransform(ComponentHandle<Transform>* parent /*= nullptr*/)
{
	return transformFactory.CreateComponent(Vect(0.0f, 0.0f, 0.0f, 1.0f), Quat(), Vect(1.0f, 1.0f, 1.0f), parent);
}

ComponentHandle<Transform>* TransformSystem::CreateTransform(const Vect& position, const Quat& rotation, const Vect& scale, ComponentHandle<Transform>* parent /*= nullptr*/)
{
	return transformFactory.CreateComponent(position, rotation, scale, parent);
}

void TransformSystem::Reload()
{
	//I don't load any data
}

void TransformSystem::Clean()
{
	this->transformFactory.CleanUp();
}
