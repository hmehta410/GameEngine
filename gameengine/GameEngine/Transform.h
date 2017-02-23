#pragma once

#include "Component.h"
#include "Math\MathEngine.h"
#include "List\Link.h"

/*
This class contains the position, rotation, and scale. 
It allows position, rotation, and scale to be locked.
It holds the local and global matrix. 
It is likely the most critical component
*/
class Transform : public Component, public Align16
{
public:
	Transform();
	Transform(const Vect& position, const Quat& rotation, const Vect& scale);

	void SetPosition(const Vect& position);
	void SetRotation(const Quat& rotation);
	void SetScale(const Vect& scale);
	void SetLocalWorld(const Matrix& world);
	void SetGlobalWorld(const Matrix& world);

	const Matrix& GetLocalWorld() const;
	const Matrix& GetGlobalWorld() const;
	const Vect& GetPosition() const;
	const Quat& GetRotation() const;
	const Vect& GetScale() const;

	void LockPosition(bool val);
	void LockRotation(bool val);
	void LockScale(bool val);

	bool IsPositionLocked() const;
	bool IsRotationLocked() const;
	bool IsScaleLocked() const;

private:
	Matrix localWorld;
	Matrix globalWorld;

	Vect position;
	Quat rotation;
	Vect scale;

	bool lockPosition;
	bool lockRotation;
	bool lockScale;
};