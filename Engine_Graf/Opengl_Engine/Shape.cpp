#include "Shape.h"

namespace FACU_RAMI_ENGINE
{
	Shape::Shape()
	{
		_vertexPosition = NULL;

		_vertexCount = 0;

		va = VertexArray();
		vb = VertexBuffer(positions, 4 * 4 * sizeof(float));

		layout = VertexBufferLayout();
		layout.Push<float>(2);		 //Video: Buffer Layout Abstraction in OpenGL - min 27.30 Explica mas cosas qe se pueden hacer
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);
		va.Bind();

		ib = IndexBuffer(indices, 6);

		shader = Shader("res/Shaders/Basic.shader");
		shader.Bind();
		shader.SetUniforms4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

		texture = Texture("res/textures/Logo.jpg");
		texture.Bind();
		shader.SetUniforms1i("u_Texture", 0);


		va.Unbind();
		vb.UnBind();
		ib.UnBind();
		shader.Unbind();
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
		renderer->Draw(va, ib, shader);


	}
}