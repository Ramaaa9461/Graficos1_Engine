#include "../Headers/baseGame.h" 

namespace FACU_RAMI_ENGINE
{
	DllExport BaseGame::BaseGame()
	{

	}

	DllExport BaseGame::~BaseGame()
	{

	}

	DllExport int BaseGame::run()
	{
		Window* window = new Window();

		Renderer* renderer = new Renderer();

		renderer->renderWindow(window->getWindow());

		delete window;

		delete renderer;

		return 0;
	}
}