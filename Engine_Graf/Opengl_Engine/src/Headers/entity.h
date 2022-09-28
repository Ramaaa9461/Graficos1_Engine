#ifndef ENTITY_H
#define ENTITY_H

#include "DDLExport.h"

#include"renderer.h"

namespace FACU_RAMI_ENGINE
{
	struct vec3
	{
		float x;
		float y;
		float z;

		vec3()
		{
			x = 0;
			y = 0;
			z = 0;
		}
	};

	class Entity
	{
	private:

		vec3 position;
		vec3 rotation;
		vec3 scale;

		//Defino la matrizes y la TRS

	public:
		DllExport Entity();
		DllExport ~Entity();

		DllExport void setPosition(vec3 newPosition);
		DllExport void setRotation(vec3 newRotation);
		DllExport void setScale(vec3 newScale);

		DllExport vec3 getPosition();
		DllExport vec3 getRotation();
		DllExport vec3 getScale();

		//UpdateTRSMat

		DllExport virtual void draw(Renderer* renderer) = 0;
	};
}

#endif