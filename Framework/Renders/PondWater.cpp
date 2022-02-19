#include "Framework.h"
#include"PondWater.h"

PondWater::PondWater()
{
	Initialize();
}

PondWater::PondWater(Shader* shader)
{
	Initialize();

	SetShader(shader);
}
void PondWater::Initialize()
{
	name = L"";

	diffuseMap = NULL;
	specularMap = NULL;
	normalMap1 = NULL;
	normalMap2 = NULL;


	buffer = new ConstantBuffer(&colorDesc, sizeof(ColorDesc));
}


PondWater::~PondWater()
{
	SafeDelete(diffuseMap);
	SafeDelete(specularMap);

	SafeDelete(normalMap2);
	SafeDelete(normalMap1);
	SafeDelete(waveMap);

	SafeDelete(buffer);
}

void PondWater::SetShader(Shader* shader)
{
	//this->shader = new Shader(L"114_PondWater.fxo"); //물 표현 전용 쉐이더
	this->shader = shader;

	sBuffer = shader->AsConstantBuffer("CB_Material");

	sDiffuseMap = shader->AsSRV("DiffuseMap");
	sSpecularMap = shader->AsSRV("SpecularMap");
	sNormalMap = shader->AsSRV("NormalMap");
}
void PondWater::CopyFrom(PondWater* material)
{
	name = material->name;
	colorDesc = material->colorDesc;

	if (material->shader != NULL)
		SetShader(material->shader);

	if (material->diffuseMap != NULL)
		diffuseMap = new Texture(material->diffuseMap->GetFile());

	if (material->specularMap != NULL)
		specularMap = new Texture(material->specularMap->GetFile());

	if (material->waveMap != NULL)
		waveMap = new Texture(material->waveMap->GetFile());
}

void PondWater::Ambient(Color& color)
{
	colorDesc.Ambient = color;
}

void PondWater::Ambient(float r, float g, float b, float a)
{
	Ambient(Color(r, g, b, a));
}

void PondWater::Diffuse(Color& color)
{
	colorDesc.Diffuse = color;
}

void PondWater::Diffuse(float r, float g, float b, float a)
{
	Diffuse(Color(r, g, b, a));
}

void PondWater::Specular(Color& color)
{
	colorDesc.Specular = color;
}

void PondWater::Specular(float r, float g, float b, float a)
{
	Specular(Color(r, g, b, a));
}

void PondWater::Emissive(Color& color)
{
	colorDesc.Emissive = color;
}

void PondWater::Emissive(float r, float g, float b, float a)
{
	Emissive(Color(r, g, b, a));
}

void PondWater::DiffuseMap(string file)
{
	DiffuseMap(String::ToWString(file));
}

void PondWater::DiffuseMap(wstring file)
{
	SafeDelete(diffuseMap);

	diffuseMap = new Texture(file);
}

void PondWater::SpecularMap(string file)
{
	SpecularMap(String::ToWString(file));
}

void PondWater::SpecularMap(wstring file)
{
	SafeDelete(specularMap);

	specularMap = new Texture(file);
}

void PondWater::NormalMap(string waveFile1, string waveFile2)
{
	NormalMap(String::ToWString(waveFile1), String::ToWString(waveFile2));
}

void PondWater::NormalMap(wstring waveFile1, wstring waveFile2)
{
	SafeDelete(normalMap1);
	SafeDelete(normalMap2);

	normalMap1 = new Texture(waveFile1);
	normalMap2 = new Texture(waveFile2);
	waveMap = normalMap1;

}

void PondWater::Update()
{
	waveTimer+=Time::Get()->Delta();
	waveTimer>1.0f? waveMap = normalMap1: waveMap = normalMap2;
	
	if (waveTimer > 2.0f) waveTimer = 0.0f;
}

void PondWater::Render()
{
	buffer->Render();
	sBuffer->SetConstantBuffer(buffer->Buffer());


	if (diffuseMap != NULL)
		sDiffuseMap->SetResource(diffuseMap->SRV());
	else
		sDiffuseMap->SetResource(NULL);

	if (specularMap != NULL)
		sSpecularMap->SetResource(specularMap->SRV());
	else
		sSpecularMap->SetResource(NULL);

	if (waveMap != NULL)
		sNormalMap->SetResource(waveMap->SRV());
	
	else
		sNormalMap->SetResource(NULL);
}




