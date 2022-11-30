#pragma once


#include "Frame.h"
#include "Timer.h"
#include <vector>

class Animation
{
	private:

		std::vector<Frame> framesVector;
		int currentIndex;
		float currentTime;
		float framesPerSeconds;

public:

	DllExport Animation();
	DllExport ~Animation();

	DllExport void UpdateAnimation(float durationInSecs);
	DllExport void addFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth);
	DllExport void addFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, int frameCount);

	DllExport int getCurrentIndex();
	DllExport std::vector<Frame>& getFrames();
};

