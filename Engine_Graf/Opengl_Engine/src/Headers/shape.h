#ifndef SHAPE_H
#define SHAPE_H

#include "entity2d.h"

namespace FACU_RAMI_ENGINE
{
	class Shape : Entity2d
	{
	private:

		float* _vertexPosition;

		int _vertexCount;

	public:
		Shape();
		~Shape();

		void setVertices(int vertexCount, float* vertexPosition);

		float* getVertexPosition();
		int getVertexCount();

		void draw(Renderer* renderer);

		//Tiene Agregar un Material (Una funcion tiene que pedirlo por parametro)
	};
}

#endif