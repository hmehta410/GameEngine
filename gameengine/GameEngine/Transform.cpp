#include "Transform.h"
#include "UniqueID.h"
#include "Assert.h"

Transform::Transform()
	: localWorld(MatrixSpecialType::IDENTITY), globalWorld(MatrixSpecialType::IDENTITY), position(0.0f, 0.0f, 0.0f, 1.0f), rotation(), scale(1.0f, 1.0f, 1.0f),
	lockPosition(false), lockRotation(false), lockScale(false)
{
}

Transform::Transform(const Vect& position, const Quat& rotation, const Vect& scale)
	: localWorld(MatrixSpecialType::IDENTITY), globalWorld(MatrixSpecialType::IDENTITY), position(position), rotation(rotation), scale(scale),
	lockPosition(false), lockRotation(false), lockScale(false)
{
}

void Transform::SetPosition(const Vect& position)
{
	if (!lockPosition)
	{
		this->position = position;
	}
}

void Transform::SetRotation(const Quat& rotation)
{
	if (!lockRotation)
	{
		this->rotation = rotation;
	}
}

void Transform::SetScale(const Vect& scale)
{
	if (!lockScale)
	{
		this->scale = scale;
	}
}

const Matrix& Transform::GetLocalWorld() const
{
	return localWorld;
}

const Matrix& Transform::GetGlobalWorld() const
{
	return globalWorld;
}

const Vect& Transform::GetPosition() const
{
	return this->position;
}

const Quat& Transform::GetRotation() const
{
	return this->rotation;
}

const Vect& Transform::GetScale() const
{
	return this->scale;
}

void Transform::LockPosition(bool val)
{
	lockPosition = val;
}

void Transform::LockRotation(bool val)
{
	lockRotation = val;
}

void Transform::LockScale(bool val)
{
	lockScale = val;
}

bool Transform::IsPositionLocked() const
{
	return lockPosition;
}

bool Transform::IsRotationLocked() const
{
	return lockRotation;
}

bool Transform::IsScaleLocked() const
{
	return lockScale;
}

void Transform::SetLocalWorld(const Matrix& world)
{
	this->localWorld = world;
}

void Transform::SetGlobalWorld(const Matrix& world)
{
	this->globalWorld = world;
}
