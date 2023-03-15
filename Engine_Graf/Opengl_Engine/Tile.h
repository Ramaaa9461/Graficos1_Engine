#pragma once

#include "Sprite.h"
#include "Frame.h"

class Tile : public Sprite
{
private:
	unsigned int _id;
	bool isWalkable;
	Frame tileFrame;

public:
	DllExport Tile();
	DllExport ~Tile();

	void setPosX(float posX);
	void setPosY(float posY);

	void configureTile(int id, std::string nameImage, bool isWalkable);

	DllExport bool getIsWalkable();
	DllExport void setIsWalkable(bool bWalkable);

	DllExport unsigned int getId();
	DllExport void setId(unsigned int id);

	void cutTexture(float initPosX, float intPosY, int framesCountX, int framesCountY);

	void getTextureSize(float& width, float& height);


};

