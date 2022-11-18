#pragma once

#include "Window.h"

 class Input
{

private:

	static Input* s_instance;

protected:
	static Window* _window;
	DllExport virtual bool IsKeyPressedImpl(int keycode) = 0;

public:

	DllExport static void setWindow(Window* window);

	DllExport inline static bool getKeyPressed(int keycode) { return s_instance->IsKeyPressedImpl(keycode);  };
	

};

