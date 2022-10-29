#pragma once

#include "glm/glm.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include "Window.h"
#include "Shape.h"

class ImGuiEngine
{

public:

	ImGuiEngine(Window* window);
	~ImGuiEngine();

	void imGuiStarDraw();
	void imGuiEndDraw();

	void imGuiDrawObject(glm::vec3 traslation, glm::vec3 rotation, glm::vec3 scale);

	void imGuiDrawObject(Shape* shape);


};

