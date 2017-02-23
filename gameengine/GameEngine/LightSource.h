#pragma once

#include "Math\MathEngine.h"
#include <Memory>

/*
A class created for convience when specifying lighting conditions in my shaders.
*/
class LightSource
{
public:
	LightSource();
	LightSource(const Vect& pos,const Vect& color, float intensity = 1.0f);

	LightSource(LightSource&& lightSource);
	LightSource(const LightSource& lightSource);

	LightSource& operator=(LightSource&& lightSource);
	LightSource& operator=(const LightSource& lightSource);

	const Vect& GetPosition() const;
	const Vect& GetColor() const;
	float GetIntensity() const;

private:
	std::unique_ptr<Vect> position;
	std::unique_ptr<Vect> color;
	float intensity;
};