#include "Input.h"



void Input::setWindow(Window* window)
{
	_window = window;
}

bool Input::getKey(int key)
{
	glfwSetKeyCallback(_window->getWindow(), key_callback);
	
	
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
	{
		
	}

}