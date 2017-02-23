#include "MathEngine.h"
#include <math.h>
#include <assert.h>
#include <smmintrin.h>


Vect::Vect()
	: x_(0.0f), y_(0.0f), z_(0.0f), w_(0.0f)
{
}

Vect::Vect(float x, float y, float z, float w)
	: x_(x), y_(y), z_(z), w_(w)
{
}

Vect::Vect(const Vect& other)
	: x_(other.x_), y_(other.y_), z_(other.z_), w_(other.w_)
{
}

Vect::~Vect()
{
}

void Vect::Set(float x, float y, float z, float w)
{
	this->x_ = x;
	this->y_ = y;
	this->z_ = z;
	this->w_ = w;
}

void Vect::Set(const Vect& other)
{
	this->x_ = other.x_;
	this->y_ = other.y_;
	this->z_ = other.z_;
	this->w_ = other.w_;
}

float Vect::x() const
{
	return this->x_;
}

float Vect::y() const
{
	return this->y_;
}

float Vect::z() const
{
	return this->z_;
}

float Vect::w() const
{
	return this->w_;
}

float& Vect::x()
{
	return this->x_;
}

float& Vect::y()
{
	return this->y_;
}
float& Vect::z()
{
	return this->z_;
}
float& Vect::w()
{
	return this->w_;
}

float Vect::operator[](const x_enum) const
{
	return this->x_;
}

float Vect::operator[](const y_enum) const
{
	return this->y_;
}

float Vect::operator[](const z_enum) const
{
	return this->z_;
}

float Vect::operator[](const w_enum) const
{
	return this->w_;
}

float& Vect::operator[](const x_enum)
{
	return this->x_;
}

float& Vect::operator[](const y_enum)
{
	return this->y_;
}

float& Vect::operator[](const z_enum)
{
	return this->z_;
}

float& Vect::operator[](const w_enum)
{
	return this->w_;
}

bool Vect::IsZero(float tolerance /*= util::kTolerance*/) const
{
	return util::IsEqual(this->x_, 0.0f, tolerance) &&
		util::IsEqual(this->y_, 0.0f, tolerance) &&
		util::IsEqual(this->z_, 0.0f, tolerance);
}

bool Vect::IsEqual(const Vect& other, float tolerance) const
{
	return util::IsEqual(this->x_, other.x_, tolerance) && 
		util::IsEqual(this->y_, other.y_, tolerance) && 
		util::IsEqual(this->z_, other.z_, tolerance) && 
		util::IsEqual(this->w_, other.w_, tolerance);
}

Vect& Vect::operator+=(const Vect& other)
{
	this->x_ += other.x_;
	this->y_ += other.y_;
	this->z_ += other.z_;
	this->w_ += other.w_;

	return *this;
}

Vect& Vect::operator-=(const Vect& other)
{
	this->x_ -= other.x_;
	this->y_ -= other.y_;
	this->z_ -= other.z_;
	this->w_ -= other.w_;

	return *this;
}

Vect& Vect::operator*=(const Matrix& matrix)
{
	float x = x_ * matrix[m0] + y_ * matrix[m4] + z_ * matrix[m8] + w_*matrix[m12];
	float y = x_ * matrix[m1] + y_ * matrix[m5] + z_ * matrix[m9] + w_*matrix[m13];
	float z = x_ * matrix[m2] + y_ * matrix[m6] + z_ * matrix[m10] + w_*matrix[m14];
	float w = x_ * matrix[m3] + y_ * matrix[m7] + z_ * matrix[m11] + w_*matrix[m15];

	this->x_ = x;
	this->y_ = y;
	this->z_ = z;
	this->w_ = w;

	return *this;
}

Vect Vect::operator+(const Vect& other) const
{
	float x = this->x_ + other.x_;
	float y = this->y_ + other.y_;
	float z = this->z_ + other.z_;
	float w = this->w_ + other.w_;

	return Vect(x, y, z, w);
}

Vect Vect::operator-(const Vect& other) const
{
	float x = this->x_ - other.x_;
	float y = this->y_ - other.y_;
	float z = this->z_ - other.z_;
	float w = this->w_ - other.w_;

	return Vect(x, y, z, w);
}

Vect Vect::operator*(const Matrix& matrix) const
{
	float x = x_ * matrix[m0] + y_ * matrix[m4] + z_ * matrix[m8] + w_*matrix[m12];
	float y = x_ * matrix[m1] + y_ * matrix[m5] + z_ * matrix[m9] + w_*matrix[m13];
	float z = x_ * matrix[m2] + y_ * matrix[m6] + z_ * matrix[m10] + w_*matrix[m14];
	float w = x_ * matrix[m3] + y_ * matrix[m7] + z_ * matrix[m11] + w_*matrix[m15];

	return Vect(x, y, z, w);
}

Vect Vect::operator+()
{
	return Vect(this->x_, this->y_, this->z_, this->w_);
}

Vect Vect::operator-()
{
	return Vect(-this->x_, -this->y_, -this->z_, this->w_);
}

Vect& Vect::operator=(const Vect& other)
{
	if (this != &other)
	{
		this->x_ = other.x_;
		this->y_ = other.y_;
		this->z_ = other.z_;
		this->w_ = other.w_;
	}

	return *this;
}


Vect& Vect::operator*=(const float scalar)
{
	this->x_ *= scalar;
	this->y_ *= scalar;
	this->z_ *= scalar;

	return *this;
}

float Vect::Dot(const Vect& other) const
{
	return this->x_*other.x_ + this->y_*other.y_ + this->z_*other.z_;
}

Vect Vect::Cross(const Vect& other) const
{
	float i = this->y_*other.z_ - this->z_*other.y_;
	float j = this->x_*other.z_ - this->z_*other.x_;
	float k = this->x_*other.y_ - this->y_*other.x_;

	//you can only cross two vectors making the w_ element hard coded to 0.
	return Vect(i, -j, k, 0.0f);
}

Vect& Vect::Normalize()
{
	float magnitude_sqr = (this->x_ * this->x_) + (this->y_ * this->y_) + (this->z_ * this->z_);

	float one_over_magnitude = 0;
	if (magnitude_sqr > 0.000001f)
	{
		one_over_magnitude = 1.0f / util::Sqrt(magnitude_sqr);
	}

	this->x_ *= one_over_magnitude;
	this->y_ *= one_over_magnitude;
	this->z_ *= one_over_magnitude;

	return *this;
}

Vect Vect::GetNormalized() const
{
	float inverse_mag = this->Magnitude();

	if (inverse_mag > 0.0f)
	{
		inverse_mag = 1 / inverse_mag;
	}

	float x = this->x_ * inverse_mag;
	float y = this->y_ * inverse_mag;
	float z = this->z_ * inverse_mag;

	return Vect(x, y, z, this->w_);
}

float Vect::Magnitude() const
{
	float magnitude_sqr = this->MagSquared();

	if (magnitude_sqr > 0.0001f)
	{
		return util::Sqrt(magnitude_sqr);
	}
	else
	{
		return 0.0f;
	}
}

float Vect::MagSquared() const
{
	//static const int mask = 0xE1; // 1110 0001
	//float* p = (float*)&_mm_dp_ps(this->m, this->m, mask).m128_f32;
	//return *p;
	return (this->x_ * this->x_) + (this->y_ * this->y_) + (this->z_ * this->z_);
}

float Vect::GetAngle(const Vect& other) const
{
	float magA = this->Magnitude();
	float magB = other.Magnitude();

	float cosTheta = this->Dot(other) / (magA*magB);
	return acosf(cosTheta);
}

bool Vect::IsPoint() const
{
	return util::IsOne(this->w_, util::kTolerance);
}

bool Vect::IsVector() const
{
	return util::IsZero(this->w_, util::kTolerance);
}

bool Vect::IsNormalized(float tolerance) const
{
	return util::IsOne(this->MagSquared(), tolerance);
}

Vect operator*(float scalar, const Vect& v)
{
	float x = v.x() * scalar;
	float y = v.y() * scalar;
	float z = v.z() * scalar;
	float w = v.w() * scalar;

	return Vect(x, y, z, w);
}

Vect operator*(const Vect& v, float scalar)
{
	float x = v.x() * scalar;
	float y = v.y() * scalar;
	float z = v.z() * scalar;
	float w = v.w() * scalar;

	return Vect(x, y, z, w);
}

Vect operator/(const Vect& v, float scalar)
{
	float x = v.x() / scalar;
	float y = v.y() / scalar;
	float z = v.z() / scalar;
	float w = v.w() / scalar;

	return Vect(x, y, z, w);
}

Vect operator*(const Vect& v1, const Vect& v2)
{
	float x = v1.x() * v2.x();
	float y = v1.y() * v2.y();
	float z = v1.z() * v2.z();
	float w = v1.w() * v2.w();

	return Vect(x, y, z, w);
}

Vect operator/(const Vect& v1, const Vect& v2)
{
	float x = v1.x() / v2.x();
	float y = v1.y() / v2.y();
	float z = v1.z() / v2.z();
	float w = v1.w() / v2.w();

	return Vect(x, y, z, w);
}