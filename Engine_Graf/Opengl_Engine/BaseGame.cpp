#include "baseGame.h" 

namespace FACU_RAMI_ENGINE
{
	DllExport BaseGame::BaseGame()
	{
		window = NULL;
		renderer = NULL;
		_input = NULL;

		windowsIsOpen = true;
	}

	DllExport BaseGame::~BaseGame()
	{
		delete window;

		delete renderer;

		delete _input;
	}

	Input* BaseGame::getInput()
	{
		return _input;
	}

	void BaseGame::run()
	{
		window = new Window();

		renderer = new Renderer();

		_input = new Input(window);
		
		windowsIsOpen = true;

		//renderer->renderWindow(window->getWindow());

		init();

		while(windowsIsOpen)
		{
			input();

			update();

			//Render here
			//renderer->Draw();

			_input->SetWindowsShouldClose(windowsIsOpen);
		}

		deInit();		
	}	
}