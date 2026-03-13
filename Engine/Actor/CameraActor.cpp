#include "CameraActor.h"
#include "Math/Transform.h"

namespace Craft
{
	CameraActor::CameraActor()
	{
	}

	CameraActor::~CameraActor()
	{
	}

	void CameraActor::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);

		// 위치 변환 행렬.
		Matrix4 translation = Matrix4::Translation(transform->position);

		// 회전 변환 행렬.
		Matrix4 rotation = Matrix4::Rotation(transform->rotation);

		// 카메라 행렬 업데이트.
		cameraMatrix
			= Matrix4::Inverse(translation)
			* Matrix4::Inverse(rotation);
	}

	void CameraActor::Draw()
	{
		Actor::Draw();


	}
}