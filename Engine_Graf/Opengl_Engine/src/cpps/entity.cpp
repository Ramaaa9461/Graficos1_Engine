#include "../Headers/entity.h"

namespace FACU_RAMI_ENGINE
{
	DllExport Entity::Entity()
	{
		position = vec3();
		rotation = vec3();
		scale = vec3();
	}

	//multtplicar S*r*t

	Entity::~Entity()
	{

	}

	DllExport void Entity::setPosition(vec3 newPosition)
	{
		position = newPosition;
		//TODO Hacer Update de la matriz model
	}

	DllExport void Entity::setRotation(vec3 newRotation)
	{
		rotation = newRotation;
		//TODO Hacer Update de la matriz model
	}

	DllExport void Entity::setScale(vec3 newScale)
	{
		scale = newScale;
		//TODO Hacer Update de la matriz model
	}

	DllExport vec3 Entity::getPosition()
	{
		return position;
	}

	DllExport vec3 Entity::getRotation()
	{
		return rotation;
	}

	DllExport vec3 Entity::getScale()
	{
		return scale;
	}
}