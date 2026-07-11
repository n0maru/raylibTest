#pragma once
#include <raymath.h>
#include <cmath>
#include <cassert>

class Vector2Operation
{
public:
	static Vector2
		Zero()
	{
		return Vector2{
			0.0f,
			0.0f
		};
	}

	static float
		LengthSq(const Vector2& src)
	{
		return src.x * src.x + src.y * src.y;
	}

	static float
		Length(const Vector2& src)
	{
		return std::hypot(src.x, src.y);
	}

	static Vector2
		OrthographicProjection(const Vector2& from, const Vector2& to)
	{
		return to * Dot(from, to) / LengthSq(to);
	}

	static Vector2
		OrthographicProjectionToNormal(const Vector2& from, const Vector2& toNormal)
	{
		return toNormal * Dot(from, toNormal);
	}

	static float
		Dot(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	static Vector3
		XZToVec3(const Vector2& src)
	{
		return Vector3{
			src.x,
			0.0f,
			src.y
		};
	}
};
using Vec2Op = Vector2Operation;