#pragma once
#include "GL/glew.h"
#include "glfw3.h"
#include "DDLExport.h"
#include<iostream>

class Window
{
public:
	DllExport Window();
	DllExport ~Window();
	DllExport int begin();
	DllExport GLFWwindow* getWindows();
	DllExport GLFWwindow* create_Window(int width, int height, const char *console_Name);
	DllExport int initialize_Glfw();
	DllExport void initialize_Glew();
	DllExport void terminate_Glfw();

private:
	GLFWwindow* window;
};
