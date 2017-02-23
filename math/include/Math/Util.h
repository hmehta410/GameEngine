#pragma once

#include "Constants.h"

namespace util
{
	bool IsEqual(float a, float b, float epsilon = kTolerance);
	bool IsNotEqual(float a, float b, float epsilon = kTolerance);
	bool IsOne(float a, float epsilon = kTolerance);
	bool IsNonZero(float a, float epsilon = kTolerance);
	bool IsZero(float a, float epsilon = kTolerance);
	float Sqrt(float a);
	float Abs(float a);
	float Max(float a, float b);
	float Min(float a, float b);
};
