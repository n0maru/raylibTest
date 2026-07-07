#include "PhysicsCalculator.h"
#include "PhysicsBody.h"
#include <algorithm>

void PhysicsCalculator::Move(PHYSICS_BODY& body, const PhysicsWorld::TRAIT& worldTrait, float dt)
{
	// 加速度を元に速度を更新
	body.velocity += worldTrait.gravity * body.trait.gravityMagnification; // 重力
	body.velocity += body.acceleration;

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
