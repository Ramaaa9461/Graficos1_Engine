#ifndef GAME_H
#define GAME_H

#include "BaseGame.h"

class Game :  BaseGame
{
private:	

public:

	Game();
	~Game();	

	void Init();
	void Input();
	void Update();
	void DeInit();
};

#endif