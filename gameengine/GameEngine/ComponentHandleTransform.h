#pragma once

#include "ComponentHandle.h"
#include "Transform.h"
#include "PCSTree/PCSNode.h"

template<>
class ComponentFactory < Transform, typename Transform::FactorySpecialization > ;

/*
ComponentHandle<Transform> has been specialized to be a PCSNode for easy placement 
in a tree hierarchy and to have a direct transform rather than an extra layer of indirection
like most handles. A transform is constructed directly in place of the handle.
*/
template<>
class ComponentHandle<Transform> : public ComponentHandleBase, public PCSNode, public Align16
{
public:
	ComponentHandle(const Vect& pos, const Quat& rot, const Vect& scale);

	virtual bool MatchesID(UniqueID id) const override;
	const ComponentHandle<Transform>* GetParent() const;

	Transform* operator->()
	{
		return &this->transform;
	}

	const Transform* operator->() const
	{
		return &this->transform;
	}

	virtual Transform* GetValue() override;
	Transform& GetReference();

	void SetValue(const Transform& trans);

	virtual void MarkForDelete() override;

	virtual bool IsMarkedForDelete() const override;

private:
	ComponentFactory<Transform>* factory;

	static UniqueID transformID;

	Transform transform;

	friend class TransformSystem;
	friend class ComponentFactory < Transform, typename Transform::FactorySpecialization >;
};
