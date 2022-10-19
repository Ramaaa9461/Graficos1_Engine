#ifndef GAME_H
#define GAME_H

#include "../../Engine_Graf/Opengl_Engine/BaseGame.h"

using namespace FACU_RAMI_ENGINE;

class Game : BaseGame
{
private:	

public:

	Game();
	~Game();

	void init();
	void input();
	void update();
	void deInit();
};

#endif