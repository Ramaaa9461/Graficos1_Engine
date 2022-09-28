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

#pragma region VertexSahder
		
		const string _vertexShader = "#version 330 core\n"
			"\n"
			"layout(location = 0) in vec4 position;"
			"\n"
			"void main()\n"
			"{\n"
			"	gl_Position = position;\n"
			"}\n";

#pragma endregion

#pragma region FragmentSahder

		const string _fragmentShader = "#version 330 core\n"
			"\n"
			"layout(location = 0) out vec4 color;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"
			"}\n";

#pragma endregion

	public:
		DllExport Renderer();
		DllExport ~Renderer();

		DllExport void renderWindow(GLFWwindow* window);		
		
		DllExport void setBuffers(int quantity, unsigned int& id, unsigned int bufferArray[], GLenum drawMode, GLenum bufferMode);
		DllExport void setBuffers(int quantity, unsigned int& id, float bufferArray[], GLenum drawMode, GLenum bufferMode);
		
		DllExport void setFloatVertex();

		DllExport static unsigned int CompileShader(unsigned int type, const std::string& source);
		DllExport static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);


		//Se multiplica la TRS por la MVP ( modelo (TRS) * M.vista * M.perspectiva )

		//Se define la matriz Vista (View),se define 1 sola vez, aca o en base game. 
		//Se define la matriz Proyection (Proyeccion), se define 1 sola vez, aca o en base game

		//Tiene Agregar un Renderer (Una funcion tiene que pedirlo por parametro)
	};
}

#endif



////En el vertexShader hay qe hacer qe tenga en cuenta la matriz MVP para aplicarla a cada Verice
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"


//Lo que tenemos qe hacer pero todo junto https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/5.1.transformations/transformations.cpp

//Lectura de archivos para Shader https://learnopengl.com/code_viewer_gh.php?code=includes/learnopengl/shader_m.h

//Matrices https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab

//Uniforms para pasarle datos a los Shaders

//

//





