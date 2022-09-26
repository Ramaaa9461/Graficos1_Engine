#include "../Headers/entity.h"


DllExport Entity::Entity(/*std::list<Coordinates> vertexes*/)
{
	//vertexList = vertexes;
}

Entity::~Entity()
{

}

DllExport void Entity::setPosition(vec3 newPosition)
{
	position = newPosition;
}

DllExport vec3 Entity::getPosition()
{
	return position;
}

//DllExport std::list<Coordinates> Entity::getVertexList()
//{
//	return vertexList;
//}

DllExport void Entity::setRotation(vec3 newRotation)
{
	rotation = newRotation;
}

DllExport vec3 Entity::getRotation()
{
	return rotation;
}

DllExport void Entity::setScale(vec3 newScale)
{
	scale = newScale;
}

DllExport vec3 Entity::getScale()
{
	return scale;
}

