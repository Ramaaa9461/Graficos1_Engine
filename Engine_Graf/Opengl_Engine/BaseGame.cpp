#include "baseGame.h" 

#include "Shape.h"
#include "RectangleShape.h"
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

		Shape* shape[3];
		
		for (int i = 0; i < 3; i++)
		{
			shape[i] = new RectangleShape();
		}


		while (window->getWindowsShouldClose())
		{
			renderer->Clear();
			imGuiEngine->imGuiStarDraw();

			Update();

			for (int i = 0; i < 3; i++)
			{
				shape[i]->draw();
			}
			
			imGuiEngine->imGuiDrawObject(shape, 3);


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



