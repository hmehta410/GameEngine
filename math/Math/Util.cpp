#include "Util.h"
#include <math.h>
#include <algorithm>

bool util::IsEqual( float a, float b, float epsilon)
{
	float tmp;
	tmp = a - b;
	return ((tmp >= -epsilon) && (tmp <= epsilon));
}

bool util::IsNotEqual( float a, float b, float epsilon)
{
	float tmp;
	tmp = a - b;
	return ((tmp < -epsilon) || (tmp > epsilon));
}

bool util::IsOne(float a, float epsilon)
{
	float tmp;
	tmp = a - 1.0f;
	return ((tmp >= -epsilon) && (tmp <= epsilon));
}

bool util::IsNonZero(float a, float epsilon)
{
	return ((a < -epsilon) || (a > epsilon));
}

bool util::IsZero( float a, float epsilon)
{
	return ((a >= -epsilon) && (a <= epsilon));
}

float util::Sqrt(float a)
{
	return sqrtf(a);
}

float util::Abs(float a)
{
	return abs(a);
}

float util::Max(float a, float b)
{
	return std::max(a, b);
}

float util::Min(float a, float b)
{
	return std::min(a, b);
}