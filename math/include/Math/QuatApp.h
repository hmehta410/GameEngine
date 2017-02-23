#pragma once

#include "Quat.h"

class QuatApp
{
		
public:
	static Quat Slerp(const Quat &source, const Quat &target, const float slerpFactor );
    
	static void SlerpArray( Quat *result, const Quat *source, const Quat *target, const float slerpFactor, const int numQuats );


};
	