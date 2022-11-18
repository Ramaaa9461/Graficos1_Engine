#ifndef BASE_GAME_H
#define BASE_GAME_H

#include "GL/glew.h"
#include "glfw3.h"

#include "DDLExport.h"

#include "src/Headers/Renderer.h"
#include "window.h"

#include "Shape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"
#include "Sprite.h"
#include "ImGuiEngine.h"
#include "CollisionManager.h"
#include "Input.h"

	class BaseGame
	{

	private:

		Window* window;
		Renderer* renderer;

	public:

		DllExport BaseGame();
		DllExport ~BaseGame();
		DllExport void run();


		DllExport virtual void Init() = 0;
		DllExport virtual void Update() = 0;
		DllExport virtual void DeInit() = 0;
	};



#endif
