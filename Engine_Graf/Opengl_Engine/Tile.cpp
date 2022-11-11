#include "Tile.h"

Tile::Tile() : _id(0), _walkable(false), Sprite("Logo.png")
{

}

Tile::~Tile()
{
}

bool Tile::isWalkable()
{
	return _walkable;
}

void Tile::setWalkable(bool Walkable)
{
	_walkable = Walkable;
}

unsigned int Tile::getId()
{
	return _id;
}
