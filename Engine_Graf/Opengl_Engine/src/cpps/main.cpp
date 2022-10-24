#include "GL/glew.h"
#include "glfw3.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../Headers/Renderer.h"

#include "../Headers/VertexBuffer.h"
#include "../Headers/VertexBufferLayout.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/VertexArray.h"
#include "../Headers/Shader.h"
#include "../Headers/Texture.h"

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;
	{
		float positions[] = {
			-0.5, -0.5,	 0.0f, 0.0f,
	 	 	 0.5, -0.5,	 1.0f, 0.0f,
			  0.5, 0.5,	 1.0f, 1.0f,
			 -0.5, 0.5,	 0.0f, 1.0f
		};

		unsigned int indices[] = { 
			0,1,2,      
			2,3,0 
		};

	//	GLCall(glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	//	GLCall(glEnable(GL_BLEND));

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);            //Video: Buffer Layout Abstraction in OpenGL - min 27.30 Explica mas cosas qe se pueden hacer
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);
		va.Bind();

		IndexBuffer ib(indices, 6);


		Shader shader("res/Shaders/Basic.shader");
		shader.Bind();
		shader.SetUniforms4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

		Texture texture("res/textures/Logo.jpg");
		texture.Bind();
		shader.SetUniforms1i("u_Texture", 0);

		va.Unbind();
		vb.UnBind();
		ib.UnBind();
		shader.Unbind();

		Renderer renderer;

		float r = 0.0f;
		float increment = 0.05f;
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			renderer.Clear();

			shader.Bind();
			shader.SetUniforms4f("u_Color", r, 0.3f, 0.8f, 1.0f);

			renderer.Draw(va, ib, shader);

			if (r > 1.0f)
				increment = -0.05f;
			else if (r < 0.0f)
				increment = 0.05f;

			r += increment;

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}


	glfwTerminate();
	return 0;

}
