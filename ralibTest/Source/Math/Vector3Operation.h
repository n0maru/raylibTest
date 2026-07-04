#pragma once
#include "Pch.h"

class Vector3Operation
{
public:
	/// <summary>
	/// デフォルトの正面ベクトル
	/// </summary>
	static Vector3
		Front()
	{
		return Vector3{
			0.0f, 0.0f, 1.0f
		};
	}
};
using Vec3Op = Vector3Operation;
