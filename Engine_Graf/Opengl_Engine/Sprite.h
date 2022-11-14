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
	unsigned int indices[6];

	void setVertices();
	void setVerticesSpriteSheet();
	void setIndixs();
	void calculateVertices();

protected:

	float positions[16];

public:

	Sprite(std::string imageName, int initPositionX, int initPositionY);
	Sprite();
	~Sprite();
	
	void setTexture(std::string imageName);

	void CreateAnimation(int x, int y, int durationInSec, int framesAmountX, int framesAmountY);
	void updateAnimation(Timer& timer);
};

