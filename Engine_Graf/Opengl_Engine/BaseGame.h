#ifndef BASE_GAME_H
#define BASE_GAME_H

#include "GL/glew.h"
#include "glfw3.h"

#include "DDLExport.h"

#include "src/Headers/Renderer.h"
#include "window.h"
#include "Input.h"

namespace FACU_RAMI_ENGINE
{

	class BaseGame
	{
		private:

			Window* window;
			Renderer* renderer;
			Input* _input;

			bool windowsIsOpen;

		protected:

			DllExport BaseGame();
			DllExport ~BaseGame();
			DllExport void run();

			Input* getInput();
			
			virtual void init() = 0;

			virtual void input() = 0;
		
			virtual void update() = 0;
		
			virtual void deInit() = 0;			
	};
}

#endif
