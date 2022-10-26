#ifndef ENTITY_H
#define ENTITY_H

#include "DDLExport.h"

#include "src/Headers/Renderer.h"
#include "src/Headers/VertexArray.h"
#include "src/Headers/VertexBuffer.h"
#include "src/Headers/VertexBufferLayout.h"

namespace FACU_RAMI_ENGINE
{
	class Entity
	{
	private:

		glm::vec3 translation;
		glm::vec3 rotation;
		glm::vec3 scale;

		glm::mat4 TRS = glm::mat4(1);

		float positions[16] = {
	-50.0f, -50.0f,	     0.0f, 0.0f,
	 50.0f, -50.0f,	     1.0f, 0.0f,
	 50.0f,  50.0f,	     1.0f, 1.0f,
	-50.0f,  50.0f,	     0.0f, 1.0f
		};
		
		unsigned int indices[6] = {
			0,1,2,
			2,3,0
		};

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

