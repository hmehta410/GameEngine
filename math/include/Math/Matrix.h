#pragma once

// SIMD includes
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Enum.h"
#include "Vect.h"

class Quat;

   
class Matrix final : public Align16
{
public:

	Matrix();
	Matrix(const Matrix& matrix);
	Matrix(const Vect& v0, const Vect& v1, const Vect& v2, const Vect& v3);
	Matrix(const MatrixSpecialType type);
	Matrix(const MatrixTransType type, const Vect& v);
	Matrix(const MatrixSkewSymmetricType type, const Vect& v);
	Matrix(const MatrixTransType type, float x, float y, float z);
	Matrix(const MatrixScaleType type, const Vect& v);
	Matrix(const MatrixScaleType type, float x, float y, float z);
	Matrix(const RotType type, const float angle);
	Matrix(const Rot3AxisType type, float x, float y, float z);
	Matrix(const RotAxisAngleType type, const Vect& c, float radians);
	Matrix(const RotOrientType type, const Vect& v, const Vect& v2);
	Matrix(const WorldType type, const Vect& scale, const Matrix& rot, const Vect& trans);
	Matrix(const Quat& q);

	Matrix& operator=(const Matrix& o);

	~Matrix();

	bool IsEqual(const Matrix& other, const float tolerance = util::kTolerance) const;
	bool IsIdentity(const float tolerance = util::kTolerance) const;

	float GetDeterminant() const;
	Matrix& Transpose();
	Matrix GetTranspose() const;

	Matrix& Inverse();
	Matrix GetInverse() const;

	void Set(const MatrixSpecialType type);
	void Set(const MatrixSkewSymmetricType type, const Vect& v);
	void Set(const MatrixTransType type, const Vect& v);
	void Set(const MatrixTransType type, const float x, const float y, const float z);
	void Set(const MatrixScaleType type, const Vect& v);
	void Set(const MatrixScaleType type, const float x, const float y, const float z);
	void Set(const RotType type, float rot);
	void Set(const MatrixRowType type, const Vect& v);
	void Set(const Vect& v0, const Vect& v1, const Vect& v2, const Vect& v3);
	void Set(const Quat& q);
	void Set(const RotAxisAngleType type, const Vect& v, float radians);
	void Set(const RotOrientType type, const Vect& v1, const Vect& v2);
	void Set(const Rot3AxisType type, const float x, const float y, const float z);
	void Set(const Matrix& m);

	Vect GetRow(const MatrixRowType type) const;

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(float scale);
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix operator*(float scale) const;

	Matrix operator+();
	Matrix operator-();

	float operator[](const m0_enum) const;
	float operator[](const m1_enum) const;
	float operator[](const m2_enum) const;
	float operator[](const m3_enum) const;
	float operator[](const m4_enum) const;
	float operator[](const m5_enum) const;
	float operator[](const m6_enum) const;
	float operator[](const m7_enum) const;
	float operator[](const m8_enum) const;
	float operator[](const m9_enum) const;
	float operator[](const m10_enum) const;
	float operator[](const m11_enum) const;
	float operator[](const m12_enum) const;
	float operator[](const m13_enum) const;
	float operator[](const m14_enum) const;
	float operator[](const m15_enum) const;

	float& operator[](const m0_enum);
	float& operator[](const m1_enum);
	float& operator[](const m2_enum);
	float& operator[](const m3_enum);
	float& operator[](const m4_enum);
	float& operator[](const m5_enum);
	float& operator[](const m6_enum);
	float& operator[](const m7_enum);
	float& operator[](const m8_enum);
	float& operator[](const m9_enum);
	float& operator[](const m10_enum);
	float& operator[](const m11_enum);
	float& operator[](const m12_enum);
	float& operator[](const m13_enum);
	float& operator[](const m14_enum);
	float& operator[](const m15_enum);

	float& m0();
	float& m1();
	float& m2();
	float& m3();
	float& m4();
	float& m5();
	float& m6();
	float& m7();
	float& m8();
	float& m9();
	float& m10();
	float& m11();
	float& m12();
	float& m13();
	float& m14();
	float& m15();

	float m0() const;
	float m1() const;
	float m2() const;
	float m3() const;
	float m4() const;
	float m5() const;
	float m6() const;
	float m7() const;
	float m8() const;
	float m9() const;
	float m10() const;
	float m11() const;
	float m12() const;
	float m13() const;
	float m14() const;
	float m15() const;

private:

// Level 4 warnings complains nameless struct/union ...
#pragma warning( disable : 4201)

union 
		{
		struct 
			{
			Vect v0_;
			Vect v1_;
			Vect v2_;
			Vect v3_;
			};

		struct 
			{
			float m0_;
			float m1_;
			float m2_;
			float m3_;
			float m4_;
			float m5_;
			float m6_;	
			float m7_;
			float m8_;
			float m9_;
			float m10_;
			float m11_;
			float m12_;
			float m13_;
			float m14_;
			float m15_;
			};
		};
};

Matrix operator*(float scale, const Matrix& other);
