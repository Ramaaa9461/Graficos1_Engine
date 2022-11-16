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


	TileMap* tileMap = new TileMap("TilePallet.png", 64, 64, 10,5);

	Entity2d* animation = new Sprite("Mario.png", 200, 200);
	((Sprite*)animation)->CreateAnimation(0, 0, 3, 4, 4);

	tileMap->setTile(0, true, 9, 0 );
	tileMap->setTile(1, true, 9, 1 );
	tileMap->setTile(2, true, 9, 2 );
	tileMap->setTile(3, true, 9, 3 );
	tileMap->setTile(4, true, 9, 4 ); // 18 - 10 TilePallet

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

	while (window->getWindowsShouldClose())
	{
		renderer->Clear();
		imGuiEngine->imGuiStarDraw();
		timer->updateDeltaTime();

		Update();

		//CalculateVertices----------------------------------------
		{
			animation->calculateVertices();
		}
		//------------------------------------

		((Sprite*)animation)->updateAnimation(*timer);

		

		//Render here-------------------------
		{
		tileMap->draw();
		animation->draw();
		}
		//------------------------------------

		//ImGui visual sliders
		{
			imGuiEngine->imGuiDrawObject(animation, 0);
		}
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



