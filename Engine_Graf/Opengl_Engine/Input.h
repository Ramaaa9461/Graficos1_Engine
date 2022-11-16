#pragma once

#include "glfw3.h"
#include "Window.h"

static class Input
{

		
	static Window* _window;

public:

	static void setWindow(Window* window);

	static bool getKey(int key);
};

