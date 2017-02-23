#pragma once

#include "Matrix.h"
#include "Enum.h"

// SIMD includes
#include <xmmintrin.h>
#include <smmintrin.h> 


	/*************************************************************************
	*
	* This class contains functions and data structure for a 4-dimensional 
	* Quaternions.  The quaternions are internally stored in terms of the 
	* imaginary components (qx,qy,qz) and the real components (qw).
	*
	* In the Math library, quaternions can be thought of as "rotational"
	* matrices, everything that you can represent with rotational matrices
	* you can use with quaternions.  Such as quaternion concatenation,
	* inverses, transpose, normalize, multiplying with matrices, and with
	* vectors.
	*  
	*  
	**************************************************************************/

class Quat final : public Align16
{
public:
	Quat();
	Quat(const Quat& other);
	Quat(float x, float y, float z, float w);
	Quat(const Vect& v, float real);
	Quat(const Matrix& matrix);
	Quat(RotType rot_type, float radians);
	Quat(RotAxisAngleType type, const Vect& v, float radians);
	Quat(RotOrientType type, const Vect& v1, const Vect& v2);
	Quat(Rot3AxisType type, float x, float y, float z);

	~Quat();

	void Set(RotOrientType type, const Vect& v, const Vect& v2);
	void Set(RotType rot_type, float radians);
	void Set(const Matrix& m);
	void Set(RotAxisAngleType type, const Vect& v, float radians);
	void Set(Rot3AxisType type, float x, float y, float z);
	void Set(float x, float y, float z, float w);
	void Set(const Vect& v, float real);
	void Set(MatrixSpecialType zero);
	void SetAxis(const Vect& v);

	Quat& operator=(const Quat& quat);

	bool IsEqual(const Quat& quat, float epsilon) const;
	bool IsEquivalent(const Quat& quat, float epsilon) const;
	bool IsOpposite(const Quat& quat, float epsilon) const;
	bool IsConjugateEqual(const Quat& quat, float epsilon) const;
	bool IsIdentity(float epsilon) const;
	bool IsNormalized(float epsilon) const;
	bool IsZero(float epsilon) const;

	float& operator[](x_enum x);
	float& operator[](y_enum y);
	float& operator[](z_enum z);
	float& operator[](w_enum w);
	float operator[](x_enum x) const;
	float operator[](y_enum y) const;
	float operator[](z_enum z) const;
	float operator[](w_enum w) const;

	Quat MultByElement(const Quat& q);

	float GetAngle() const;
	void GetAxis(Vect& out) const;
	Vect GetAxis() const;

	//linear op => quat * vect * quat_conjugate    quat_conjugate == quat_inverse for unit_quat
	//Lqvqc == rotation_matrix * column_vector
	void Lqvqc(const Vect& v1, Vect& v_out) const;
	Vect Lqvqc(const Vect& v1) const;
	
	//Lqcvq == row_vector * rotation_matrix
	void Lqcvq(const Vect& v1, Vect& v_out) const;
	Vect Lqcvq(const Vect& v1) const;

	float Dot(const Quat& q) const;

	float Magnitude() const;
	float MagSquared() const;
	float InverseMag() const;

	Quat GetConjugate() const;
	Quat& Conjugate();

	Quat GetTranspose() const;
	Quat& Transpose();

	Quat GetInverse() const;
	Quat& Inverse();

	Quat GetNormalized() const;
	Quat& Normalize();

	Quat operator+();
	Quat operator+(const Quat& other) const;
	Quat operator+= (const Quat& other);
	Quat operator+(float c) const;
	Quat operator+=(float c);

	Quat operator-();
	Quat operator-(const Quat& other) const;
	Quat operator-= (const Quat& other);
	Quat operator-(float c) const;
	Quat operator-=(float c);

	Quat operator*(const Quat& other) const;
	Quat operator*= (const Quat& other);
	Quat operator*(float c) const;
	Quat operator*=(float c);

	Quat operator/(const Quat& other) const;
	Quat operator/= (const Quat& other);
	Quat operator/(float c) const;
	Quat operator/=(float c);


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
			float qx;
			float qy;
			float qz;
			float qw;
			};
	};


};

Quat operator+(float c, const Quat& quat);
Quat operator-(float c, const Quat& quat);
Quat operator*(float c, const Quat& quat);
Quat operator/(float c, const Quat& quat);
