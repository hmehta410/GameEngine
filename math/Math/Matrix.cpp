#include "MathEngine.h"
#include <math.h>
#include <assert.h>
#include <algorithm>

Matrix::Matrix()
	: m0_(0.0f), m1_(0.0f), m2_(0.0f), m3_(0.0f),
	m4_(0.0f), m5_(0.0f), m6_(0.0f), m7_(0.0f),
	m8_(0.0f), m9_(0.0f), m10_(0.0f), m11_(0.0f),
	m12_(0.0f), m13_(0.0f), m14_(0.0f), m15_(0.0f)
{
}

Matrix::Matrix(const MatrixSpecialType type)
	: m0_(1.0f), m1_(0.0f), m2_(0.0f), m3_(0.0f),
	m4_(0.0f), m5_(1.0f), m6_(0.0f), m7_(0.0f),
	m8_(0.0f), m9_(0.0f), m10_(1.0f), m11_(0.0f),
	m12_(0.0f), m13_(0.0f), m14_(0.0f), m15_(1.0f)
{
	if (type == ZERO)
	{
		m0_ = 0.0f;
		m5_ = 0.0f;
		m10_ = 0.0f;
		m15_ = 0.0f;
	}
}

Matrix::Matrix(const MatrixTransType, const Vect& v)
	: m0_(1.0f), m1_(0.0f), m2_(0.0f), m3_(0.0f),
	m4_(0.0f), m5_(1.0f), m6_(0.0f), m7_(0.0f),
	m8_(0.0f), m9_(0.0f), m10_(1.0f), m11_(0.0f),
	v3_(v)
{
	m15_ = 1.0f;
}

Matrix::Matrix(const MatrixTransType, float x, float y, float z)
	: m0_(1.0f), m1_(0.0f), m2_(0.0f), m3_(0.0f),
	m4_(0.0f), m5_(1.0f), m6_(0.0f), m7_(0.0f),
	m8_(0.0f), m9_(0.0f), m10_(1.0f), m11_(0.0f),
	m12_(x), m13_(y), m14_(z), m15_(1.0f)
{
}

Matrix::Matrix(const MatrixSkewSymmetricType, const Vect& v)
	: m0_(0.0f), m1_(-v.z()), m2_(v.y()), m3_(0.0f),
	m4_(v.z()), m5_(0.0f), m6_(-v.x()), m7_(0.0f),
	m8_(-v.y()), m9_(v.x()), m10_(0.0f), m11_(0.0f),
	m12_(0.0f), m13_(0.0f), m14_(0.0f), m15_(1.0f)
{
}

Matrix::Matrix(const MatrixScaleType, const Vect& v)
	: m0_(v[x]), m1_(0.0f), m2_(0.0f), m3_(0.0f),
	m4_(0.0f), m5_(v[y]), m6_(0.0f), m7_(0.0f),
	m8_(0.0f), m9_(0.0f), m10_(v[z]), m11_(0.0f),
	m12_(0.0f), m13_(0.0f), m14_(0.0f), m15_(1.0f)
{
}

Matrix::Matrix(const MatrixScaleType, float x, float y, float z)
	: m0_(x), m1_(0.0f), m2_(0.0f), m3_(0.0f),
	m4_(0.0f), m5_(y), m6_(0.0f), m7_(0.0f),
	m8_(0.0f), m9_(0.0f), m10_(z), m11_(0.0f),
	m12_(0.0f), m13_(0.0f), m14_(0.0f), m15_(1.0f)
{
}

Matrix::Matrix(const Vect& v0, const Vect& v1, const Vect& v2, const Vect& v3)
	: v0_(v0), v1_(v1), v2_(v2), v3_(v3)
{
}

Matrix::Matrix(const RotType type, const float angle)
	: m0_(1.0f), m1_(0.0f), m2_(0.0f), m3_(0.0f),
	m4_(0.0f), m5_(1.0f), m6_(0.0f), m7_(0.0f),
	m8_(0.0f), m9_(0.0f), m10_(1.0f), m11_(0.0f),
	m12_(0.0f), m13_(0.0f), m14_(0.0f), m15_(1.0f)
{
	float sin = sinf(angle);
	float cos = cosf(angle);

	switch (type)
	{
	case ROT_X:
		this->m5_ = cos;
		this->m6_ = sin;
		this->m9_ = -sin;
		this->m10_ = cos;
		break;
	case ROT_Y:
		this->m0_ = cos;
		this->m8_ = sin;
		this->m2_ = -sin;
		this->m10_ = cos;
		break;
	case ROT_Z:
		this->m0_ = cos;
		this->m1_ = sin;
		this->m4_ = -sin;
		this->m5_ = cos;
		break;
	}
}

Matrix::Matrix(const Matrix& m)
	: v0_(m.v0_), v1_(m.v1_), v2_(m.v2_), v3_(m.v3_)
{
}

Matrix::Matrix(const Quat& quat)
	: m3_(0.0f), m7_(0.0f), m11_(0.0f),
	m12_(0.0f), m13_(0.0f), m14_(0.0f), m15_(1.0f)
{
	this->Set(quat);
}

Matrix::Matrix(const Rot3AxisType type, float x, float y, float z)
{
	this->Set(type, x, y, z);
}

Matrix::Matrix(const RotAxisAngleType type, const Vect& vect, float radians)
{
	this->Set(type, vect, radians);
}

Matrix::Matrix(const RotOrientType type, const Vect& v, const Vect& v2)
{
	this->Set(type, v, v2);
}

Matrix::Matrix(const WorldType, const Vect& scale, const Matrix& rot, const Vect& trans)
	: v0_(rot.v0_), v1_(rot.v1_), v2_(rot.v2_), v3_(trans)
{
	this->v0_ *= scale[x];
	this->v1_ *= scale[y];
	this->v2_ *= scale[z];
	this->m15_ = 1.0f;
}

void Matrix::Set(const Matrix& m)
{
	this->v0_ = m.v0_;
	this->v1_ = m.v1_;
	this->v2_ = m.v2_;
	this->v3_ = m.v3_;
}

void Matrix::Set(const Quat& quat)
{
	Quat q = quat.GetNormalized();
	Matrix& m = *this;
	m.m0() = 1 - 2 * (q[y] * q[y] + q[z] * q[z]);
	m.m1() = 2 * (q[x] * q[y] + q[w] * q[z]);
	m.m2() = 2 * (q[x] * q[z] - q[w] * q[y]);
		
	m.m4() = 2 * (q[x] * q[y] - q[w] * q[z]);
	m.m5() = 1 - 2 * (q[x] * q[x] + q[z] * q[z]);
	m.m6() = 2 * (q[y] * q[z] + q[w] * q[x]);
		
	m.m8() = 2 * (q[x] * q[z] + q[w] * q[y]);
	m.m9() = 2 * (q[y] * q[z] - q[w] * q[x]);
	m.m10() = 1 - 2 * (q[x] * q[x] + q[y] * q[y]);
	m.m15() = 1;
}

void Matrix::Set(const RotAxisAngleType, const Vect& vect, float radians)
{
	Vect normalized = vect.GetNormalized();

	normalized[x] *= -1;
	normalized[y] *= -1;
	normalized[z] *= -1;

	float cos_theta = cosf(radians);
	float sin_theta = sinf(radians);

	float u = normalized[x];
	float v = normalized[y];
	float w = normalized[z];

	m0_ = u*u + (v*v + w*w)*cos_theta;
	m1_ = u*v*(1 - cos_theta) - w*sin_theta;
	m2_ = u*w*(1 - cos_theta) + v*sin_theta;
	m3_ = 0.0f;
	m4_ = u*v*(1 - cos_theta) + w*sin_theta;
	m5_ = v*v + (u*u + w*w)*cos_theta;
	m6_ = v*w*(1 - cos_theta) - u*sin_theta;
	m7_ = 0.0f;
	m8_ = u*w*(1 - cos_theta) - v*sin_theta;
	m9_ = v*w*(1 - cos_theta) + u*sin_theta;
	m10_ = w*w + (u*u + v*v)*cos_theta;
	m11_ = 0.0f;
	m12_ = 0.0f;
	m13_ = 0.0f;
	m14_ = 0.0f;
	m15_ = 1.0f;
}

void Matrix::Set(const RotOrientType type, const Vect& direction_of_flight, const Vect& up)
{
	Vect dof = direction_of_flight.GetNormalized();
	Vect up_norm = up.GetNormalized();
	Vect vx = up_norm.Cross(dof);
	Vect vy = dof.Cross(vx);

	if (ROT_ORIENT == type)
	{
		m0_ = vx[x];
		m1_ = vx[y];
		m2_ = vx[z];
		m3_ = 0.0f;
		m4_ = vy[x];
		m5_ = vy[y];
		m6_ = vy[z];
		m7_ = 0.0f;
		m8_ = dof[x];
		m9_ = dof[y];
		m10_ = dof[z];
		m11_ = 0.0f;
		m12_ = 0.0f;
		m13_ = 0.0f;
		m14_ = 0.0f;
		m15_ = 1.0f;
	}
	else
	{
		m0_ = vx[x];
		m1_ = vy[x];
		m2_ = dof[x];
		m3_ = 0.0f;
		m4_ = vx[y];
		m5_ = vy[y];
		m6_ = dof[y];
		m7_ = 0.0f;
		m8_ = vx[z];
		m9_ = vy[z];
		m10_ = dof[z];
		m11_ = 0.0f;
		m12_ = 0.0f;
		m13_ = 0.0f;
		m14_ = 0.0f;
		m15_ = 1.0f;
	}
}

void Matrix::Set(const Rot3AxisType, const float x, const float y, const float z)
{
	Matrix m1(ROT_X, x);
	Matrix m2(ROT_Y, y);
	Matrix m3(ROT_Z, z);

	*this = m1*m2*m3;
}

void Matrix::Set(const MatrixSkewSymmetricType, const Vect& v)
{
	m0_ = 0.0f; m1_ = -v[z]; m2_ = v[y]; m3_ = 0.0f;
	m4_ = v[z]; m5_ = 0.0f; m6_ = -v[x]; m7_ = 0.0f;
	m8_ = -v[y]; m9_ = v[x]; m10_ = 0.0f; m11_ = 0.0f;
	m12_ = 0.0f; m13_ = 0.0f; m14_ = 0.0f; m15_ = 1.0f;
}

Matrix::~Matrix()
{
}

bool Matrix::IsEqual(const Matrix& other, const float tolerance) const
{
	return this->v0_.IsEqual(other.v0_, tolerance) 
		&& this->v1_.IsEqual(other.v1_, tolerance) 
		&& this->v2_.IsEqual(other.v2_, tolerance) 
		&& this->v3_.IsEqual(other.v3_, tolerance);
}

bool Matrix::IsIdentity(const float tolerance) const
{
	return this->v0_.IsEqual(Vect(1, 0, 0, 0), tolerance) 
		&& this->v1_.IsEqual(Vect(0, 1, 0, 0), tolerance) 
		&& this->v2_.IsEqual(Vect(0, 0, 1, 0), tolerance) 
		&& this->v3_.IsEqual(Vect(0, 0, 0, 1), tolerance);
}

float Matrix::GetDeterminant() const
{
	return m0_*(m5_*(m10_*m15_ - m11_*m14_) - m6_*(m9_*m15_ - m11_*m13_) + m7_*(m9_*m14_ - m10_*m13_))
		- m1_*(m4_*(m10_*m15_ - m11_*m14_) - m6_*(m8_*m15_ - m11_*m12_) + m7_*(m8_*m14_ - m10_*m12_))
		+ m2_*(m4_*(m9_*m15_ - m11_*m13_) - m5_*(m8_*m15_ - m11_*m12_) + m7_*(m8_*m13_ - m9_*m12_))
		- m3_*(m4_*(m9_*m14_ - m10_*m13_) - m5_*(m8_*m14_ - m10_*m12_) + m6_*(m8_*m13_ - m9_*m12_));
}

Matrix& Matrix::Transpose()
{
	std::swap(this->m1_, this->m4_);
	std::swap(this->m2_, this->m8_);
	std::swap(this->m3_, this->m12_);
	std::swap(this->m6_, this->m9_);
	std::swap(this->m7_, this->m13_);
	std::swap(this->m11_, this->m14_);

	return *this;
}

Matrix Matrix::GetTranspose() const
{
	Vect v0(this->m0_, this->m4_, this->m8_, this->m12_);
	Vect v1(this->m1_, this->m5_, this->m9_, this->m13_);
	Vect v2(this->m2_, this->m6_, this->m10_, this->m14_);
	Vect v3(this->m3_, this->m7_, this->m11_, this->m15_);

	return Matrix(v0, v1, v2, v3);
}

Matrix& Matrix::Inverse()
{
	float m0 = m6_*m11_*m13_ - m7_*m10_*m13_ + m7_*m9_*m14_ - m5_*m11_*m14_ - m6_*m9_*m15_ + m5_*m10_*m15_;
	float m1 = m3_*m10_*m13_ - m2_*m11_*m13_ - m3_*m9_*m14_ + m1_*m11_*m14_ + m2_*m9_*m15_ - m1_*m10_*m15_;
	float m2 = m2_*m7_*m13_ - m3_*m6_*m13_ + m3_*m5_*m14_ - m1_*m7_*m14_ - m2_*m5_*m15_ + m1_*m6_*m15_;
	float m3 = m3_*m6_*m9_ - m2_*m7_*m9_ - m3_*m5_*m10_ + m1_*m7_*m10_ + m2_*m5_*m11_ - m1_*m6_*m11_;

	float m4 = m7_*m10_*m12_ - m6_*m11_*m12_ - m7_*m8_*m14_ + m4_*m11_*m14_ + m6_*m8_*m15_ - m4_*m10_*m15_;
	float m5 = m2_*m11_*m12_ - m3_*m10_*m12_ + m3_*m8_*m14_ - m0_*m11_*m14_ - m2_*m8_*m15_ + m0_*m10_*m15_;
	float m6 = m3_*m6_*m12_ - m2_*m7_*m12_ - m3_*m4_*m14_ + m0_*m7_*m14_ + m2_*m4_*m15_ - m0_*m6_*m15_;
	float m7 = m2_*m7_*m8_ - m3_*m6_*m8_ + m3_*m4_*m10_ - m0_*m7_*m10_ - m2_*m4_*m11_ + m0_*m6_*m11_;

	float m8 = m5_*m11_*m12_ - m7_*m9_*m12_ + m7_*m8_*m13_ - m4_*m11_*m13_ - m5_*m8_*m15_ + m4_*m9_*m15_;
	float m9 = m3_*m9_*m12_ - m1_*m11_*m12_ - m3_*m8_*m13_ + m0_*m11_*m13_ + m1_*m8_*m15_ - m0_*m9_*m15_;
	float m10 = m1_*m7_*m12_ - m3_*m5_*m12_ + m3_*m4_*m13_ - m0_*m7_*m13_ - m1_*m4_*m15_ + m0_*m5_*m15_;
	float m11 = m3_*m5_*m8_ - m1_*m7_*m8_ - m3_*m4_*m9_ + m0_*m7_*m9_ + m1_*m4_*m11_ - m0_*m5_*m11_;

	float m12 = m6_*m9_*m12_ - m5_*m10_*m12_ - m6_*m8_*m13_ + m4_*m10_*m13_ + m5_*m8_*m14_ - m4_*m9_*m14_;
	float m13 = m1_*m10_*m12_ - m2_*m9_*m12_ + m2_*m8_*m13_ - m0_*m10_*m13_ - m1_*m8_*m14_ + m0_*m9_*m14_;
	float m14 = m2_*m5_*m12_ - m1_*m6_*m12_ - m2_*m4_*m13_ + m0_*m6_*m13_ + m1_*m4_*m14_ - m0_*m5_*m14_;
	float m15 = m1_*m6_*m8_ - m2_*m5_*m8_ + m2_*m4_*m9_ - m0_*m6_*m9_ - m1_*m4_*m10_ + m0_*m5_*m10_;

	float iDet = 1 / this->GetDeterminant();

	this->m0_ = m0*iDet;
	this->m1_ = m1*iDet;
	this->m2_ = m2*iDet;
	this->m3_ = m3*iDet;
	this->m4_ = m4*iDet;
	this->m5_ = m5*iDet;
	this->m6_ = m6*iDet;
	this->m7_ = m7*iDet;
	this->m8_ = m8*iDet;
	this->m9_ = m9*iDet;
	this->m10_ = m10*iDet;
	this->m11_ = m11*iDet;
	this->m12_ = m12*iDet;
	this->m13_ = m13*iDet;
	this->m14_ = m14*iDet;
	this->m15_ = m15*iDet;

	return *this;
}

Matrix Matrix::GetInverse() const
{
	Matrix temp = *this;
	return temp.Inverse();
}

void Matrix::Set(const MatrixSpecialType type)
{
	if (type == ZERO)
	{
		this->Set(Vect(0.0f, 0.0f, 0.0f, 0.0f), 
			Vect(0.0f, 0.0f, 0.0f, 0.0f),
			Vect(0.0f, 0.0f, 0.0f, 0.0f),
			Vect(0.0f, 0.0f, 0.0f, 0.0f));
	}
	else
	{
		this->Set(
			Vect(1.0f, 0.0f, 0.0f, 0.0f),
			Vect(0.0f, 1.0f, 0.0f, 0.0f),
			Vect(0.0f, 0.0f, 1.0f, 0.0f),
			Vect(0.0f, 0.0f, 0.0f, 1.0f));
	}
}

void Matrix::Set(const MatrixTransType, const Vect& v)
{
	this->Set(
		Vect(1.0f, 0.0f, 0.0f, 0.0f), 
		Vect(0.0f, 1.0f, 0.0f, 0.0f),
		Vect(0.0f, 0.0f, 1.0f, 0.0f),
		v);
}

void Matrix::Set(const MatrixTransType, const float x, const float y, const float z)
{
	this->Set(
		Vect(1.0f, 0.0f, 0.0f, 0.0f), 
		Vect(0.0f, 1.0f, 0.0f, 0.0f), 
		Vect(0.0f, 0.0f, 1.0f, 0.0f), 
		Vect(x, y, z, 1.0f));
}

void Matrix::Set(const MatrixScaleType, const Vect& v)
{
	this->Set(
		Vect(v[x], 0.0f, 0.0f, 0.0f), 
		Vect(0.0f, v[y], 0.0f, 0.0f), 
		Vect(0.0f, 0.0f, v[z], 0.0f), 
		Vect(0.0f, 0.0f, 0.0f, 1.0f));
}

void Matrix::Set(const MatrixScaleType, const float x, const float y, const float z)
{
	this->Set(
		Vect(x, 0.0f, 0.0f, 0.0f),
		Vect(0.0f, y, 0.0f, 0.0f), 
		Vect(0.0f, 0.0f, z, 0.0f),
		Vect(0.0f, 0.0f, 0.0f, 1.0f));
}

void Matrix::Set(const RotType type, float theta)
{
	this->Set(
		Vect(1.0f, 0.0f, 0.0f, 0.0f),
		Vect(0.0f, 1.0f, 0.0f, 0.0f),
		Vect(0.0f, 0.0f, 1.0f, 0.0f),
		Vect(0.0f, 0.0f, 0.0f, 1.0f));
	float sin = sinf(theta);
	float cos = cosf(theta);

	switch (type)
	{
	case ROT_X:
		this->m5_ = cos;
		this->m6_ = sin;
		this->m9_ = -sin;
		this->m10_ = cos;
		break;
	case ROT_Y:
		this->m0_ = cos;
		this->m8_ = sin;
		this->m2_ = -sin;
		this->m10_ = cos;
		break;
	case ROT_Z:
		this->m0_ = cos;
		this->m1_ = sin;
		this->m4_ = -sin;
		this->m5_ = cos;
		break;
	}
}

void Matrix::Set(const MatrixRowType type, const Vect& v)
{
	switch (type)
	{
	case ROW_0:
		this->v0_ = v;
		break;
	case ROW_1:
		this->v1_ = v;
		break;
	case ROW_2:
		this->v2_ = v;
		break;
	case ROW_3:
		this->v3_ = v;
		break;
	}
}

void Matrix::Set(const Vect& v0, const Vect& v1, const Vect& v2, const Vect& v3)
{
	this->v0_ = v0;
	this->v1_ = v1;
	this->v2_ = v2;
	this->v3_ = v3;
}

Vect Matrix::GetRow(const MatrixRowType type) const
{
	switch (type)
	{
	case ROW_0:
		return this->v0_;
	case ROW_1:
		return this->v1_;
	case ROW_2:
		return this->v2_;
	case ROW_3:
		return this->v3_;
	}
	return Vect();
}

Matrix operator*(float scale, const Matrix& other)
{
	return other * scale;
}

Matrix Matrix::operator*(float scale) const
{
	float m0 = this->m0_ * scale;
	float m1 = this->m1_ * scale;
	float m2 = this->m2_ * scale;
	float m3 = this->m3_ * scale;
	float m4 = this->m4_ * scale;
	float m5 = this->m5_  * scale;
	float m6 = this->m6_  * scale;
	float m7 = this->m7_  * scale;
	float m8 = this->m8_  * scale;
	float m9 = this->m9_  * scale;
	float m10 = this->m10_  * scale;
	float m11 = this->m11_  * scale;
	float m12 = this->m12_  * scale;
	float m13 = this->m13_  * scale;
	float m14 = this->m14_  * scale;
	float m15 = this->m15_  * scale;

	Vect v0(m0, m1, m2, m3);
	Vect v1(m4, m5, m6, m7);
	Vect v2(m8, m9, m10, m11);
	Vect v3(m12, m13, m14, m15);

	return Matrix(v0, v1, v2, v3);
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	this->m0_ += other.m0_;
	this->m1_ += other.m1_;
	this->m2_ += other.m2_;
	this->m3_ += other.m3_;
	this->m4_ += other.m4_;
	this->m5_ += other.m5_;
	this->m6_ += other.m6_;
	this->m7_ += other.m7_;
	this->m8_ += other.m8_;
	this->m9_ += other.m9_;
	this->m10_ += other.m10_;
	this->m11_ += other.m11_;
	this->m12_ += other.m12_;
	this->m13_ += other.m13_;
	this->m14_ += other.m14_;
	this->m15_ += other.m15_;

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	this->m0_ -= other.m0_;
	this->m1_ -= other.m1_;
	this->m2_ -= other.m2_;
	this->m3_ -= other.m3_;
	this->m4_ -= other.m4_;
	this->m5_ -= other.m5_;
	this->m6_ -= other.m6_;
	this->m7_ -= other.m7_;
	this->m8_ -= other.m8_;
	this->m9_ -= other.m9_;
	this->m10_ -= other.m10_;
	this->m11_ -= other.m11_;
	this->m12_ -= other.m12_;
	this->m13_ -= other.m13_;
	this->m14_ -= other.m14_;
	this->m15_ -= other.m15_;

	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	float m0 = this->m0_*other.m0_ + this->m1_*other.m4_ + this->m2_*other.m8_ + this->m3_*other.m12_;
	float m1 = this->m0_*other.m1_ + this->m1_*other.m5_ + this->m2_*other.m9_ + this->m3_*other.m13_;
	float m2 = this->m0_*other.m2_ + this->m1_*other.m6_ + this->m2_*other.m10_ + this->m3_*other.m14_;
	float m3 = this->m0_*other.m3_ + this->m1_*other.m7_ + this->m2_*other.m11_ + this->m3_*other.m15_;
	float m4 = this->m4_*other.m0_ + this->m5_*other.m4_ + this->m6_*other.m8_ + this->m7_*other.m12_;
	float m5 = this->m4_*other.m1_ + this->m5_*other.m5_ + this->m6_*other.m9_ + this->m7_*other.m13_;
	float m6 = this->m4_*other.m2_ + this->m5_*other.m6_ + this->m6_*other.m10_ + this->m7_*other.m14_;
	float m7 = this->m4_*other.m3_ + this->m5_*other.m7_ + this->m6_*other.m11_ + this->m7_*other.m15_;
	float m8 = this->m8_*other.m0_ + this->m9_*other.m4_ + this->m10_*other.m8_ + this->m11_*other.m12_;
	float m9 = this->m8_*other.m1_ + this->m9_*other.m5_ + this->m10_*other.m9_ + this->m11_*other.m13_;
	float m10 = this->m8_*other.m2_ + this->m9_*other.m6_ + this->m10_*other.m10_ + this->m11_*other.m14_;
	float m11 = this->m8_*other.m3_ + this->m9_*other.m7_ + this->m10_*other.m11_ + this->m11_*other.m15_;
	float m12 = this->m12_*other.m0_ + this->m13_*other.m4_ + this->m14_*other.m8_ + this->m15_*other.m12_;
	float m13 = this->m12_*other.m1_ + this->m13_*other.m5_ + this->m14_*other.m9_ + this->m15_*other.m13_;
	float m14 = this->m12_*other.m2_ + this->m13_*other.m6_ + this->m14_*other.m10_ + this->m15_*other.m14_;
	float m15 = this->m12_*other.m3_ + this->m13_*other.m7_ + this->m14_*other.m11_ + this->m15_*other.m15_;

	this->m0_ = m0;
	this->m1_ = m1;
	this->m2_ = m2;
	this->m3_ = m3;
	this->m4_ = m4;
	this->m5_ = m5;
	this->m6_ = m6;
	this->m7_ = m7;
	this->m8_ = m8;
	this->m9_ = m9;
	this->m10_ = m10;
	this->m11_ = m11;
	this->m12_ = m12;
	this->m13_ = m13;
	this->m14_ = m14;
	this->m15_ = m15;

	return *this;
}

Matrix& Matrix::operator*=(float scale)
{
	this->m0_ *= scale;
	this->m1_ *= scale;
	this->m2_ *= scale;
	this->m3_ *= scale;
	this->m4_ *= scale;
	this->m5_ *= scale;
	this->m6_ *= scale;
	this->m7_ *= scale;
	this->m8_ *= scale;
	this->m9_ *= scale;
	this->m10_ *= scale;
	this->m11_ *= scale;
	this->m12_ *= scale;
	this->m13_ *= scale;
	this->m14_ *= scale;
	this->m15_ *= scale;

	return *this;
}

Matrix Matrix::operator+(const Matrix& other) const
{
	float m0 = this->m0_ + other.m0_;
	float m1 = this->m1_ + other.m1_;
	float m2 = this->m2_ + other.m2_;
	float m3 = this->m3_ + other.m3_;
	float m4 = this->m4_ + other.m4_;
	float m5 = this->m5_ + other.m5_;
	float m6 = this->m6_ + other.m6_;
	float m7 = this->m7_ + other.m7_;
	float m8 = this->m8_ + other.m8_;
	float m9 = this->m9_ + other.m9_;
	float m10 = this->m10_ + other.m10_;
	float m11 = this->m11_ + other.m11_;
	float m12 = this->m12_ + other.m12_;
	float m13 = this->m13_ + other.m13_;
	float m14 = this->m14_ + other.m14_;
	float m15 = this->m15_ + other.m15_;

	Vect v0(m0, m1, m2, m3);
	Vect v1(m4, m5, m6, m7);
	Vect v2(m8, m9, m10, m11);
	Vect v3(m12, m13, m14, m15);

	return Matrix(v0, v1, v2, v3);
}

Matrix Matrix::operator-(const Matrix& other) const
{
	float m0 = this->m0_ - other.m0_;
	float m1 = this->m1_ - other.m1_;
	float m2 = this->m2_ - other.m2_;
	float m3 = this->m3_ - other.m3_;
	float m4 = this->m4_ - other.m4_;
	float m5 = this->m5_ - other.m5_;
	float m6 = this->m6_ - other.m6_;
	float m7 = this->m7_ - other.m7_;
	float m8 = this->m8_ - other.m8_;
	float m9 = this->m9_ - other.m9_;
	float m10 = this->m10_ - other.m10_;
	float m11 = this->m11_ - other.m11_;
	float m12 = this->m12_ - other.m12_;
	float m13 = this->m13_ - other.m13_;
	float m14 = this->m14_ - other.m14_;
	float m15 = this->m15_ - other.m15_;

	Vect v0(m0, m1, m2, m3);
	Vect v1(m4, m5, m6, m7);
	Vect v2(m8, m9, m10, m11);
	Vect v3(m12, m13, m14, m15);

	return Matrix(v0, v1, v2, v3);
}

Matrix Matrix::operator*(const Matrix& other) const
{
	float m0 = this->m0_*other.m0_ + this->m1_*other.m4_ + this->m2_*other.m8_ + this->m3_*other.m12_;
	float m1 = this->m0_*other.m1_ + this->m1_*other.m5_ + this->m2_*other.m9_ + this->m3_*other.m13_;
	float m2 = this->m0_*other.m2_ + this->m1_*other.m6_ + this->m2_*other.m10_ + this->m3_*other.m14_;
	float m3 = this->m0_*other.m3_ + this->m1_*other.m7_ + this->m2_*other.m11_ + this->m3_*other.m15_;
	float m4 = this->m4_*other.m0_ + this->m5_*other.m4_ + this->m6_*other.m8_ + this->m7_*other.m12_;
	float m5 = this->m4_*other.m1_ + this->m5_*other.m5_ + this->m6_*other.m9_ + this->m7_*other.m13_;
	float m6 = this->m4_*other.m2_ + this->m5_*other.m6_ + this->m6_*other.m10_ + this->m7_*other.m14_;
	float m7 = this->m4_*other.m3_ + this->m5_*other.m7_ + this->m6_*other.m11_ + this->m7_*other.m15_;
	float m8 = this->m8_*other.m0_ + this->m9_*other.m4_ + this->m10_*other.m8_ + this->m11_*other.m12_;
	float m9 = this->m8_*other.m1_ + this->m9_*other.m5_ + this->m10_*other.m9_ + this->m11_*other.m13_;
	float m10 = this->m8_*other.m2_ + this->m9_*other.m6_ + this->m10_*other.m10_ + this->m11_*other.m14_;
	float m11 = this->m8_*other.m3_ + this->m9_*other.m7_ + this->m10_*other.m11_ + this->m11_*other.m15_;
	float m12 = this->m12_*other.m0_ + this->m13_*other.m4_ + this->m14_*other.m8_ + this->m15_*other.m12_;
	float m13 = this->m12_*other.m1_ + this->m13_*other.m5_ + this->m14_*other.m9_ + this->m15_*other.m13_;
	float m14 = this->m12_*other.m2_ + this->m13_*other.m6_ + this->m14_*other.m10_ + this->m15_*other.m14_;
	float m15 = this->m12_*other.m3_ + this->m13_*other.m7_ + this->m14_*other.m11_ + this->m15_*other.m15_;

	Vect v0(m0, m1, m2, m3);
	Vect v1(m4, m5, m6, m7);
	Vect v2(m8, m9, m10, m11);
	Vect v3(m12, m13, m14, m15);

	return Matrix(v0, v1, v2, v3);
}

float& Matrix::m0()
{
	return this->m0_;
}
float& Matrix::m1()
{
	return this->m1_;
}
float& Matrix::m2()
{
	return this->m2_;
}
float& Matrix::m3()
{
	return this->m3_;
}
float& Matrix::m4()
{
	return this->m4_;
}
float& Matrix::m5()
{
	return this->m5_;
}
float& Matrix::m6()
{
	return this->m6_;
}
float& Matrix::m7()
{
	return this->m7_;
}
float& Matrix::m8()
{
	return this->m8_;
}
float& Matrix::m9()
{
	return this->m9_;
}
float& Matrix::m10()
{
	return this->m10_;
}
float& Matrix::m11()
{
	return this->m11_;
}
float& Matrix::m12()
{
	return this->m12_;
}
float& Matrix::m13()
{
	return this->m13_;
}
float& Matrix::m14()
{
	return this->m14_;
}
float& Matrix::m15()
{
	return this->m15_;
}

float Matrix::m0() const
{
	return this->m0_;
}
float Matrix::m1() const
{
	return this->m1_;
}
float Matrix::m2() const
{
	return this->m2_;
}
float Matrix::m3() const
{
	return this->m3_;
}
float Matrix::m4() const
{
	return this->m4_;
}
float Matrix::m5() const
{
	return this->m5_;
}
float Matrix::m6() const
{
	return this->m6_;
}
float Matrix::m7() const
{
	return this->m7_;
}
float Matrix::m8() const
{
	return this->m8_;
}
float Matrix::m9() const
{
	return this->m9_;
}
float Matrix::m10() const
{
	return this->m10_;
}
float Matrix::m11() const
{
	return this->m11_;
}
float Matrix::m12() const
{
	return this->m12_;
}
float Matrix::m13() const
{
	return this->m13_;
}
float Matrix::m14() const
{
	return this->m14_;
}
float Matrix::m15() const
{
	return this->m15_;
}

Matrix Matrix::operator+()
{
	return *this;
}

Matrix Matrix::operator-()
{
	return *this * -1;
}

float& Matrix::operator[](const m0_enum)
{
	return this->m0_;
}

float& Matrix::operator[](const m1_enum)
{
	return this->m1_;
}

float& Matrix::operator[](const m2_enum)
{
	return this->m2_;
}

float& Matrix::operator[](const m3_enum)
{
	return this->m3_;
}

float& Matrix::operator[](const m4_enum)
{
	return this->m4_;
}

float& Matrix::operator[](const m5_enum)
{
	return this->m5_;
}

float& Matrix::operator[](const m6_enum)
{
	return this->m6_;
}

float& Matrix::operator[](const m7_enum)
{
	return this->m7_;
}

float& Matrix::operator[](const m8_enum)
{
	return this->m8_;
}

float& Matrix::operator[](const m9_enum)
{
	return this->m9_;
}

float& Matrix::operator[](const m10_enum)
{
	return this->m10_;
}

float& Matrix::operator[](const m11_enum)
{
	return this->m11_;
}

float& Matrix::operator[](const m12_enum)
{
	return this->m12_;
}

float& Matrix::operator[](const m13_enum)
{
	return this->m13_;
}

float& Matrix::operator[](const m14_enum)
{
	return this->m14_;
}

float& Matrix::operator[](const m15_enum)
{
	return this->m15_;
}

float Matrix::operator[](const m0_enum) const
{
	return this->m0_;
}

float Matrix::operator[](const m1_enum) const
{
	return this->m1_;
}

float Matrix::operator[](const m2_enum) const
{
	return this->m2_;
}

float Matrix::operator[](const m3_enum) const
{
	return this->m3_;
}

float Matrix::operator[](const m4_enum) const
{
	return this->m4_;
}

float Matrix::operator[](const m5_enum) const
{
	return this->m5_;
}

float Matrix::operator[](const m6_enum) const
{
	return this->m6_;
}

float Matrix::operator[](const m7_enum) const
{
	return this->m7_;
}

float Matrix::operator[](const m8_enum) const
{
	return this->m8_;
}

float Matrix::operator[](const m9_enum) const
{
	return this->m9_;
}

float Matrix::operator[](const m10_enum) const
{
	return this->m10_;
}

float Matrix::operator[](const m11_enum) const
{
	return this->m11_;
}

float Matrix::operator[](const m12_enum) const
{
	return this->m12_;
}

float Matrix::operator[](const m13_enum) const
{
	return this->m13_;
}

float Matrix::operator[](const m14_enum) const
{
	return this->m14_;
}

float Matrix::operator[](const m15_enum) const
{
	return this->m15_;
}