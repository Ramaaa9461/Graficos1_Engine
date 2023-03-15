#pragma once

#include "Entity2d.h"
#include "CollisionManager.h"
#include "Tile.h"

#include "glm/glm.hpp"

class TileMap
{

public:
	DllExport TileMap();
	DllExport ~TileMap();

	DllExport const Tile& getTile(unsigned int uiId);
	DllExport void setTile(const Tile& rkTile);
	DllExport void setMapTileId(int layer, unsigned int uiCol, unsigned int uiRow, unsigned int uiId);

	DllExport void setDimensions(float width, float heigth);
	DllExport void setTileDimensions(float tileWidth, float tileHeigth);

	DllExport void setTexture(const Texture& rkTexture);
	DllExport void draw(Renderer& rkRenderer);

	DllExport bool importTileMap(std::string filePath, Renderer& rkRenderer);
	DllExport void checkCollision(Entity2d& object);

private:
	std::vector<Tile> tiles;
	std::vector<Tile**> _tileMapGrid;

	unsigned int _width;
	unsigned int _height;

	float _tileWidth;
	float _tileHeight;

	Texture _texture;

	float _imageWidth;
	float _imageHeight;

	float convertedPosX;
	float convertedPosY;

	std::string _imagePath;
};

