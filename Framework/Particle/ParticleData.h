#pragma once
#include"Framework.h"
struct ParticleData
{
	enum class BlendType
	{
		Opaque = 0, Additive, AlphaBlend
	} Type = BlendType::Opaque;


	wstring TextureFile = L"";

	UINT MaxParticles = 100;

	float ReadyTime = 1.0f;
	float ReadyRandomTime = 0; //������ ���� ����

	float StartVelocity = 1; 
	float EndVelocity = 1;

	float MinHorizontalVelocity = 0; //���� ���ప
	float MaxHorizontalVelocity = 0;

	float MinVerticalVelocity = 0; //���� ���ప (Z)
	float MaxVerticalVelocity = 0;

	Vector3 Gravity = Vector3(0, 0, 0);

	Color MinColor = Color(1, 1, 1, 1);
	Color MaxColor = Color(1, 1, 1, 1);

	float MinRotateSpeed = 0;
	float MaxRotateSpeed = 0;

	float MinStartSize = 100;
	float MaxStartSize = 100;

	float MinEndSize = 100;
	float MaxEndSize = 100;
};