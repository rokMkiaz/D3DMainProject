#pragma once
#include "Systems/IExecute.h"

class PondWaterDemo : public IExecute
{
public:
	virtual void Initialize() override;
	virtual void Ready() override {}
	virtual void Destroy() override {}
	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
	virtual void ResizeScreen() override {}

private:
	void Mesh();
	void Airplane();
	
	

	void Pass(UINT mesh, UINT model, UINT anim);

private:
	Shader* shader;

	Shadow* shadow;
	Render2D* render2D;

	CubeSky* sky;

	Material* floor;
	PondWater* water;
	Material* stone;
	Material* brick;
	Material* wall;

	MeshRender* cube;
	MeshRender* cylinder;
	MeshRender* sphere;
	MeshRender* grid;
	MeshRender* waterGrid;

	ModelRender* airplane = NULL;


	vector<MeshRender*> meshes;
};