#include "baseGame.h" 

#include "Shape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"
#include "Sprite.h"
#include "ImGuiEngine.h"
#include "CollisionManager.h"
#include "Tilemap.h"

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

	Entity2d* animation = new Sprite("Mario.png", 200, 200);
	Entity2d* animation1 = new Sprite("Mario.png", 400, 200);

	((Sprite*)animation)->CreateAnimation(0, 0, 1, 4, 4);
	((Sprite*)animation1)->CreateAnimation(0, 128, 2, 4, 4);

	glm::vec3 normal;
	float depth;

	while (window->getWindowsShouldClose())
	{
		renderer->Clear();
		imGuiEngine->imGuiStarDraw();
		timer->updateDeltaTime();

		Update();

		//CalculateVertices----------------------------------------
		{
			animation->calculateVertices();
			animation1->calculateVertices();
		}
		//------------------------------------

		((Sprite*)animation)->updateAnimation(*timer);
		((Sprite*)animation1)->updateAnimation(*timer);

		//Render here-------------------------
		{
			animation->draw();
			animation1->draw();
		}
		//------------------------------------

		//ImGui visual sliders

		if (CollisionManager::IntersectPolygons(animation->getVertices(), 4, animation1->getVertices(), 4, normal, depth))
		{

			animation->setPosition(animation->getPosition() - normal * (depth / 2));
			animation1->setPosition(animation1->getPosition() + normal * (depth / 2));
		}

		imGuiEngine->imGuiDrawObject(animation, 0);
		imGuiEngine->imGuiDrawObject(animation1, 1);

		//------------------------------------




		imGuiEngine->imGuiEndDraw();
		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
	}

	DeInit();

	delete animation;
	delete animation1;

	delete imGuiEngine;

	delete window;

	delete renderer;

	//return 0;
}



