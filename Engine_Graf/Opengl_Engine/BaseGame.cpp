#include "baseGame.h" 

#include "Shape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"
#include "Sprite.h"
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
	Timer* timer = new Timer();
	Init();

	Entity2d* entity;

	//GLCall(glEnable(GL_BLEND));
	//GLCall(glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA)); 

	entity = new Sprite("Mario.png", true);

//	((Sprite*)entity)->CreateAnimation(0, 0, 10, 4);

	while (window->getWindowsShouldClose())
	{
		renderer->Clear();
		imGuiEngine->imGuiStarDraw();
		timer->updateDeltaTime();

		std::cout << timer->timeBetweenFrames() << std::endl;

		Update();
		//Render here-------------------------
		//((Sprite*)entity)->updateAnimation(*timer);



		entity->draw();
		imGuiEngine->imGuiDrawObject(entity);

		//------------------------------------
		imGuiEngine->imGuiEndDraw();
		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
	}

	DeInit();

	delete imGuiEngine;

	delete entity;

	delete window;

	delete renderer;

	//return 0;
}



