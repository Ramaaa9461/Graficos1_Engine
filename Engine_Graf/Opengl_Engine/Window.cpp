#include "Window.h"

	DllExport Window::Window()
	{
		createWindow();
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

	DllExport int Window::createWindow() //Aca se puede pedir el tamaño de la pantalla
	{
		if (!initGlfw())
			return -1;

		window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGl_Engine", NULL, NULL);

		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		glfwSwapInterval(1); //Ni idea qe onda esto

		initGlew();
	}

	DllExport GLFWwindow* Window::getWindow()
	{
		return window;
	}
	
	DllExport int Window::GetScreenWidth()
	{
		return WINDOW_WIDTH;
	}

	DllExport int Window::GetScreenHeight()
	{
		return WINDOW_HEIGHT;
	}

	DllExport bool Window::getWindowsShouldClose()
	{
		return glfwWindowShouldClose;
	}