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
	Init();

	Shape* shape[3];

	//GLCall(glEnable(GL_BLEND));
	//GLCall(glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA)); 

	shape[0] = new RectangleShape(glm::vec4(0.5f, 0.9f,0.1f, 1.0f));
	shape[1] = new TriangleShape(glm::vec4(0.2f, 0.6f, 0.9f, 1.0f));
	shape[2] = new Sprite("Mario.png");

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



