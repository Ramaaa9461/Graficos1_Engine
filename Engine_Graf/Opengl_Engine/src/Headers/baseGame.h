#pragma once
#include "DDLExport.h"
#include "GL/glew.h"
#include "glfw3.h"
#include "renderer.h"
#include "window.h"

class BaseGame
{
public:
	DllExport BaseGame();
	DllExport ~BaseGame();
	DllExport int run();

private:

};

