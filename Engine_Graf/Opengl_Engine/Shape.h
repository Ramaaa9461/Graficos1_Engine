#ifndef SHAPE_H
#define SHAPE_H

#include "entity2d.h"

#include "../Headers/VertexArray.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/VertexBufferLayout.h"
#include "../Headers/Shader.h"
#include "../Headers/Texture.h"
#include "ShaderType.h"

	class Shape : public Entity2d
	{

	protected:


	public:

			DllExport Shape(int initPositionX, int initPositionY);
 			DllExport ~Shape();

		//Tiene Agregar un Material (Una funcion tiene que pedirlo por parametro)
	};


#endif

