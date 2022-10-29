#include "baseGame.h" 

#include "Shape.h"
#include "ImGuiEngine.h"


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

		ImGuiEngine* imGuiEngine = new ImGuiEngine(window);
		Init();

		Shape* shape = new Shape();

		while (window->getWindowsShouldClose())
		{
			renderer->Clear();
			imGuiEngine->imGuiStarDraw();

			Update();


			shape->draw();

			//imGuiEngine->imGuiDrawObject(shape->getPosition(), shape->getRotation(), shape->getScale());
			imGuiEngine->imGuiDrawObject(shape);


			imGuiEngine->imGuiEndDraw();
			glfwSwapBuffers(window->getWindow());
			glfwPollEvents();
		}
	
		DeInit();

		delete imGuiEngine;

		delete shape;

		delete window;

		delete renderer;

		//return 0;
	}



