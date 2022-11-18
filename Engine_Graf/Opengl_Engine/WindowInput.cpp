#include "WindowInput.h"



Input* Input::s_instance = new WindowInput();

DllExport bool WindowInput::IsKeyPressedImpl(int keycode)
{

	auto state = glfwGetKey(_window->getWindow() , keycode);
	
	return (state == GLFW_PRESS || state == GLFW_REPEAT);
	
}
