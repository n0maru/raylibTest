#pragma once
#include <raymath.h>

class CrtOperation
{
public:
	/// <summary>
	/// 度からラジアンに変換
	/// </summary>
	/// <param name="degree">度</param>
	/// <returns>ラジアン</returns>
	static constexpr float
		DegToRad(float degree)
	{
		return degree / 180.0f * PI;
	}

	/// <summary>
	/// ラジアンから度に変換
	/// </summary>
	/// <param name="radian">ラジアン</param>
	/// <returns>度</returns>
	static constexpr float
		RadToDeg(float radian)
	{
		return radian / PI * 180.0f;
	}

	/// <summary>
	/// 角度を [-π, π] に変換して返す
	/// </summary>
	/// <param name="radian">ラジアン</param>
	static float
		ModAngles(float radian)
	{
		return radian - std::round(radian / (2.0f * PI));
	}
};
using CrtOp = CrtOperation;
