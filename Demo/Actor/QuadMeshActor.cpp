#include "QuadMeshActor.h"
#include "Resource/MeshLoader.h"
#include "Shader/Shader.h"
#include "Texture/Texture.h"

using namespace Craft;

QuadMeshActor::QuadMeshActor()
{
	// 메시 로드 요청.
	MeshLoader::Get().GetMesh("Quad.obj", mesh);
	
	// 셰이더 생성.
	shader = std::make_shared<Shader>(L"Default");

	// @Test: 텍스처 로드 테스트.
	std::shared_ptr<Texture> texture
		= std::make_shared<Texture>("T_coord.png");
}