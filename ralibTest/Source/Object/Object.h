#pragma once
#include <raylib.h>
#include "Pch.h"

/// <summary>
/// ゲーム内に存在する位置と向きを持ったもの。
/// </summary>
struct OBJECT
{
	Vector3 pos;
	Vector3 dir;


	OBJECT()
		: pos{}
		, dir{ Vec3Op::Front() }
	{
	}
};
