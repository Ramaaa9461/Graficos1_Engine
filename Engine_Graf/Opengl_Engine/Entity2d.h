#ifndef ENTITY2D_H
#define ENTITY2D_H

#include"entity.h"

#include "../Headers/VertexArray.h"
#include "../Headers/IndexBuffer.h"
#include "../Headers/VertexBufferLayout.h"
#include "../Headers/Shader.h"
#include "../Headers/Texture.h"
#include "ShaderType.h"

	class Entity2d : public Entity
	{

	protected:

		VertexArray* va;
		VertexBuffer* vb;
		VertexBufferLayout layout;
		IndexBuffer* ib;
		Shader* shader;
		Texture* texture;

		ShaderType shaderType;

		glm::vec3 vertices[4];


		DllExport virtual void  setVertices() = 0;
		DllExport virtual void  setIndixs() = 0;

	public:

		DllExport Entity2d(int initPositionX, int initPositionY);
		DllExport ~Entity2d();

		DllExport glm::vec3* getVertices();

		DllExport void draw();
		DllExport virtual void calculateVertices() = 0;

	};


#endif