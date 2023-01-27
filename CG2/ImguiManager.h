#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx12.h"
#include "Vector2.h"

class ImguiManager
{
public:

	/// <summary>
	/// imguiの初期化
	/// </summary>
	void Initialize();

	void PreUpdate();

	/// <summary>
	/// imguiの描画
	/// </summary>
	void Draw();

	void PreDraw();

	/// <summary>
	/// imguiの終了処理
	/// </summary>
	void Finalize();

	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns></returns>
	static ImguiManager* GetInstance();

private:
	ImguiManager() {};
	~ImguiManager() {};
	ImguiManager(const ImguiManager& a) = delete;
	ImguiManager& operator=(const ImguiManager&) = delete;
	//SRV用デスクリプタヒープ
	//Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>srvHeap_;
};