#include "QuadMeshActor.h"
#include "Resource/MeshLoader.h"
#include "Shader/Shader.h"

using namespace Craft;

QuadMeshActor::QuadMeshActor()
{
	// 메시 로드 요청.
	MeshLoader::Get().GetMesh("Quad.obj", mesh);
	
	// 셰이더 생성.
	shader = std::make_shared<Shader>(L"Default");
}