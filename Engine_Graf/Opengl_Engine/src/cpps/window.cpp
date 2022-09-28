#include "../Headers/window.h"

namespace FACU_RAMI_ENGINE
{
	DllExport Window::Window()
	{
		run();
	}

	DllExport Window::~Window()
	{
		glfwTerminate();
	}

	DllExport int Window::initGlfw()
	{
		return glfwInit();
	}

	DllExport void Window::initGlew()
	{
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Glew initialization failed!" << std::endl;
		}
	}

	DllExport int Window::run()
	{
		if (!initGlfw())
			return -1;

		window = glfwCreateWindow(640, 480, "OpenGl_Engine", NULL, NULL);

		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		initGlew();
	}

	DllExport GLFWwindow* Window::getWindow()
	{
		return window;
	}		
}