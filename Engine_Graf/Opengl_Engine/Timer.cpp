#include "Timer.h"

Timer* Timer::S_Timer = nullptr;

Timer::Timer(){}

Timer::~Timer(){}

DllExport Timer* Timer::getTimer()
{
	if (S_Timer == nullptr) {
		S_Timer = new Timer();
	}
	return S_Timer;
}

DllExport float Timer::timeBetweenFrames()
{
	return deltaTime;
}

DllExport void Timer::updateDeltaTime()
{
	deltaTime = clock() - oldTime;
	//double fps = (1 / deltaTime) * 1000;
	oldTime = clock();
}

//https://stackoverflow.com/questions/34133249/c-deltatime-using-clock-is-0