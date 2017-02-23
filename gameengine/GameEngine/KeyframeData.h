#ifndef BONE_TRANSFORMS_H
#define BONE_TRANSFORMS_H

#include "Math\MathEngine.h"

//Similar to transform except more compact.
struct KeyframeData : Align16
{
 	Vect translation;
	Quat rotation;
	Vect scale;
}; 

#endif