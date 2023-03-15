#include "Game.h"

#include "Input.h"

Game::Game()
{
	BaseGame::run();
}

Game::~Game()
{

}


void Game::Init()
{
	animation = new Sprite("FireEmblem.jpeg", 200, 200);
	animation1 = new Sprite("Logo.jpg", 400, 200);

	((Sprite*)animation)->CreateAnimation(0, 10, 6, 18);
	
	tileMap = new TileMap("TilePallet.png", 200, 200, 10, 5); //620 x 310

	tileMap->setTile(0, true, 9, 0);
	tileMap->setTile(1, true, 9, 1);
	tileMap->setTile(2, true, 9, 2);
	tileMap->setTile(3, true, 9, 3);
	tileMap->setTile(4, true, 9, 4); // 18 - 10 TilePallet

	tileMap->setDimensions(5, 5);
	tileMap->setTileDimensions(64, 64);
	int id = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			tileMap->setMapTileId(i, j, id);
		}
		id++;
	}

}

void Game::Input()
{
	if (Input::getKeyPressed(GLFW_KEY_A) || Input::getKeyPressed(GLFW_KEY_A + 32))
	{
		animation->addPosition(glm::vec3(-5, 0, 0));
	}
	else if (Input::getKeyPressed(GLFW_KEY_S) || Input::getKeyPressed(GLFW_KEY_S + 32))
	{
		animation->addPosition(glm::vec3(0, -5, 0));
	}
	else if (Input::getKeyPressed(GLFW_KEY_D) || Input::getKeyPressed(GLFW_KEY_D + 32))
	{
		animation->addPosition(glm::vec3(5, 0, 0));
	}
	else if (Input::getKeyPressed(GLFW_KEY_W) || Input::getKeyPressed(GLFW_KEY_W + 32))
	{
		animation->addPosition(glm::vec3(0, 5, 0));
	}

	animation1->setPosition(glm::vec3(Input::getMousePosition().x, Input::getMousePosition().y, 0.0f));


	//if (Input::getKeyPressed(GLFW_KEY_LEFT))
	//{
	//	animation1->addPosition(glm::vec3(-5, 0, 0));
	//}
	//else if (Input::getKeyPressed(GLFW_KEY_DOWN))
	//{
	//	animation1->addPosition(glm::vec3(0, -5, 0));
	//}
	//else if (Input::getKeyPressed(GLFW_KEY_RIGHT))
	//{
	//	animation1->addPosition(glm::vec3(5, 0, 0));
	//}
	//else if (Input::getKeyPressed(GLFW_KEY_UP))
	//{
	//	animation1->addPosition(glm::vec3(0, 5, 0));
	//}

	/*
	if (Input::getMouseButtonPressed(0))
	{
		animation1->setPosition(glm::vec3(Input::getMousePosition().x, -Input::getMousePosition().y, 0.0f));
	}
	if (Input::getMouseButtonPressed(1))
	{
		animation->setPosition(glm::vec3(Input::getMousePosition().x, -Input::getMousePosition().y, 0.0f));
	}*/
}

void Game::Update()
{
	Input();
	//CalculateVertices----------------------------------------
	{
		animation->calculateVertices();
		animation1->calculateVertices();
	}
	//Update animation-------------------------

	((Sprite*)animation)->updateAnimation(2.0f);

	//Render here-------------------------
	{
		tileMap->draw();

	/*	((Sprite*)animation)->drawTexture();
		((Sprite*)animation1)->drawTexture();*/
	}
	//------------------------------------

	//ImGui visual sliders

	if (CollisionManager::IntersectPolygons(animation->getVertices(), 4, animation1->getVertices(), 4, normal, depth))
	{
		animation->addPosition(-normal * (depth / 2));
	//	animation1->addPosition(+normal * (depth / 2));
	}


}

void Game::DeInit()
{
	delete animation;
	delete animation1;

	delete tileMap;
}
