#pragma once
#include <raylib.h>
#include "Pch.h"

/// <summary>
/// ゲーム内に存在する位置と向きを持ったもの。
/// </summary>
struct OBJECT
{
	Vector3 pos; // 位置
	Vector3 dir; // 向き

	/// <summary>
	/// デフォルトコンストラクタ
	/// 原点でデフォルトの正面方向を向く。
	/// </summary>
	OBJECT()
		: pos{}
		, dir{ Vec3Op::WorldFront() }
	{
	}
};
