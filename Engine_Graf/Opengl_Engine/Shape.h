#ifndef SHAPE_H
#define SHAPE_H

#include "entity2d.h"

#include "../Headers/VertexArray.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/VertexBufferLayout.h"
#include "../Headers/Shader.h"
#include "../Headers/Texture.h"


	class Shape : public Entity2d
	{

	private:

		float positions[16] = {
	-50.0f, -50.0f,	     0.0f, 0.0f,
	 50.0f, -50.0f,	     1.0f, 0.0f,
	 50.0f,  50.0f,	     1.0f, 1.0f,
	-50.0f,  50.0f,	     0.0f, 1.0f
		};

		unsigned int indices[6] = {
			0,1,2,
			2,3,0
		};

		VertexArray* va;
		VertexBuffer* vb;
		VertexBufferLayout layout;

		IndexBuffer* ib;

		Shader* shader;

		Texture* texture;


		float* _vertexPosition;

		int _vertexCount;

	public:

		Shape();
		~Shape();

		void setVertices(int vertexCount, float* vertexPosition);

		float* getVertexPosition();
		int getVertexCount();

		void draw();

		//Tiene Agregar un Material (Una funcion tiene que pedirlo por parametro)
	};


#endif

