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
			0.0f, 0.0f, -1.0f
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
		XZ(const Vector3& src)
	{
		return Vector3{
			src.x,
			0.0f,
			src.z
		};
	}

	static Vector2
		XZToVec2(const Vector3& src)
	{
		return Vector2{
			src.x,
			src.z
		};
	}

	/// <summary>
	/// ピッチ（X軸回転量）を求める
	/// </summary>
	/// <param name="src"></param>
	/// <returns>
	/// [-π/2, π/2] で求める。
	/// ゼロベクトルの際の返り値は未定義動作。
	/// </returns>
	static float
		GetPitch(const Vector3& src)
	{
		const float xzLength = std::hypot(src.x, src.z);

		// 
		return -std::atan2(src.y, xzLength);
	}

	/// <summary>
	/// ヨー（Y軸回転量）を求める
	/// </summary>
	/// <param name="src"></param>
	/// <returns>
	/// [-π, π] で求める。
	/// ゼロベクトルの際の返り値は未定義動作。
	/// </returns>
	static float
		GetYaw(const Vector3& src)
	{
		return std::atan2(-src.x, -src.z);
	}

	static Vector2
		GetPitchYaw(const Vector3& src) {
		return Vector2{
			GetPitch(src),
			GetYaw(src)
		};
	}
};
using Vec3Op = Vector3Operation;

// Vector3 の拡張

Vector3 operator - (const Vector3& src);
