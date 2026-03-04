#pragma once

#include "Core/Common.h"

namespace Craft
{
	class CRAFT_API Vector3
	{
	public:
		// 벡터의 컴포넌트.
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
		~Vector3() = default;

		// 연산자 오버로딩.
		Vector3 operator+(const Vector3& other) const;
		Vector3 operator-(const Vector3& other) const;
		Vector3 operator*(const Vector3& other) const;
		Vector3 operator*(float scale) const;
	};
}