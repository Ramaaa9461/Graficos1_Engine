#pragma once
#include "GL/glew.h"
#include "glfw3.h"
#include "DDLExport.h"
#include<iostream>
#include<string.h>


class Renderer
{
public:
	DllExport Renderer();
	DllExport ~Renderer();
	DllExport void renderWindow(GLFWwindow* window);
	DllExport void clearWindow();
	DllExport void swapBuffers(GLFWwindow* window);
	DllExport void pollEvents();
	DllExport int windowShouldClose(GLFWwindow* window);
	DllExport void setBuffers(int quantity, unsigned int& id, unsigned int bufferArray[], GLenum drawMode, GLenum bufferMode);
	DllExport void setBuffers(int quantity, unsigned int& id, float bufferArray[], GLenum drawMode, GLenum bufferMode);
	DllExport void setFloatVertex();
	DllExport static unsigned int CompileShader(unsigned int type, const std::string& source);
	DllExport static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
private:

};
