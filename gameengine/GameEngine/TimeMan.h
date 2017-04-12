#pragma once
#include "Time\Time.h"

class TimerMan
{
public:
	static Time GetTotalGameTime();

	static Time GetDeltaTime();

	static void Update(Time deltaTime);

private:
	static Time deltaTime;
	static Time totalTime;
};