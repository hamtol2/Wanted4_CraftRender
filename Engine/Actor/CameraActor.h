#pragma once

#include "Actor.h"
#include "Math/Matrix4.h"

// Entity-Component System.
namespace Craft
{
	// 뷰 변환 행렬을 제공 및 처리하는 카메라 액터.
	class CRAFT_API CameraActor : public Actor
	{
	public:
		CameraActor();
		~CameraActor();

		virtual void Tick(float deltaTime) override;
		virtual void Draw() override;

	private:
		// 뷰 변환 행렬.
		// (R x T)^-1 = T^-1 x R^-1.
		Matrix4 cameraMatrix;
	};
}