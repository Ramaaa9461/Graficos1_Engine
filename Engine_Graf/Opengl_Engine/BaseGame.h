#ifndef BASE_GAME_H
#define BASE_GAME_H

#include "GL/glew.h"
#include "glfw3.h"

#include "DDLExport.h"

#include "src/Headers/Renderer.h"
#include "window.h"



	class BaseGame
	{

	private:

		Window* window;
		Renderer* renderer;

	public:

		DllExport BaseGame();
		DllExport ~BaseGame();
		DllExport void run();


		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void DeInit() = 0;


	};



#endif
