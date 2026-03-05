#include "Actor.h"
#include "Graphics/Renderer.h"

namespace Craft
{
	Actor::Actor()
	{
	}

	Actor::~Actor()
	{
	}

	void Actor::BeginPlay()
	{
		hasBeganPlay = true;
	}

	void Actor::Tick(float deltaTime)
	{
	}

	void Actor::Draw()
	{
		// @Incomplete: 예외처리.
		if (!mesh.lock())
		{
			// 일단 조용히 반환.
			// Silence is violent.
			return;
		}

		Renderer::Get().Submit(mesh.lock(), shader);
	}

	void Actor::SetOwner(std::weak_ptr<Level> newOwner)
	{
		owner = newOwner;
	}
}