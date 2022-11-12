#pragma once

#include "Entity2d.h"
#include "Animaiton.h"
#include <vector>

class Sprite : public Entity2d
{


private:

	Animation* animation;
	std::vector<Frame> frames;

	int width, height;
	float positions[16];
	unsigned int indices[6];

	void setVertices();
	void setVerticesSpriteSheet();
	void setIndixs();
	void calculateVertices();


public:

	Sprite(std::string imageName);
	~Sprite();
	
	void CreateAnimation(int x, int y, int durationInSec, int framesAmountX, int framesAmountY);
	void updateAnimation(Timer& timer);
};

