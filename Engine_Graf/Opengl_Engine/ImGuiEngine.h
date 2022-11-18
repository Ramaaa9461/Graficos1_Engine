#pragma once

#include "glm/glm.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include "Window.h"
#include "Entity2d.h"

class ImGuiEngine
{
private:

	glm::vec3 traslation;
	glm::vec3 rotation;
	glm::vec3 scale;

	static int objectNumber;


public:

	DllExport ImGuiEngine(Window* window);
	DllExport ~ImGuiEngine();
	
	DllExport void imGuiStarDraw();
	DllExport void imGuiEndDraw();
	
	DllExport void imGuiDrawObject(glm::vec3 traslation, glm::vec3 rotation, glm::vec3 scale);
	DllExport void imGuiDrawObject(Entity2d* entity2d, int index);
};

