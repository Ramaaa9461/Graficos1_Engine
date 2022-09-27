#include "../Headers/baseGame.h"

int main()
{
	FACU_RAMI_ENGINE::BaseGame* game = new FACU_RAMI_ENGINE::BaseGame();

	game->run();

	delete game;

	return 0;
}