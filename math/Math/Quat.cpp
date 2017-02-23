/*****************************************************************************/
/*                                                                           */
/* File: Quat.cpp                                                            */
/*                                                                           */
/* Quaterion Class                                                           */
/*                                                                           */
/*****************************************************************************/

#include "MathEngine.h"
#include <math.h>
#include <assert.h>

Quat::Quat()
	: qx(0.0f), qy(0.0f), qz(0.0f), qw(1.0f)
{
}

Quat::Quat(const Quat& o)
	: qx(o.qx), qy(o.qy), qz(o.qz), qw(o.qw)
{
}

Quat::Quat(float x, float y, float z, float w)
	: qx(x), qy(y), qz(z), qw(w)
{
}

Quat::Quat(const Vect& v, float real)
	: qx(v[x]), qy(v[y]), qz(v[z]), qw(real)
{
}

Quat::Quat(const Matrix& m)
	: qx(0.0f), qy(0.0f), qz(0.0f), qw(1.0f)
{
	this->Set(m);
}

Quat::Quat(RotType rot_type, float radians) 
	: qx(0.0f), qy(0.0f), qz(0.0f), qw(1.0f)
{
	this->Set(rot_type, radians);
}

Quat::Quat(RotAxisAngleType type, const Vect& v, float radians) 
	: qx(0.0f), qy(0.0f), qz(0.0f), qw(1.0f)
{
	this->Set(type, v, radians);
}

Quat::Quat(RotOrientType type, const Vect& direction_of_flight, const Vect& up)
	: qx(0.0f), qy(0.0f), qz(0.0f), qw(1.0f)
{
	this->Set(type, direction_of_flight, up);
}

Quat::Quat(Rot3AxisType type, float x, float y, float z)
	: qx(0.0f), qy(0.0f), qz(0.0f), qw(1.0f)
{
	this->Set(type, x, y, z);
}

Quat::~Quat()
{
}


void Quat::Set(Rot3AxisType, float x, float y, float z)
{
	Quat q1(ROT_X, x);
	Quat q2(ROT_Y, y);
	Quat q3(ROT_Z, z);

	*this = q1*q2*q3;
}

void Quat::Set(RotOrientType type, const Vect& direction_of_flight, const Vect& up)
{
	Matrix m(type, direction_of_flight, up);
	this->Set(m);
}

void Quat::Set(RotType rot_type, float radians)
{
	switch (rot_type)
	{
	case ROT_X:
		this->qx = sinf(radians / 2.0f);
		this->qw = cosf(radians / 2.0f);
		break;
	case ROT_Y:
		this->qy = sinf(radians / 2.0f);
		this->qw = cosf(radians / 2.0f);
		break;
	case ROT_Z:
		this->qz = sinf(radians / 2.0f);
		this->qw = cosf(radians / 2.0f);
		break;
	default:
		assert(false);
		break;
	}
}

void Quat::Set(MatrixSpecialType type)
{
	if (type == ZERO)
	{
		qx = 0.0f;
		qy = 0.0f;
		qz = 0.0f;
		qw = 0.0f;
	}
	else
	{
		qx = 0.0f;
		qy = 0.0f;
		qz = 0.0f;
		qw = 1.0f;
	}
}

void Quat::Set(const Matrix& m)
{
	float tr = m[m0] + m[m5] + m[m10];
	float s;

	if (tr > 0.0f)
	{
		s = 2.0f * sqrtf(tr + 1.0f);
		this->qw = 0.25f * s;
		this->qx = -(m[m9] - m[m6]) / s;
		this->qy = -(m[m2] - m[m8]) / s;
		this->qz = -(m[m4] - m[m1]) / s;
	}
	else if (m[m0] > m[m5] && m[m0] > m[m10])
	{
		s = 2.0f * sqrtf(1.0f + m[m0] - m[m5] - m[m10]);
		this->qw = -(m[m9] - m[m6]) / s;
		this->qx = 0.25f * s;
		this->qy = (m[m1] + m[m4]) / s;
		this->qz = (m[m2] + m[m8]) / s;
	}
	else if (m[m5] > m[m10])
	{
		s = 2.0f * sqrtf(1.0f + m[m5] - m[m0] - m[m10]);
		this->qw = -(m[m2] - m[m8]) / s;
		this->qx = (m[m1] + m[m4]) / s;
		this->qy = 0.25f * s;
		this->qz = (m[m6] + m[m9]) / s;
	}
	else
	{
		s = 2.0f * sqrtf(1.0f + m[m10] - m[m0] - m[m5]);
		this->qw = -(m[m4] - m[m1]) / s;
		this->qx = (m[m2] + m[m8]) / s;
		this->qy = (m[m6] + m[m9]) / s;
		this->qz = 0.25f * s;
	}
}

void Quat::Set(RotAxisAngleType, const Vect& v, float radians)
{
	Vect normalized = v.GetNormalized();

	normalized *= sinf(radians / 2.0f);

	this->qx = normalized[x];
	this->qy = normalized[y];
	this->qz = normalized[z];
	this->qw = cosf(radians / 2.0f);
}

void Quat::Set(float x, float y, float z, float w)
{
	qx = x;
	qy = y;
	qz = z;
	qw = w;
}

void Quat::Set(const Vect& v, float real)
{
	qx = v[x];
	qy = v[y];
	qz = v[z];
	qw = real;
}

void Quat::SetAxis(const Vect& v)
{
	qx = v[x];
	qy = v[y];
	qz = v[z];
}

Quat& Quat::operator=(const Quat& quat)
{
	if (this != &quat)
	{
		this->qx = quat.qx;
		this->qy = quat.qy;
		this->qz = quat.qz;
		this->qw = quat.qw;
	}

	return *this;
}

bool Quat::IsEqual(const Quat& quat, float epsilon) const
{
	return util::IsEqual(qx, quat.qx, epsilon) &&
		util::IsEqual(qy, quat.qy, epsilon) &&
		util::IsEqual(qz, quat.qz, epsilon) &&
		util::IsEqual(qw, quat.qw, epsilon);
}

bool Quat::IsEquivalent(const Quat& quat, float epsilon) const
{
	return this->IsEqual(quat, epsilon) || IsOpposite(quat, epsilon);
}

bool Quat::IsOpposite(const Quat& quat, float epsilon) const
{
	return util::IsEqual(-qx, quat.qx, epsilon) &&
		util::IsEqual(-qy, quat.qy, epsilon) &&
		util::IsEqual(-qz, quat.qz, epsilon) &&
		util::IsEqual(-qw, quat.qw, epsilon);
}

bool Quat::IsConjugateEqual(const Quat& quat, float epsilon) const
{
	Quat conj = quat.GetConjugate();
	return this->IsEqual(conj, epsilon);
}

bool Quat::IsIdentity(float epsilon) const
{
	return util::IsZero(qx, epsilon) &&
		util::IsZero(qy, epsilon) &&
		util::IsZero(qz, epsilon) &&
		util::IsOne(qw, epsilon);
}

bool Quat::IsNormalized(float epsilon) const
{
	return util::IsOne(this->MagSquared(), epsilon);
}

bool Quat::IsZero(float epsilon) const
{
	return util::IsZero(qx, epsilon) &&
		util::IsZero(qy, epsilon) &&
		util::IsZero(qz, epsilon) &&
		util::IsZero(qw, epsilon);
}

float& Quat::operator[](x_enum)
{
	return qx;
}

float& Quat::operator[](y_enum)
{
	return qy;
}

float& Quat::operator[](z_enum)
{
	return qz;
}

float& Quat::operator[](w_enum)
{
	return qw;
}

float Quat::operator[](x_enum) const
{
	return qx;
}

float Quat::operator[](y_enum) const
{
	return qy;
}

float Quat::operator[](z_enum) const
{
	return qz;
}

float Quat::operator[](w_enum) const
{
	return qw;
}

Quat Quat::MultByElement(const Quat& quat)
{
	return Quat(qx*quat.qx, qy*quat.qy, qz*quat.qz, qw*quat.qw);
}

float Quat::GetAngle() const
{
	return 2.0f*acosf(qw);
}

void Quat::GetAxis(Vect& out) const
{
	out[x] = qx;
	out[y] = qy;
	out[z] = qz;
	out[w] = 0.0f;
}

Vect Quat::GetAxis() const
{
	return Vect(qx, qy, qz, 0.0f);
}

void Quat::Lqvqc(const Vect& v1, Vect& v_out) const
{
	assert(this->IsNormalized(util::kTolerance));
	Vect qv;
	this->GetAxis(qv);

	v_out = 2.0f * qw*(v1.Cross(qv)) + (qw*qw - qv.Dot(qv))*v1 + 2.0f * (qv.Dot(v1))*qv;
}

void Quat::Lqcvq(const Vect& v1, Vect& v_out) const
{
	assert(this->IsNormalized(util::kTolerance));
	Vect qv;
	this->GetAxis(qv);

	v_out = 2.0f * qw*(qv.Cross(v1)) + (qw*qw - qv.Dot(qv))*v1 + 2.0f * (qv.Dot(v1))*qv;
}

Vect Quat::Lqvqc(const Vect& v1) const
{
	assert(this->IsNormalized(util::kTolerance));
	Vect qv(qx, qy, qz);
	return 2.0f * qw*(v1.Cross(qv)) + (qw*qw - qv.Dot(qv))*v1 + 2.0f * (qv.Dot(v1))*qv;
}

Vect Quat::Lqcvq(const Vect& v1) const
{
	assert(this->IsNormalized(util::kTolerance));
	Vect qv(qx, qy, qz);
	return 2.0f * qw*(qv.Cross(v1)) + (qw*qw - qv.Dot(qv))*v1 + 2.0f * (qv.Dot(v1))*qv;
}

float Quat::Dot(const Quat& q) const
{
	return qx*q.qx + qy*q.qy + qz*q.qz + qw*q.qw;
}

float Quat::Magnitude() const
{
	return util::Sqrt(MagSquared());
}

float Quat::MagSquared() const
{
	return qx*qx + qy*qy + qz*qz + qw*qw;
}

float Quat::InverseMag() const
{
	return 1.0f / (Magnitude());
}

Quat Quat::GetConjugate() const
{
	return Quat(-qx, -qy, -qz, qw);
}

Quat& Quat::Conjugate()
{
	qx *= -1.0f;
	qy *= -1.0f;
	qz *= -1.0f;
	return *this;
}

Quat Quat::GetTranspose() const
{
	return Quat(-qx, -qy, -qz, qw);
}
Quat& Quat::Transpose()
{
	qx *= -1.0f;
	qy *= -1.0f;
	qz *= -1.0f;
	return *this;
}

Quat Quat::GetInverse() const
{
	float iMagSqr = 1.0f / MagSquared();
	return Quat(-qx*iMagSqr, -qy*iMagSqr, -qz*iMagSqr, qw*iMagSqr);
}
Quat& Quat::Inverse()
{
	float iMagSqr = 1.0f / MagSquared();

	qx *= -iMagSqr;
	qy *= -iMagSqr;
	qz *= -iMagSqr;
	qw *= iMagSqr;

	return *this;
}

Quat Quat::GetNormalized() const
{
	float iMag = this->InverseMag();
	return Quat(qx*iMag, qy*iMag, qz*iMag, qw*iMag);
}

Quat& Quat::Normalize()
{
	float iMag = this->InverseMag();

	qx *= iMag;
	qy *= iMag;
	qz *= iMag;
	qw *= iMag;

	return *this;
}

Quat Quat::operator+()
{
	return *this;
}

Quat Quat::operator+(const Quat& other) const
{
	return Quat(qx+other.qx, qy+other.qy, qz+other.qz, qw+other.qw);
}

Quat Quat::operator+= (const Quat& other)
{
	qx += other.qx;
	qy += other.qy;
	qz += other.qz;
	qw += other.qw;
	return *this;
}

Quat Quat::operator+(float c) const
{
	return Quat(qx+c, qy+c, qz+c, qw+c);
}

Quat Quat::operator+=(float c)
{
	qx += c;
	qy += c;
	qz += c;
	qw += c;
	return *this;
}

Quat Quat::operator-()
{
	return Quat(-qx, -qy, -qz, -qw);
}
Quat Quat::operator-(const Quat& other) const
{
	return Quat(qx - other.qx, qy - other.qy, qz - other.qz, qw - other.qw);
}
Quat Quat::operator-= (const Quat& other)
{
	qx -= other.qx;
	qy -= other.qy;
	qz -= other.qz;
	qw -= other.qw;
	return *this;
}
Quat Quat::operator-(float c) const
{
	return Quat(qx - c, qy - c, qz - c, qw - c);
}
Quat Quat::operator-=(float c)
{
	qx -= c;
	qy -= c;
	qz -= c;
	qw -= c;
	return *this;
}

Quat Quat::operator*(const Quat& other) const
{
	Vect v1;
	this->GetAxis(v1);
	Vect v2;
	other.GetAxis(v2);

	float real = qw*other.qw - v1.Dot(v2);
	Vect vect3 = v2.Cross(v1) + other.qw*v1 + qw*v2;
	return Quat(vect3, real);
}
Quat Quat::operator*= (const Quat& other)
{
	Vect v1;
	this->GetAxis(v1);
	Vect v2;
	other.GetAxis(v2);

	this->SetAxis(v2.Cross(v1) + other.qw*v1 + qw*v2);
	this->qw = qw*other.qw - v1.Dot(v2);

	return *this;
}
Quat Quat::operator*(float c) const
{
	return Quat(qx*c, qy*c, qz*c, qw*c);
}
Quat Quat::operator*=(float c)
{
	qx *= c;
	qy *= c;
	qz *= c;
	qw *= c;
	return *this;
}

Quat Quat::operator/(const Quat& other) const
{
	return Quat(qx/other.qx, qy/other.qy, qz/other.qz, qw/other.qw);
}
Quat Quat::operator/= (const Quat& other)
{
	qx /= other.qx;
	qy /= other.qy;
	qz /= other.qz;
	qw /= other.qw;
	return *this;
}
Quat Quat::operator/(float c) const
{
	return Quat(qx/c, qy/c, qz/c, qw/c);
}
Quat Quat::operator/=(float c)
{
	qx /= c;
	qy /= c;
	qz /= c;
	qw /= c;
	return *this;
}

Quat operator+(float c, const Quat& quat)
{
	return Quat(c+quat[x], c+quat[y], c+quat[z], c+quat[w]);
}

Quat operator-(float c, const Quat& quat)
{
	return Quat(c - quat[x], c - quat[y], c - quat[z], c - quat[w]);
}

Quat operator*(float c, const Quat& quat)
{
	return Quat(c*quat[x], c*quat[y], c*quat[z], c*quat[w]);
}

Quat operator/(float c, const Quat& quat)
{
	return Quat(c/quat[x], c/quat[y], c/quat[z], c/quat[w]);
}