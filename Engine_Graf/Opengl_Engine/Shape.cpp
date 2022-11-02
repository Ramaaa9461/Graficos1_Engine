#include "Shape.h"


	Shape::Shape()
	{

		
	}

	Shape::~Shape()
	{
		delete va;
		delete vb;
		delete ib;
		delete shader;
		delete texture;
	}

	void Shape::draw()
	{
		glm::mat4 mvp = renderer->proj * renderer->view * TRS;

		shader->Bind();
		shader->SetUniformsMat4f("u_MVP", mvp);

		renderer->Draw(va, ib, shader); //Esta raro... pide direccion de memoria, habria qe pasar solo el puntero (sin el *)
	}
