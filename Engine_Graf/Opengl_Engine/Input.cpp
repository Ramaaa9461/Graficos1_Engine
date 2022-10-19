#include "Input.h"

namespace FACU_RAMI_ENGINE
{
	Input::Input(Window* window)
	{
		this->window = window;
	}

	Input::~Input()
	{

	}

	bool Input::GetKey(int key)
	{
		return glfwGetKey(window->getWindow(), key) == GLFW_PRESS;
	}

	void Input::SetWindowsShouldClose(bool windowsIsOpen)
	{		
		glfwSetWindowShouldClose(window->getWindow(), windowsIsOpen);
	}
}