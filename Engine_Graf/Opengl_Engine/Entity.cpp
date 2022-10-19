#include "Entity.h"
#include <glm\ext\matrix_transform.hpp>
#include <glfw3.h>

namespace FACU_RAMI_ENGINE
{
	DllExport Entity::Entity()
	{
		position = glm::vec3();
		rotation = glm::vec3();
		scale = glm::vec3();

		TRS = glm::mat4();

		//Inicializar los Buffers

	}

	Entity::~Entity()
	{

	}

	DllExport void Entity::setPosition(glm::vec3 newPosition)
	{
		position = newPosition;
		UpdateTRSMat();
	}

	DllExport void Entity::setRotation(glm::vec3 newRotation)
	{
		rotation = newRotation;
		UpdateTRSMat();
	}

	DllExport void Entity::setScale(glm::vec3 newScale)
	{
		scale = newScale;
		UpdateTRSMat();
	}

	DllExport glm::vec3 Entity::getPosition()
	{
		return position;
	}

	DllExport glm::vec3 Entity::getRotation()
	{
		return rotation;
	}

	DllExport glm::vec3 Entity::getScale()
	{
		return scale;
	}

	void Entity::UpdateTRSMat()
	{
		glm::mat4 t = glm::translate(glm::mat4(1.0f), position);
		glm::mat4 r = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime(), rotation); //Chequar ese 10 harcodeado
		glm::mat4 s = glm::scale(glm::mat4(1.0f), scale);

		TRS = s * r * t;


		//ASI LO HACE LEARNOPENGL

		// create transformations	https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/5.1.transformations/transformations.cpp
		//glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		//transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
		//transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));


	}
}