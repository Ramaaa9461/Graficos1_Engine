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
	deltaTime = clock() - oldTime;
	//double fps = (1 / deltaTime) * 1000;
	oldTime = clock();
}

