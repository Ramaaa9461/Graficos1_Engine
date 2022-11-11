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

public:

	ImGuiEngine(Window* window);
	~ImGuiEngine();

	void imGuiStarDraw();
	void imGuiEndDraw();

	void imGuiDrawObject(glm::vec3 traslation, glm::vec3 rotation, glm::vec3 scale);

	void imGuiDrawObject(Entity2d* entity2d);
};

