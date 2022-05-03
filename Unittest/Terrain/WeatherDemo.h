#pragma once
#include "Systems/IExecute.h"

class WeatherDemo : public IExecute
{
public:
	virtual void Initialize() override;
	virtual void Ready() override {}
	virtual void Destroy() override {}
	virtual void Update() override;
	virtual void PreRender() override {}
	virtual void Render() override;
	virtual void PostRender() override {}
	virtual void ResizeScreen() override {}

private:
	void Mesh();
	void Airplane();
	

	void Pass(UINT mesh, UINT model, UINT anim);

private:
	Shader* shader;



	CubeSky* sky;


	enum class WeatherType
	{
		None = 0, Rain, Snow, Count,
	} weatherType;

	Rain* rain;
	Snow* snow;

	Material* floor;
	Material* stone;
	Material* brick;
	Material* wall;

	MeshRender* cube;
	MeshRender* cylinder;
	MeshRender* sphere;
	MeshRender* grid;

	ModelRender* airplane = NULL;



	vector<MeshRender*> meshes;
	vector<ModelRender*> models;
	vector<ModelAnimator*> animators;
};