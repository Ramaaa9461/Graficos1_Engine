#include "baseGame.h" 


	DllExport BaseGame::BaseGame()
	{

	}

	DllExport BaseGame::~BaseGame()
	{

	}

	void BaseGame::run()
	{
		Window* window = new Window();

		Renderer* renderer = new Renderer(window);

		//renderer->renderWindow(window->getWindow()); 
		//ACA deberia entrar al loop del engine

		delete window;

		delete renderer;

		//return 0;
	}



