#include "Input.h"


Window* Input::_window = nullptr;

DllExport void Input::setWindow(Window* window)
{
	Input::_window = window;
}
