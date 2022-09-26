#pragma once
#include "DDLExport.h"
#include <list>
#include"renderer.h"

struct vec3
{
	float x;
	float y;
	float z;
};

class Entity
{
public:
	DllExport Entity(/*std::list<Coordinates> vertexes*/);
	DllExport ~Entity();
	DllExport void setPosition(vec3 newPosition);
	DllExport vec3 getPosition();
	DllExport void setRotation(vec3 newRotation);
	DllExport vec3 getRotation();
	DllExport void setScale(vec3 newScale);
	DllExport vec3 getScale();
	//DllExport std::list<Coordinates> getVertexList();
	DllExport virtual void draw(Renderer* renderer) = 0;

private:
	vec3 position;
	vec3 rotation;
	vec3 scale;
	//std::list<Coordinates> vertexList;
};


