#include "../Headers/baseGame.h" 

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

	renderer->renderWindow(window->getWindows());

	delete window;
	delete renderer;
	return 0;
}
