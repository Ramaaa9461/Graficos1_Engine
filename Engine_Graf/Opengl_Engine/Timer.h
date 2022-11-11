#pragma once

#include <time.h>


class Timer
{
private:

	float deltaTime = 0.0f;
	float oldTime = 0.0f;

public:

	Timer();
	~Timer();


	float timeBetweenFrames();

	void updateDeltaTime();

};

