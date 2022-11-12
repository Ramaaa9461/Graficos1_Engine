#include "baseGame.h" 

#include "Shape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"
#include "Sprite.h"
#include "ImGuiEngine.h"
#include "CollisionManager.h"

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

	Entity2d* entity = new RectangleShape ();
	Entity2d* entity2 = new RectangleShape();

	((RectangleShape*)entity)->setColor(glm::vec4(0.3f, 0.4, 0.9, 1.0f));
	((RectangleShape*)entity2)->setColor(glm::vec4(0.5f, 0.9, 0.4, 1.0f));
	//entity = new Sprite("Mario.png");

	//((Sprite*)entity)->CreateAnimation(0, 0, 1, 4, 4); //La textura es 256 x 256 (64, 128,192, 256)
	glm::vec3 normal;
	float depth;

	while (window->getWindowsShouldClose())
	{
		renderer->Clear();
		imGuiEngine->imGuiStarDraw();
		timer->updateDeltaTime();

		Update();
		
		//CalculateVertices
		entity->calculateVertices();
		entity2->calculateVertices();
		//Render here-------------------------
	//	((Sprite*)entity)->updateAnimation(*timer);

		if (CollisionManager::IntersectPolygons(entity->getVertices(), 4, entity2->getVertices(), 4, normal, depth))
		{
			std::cout << "Se la dieron" << std::endl;
		}
		else
		{
			std::cout << "no se la estan dando" << std::endl;
		}


		entity->draw();
		entity2->draw();
		imGuiEngine->imGuiDrawObject(entity, 0);
		imGuiEngine->imGuiDrawObject(entity2, 1);

		//------------------------------------
		imGuiEngine->imGuiEndDraw();
		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
	}

	DeInit();

	delete entity2;

	delete imGuiEngine;

	delete entity;

	delete window;

	delete renderer;

	//return 0;
}



