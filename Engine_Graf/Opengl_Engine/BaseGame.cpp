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

		Renderer* renderer = Renderer::getRenderer();
		renderer->initRenderer(window);

		Init();

		while (window->getWindowsShouldClose())
		{
			renderer->Clear();


			Update();



			glfwSwapBuffers(window->getWindow());
			glfwPollEvents();
		}
	
		DeInit();

		delete window;

		delete renderer;

		//return 0;
	}



