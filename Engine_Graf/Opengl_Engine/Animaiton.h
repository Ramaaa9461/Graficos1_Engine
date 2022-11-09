#pragma once


#include "Frame.h"
#include "Timer.h"
#include <vector>

class Animation
{
	private:

		std::vector<Frame> framesVector;
		int currentIndex;
		int currentTime;
		float length;

public:

	Animation();
	~Animation();

	void UpdateAnimation(Timer& timer);
	void addFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float durationInSecs);
	void addFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float durationInSecs, int frameCount);

	int getCurrentIndex();
	std::vector<Frame>& getFrames();
};

