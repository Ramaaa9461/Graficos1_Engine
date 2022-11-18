#pragma once

#include "Window.h"

 class Input
{

private:

	static Input* s_instance;

protected:
	static Window* _window;
	virtual bool IsKeyPressedImpl(int keycode) = 0;

public:

	static void setWindow(Window* window);

	inline static bool getKeyPressed(int keycode) { return s_instance->IsKeyPressedImpl(keycode);  };
	

};

