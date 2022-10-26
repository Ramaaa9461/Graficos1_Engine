#include "Shape.h"


	Shape::Shape()
	{
		_vertexPosition = NULL;

		_vertexCount = 0;

		va = new VertexArray();
		vb = new VertexBuffer(positions, 4 * 4 * sizeof(float));

		layout = VertexBufferLayout();
		layout.Push<float>(2);		 //Video: Buffer Layout Abstraction in OpenGL - min 27.30 Explica mas cosas qe se pueden hacer
		layout.Push<float>(2);
		va->AddBuffer(*vb, layout);
		va->Bind();

		ib = new IndexBuffer(indices, 6);

		shader = new Shader("res/Shaders/Basic.shader");
		shader->Bind();
		shader->SetUniforms4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

		texture = new Texture("res/textures/Logo.jpg");
		texture->Bind();
		shader->SetUniforms1i("u_Texture", 0);


		va->Unbind();
		vb->UnBind();
		ib->UnBind();
		shader->Unbind();
	}

	Shape::~Shape()
	{
		delete va;
		delete vb;
		delete ib;
		delete shader;
		delete texture;
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
		glm::mat4 mvp = renderer->proj * renderer->view * TRS;

		shader->Bind();
		shader->SetUniformsMat4f("u_MVP", mvp);

		renderer->Draw(va, ib, shader); //Esta raro... pide direccion de memoria, habria qe pasar solo el puntero (sin el *)
	}
