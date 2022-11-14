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


	TileMap* tileMap = new TileMap("TilePallet.png", 64,64);

	Entity2d* animation = new Sprite("Mario.png", 200,200);
	((Sprite*)animation)->CreateAnimation(0,0,3,4,4);

	while (window->getWindowsShouldClose())
	{
		renderer->Clear();
		imGuiEngine->imGuiStarDraw();
		timer->updateDeltaTime();

		Update();

		tileMap->setTile(0, true, 0, 0,    18, 10);
		tileMap->setTile(1, true, 0, 32,   18, 10);
		tileMap->setTile(2, true, 32, 0,   18, 10);
		tileMap->setTile(3, true, 32, 64,  18, 10);
		tileMap->setTile(4, true, 128, 32, 18, 10);

		//CalculateVertices----------------------------------------
		animation->calculateVertices();
		((Sprite*)animation)->updateAnimation(*timer);

		tileMap->setDimensions(5, 5);

		int id = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				tileMap->setMapTileId(i, j, id);
			}
			id++;
		}

		//Render here-------------------------
		tileMap->draw();
		animation->draw();

		imGuiEngine->imGuiDrawObject(animation, 0);
		//------------------------------------
		imGuiEngine->imGuiEndDraw();
		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
	}

	DeInit();

	delete tileMap;
	delete animation;

	delete imGuiEngine;

	delete window;

	delete renderer;

	//return 0;
}



