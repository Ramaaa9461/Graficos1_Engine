#include "../Headers/renderer.h"

using namespace std;

namespace FACU_RAMI_ENGINE
{
	DllExport Renderer::Renderer()
	{

	}

	DllExport Renderer::~Renderer()
	{

	}

	DllExport void Renderer::renderWindow(GLFWwindow* window)
	{
		unsigned int indexBufferObject;
		unsigned int vertexBufferObject;

		float vertexPositions[] =
		{
			-0.5f, -0.5f, 0.0f, 
			 0.5f, -0.5f, 0.0f, 
			 0.5f,  0.5f, 0.0f, 
			-0.5f,  0.5f, 0.0f  
		};

		unsigned int indexes[] =
		{
			0,1,2,
			2,3,0
		};

		setBuffers(1, vertexBufferObject, vertexPositions, GL_STATIC_DRAW, GL_ARRAY_BUFFER);
		setBuffers(1, indexBufferObject, indexes, GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER);

		setFloatVertex();

		unsigned int shader = CreateShader(_vertexShader, _fragmentShader);

		glUseProgram(shader);

		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			glfwSwapBuffers(window);

			glfwPollEvents();
		}

		glDeleteProgram(shader);
	}		

	DllExport void Renderer::setBuffers(int quantity, unsigned int& id, unsigned int bufferArray[], GLenum drawMode, GLenum bufferMode)
	{
		glGenBuffers(quantity, &id);
		glBindBuffer(bufferMode, id);
		glBufferData(bufferMode, 6 * 2 * sizeof(float), bufferArray, drawMode);
	}

	DllExport void Renderer::setBuffers(int quantity, unsigned int& id, float bufferArray[], GLenum drawMode, GLenum bufferMode)
	{
		glGenBuffers(quantity, &id);
		glBindBuffer(bufferMode, id);
		glBufferData(bufferMode, 6 * 2 * sizeof(float), bufferArray, drawMode);
	}

	DllExport void Renderer::setFloatVertex()
	{
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
		glEnableVertexAttribArray(0);
	}

	DllExport unsigned int Renderer::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		
		const char* src = source.c_str();

		glShaderSource(id, 1, &src, nullptr);

		glCompileShader(id);

		int result;
		
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int length;
			
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			
			char* message = (char*)_malloca(length * sizeof(char));
			
			glGetShaderInfoLog(id, length, &length, message);
			
			cout << "Failed to compile" << 
				(type == GL_VERTEX_SHADER ? " vertex" : " fragment") << " shader!" << std::endl;
			
			cout << message << std::endl;
			
			glDeleteShader(id);

			return 0;
		}

		return id;
	}

	DllExport  unsigned int Renderer::CreateShader(const std::string& _vertexShader, const std::string& _fragmentShader)
	{
		unsigned int program = glCreateProgram();

		unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, _vertexShader);
		unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, _fragmentShader);

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		glLinkProgram(program);
		
		glValidateProgram(program);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return program;
	}
}