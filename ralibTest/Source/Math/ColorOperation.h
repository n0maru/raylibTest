#pragma once
#include <raylib.h>

/// <summary>
/// 色関連の関数・定数群
/// エイリアス：ColorOp
/// </summary>
class ColorOperation
{
public:
	/// <summary>
	/// 肌色
	/// </summary>
	static constexpr Color SkinColor{ 255, 225, 205, 255 };
};
using ColorOp = ColorOperation;