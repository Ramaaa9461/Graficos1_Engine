#include "Timer.h"

Timer::Timer()
{



}

Timer::~Timer()
{

}

float Timer::timeBetweenFrames()
{
	return deltaTime;
}

void Timer::updateDeltaTime()
{
	deltaTime = (clock() - oldTime) / 1000.0f;
	//double fps = (1 / deltaTime) * 1000;
	oldTime = clock();
}

