#include "PhysicsCalculator.h"
#include "PhysicsBody.h"
#include <algorithm>

void PhysicsCalculator::Move(PHYSICS_BODY& body, const PhysicsWorld::TRAIT& worldTrait, float dt)
{

	// 加速度の合計
	Vector3 sumAcceleration = Vec3Op::Zero();
	sumAcceleration += worldTrait.gravity * body.trait.gravityMagnification; // 重力
	sumAcceleration += body.acceleration;

	// 加速度を元に速度を更新
	body.velocity += sumAcceleration;

	// 速度を元に位置を更新
	const Vector3 prevPos = body.pos;
	body.pos += body.velocity * dt; // dt[sec] 分だけ移動する

	// 地面にめり込まないようにする
	const float minY = body.trait.shape.min.y + body.pos.y; // 体の内最も低い位置
	const float diffY = std::max(-minY, 0.0f); // 物体が地面にめり込まないために必要な上昇量
	body.pos.y += diffY;

	// 移動量を元に速度を更新
	body.velocity = (dt == 0.0f ? Vector3{ 0.0f, 0.0f, 0.0f } : (body.pos - prevPos) / dt);

	// 加速度をリセット
	body.acceleration = Vector3{ 0.0f, 0.0f, 0.0f };
}

float PhysicsCalculator::_CalcGetFrictionAcceleration(const PHYSICS_BODY& body, const PhysicsWorld::TRAIT& worldTrait)
{
	//【前提】
	// - 地面は重力に対して垂直な面であること
	// 
	// 【導出】
	// 摩擦力 F = ma を移項して
	// a = F / m ...(1)
	// より、オブジェクトの加速度として反映させる。
	// 
	// 摩擦力 F を
	// F = μN （μ:摩擦係数, N:垂直抗力）...(2)
	// としてモデリングする。（クーロン摩擦力と呼ばれるモデル）
	// 
	// 地面は重力に対して垂直な面であることを前提にしているため、垂直抗力 N は
	// N = mg （g:重力加速度）...(3)
	// として表せる。
	// 
	// (1),(2),(3) より摩擦加速度 a を
	// a = (μmg) / m
	// a = μg
	// で表す。
	return std::abs(worldTrait.gravity.y * body.trait.frictionCoeff);
}
