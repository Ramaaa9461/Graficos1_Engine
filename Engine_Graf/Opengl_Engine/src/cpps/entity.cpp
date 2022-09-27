#include "../Headers/entity.h"

namespace FACU_RAMI_ENGINE
{
	DllExport Entity::Entity()
	{
		position = vec3();
		rotation = vec3();
		scale = vec3();
	}

	Entity::~Entity()
	{

	}

	DllExport void Entity::setPosition(vec3 newPosition)
	{
		position = newPosition;
	}

	DllExport void Entity::setRotation(vec3 newRotation)
	{
		rotation = newRotation;
	}

	DllExport void Entity::setScale(vec3 newScale)
	{
		scale = newScale;
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