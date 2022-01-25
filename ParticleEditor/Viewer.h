#pragma once
#include"Systems\IExecute.h"
class Viewer : public IExecute
{
public:
	void Initialize() override;
	void Ready() override {};
	void Destroy() override;
	void Update() override;
	void PreRender() override {};
	void Render() override;
	void PostRender() override {};
	void ResizeScreen() override {};

private:
	void Mesh();

private:
	Shader* shader;
	CubeSky* sky;

	Material* floor;
	Material* stone;

	MeshRender* sphere;
	MeshRender* grid;
};