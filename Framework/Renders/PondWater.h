#pragma once
#include"Material.h"

class PondWater :public Material
{
public:
	PondWater(Shader* shader);
	~PondWater();

	void SetShader(Shader* shader);

	void NormalMap(string waveFile1,string waveFile2);
	void NormalMap(wstring waveFile1,wstring waveFile2);


private:
	void Initialize();

private:
	struct ColorDesc
	{
		Color Ambient = Color(0, 0, 0, 1);
		Color Diffuse = Color(1, 1, 1, 1);
		Color Specular = Color(0, 0, 0, 1);
		Color Emissive = Color(0, 0, 0, 1);
	} colorDesc;

private:
	Shader* shader = NULL;
	
	wstring name;

	Texture* diffuseMap;
	Texture* specularMap;
	Texture* wave1NormalMap;
	Texture* wave2NormalMap;

	ConstantBuffer* buffer;
	ID3DX11EffectConstantBuffer* sBuffer;

	ID3DX11EffectShaderResourceVariable* sDiffuseMap;
	ID3DX11EffectShaderResourceVariable* sSpecularMap;
	ID3DX11EffectShaderResourceVariable* sWaveNormalMap1;
	ID3DX11EffectShaderResourceVariable* sWaveNormalMap2;

};