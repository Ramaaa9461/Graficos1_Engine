
#include "../Headers/Renderer.h"

#include <iostream>

namespace FACU_RAMI_ENGINE
{

	void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	bool GLLogCall(const char* funtion, const char* file, int line)
	{
		while (GLenum error = glGetError())
		{
			std::cout << "[OpenGL Error (" << error << "); " << funtion <<
				" " << file << ":" << line << std::endl;
			return false;
		}
		return true;
	}

	Renderer::Renderer(Window* window)
	{
		this->window = window;

		proj = glm::ortho(0.0f, (float)window->WINDOW_WIDTH, 0.0f, (float)window->WINDOW_HEIGHT, -1.0f, 1.0f); //Proyeccion ortografica
		view = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	void Renderer::Clear() const
	{
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
	{
		shader.Bind();
		va.Bind();
		ib.Bind();

		GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

	}

}