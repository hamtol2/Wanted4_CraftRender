#include "Vector3.h"

namespace Craft
{
	Vector3 Vector3::Zero(0.0f, 0.0f, 0.0f);
	Vector3 Vector3::One(1.0f, 1.0f, 1.0f);
	Vector3 Vector3::Right(1.0f, 0.0f, 0.0f);
	Vector3 Vector3::Up(0.0f, 1.0f, 0.0f);
	Vector3 Vector3::Forward(0.0f, 0.0f, 1.0f);

	Vector3::Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}

	Vector3 Vector3::operator+(const Vector3& other) const
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}
	
	Vector3 Vector3::operator-(const Vector3& other) const
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}
	
	Vector3 Vector3::operator*(const Vector3& other) const
	{
		return Vector3(x * other.x, y * other.y, z * other.z);
	}
	
	Vector3 Vector3::operator*(float scale) const
	{
		return Vector3(x * scale, y * scale, z * scale);
	}

	float Dot(const Vector3& left, const Vector3& right)
	{
		return left.x * right.x 
			+ left.y * right.y 
			+ left.z * right.z;
	}
	
	Vector3 Cross(const Vector3& left, const Vector3& right)
	{
		// 3중적. (두 벡터와 직교하는 다른 벡터를 구하는 벡터의 곱셈).
		// !! 곱셈의 순서가 중요. 교환법칙 성립 안함.
		// A X B = A x B x Sin(Theta).
		return Vector3(
			(left.y * right.z) - (left.z * right.y),
			(left.z * right.x) - (left.x * right.z),
			(left.x * right.y) - (left.y * right.x)
		);
	}
}