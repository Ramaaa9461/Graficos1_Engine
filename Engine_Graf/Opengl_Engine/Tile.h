#pragma once

#include "Sprite.h"

class Tile : public Sprite
{
private:
	unsigned int _id;
	bool _walkable;


public:

	DllExport Tile();
	DllExport ~Tile();

	DllExport bool isWalkable();
	DllExport void setWalkable(bool Walkable);

	DllExport unsigned int getId();

};

