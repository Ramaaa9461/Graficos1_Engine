#ifndef ENTITY_H
#define ENTITY_H

#include "DDLExport.h"

#include "src/Headers/Renderer.h"

namespace FACU_RAMI_ENGINE
{
	class Entity
	{
	private:

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		glm::mat4 TRS;
		//Defino la matrizes y la TRS

	public:
		DllExport Entity();
		DllExport ~Entity();

		DllExport void setPosition(glm::vec3 newPosition);
		DllExport void setRotation(glm::vec3 newRotation);
		DllExport void setScale(glm::vec3 newScale);

		DllExport glm::vec3 getPosition();
		DllExport glm::vec3 getRotation();
		DllExport glm::vec3 getScale();

		DllExport void UpdateTRSMat();

		DllExport virtual void draw(Renderer* renderer) = 0;
	};
}

#endif

