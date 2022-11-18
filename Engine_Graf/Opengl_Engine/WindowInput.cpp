#include "WindowInput.h"
#include "Window.h"



Input* Input::s_instance = new WindowInput();

DllExport bool WindowInput::IsKeyPressedImpl(int keycode)
{

	auto state = glfwGetKey( Window::getWindow()->getNativeWindow() , keycode);
	
	return (state == GLFW_PRESS || state == GLFW_REPEAT);
	
}
