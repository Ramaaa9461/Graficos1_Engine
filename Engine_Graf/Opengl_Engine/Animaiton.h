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
		float speed;

public:

	Animation();
	~Animation();

	void UpdateAnimation(Timer& timer);
	void addFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float animationSpeed);
	void addFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float animationSpeed, int frameCount);

	int getCurrentIndex();
	std::vector<Frame>& getFrames();
};

