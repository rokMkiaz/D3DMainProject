#include "stdafx.h"
#include "Main.h"
#include "Systems/Window.h"

#include"PostEffects/ColorToneDemo.h"
#include"Lighting/NormalMappingDemo.h"
#include"Lighting/SpotLightingDemo.h"
#include"Lighting/PointLightingDemo.h"
#include"Lighting/LightingDemo.h"
#include"Objects/BillboardDemo.h"
#include"Terrain/WeatherDemo.h"
/*
#include"DirectCompute/GetMultiBoneDemo.h"
#include"DirectCompute/GetAnimationBoneDemo.h"
#include"Instancing/InstancingFrameworkDemo.h"
#include"Instancing/InstancingDemo.h"
#include"World/GridDemo.h"
#include"World/WorldDemo3.h"
#include"World/RotationDemo.h"
#include"Vertex/UserInterfaceDemo.h"
#include"Vertex/RectDemo.h"
#include"Vertex/Vertex_Line.h"
#include"Vertex/Vertex_Line2.h"
#include"Vertex/TriangleList.h"
#include"Mesh/CubeDemo.h"
#include"Mesh/MeshDemo.h"
#include"Texture/TextureDemo.h"
#include"Texture/TextureLoadDemo.h"
#include"Texture/TextureSamplerDemo.h"
#include"Terrain/HeightMapDemo.h"
#include"Terrain/NormalVectorDemo.h"
#include"Terrain/GetHeightDemo.h"
#include"Terrain/GetVerticalRaycast.h"
#include"Objects/CubeSkyDemo.h"
#include"DirectCompute/ThreadDemo.h"
#include"DirectCompute/RawBufferDemo.h"
#include"DirectCompute/TextureBufferDemo.h"
#include"Projection/ViewportDemo.h"
#include"Projection/ProjectionDemo.h"
#include"Terrain/GetRaycastDemo.h"
#include"Objects/ObbRaycastDemo.h"
#include"Objects/ObbCollisionDemo.h"
*/

void Main::Initialize()
{
	Push(new ColorToneDemo);
	//Push(new WeatherDemo);
	//Push(new BillboardDemo);
	//Push(new NormalMappingDemo);
	//Push(new SpotLightingDemo);
	//Push(new PointLightingDemo);
	//Push(new LightingDemo);
	/*
	Push(new GetMultiBoneDemo);
	Push(new ObbCollisionDemo);
	Push(new ObbRaycastDemo);
	Push(new GetRaycastDemo);
	Push(new ProjectionDemo);
	Push(new ViewportDemo);
	Push(new GetAnimationBoneDemo);
	Push(new InstancingFrameworkDemo);
	Push(new TextureBufferDemo);
	Push(new RawBufferDemo);
	Push(new ThreadDemo);
	Push(new InstancingDemo);
	Push(new CubeSkyDemo);
	Push(new MeshDemo);
	Push(new GetVerticalRaycast);
	Push(new GetHeightDemo);
	Push(new NormalVectorDemo);
	Push(new HeightMapDemo);
	Push(new TextureSamplerDemo);
	Push(new TextureLoadDemo);
	Push(new TextureDemo);
	Push(new RotationDemo);
	Push(new  GridDemo);
	Push(new CubeDemo);
	Push(new UserInterfaceDemo);
	Push(new RectDemo());
	Push(new TriangleList());
	*/
}

void Main::Ready()
{

}

void Main::Destroy()
{
	for (IExecute* exe : executes)
	{
		exe->Destroy();
		SafeDelete(exe);
	}
}

void Main::Update()
{
	for (IExecute* exe : executes)
		exe->Update();
}

void Main::PreRender()
{
	for (IExecute* exe : executes)
		exe->PreRender();
}

void Main::Render()
{
	for (IExecute* exe : executes)
		exe->Render();
}

void Main::PostRender()
{
	for (IExecute* exe : executes)
		exe->PostRender();
}

void Main::ResizeScreen()
{
	for (IExecute* exe : executes)
		exe->ResizeScreen();
}

void Main::Push(IExecute * execute)
{
	executes.push_back(execute);

	execute->Initialize();
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR param, int command)
{
	D3DDesc desc;
	desc.AppName = L"D3D Game";
	desc.Instance = instance;
	desc.bFullScreen = false;
	desc.bVsync = false;
	desc.Handle = NULL;
	desc.Width = 1280;
	desc.Height = 720;
	desc.Background = Color(0.3f, 0.3f, 0.3f, 1.0f);
	D3D::SetDesc(desc);

	Main* main = new Main();
	WPARAM wParam = Window::Run(main);

	SafeDelete(main);

	return wParam;
}