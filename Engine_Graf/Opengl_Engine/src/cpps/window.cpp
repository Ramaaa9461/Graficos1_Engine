#include "../Headers/window.h"

DllExport Window::Window()
{
	begin();
}

DllExport Window::~Window()
{
	terminate_Glfw();
}

DllExport GLFWwindow* Window::getWindows()
{
	return window;
}

DllExport GLFWwindow* Window::create_Window(int width, int height, const char *console_Name)
{
	return glfwCreateWindow(width, height, console_Name, NULL, NULL);
}

DllExport int Window::initialize_Glfw()
{
	return glfwInit();
}

DllExport void Window::terminate_Glfw()
{
	glfwTerminate();
}

DllExport void Window::initialize_Glew()
{
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error" << std::endl;
	}
}

DllExport int Window::begin()
{
	if (!initialize_Glfw())
		return -1;

	window = create_Window(640, 480, "OpenGl_Engine");

	if (!window)
	{
		terminate_Glfw();
		return -1;
	}

	glfwMakeContextCurrent(window);
	initialize_Glew();
}
