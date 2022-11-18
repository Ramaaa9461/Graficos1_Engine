#pragma once

#include <time.h>
#include "DDLExport.h"

class Timer
{
private:

	float deltaTime = 0.0f;
	float oldTime = 0.0f;

public:

	DllExport Timer();
	DllExport ~Timer();


	DllExport float timeBetweenFrames();

	DllExport void updateDeltaTime();

};

