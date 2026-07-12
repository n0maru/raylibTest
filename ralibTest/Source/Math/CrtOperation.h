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
};
using CrtOp = CrtOperation;
