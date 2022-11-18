#include "Input.h"
#include "Window.h"



DllExport bool Input::IsKeyPressedImpl(int keycode)
{
	auto state = glfwGetKey(Window::getWindow()->getNativeWindow(), keycode);

	return (state == GLFW_PRESS || state == GLFW_REPEAT);
}
