#include "Framework.h"
#include "Billboard.h"

Billboard::Billboard(Shader* shader)
	: Renderer(shader)
{
	Topology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST); //점을 면으로 처리하므로 1대1처리

	sDiffuseMap = shader->AsSRV("DiffuseMap");
}

Billboard::~Billboard()
{
	SafeDelete(texture);
}

void Billboard::Update()
{
	Super::Update();
}

void Billboard::Render()
{
	if (vertexCount!= vertices.size())
	{
		vertexCount = vertices.size();

		SafeDelete(vertexBuffer);
		vertexBuffer = new VertexBuffer(&vertices[0], vertices.size(), sizeof(VertexBillboard));

	}

	Super::Render();


	sDiffuseMap->SetResource(texture->SRV());
	shader->DrawIndexed(0, Pass(), vertexCount);
}

void Billboard::Add(Vector3& position, Vector2& scale)
{ 
	VertexBillboard vertex =
	{
		position,scale
	};

	vertices.push_back(vertex);
}
