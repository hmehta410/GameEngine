#include "LightSource.h"

LightSource::LightSource() 
	: position(new Vect(0, 0, 0, 0)), color(new Vect(1, 1, 1, 0)), intensity(1.0f)
{
}

LightSource::LightSource(const Vect& pos, const Vect& color, float intensity)
	:position(new Vect(pos)), color(new Vect(color)), intensity(intensity)
{
}

LightSource::LightSource(LightSource&& o) 
	: position(std::move(o.position)), color(std::move(o.color)), intensity(intensity)
{
}

LightSource::LightSource(const LightSource& o)
	: position(new Vect(*o.position)), color(new Vect(*o.color)), intensity(intensity)
{
}

LightSource& LightSource::operator=(LightSource&& o)
{
	if (this != &o)
	{
		this->position = std::move(o.position);
		this->color = std::move(o.color);
		this->intensity = intensity;
	}
	return *this;
}

LightSource& LightSource::operator=(const LightSource& o)
{
	if (this != &o)
	{
		this->position.reset(new Vect(*o.position));
		this->color.reset(new Vect(*o.color));
		this->intensity = intensity;
	}
	return *this;
}

const Vect& LightSource::GetPosition() const
{
	return *this->position;
}

const Vect& LightSource::GetColor() const
{
	return *this->color;
}

float LightSource::GetIntensity() const
{
	return this->intensity;
}
