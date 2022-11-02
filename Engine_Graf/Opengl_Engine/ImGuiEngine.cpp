#include "ImGuiEngine.h"

ImGuiEngine::ImGuiEngine(Window* window)
{
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(window->getWindow(), true);
	ImGui::StyleColorsDark();
}

ImGuiEngine::~ImGuiEngine()
{
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiEngine::imGuiStarDraw()
{
	ImGui_ImplGlfwGL3_NewFrame();

}

void ImGuiEngine::imGuiEndDraw()
{

	ImGui::Render();
	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiEngine::imGuiDrawObject(glm::vec3 traslation, glm::vec3 rotation, glm::vec3 scale)
{
	ImGui::SliderFloat3("Translation", &traslation.x, 0.0f, 960.0f);
	ImGui::SliderFloat3("Rotation", &rotation.x, 0.0f, 360.0f);
	ImGui::SliderFloat3("Scale", &scale.x, 0.0f, 10.0f);

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}

void ImGuiEngine::imGuiDrawObject(Shape* shape[], int size)
{
	for (int i = 0; i < size; i++)
	{
		traslation = shape[i]->getPosition();
		rotation = shape[i]->getRotation();
		scale = shape[i]->getScale();

		{
			ImGui::SliderFloat2("Translation" + i, &traslation.x, 0.0f, 960.0f);
			ImGui::SliderFloat("Rotation " + i, &rotation.z, 0.0f, 360.0f);
			ImGui::SliderFloat2("Scale " + i, &scale.x, 0.0f, 10.0f);
		}

		shape[i]->setPosition(traslation);
		shape[i]->setRotation(rotation);
		shape[i]->setScale(scale);
	}
}
