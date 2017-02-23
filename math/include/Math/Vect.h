#pragma  once

// Includes to handle SIMD register types
#include <xmmintrin.h>
#include <smmintrin.h> 
#include "Constants.h"
#include "Enum.h"
#include "Align16.h"
// forward declare
class Matrix;

class Vect final : public Align16
{
public:
	Vect();
	Vect(float x, float y, float z, float w = 0.0f);
	Vect(const Vect& other);
	~Vect();

	Vect& operator=(const Vect& other);

	void Set(float x, float y, float z, float w = 0.0f);
	void Set(const Vect& other);

	float operator[](const x_enum) const;
	float operator[](const y_enum) const;
	float operator[](const z_enum) const;
	float operator[](const w_enum) const;
	float& operator[](const x_enum);
	float& operator[](const y_enum);
	float& operator[](const z_enum);
	float& operator[](const w_enum);

	float x() const;
	float y() const;
	float z() const;
	float w() const;
	float& x();
	float& y();
	float& z();
	float& w();

	bool IsZero(float tolerance = util::kTolerance) const;
	bool IsEqual(const Vect& other, float tolerance = util::kTolerance) const;
	bool IsNormalized(float tolerance = util::kTolerance) const;
	bool IsPoint() const;
	bool IsVector() const;

	Vect& operator+=(const Vect& other);
	Vect& operator-=(const Vect& other);
	Vect& operator*=(const Matrix& matrix);
	Vect& operator*=(const float scalar);
	Vect operator+(const Vect& other) const;
	Vect operator-(const Vect& other) const;
	Vect operator*(const Matrix& matrix) const;

	Vect operator+();
	Vect operator-();

	float Dot(const Vect& other) const;
	Vect Cross(const Vect& other) const;
	Vect& Normalize();
	Vect GetNormalized() const;
	float Magnitude() const;
	float MagSquared() const;
	float GetAngle(const Vect& other) const;


private:

// Level 4 complains nameless struct/union ...
#pragma warning( disable : 4201)

	// anonymous union
	union 
	{
		__m128	m;

		// anonymous struct
		struct 
			{
			float x_;
			float y_;
			float z_;
			float w_;
			};
	};
};

Vect operator*(float scalar, const Vect& v);
Vect operator*(const Vect& v, float scalar);
Vect operator/(const Vect& v, float scalar);
//multiplication by parts. v_out = (x1*x2, y1*y2, z1*z2, w1*w2);
Vect operator*(const Vect& v1, const Vect& v2);
//division by parts. v_out = (x1/x2, y1/y2, z1/z2, w1/w2);
Vect operator/(const Vect& v1, const Vect& v2);
