#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include "GL/glew.h"
#include "glfw3.h"

#include "DDLExport.h"

namespace FACU_RAMI_ENGINE
{
	class Window
	{
	private:

		GLFWwindow* window;
		const int WINDOW_WIDTH = 960;
		const int WINDOW_HEIGHT = 540;


	public:
		DllExport Window();
		DllExport ~Window();

		DllExport int initGlfw();
		DllExport void initGlew();

		DllExport int createWindow();

		DllExport GLFWwindow* getWindow();

		DllExport int GetScreenWidth();
		DllExport int GetScreenHeight();
	};
}

#endif