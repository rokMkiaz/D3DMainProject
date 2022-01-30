
#pragma once
#include "Systems/IExecute.h"

class Editor : public IExecute
{
public:
	virtual void Initialize() override;
	virtual void Ready() override {}
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void PreRender() override {}
	virtual void Render() override;
	virtual void PostRender() override {}
	virtual void ResizeScreen() override {}

private:
	void Mesh();

private:
	void UpdateParticleList(); //파일가져오기
	void UpdateTextureList();

	void OnGUI();
	void OnGUI_List();
	void OnGUI_Settings();
	void OnGUI_Write();//Write버튼 출력

	void WriteFile(wstring file);

private:
	Shader* shader;
	CubeSky* sky;

	float windowWidth = 500;

	bool bLoop = false;
	UINT maxParticle = 0;

	vector<wstring> particleList;
	vector<wstring> textureList;

	wstring file = L"";

	ParticleSystem* particleSystem = NULL;

	Material* floor;
	Material* stone;

	MeshRender* sphere;
	MeshRender* grid;
};