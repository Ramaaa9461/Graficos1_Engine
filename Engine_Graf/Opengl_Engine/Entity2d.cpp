#include "Entity2d.h"
//


Entity2d::Entity2d(int initPositionX, int initPositionY) : Entity(initPositionX, initPositionY)
{
}

Entity2d::~Entity2d()
{
	delete va;
	delete vb;
	delete ib;
	delete shader;
	delete texture;
}

glm::vec3* Entity2d::getVertices()
{
	return vertices;
}

void Entity2d::draw()
{
	glm::mat4 mvp = renderer->proj * renderer->view * TRS;

	shader->Bind();
	shader->SetUniformsMat4f("u_MVP", mvp);

	renderer->Draw(va, ib, shader); //Esta raro... pide direccion de memoria, habria qe pasar solo el puntero (sin el *)
}
