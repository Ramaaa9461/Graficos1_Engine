#pragma once

#include "GL/glew.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../../Window.h"

namespace FACU_RAMI_ENGINE
{
#pragma region Assert

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))


	void GLClearError();

	bool GLLogCall(const char* funtion, const char* file, int line);

#pragma endregion

	class Renderer
	{

	private:

		Window* window; 
		const int WINDOW_WIDTH = 960;
		const int WINDOW_HEIGHT = 540;

	public:

		Renderer(Window* window);

		glm::mat4 proj;
		glm::mat4 view;

		void Clear() const;
		void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)const;
		//El draw tendria que ser virtual puro
	};

}