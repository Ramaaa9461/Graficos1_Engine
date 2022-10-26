#include "Entity.h"
#include <glm\gtc\matrix_transform.hpp>
#include <glfw3.h>

namespace FACU_RAMI_ENGINE
{
	DllExport Entity::Entity()
	{
		glm::vec3 translation(200, 200, 0);
		glm::vec3 rotation(0, 0, 0);
		glm::vec3 scale(1, 1, 0);
	}

	Entity::~Entity()
	{

	}

	DllExport void Entity::setPosition(glm::vec3 newPosition)
	{
		translation = newPosition;
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
		return translation;
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
		glm::mat4 tras = glm::translate(glm::mat4(1.0f), translation);
		glm::mat4 rotX = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 rotY = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 rotZ = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 sca = glm::scale(glm::mat4(1.0f), scale);

		glm::mat4 rot = rotX * rotY * rotZ;
		TRS = tras * rot * sca;
	}
}