#include "Animaiton.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::UpdateAnimation(Timer& timer) //Recibe un timer
{
	currentTime += timer.timeBetweenFrames();

	while (currentTime > length) 
	{
		currentTime -= length;
	}

	float frameLength = length / framesVector.size();
	currentIndex = static_cast<int>(currentTime / frameLength);
}

void Animation::addFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float durationInSecs)
{
	length = durationInSecs * 1000;
	//----------------------------------------------------------------
	Frame frame;

	frame.uvCoords[0].u = (frameX / textureWidth);
	frame.uvCoords[0].v = (frameY / textureHeigth);
	//----------------------------------------------------------------
	frame.uvCoords[1].u = ((frameX + frameWidth) / textureWidth);
	frame.uvCoords[1].v = (frameY / textureHeigth);
	//----------------------------------------------------------------
	frame.uvCoords[2].u = (frameX / textureWidth);
	frame.uvCoords[2].v = ((frameY + frameHeigth) / textureHeigth);
	//----------------------------------------------------------------
	frame.uvCoords[3].u = ((frameX + frameWidth) / textureWidth);
	frame.uvCoords[3].v = ((frameY + frameHeigth) / textureHeigth);
	//----------------------------------------------------------------
	framesVector.push_back(frame);
}

void Animation::addFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float durationInSecs, int frameCount)
{
	length = durationInSecs * 1000;

	float frameXIndex = 0;

	for (int i = 0; i < frameCount; i++) {
		Frame frame;

		frame.uvCoords[0].u = ((frameX + frameXIndex) / textureWidth);
		frame.uvCoords[0].v = (frameY / textureHeigth);
		//-----------------------------------------------------------------------------
		frame.uvCoords[1].u = (((frameX + frameXIndex) + frameWidth) / textureWidth);
		frame.uvCoords[1].v = (frameY / textureHeigth);
		//-----------------------------------------------------------------------------
		frame.uvCoords[2].u = ((frameX + frameXIndex) / textureWidth);
		frame.uvCoords[2].v = ((frameY + frameHeigth) / textureHeigth);
		//-----------------------------------------------------------------------------
		frame.uvCoords[3].u = (((frameX + frameXIndex) + frameWidth) / textureWidth);
		frame.uvCoords[3].v = ((frameY + frameHeigth) / textureHeigth);
		//-----------------------------------------------------------------------------

		framesVector.push_back(frame);
		frameXIndex += frameWidth;
	}
}

int Animation::getCurrentIndex()
{
	return currentIndex;
}

std::vector<Frame>& Animation::getFrames()
{
	return framesVector;
}
