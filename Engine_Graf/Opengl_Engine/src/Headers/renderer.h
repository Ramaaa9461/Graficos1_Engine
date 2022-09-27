#ifndef RENDERER_H
#define RENDERER_H

#include<iostream>
#include<string.h>

#include "GL/glew.h"
#include "glfw3.h"

#include "DDLExport.h"

using namespace std;

namespace FACU_RAMI_ENGINE
{
	class Renderer
	{
	private:
		const string _vertexShader = "#version 330 core\n"
			"\n"
			"layout(location = 0) in vec4 position;"
			"\n"
			"void main()\n"
			"{\n"
			"	gl_Position = position;\n"
			"}\n";

		const string _fragmentShader = "#version 330 core\n"
			"\n"
			"layout(location = 0) out vec4 color;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"
			"}\n";

	public:
		DllExport Renderer();
		DllExport ~Renderer();

		DllExport void renderWindow(GLFWwindow* window);		
		
		DllExport void setBuffers(int quantity, unsigned int& id, unsigned int bufferArray[], GLenum drawMode, GLenum bufferMode);
		DllExport void setBuffers(int quantity, unsigned int& id, float bufferArray[], GLenum drawMode, GLenum bufferMode);
		
		DllExport void setFloatVertex();

		DllExport static unsigned int CompileShader(unsigned int type, const std::string& source);
		DllExport static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	};
}

#endif