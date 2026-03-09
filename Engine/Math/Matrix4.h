#pragma once

#include "Core/Common.h"
#include "Vector3.h"

namespace Craft
{
	// 4x4 행렬.
	// 행기준 행렬(Row-Major 행렬).
	// CPU가 좋아함/GPU가 싫어함.
	// SIMD(Single Instruction Multi ...). MMX/SSE...
	class CRAFT_API Matrix4
	{
	public:
		Matrix4();
		Matrix4(const Matrix4& other);
		~Matrix4() = default;

		// 스케일 변환 행렬.
		// 트랜스폼(Transform->Transformation->변신/변환).
		static Matrix4 Scale(float x, float y, float z);
		static Matrix4 Scale(const Vector3& scale);
		static Matrix4 Scale(float scale);

		// 연산자 오버로딩.
		Matrix4& operator=(const Matrix4& other);
		Matrix4 operator*(const Matrix4& other) const;
		Matrix4& operator*=(const Matrix4& other);

		// 벡터와의 연산 오버로딩.
		friend CRAFT_API Vector3 operator*(const Matrix4& m, const Vector3& v);
		friend CRAFT_API Vector3 operator*(const Vector3& v, const Matrix4& m);

		// 전역 변수.
		// 단위 행렬.
		static Matrix4 Identity;

		// 호도법(라디안) <-> 각도법 변환 공식.
		static constexpr float degreeToRadian = 3.141592f / 180.0f;
		static constexpr float radianToDegree = 180.0f / 3.141592f;

	private:
		// 공용체.
		// 메모리 공간 공유. 
		// 여러 변수 중에 가장 공간이 큰 메모리를 할당 후 공유.
		union
		{
			struct
			{
				float m00, m01, m02, m03;
				float m10, m11, m12, m13;
				float m20, m21, m22, m23;
				float m30, m31, m32, m33;
			};

			// 배열.
			float elements[4 * 4] = {};
		};
	};
}
