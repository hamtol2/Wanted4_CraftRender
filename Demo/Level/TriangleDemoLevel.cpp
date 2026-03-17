#include "TriangleDemoLevel.h"
#include "Actor/TriangleMeshActor.h"
#include "Actor/QuadMeshActor.h"
#include "Actor/CameraActor.h"
#include "Actor/CameraMovementActor.h"
#include "Math/Transform.h"

using namespace Craft;

void TriangleDemoLevel::OnInitialized()
{
	Level::OnInitialized();

	//SpawnActor<TriangleMeshActor>();
	SpawnActor<QuadMeshActor>();

	// 카메라 액터 생성.
	//std::shared_ptr<CameraActor> camera = SpawnActor<CameraActor>();
	std::shared_ptr<CameraMovementActor> camera 
		= SpawnActor<CameraMovementActor>();
	camera->transform->position.z = -2.0f;
	//camera->transform->rotation.z = 30.0f;
}