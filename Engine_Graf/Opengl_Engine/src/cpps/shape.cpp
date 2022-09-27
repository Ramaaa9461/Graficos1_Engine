#include "../Headers/shape.h"

namespace FACU_RAMI_ENGINE
{
	Shape::Shape()
	{
		_vertexPosition = NULL;

		_vertexCount = 0;
	}

	Shape::~Shape()
	{

	}

	void Shape::setVertices(int vertexCount, float* vertexPosition)
	{
		_vertexPosition = vertexPosition;

		_vertexCount = vertexCount;
	}

	float* Shape::getVertexPosition()
	{
		return _vertexPosition;
	}

	int Shape::getVertexCount()
	{
		return _vertexCount;
	}

	void Shape::draw(Renderer* renderer)
	{

	}
}