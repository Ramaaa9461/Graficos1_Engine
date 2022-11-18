#include "Input.h"


Window* Input::_window = nullptr;

void Input::setWindow(Window* window)
{
	Input::_window = window;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_REPEAT)
	{
		switch (key)
		{
		case GLFW_KEY_E:

			break;
		}
	}

}