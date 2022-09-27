#ifndef BASE_GAME_H
#define BASE_GAME_H

#include "GL/glew.h"
#include "glfw3.h"

#include "DDLExport.h"

#include "renderer.h"
#include "window.h"

namespace FACU_RAMI_ENGINE
{
	class BaseGame
	{
	private:

	public:
		DllExport BaseGame();
		DllExport ~BaseGame();

		DllExport int run();
	};
}

#endif