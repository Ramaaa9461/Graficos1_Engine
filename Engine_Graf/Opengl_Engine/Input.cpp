#include "Input.h"



void Input::setWindow(Window* window)
{
	_window = window;
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