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

		// 내적(Dot Product/Inner Product).
		// A Dot B = A(크기) x B(크기) x Cos(Theta).
		friend CRAFT_API float Dot(
			const Vector3& left, 
			const Vector3& right
		);

		// 외적(Cross Product/Outer Product).
		friend CRAFT_API Vector3 Cross(
			const Vector3& left, 
			const Vector3& right
		);

		// 전역 변수.
		static Vector3 Zero;
		static Vector3 One;
		static Vector3 Right;
		static Vector3 Up;
		static Vector3 Forward;
	};
}