#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx12.h"
#include "Vector2.h"

class ImguiManager
{
public:

	/// <summary>
	/// imgui�̏�����
	/// </summary>
	void Initialize();

	void PreUpdate();

	/// <summary>
	/// imgui�̕`��
	/// </summary>
	void Draw();

	void PreDraw();

	/// <summary>
	/// imgui�̏I������
	/// </summary>
	void Finalize();

	/// <summary>
	/// �C���X�^���X���擾
	/// </summary>
	/// <returns></returns>
	static ImguiManager* GetInstance();

private:
	ImguiManager() {};
	~ImguiManager() {};
	ImguiManager(const ImguiManager& a) = delete;
	ImguiManager& operator=(const ImguiManager&) = delete;
	//SRV�p�f�X�N���v�^�q�[�v
	//Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>srvHeap_;
};