#include "TimeMan.h"



Time TimerMan::GetTotalGameTime()
{
	return totalTime;
}

Time TimerMan::GetDeltaTime()
{
	return deltaTime;
}

void TimerMan::Update(Time deltaT)
{
	deltaTime = deltaT;
	totalTime += deltaT;
}

Time TimerMan::deltaTime;

Time TimerMan::totalTime;
