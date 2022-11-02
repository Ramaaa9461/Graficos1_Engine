#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include "GL/glew.h"
#include "glfw3.h"

#include "DDLExport.h"


	class Window
	{
	private:

		GLFWwindow* window;


	public:

		static const int WINDOW_WIDTH = 960;
		static const int WINDOW_HEIGHT = 540;


		DllExport Window();
		DllExport ~Window();

		DllExport int initGlfw();
		DllExport void initGlew();

		DllExport int createWindow();

		DllExport GLFWwindow* getWindow();

		DllExport int GetScreenWidth();
		DllExport int GetScreenHeight();

		bool getWindowsShouldClose();

	};


#endif