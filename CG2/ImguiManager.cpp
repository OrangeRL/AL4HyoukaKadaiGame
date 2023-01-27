#include "ImguiManager.h"
#include "WinApp.h"
#include "DX12base.h"
#include "Texture.h"
WinApp winApp;
void ImguiManager::Initialize()
{
	//ImGuiのコンテキストを生成
	ImGui::CreateContext();
	//ImGuiのスタイルを設定
	ImGui::StyleColorsDark();
	ImGui_ImplWin32_Init(winApp.hwnd);
}

ImguiManager* ImguiManager::GetInstance()
{
	static ImguiManager instance;
	return &instance;
}