#include "stdafx.h"
#include "PondWaterDemo.h"

void PondWaterDemo::Initialize()
{
	Context::Get()->GetCamera()->RotationDegree(20, 0, 0);
	Context::Get()->GetCamera()->Position(1, 36, -85);
	((Freedom*)Context::Get()->GetCamera())->Speed(50, 2);


	shader = new Shader(L"113_Shadow.fxo");

	UINT size = 1024;// * 8; * 16; ÇØ»óµµ
	shadow = new Shadow(shader, Vector3(0, 0, 0), 65, size, size);

	render2D = new Render2D();
	//render2D->GetTransform()->Position(D3D::Width() * 0.5f, D3D::Height() * 0.5f, 0);
	//render2D->GetTransform()->Scale(D3D::Width(), D3D::Height(), 1);
	render2D->GetTransform()->Position(150, D3D::Height() - 150, 0);
	render2D->GetTransform()->Scale(300, 300, 1);
	render2D->SRV(shadow->SRV());



	sky = new CubeSky(L"Environment/GrassCube1024.dds");

	Mesh();
	Airplane();


}

void PondWaterDemo::Update()
{
	sky->Update();

	cube->Update();
	grid->Update();
	water->Update();

	waterGrid->Update();

	cylinder->Update();
	sphere->Update();

	airplane->Update();
	


	render2D->Update();
}

void PondWaterDemo::PreRender()
{
	shadow->PreRender();

	Pass(0, 1, 2);

	wall->Render();
	sphere->Render();

	brick->Render();
	cylinder->Render();

	stone->Render();
	cube->Render();

	floor->Render();
	grid->Render();

	water->Render();
	waterGrid->Render();

	airplane->Render();

}

void PondWaterDemo::Render()
{
	sky->Pass(0); //ÇÏ´ÃÀº ±íÀÌx
	sky->Render();

	Pass(3, 4, 5);

	wall->Render();
	sphere->Render();

	brick->Render();
	cylinder->Render();

	stone->Render();
	cube->Render();

	floor->Render();
	grid->Render();

	water->Render();
	waterGrid->Render();


	airplane->Render();

}

void PondWaterDemo::PostRender()
{
	render2D->Render();
}

void PondWaterDemo::Mesh()
{
	//Create Material
	{
		floor = new Material(shader);
		floor->DiffuseMap("Floor.png");
		floor->Specular(1, 1, 1, 20);
		floor->SpecularMap("Floor_Specular.png");
		floor->NormalMap("Floor_Normal.png");

		water = new PondWater(shader);
		water ->DiffuseMap("White.png");
		water ->Specular(1, 1, 1, 20);
		//water ->SpecularMap("Waterwave0.dds");
		water ->NormalMap("Waterwave0.dds","Waterwave1.dds");
		//water->NormalMap("Waterwave0.dds");

		stone = new Material(shader);
		stone->DiffuseMap("Stones.png");
		stone->Specular(1, 1, 1, 20);
		stone->SpecularMap("Stones_Specular.png");
		stone->Emissive(0.15f, 0.15f, 0.15f, 0.3f);
		stone->NormalMap("Stones_Normal.png");


		brick = new Material(shader);
		brick->DiffuseMap("Bricks.png");
		brick->Specular(1, 0.3f, 0.3f, 20);
		brick->SpecularMap("Bricks_Specular.png");
		brick->Emissive(0.15f, 0.15f, 0.15f, 0.3f);
		brick->NormalMap("Bricks_Normal.png");

		wall = new Material(shader);
		wall->DiffuseMap("Wall.png");
		wall->Specular(1, 1, 1, 20);
		wall->SpecularMap("Wall_Specular.png");
		wall->Emissive(0.15f, 0.15f, 0.15f, 0.3f);
		wall->NormalMap("Wall_Normal.png");
	}

	//Create Mesh
	{
		Transform* transform = NULL;

		cube = new MeshRender(shader, new MeshCube());
		transform = cube->AddTransform();
		transform->Position(0, 5, 0);
		transform->Scale(20, 10, 20);

		grid = new MeshRender(shader, new MeshGrid(5, 5));
		transform = grid->AddTransform();
		transform->Position(0, 0, 0);
		transform->Scale(12, 1, 12);

		waterGrid = new MeshRender(shader, new MeshGrid(5, 5));
		transform = waterGrid->AddTransform();
		transform->Position(0, 2, 0);
		transform->Scale(12, 1, 12);

		cylinder = new MeshRender(shader, new MeshCylinder(0.5f, 3.0f, 20, 20));
		sphere = new MeshRender(shader, new MeshSphere(0.5f, 20, 20));
		for (UINT i = 0; i < 5; i++)
		{
			transform = cylinder->AddTransform();
			transform->Position(-30, 6, -15.0f + (float)i * 15.0f);
			transform->Scale(5, 5, 5);

			transform = cylinder->AddTransform();
			transform->Position(30, 6, -15.0f + (float)i * 15.0f);
			transform->Scale(5, 5, 5);


			transform = sphere->AddTransform();
			transform->Position(-30, 15.5f, -15.0f + (float)i * 15.0f);
			transform->Scale(5, 5, 5);

			transform = sphere->AddTransform();
			transform->Position(30, 15.5f, -15.0f + (float)i * 15.0f);
			transform->Scale(5, 5, 5);
		}
	}

	sphere->UpdateTransforms();
	cylinder->UpdateTransforms();
	cube->UpdateTransforms();
	waterGrid->UpdateTransforms();
	grid->UpdateTransforms();

	meshes.push_back(sphere);;
	meshes.push_back(cylinder);
	meshes.push_back(cube);
	meshes.push_back(grid);
	meshes.push_back(waterGrid);
}

void PondWaterDemo::Airplane()
{
	airplane = new ModelRender(shader);
	airplane->ReadMesh(L"B787/Airplane");
	airplane->ReadMaterial(L"B787/Airplane");

	Transform* transform = airplane->AddTransform();
	transform->Position(2.0f, 9.91f, 2.0f);
	transform->Scale(0.004f, 0.004f, 0.004f);
	airplane->UpdateTransforms();

}



void PondWaterDemo::Pass(UINT mesh, UINT model, UINT anim)
{
	for (MeshRender* temp : meshes)
		temp->Pass(mesh);

}