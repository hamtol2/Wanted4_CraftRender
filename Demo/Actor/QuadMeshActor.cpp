#include "QuadMeshActor.h"
#include "Resource/MeshLoader.h"

#include "Shader/Shader.h"
#include "Shader/TextureMappingShader.h"

#include "Texture/Texture.h"
#include "Resource/TextureLoader.h"

using namespace Craft;

QuadMeshActor::QuadMeshActor()
{
	// 메시 로드 요청.
	MeshLoader::Get().GetMesh("Quad.obj", mesh);

	// 셰이더 생성.
	//shader = std::make_shared<Shader>(L"Default");
	shader = std::make_shared<TextureMappingShader>("T_coord.png");

	// @Test: 텍스처 로드 테스트.
	//std::shared_ptr<Texture> texture = std::make_shared<Texture>("T_coord.png");

	//std::weak_ptr<Texture> texture;
	//TextureLoader::Get().Load("T_coord.png", texture);
}