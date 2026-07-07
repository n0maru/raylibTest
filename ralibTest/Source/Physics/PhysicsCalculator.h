#pragma once
#include "PhysicsWorld.h"

struct PHYSICS_BODY;

/// <summary>
/// 物理計算機。
/// 物理関連の前計算が必要ならこのクラスで行うようにする
/// </summary>
class PhysicsCalculator
{
public:
	/// <summary>
	/// 指定された物理ボディを与えられた特性に基づいて移動または更新します。
	/// </summary>
	/// <param name="body">移動または更新対象の PHYSICS_BODY への参照。</param>
	/// <param name="worldTrait">移動の方法や設定を表す PhysicsWorld::TRAIT 型の定数参照。</param>
	/// <param name="dt">経過時間</param>
	static void
		Move(PHYSICS_BODY& body, const PhysicsWorld::TRAIT& worldTrait, float dt);
};
using PhysicsCalc = PhysicsCalculator;
