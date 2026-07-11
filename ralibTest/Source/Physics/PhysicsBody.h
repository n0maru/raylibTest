#pragma once
#include "Pch.h"

/// <summary>
/// 物体
/// </summary>
struct PHYSICS_BODY
{
	/// <summary>
	/// 物体の物理特性
	/// </summary>
	struct TRAIT
	{
		Vector3 gravityMagnification; // 重力の倍率
		BoundingBox shape; // 形（posを 0 としたときの値）
		float frictionCoeff; // 摩擦定数

		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		TRAIT()
			: gravityMagnification{ 1.0f, 1.0f, 1.0f }
			, shape{ Vector3{-0.5f, -0.5f, -0.5f}, Vector3{0.5f, 0.5f, 0.5f} }
		{
		}
	};

	Vector3 acceleration; // 加速度
	Vector3 velocity; // 速度
	Vector3 pos; // 位置
	TRAIT trait; // 特性

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	PHYSICS_BODY()
		: acceleration{ 0.0f, 0.0f, 0.0f }
		, velocity{ 0.0f, 0.0f, 0.0f }
		, pos{ 0.0f, 0.0f, 0.0f }
		, trait{}
	{
	}
};
