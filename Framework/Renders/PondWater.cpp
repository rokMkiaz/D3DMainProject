#include "Framework.h"
#include"PondWater.h"

PondWater::PondWater(Shader* shader)
{
	Initialize();
	SetShader(shader);
}

PondWater::~PondWater()
{
	SafeDelete(diffuseMap);
	SafeDelete(specularMap);
	SafeDelete(wave1NormalMap);
	SafeDelete(wave2NormalMap);

	SafeDelete(buffer);
}

void PondWater::SetShader(Shader* shader)
{
	this->shader = shader;

	sBuffer = shader->AsConstantBuffer("CB_Material");

	sDiffuseMap = shader->AsSRV("DiffuseMap");
	sSpecularMap = shader->AsSRV("SpecularMap");
	sWaveNormalMap1 = shader->AsSRV("WaveNormalMap1");
	sWaveNormalMap2 = shader->AsSRV("WaveNormalMap2");
}

void PondWater::NormalMap(string waveFile1, string waveFile2)
{
	NormalMap(String::ToWString(waveFile1), String::ToWString(waveFile2));
}

void PondWater::NormalMap(wstring waveFile1, wstring waveFile2)
{
	SafeDelete(wave1NormalMap);
	SafeDelete(wave2NormalMap);

	wave1NormalMap = new Texture(waveFile1);
	wave2NormalMap = new Texture(waveFile2);

}

void PondWater::Initialize()
{
	name = L"";

	diffuseMap = NULL;
	specularMap = NULL;
	wave1NormalMap = NULL;
	wave2NormalMap = NULL;


	buffer = new ConstantBuffer(&colorDesc, sizeof(ColorDesc));
}



