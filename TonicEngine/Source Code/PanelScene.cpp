#include "PanelScene.h"
#include "ModuleCamera3D.h"
#include "Viewport.h"
#include "ModuleWindow.h"
#include "ModuleRenderer3D.h"

PanelScene::PanelScene()
{
}

PanelScene::~PanelScene()
{
}

// EVERYTHING COMMENTED IS WORK IN PROGRESS

bool PanelScene::Start()
{
	this->active = true;

	//viewport_tex = new Viewport();
	//viewport_tex->StartBuffers(current_size);

	return true;
}

bool PanelScene::Draw()
{
	if (!App->gui->Pscene->active)
		return false;

	if (App->gui->Pscene->active)
	{
		if (ImGui::Begin("Scene", &active, ImGuiWindowFlags_NoScrollbar))
		{
			if (ImGui::IsWindowHovered()) App->camera->isOnScene = true;
			else App->camera->isOnScene = false;
		}

		/*ImVec2 vMin = ImGui::GetWindowContentRegionMin();
		ImVec2 vMax = ImGui::GetWindowContentRegionMax();

		vMin.x += ImGui::GetWindowPos().x;
		vMin.y += ImGui::GetWindowPos().y;
		vMax.x += ImGui::GetWindowPos().x;
		vMax.y += ImGui::GetWindowPos().y;

		ImGui::GetForegroundDrawList()->AddRect(vMin, vMax, IM_COL32(255, 255, 0, 255));

		new_size = ImGui::GetContentRegionAvail();

		ImGui::Image((ImTextureID)App->camera->GetEditorCamera()->GetComponentCamera()->viewport->GetTexture(), ImVec2(current_size.x, current_size.y), ImVec2(0, 1), ImVec2(1, 0));*/

		ImVec2 newSize = ImGui::GetWindowSize();
		ImVec2 size = { 0, 0 };
		if (newSize.x != size.x || newSize.y != size.y)
		{
			size = newSize;
			float newAR = size.x / size.y;
			App->camera->activeCam->SetRatio(newAR);
			//App->renderer3D->changedSceneFOV = true;
		}

		ImGui::Image((ImTextureID)App->renderer3D->scene_tex, ImVec2((float)newSize.x, (float)newSize.y), ImVec2(0, 1), ImVec2(1, 0));
		
		ImGui::End();
	}

	return true;
}


update_status PanelScene::PreUpdate(float dt)
{
	/*if (current_size.x != new_size.x || current_size.y != new_size.y)
	{
		current_size = new_size;
		viewport_tex->StartBuffers(current_size);
		App->renderer3D->OnResize(current_size.x, current_size.y);
	}

	viewport_tex->BindViewport();*/

	//App->camera->GetEditorCamera()->GetComponentCamera()->viewport->BindViewport();

	return UPDATE_CONTINUE;
}

update_status PanelScene::PostUpdate(float dt)
{
	//viewport_tex->UnbindViewport();
	//App->camera->GetEditorCamera()->GetComponentCamera()->viewport->UnbindViewport();

	return UPDATE_CONTINUE;
}

bool PanelScene::CleanUp()
{
	/*viewport_tex->DeleteBuffers();
	delete viewport_tex;
	viewport_tex = nullptr;*/

	return true;
}