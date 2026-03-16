#include "CameraActor.h"
#include "Math/Transform.h"
#include "Graphics/Renderer.h"
#include "Core/Engine.h"

namespace Craft
{
	CameraActor::CameraActor(
		float fieldOfView,
		float nearDistance,
		float farDistance)
		: fieldOfView(fieldOfView),
		width(static_cast<float>(Engine::Get().GetWidth())),
		height(static_cast<float>(Engine::Get().GetHeight())),
		nearDistance(nearDistance),
		farDistance(farDistance)
	{
		// 뷰 행렬 생성.
		// 위치 변환 행렬의 역변환.
		Matrix4 translation
			= Matrix4::Translation(transform->position * -1.0f);

		// 회전 변환 행렬.
		Matrix4 rotation = Matrix4::Rotation(transform->rotation);

		// 카메라 행렬 업데이트.
		viewMatrix = translation * Matrix4::Inverse(rotation);

		// 투영 행렬 생성.
		projectionMatrix = Matrix4::Perspective(
			fieldOfView,
			width,
			height,
			nearDistance,
			farDistance
		);
	}

	CameraActor::~CameraActor()
	{
	}

	void CameraActor::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);

		// 위치 변환 행렬의 역변환.
		Matrix4 translation
			= Matrix4::Translation(transform->position * -1.0f);

		// 회전 변환 행렬.
		Matrix4 rotation = Matrix4::Rotation(transform->rotation);

		// 카메라 행렬 업데이트.
		viewMatrix = translation * Matrix4::Inverse(rotation);

		// 투영 행렬 생성.
		//perspective = Matrix4::Perspective(
		//	fieldOfView,
		//	width,
		//	height,
		//	nearDistance,
		//	farDistance
		//);
	}

	void CameraActor::Draw()
	{
		Actor::Draw();

		// 렌더러에 행렬 제출.
		Renderer::Get().UpdateCameraMatrix(viewMatrix, projectionMatrix);
	}
}