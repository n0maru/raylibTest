#pragma once
#include <raymath.h>
#include <cmath>

/// <summary>
/// 3次元ベクトルの関数・定数群
/// エイリアス：Vec3Op
/// </summary>
class Vector3Operation
{
public:
	/// <summary>
	/// デフォルトの正面ベクトル
	/// </summary>
	static Vector3
		WorldFront()
	{
		return Vector3{
			0.0f, 0.0f, 1.0f
		};
	}

	static Vector3
		WorldUp()
	{
		return Vector3{
			0.0f, 1.0f, 0.0f
		};
	}

	static Vector3
		WorldRight()
	{
		return Vector3{
			1.0f, 0.0f, 0.0f
		};
	}

	static Vector3
		Zero()
	{
		return Vector3{
			0.0f, 0.0f, 0.0f
		};
	}

	static float
		LengthSq(const Vector3& src)
	{
		return src.x * src.x + src.y * src.y + src.z * src.z;
	}

	static float
		Length(const Vector3& src)
	{
		return std::hypot(src.x, src.y, src.z);
	}

	static Vector3
		Normalize(const Vector3& src)
	{
		const float length = Length(src);
		if (length > 0.0f)
		{
			return src / length;
		}
		else
		{
			return src;
		}
	}

	static Vector3
		XZ(const Vector3& src)
	{
		return Vector3{
			src.x,
			0.0f,
			src.z
		};
	}
};
using Vec3Op = Vector3Operation;

// Vector3 の拡張

Vector3 operator - (const Vector3& src);
