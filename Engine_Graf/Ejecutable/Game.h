#ifndef GAME_H
#define GAME_H

#include "BaseGame.h"

#include "Shape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"
#include "Sprite.h"
#include "ImGuiEngine.h"
#include "CollisionManager.h"
#include "Tilemap.h"

class Game : public BaseGame
{

private:

	Entity2d* animation;
	Entity2d* animation1;

	glm::vec3 normal;
	float depth;

	TileMap* tileMap;

public:

	Game();
	~Game();

	void Init();
	void Input();
	void Update();
	void DeInit();

};

#endif