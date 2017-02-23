#pragma once

#include "Vect.h"


class VectApp
{
		
public:

	// lerp
	static Vect Lerp(const Vect &a, const Vect &b,  const float t );
	
	// lerp array
	static void LerpArray(Vect *out, const Vect *a, const Vect *b,   const float t, const int numVects );
	  						  

};