#pragma once
#include "Pch.h"
#include "Player.h"

void Player::Init()
{
	// 物理特性の設定
	m_physBody.trait.gravityMagnification = Vector3{ 1.0f, 1.0f, 1.0f };
	m_physBody.trait.shape = BoundingBox{ Vector3{-1.0f, 0.0f, -1.0f}, Vector3{1.0f, 1.75f, 1.0f} };
	m_physBody.trait.frictionCoeff = 0.6f; // 適切な値か分からない（今は使われていない）

	// 物理状態のリセット
	m_physBody.acceleration = Vector3{ 0.0f, 0.0f, 0.0f };
	m_physBody.velocity = Vector3{ 0.0f, 0.0f, 0.0f };
	m_physBody.pos = Vector3{ 0.0f, 0.0f, 0.0f };

	m_personModel.SetObject(&m_object); // m_object をモデルの描画位置として参照する
	m_object.pos = m_physBody.pos;
	m_object.dir = Vec3Op::WorldFront();

	// 移動速度
	m_moveVelocityXZ = Vec2Op::Zero();

	_ResetRequest();
}

void Player::Draw() const
{
	m_personModel.Draw();
}

void Player::UpdatePrePysics(float dt)
{
	// ジャンプ要求を処理
	if (m_isRequestedJump) {
		if (m_physBody.pos.y <= 0.0f) {
			// 着地中なら
			m_physBody.velocity.y += 5.0f;
		}
	}

	// 平面移動処理
	{
		static constexpr float maxSpeed = 30.0f * 1000.0f / 60.0f / 24.0f; // 30[km/h]
		static constexpr float acceleration = maxSpeed / 0.5f; // 10[sec] で最高速度になるくらいの加速度

		Vector2 targetVelocity = Vec2Op::Zero(); // 目標速度
		const float length = Vec2Op::Length(m_requestMoveDirXZ);
		if (length > 0.0f) {
			m_requestMoveDirXZ /= length; // 要求方向を正規化
			targetVelocity = m_requestMoveDirXZ * maxSpeed; // 目標速度＝最高速度で要求方向に進む速度ベクトル
		}
		else {
			// 要求方向がゼロベクトル（＝停止）の場合
			// 目標速度はゼロベクトルなので上書き不要
		}

		// 移動速度が目標速度に近づくように加速度を加える
		const Vector2 diffVec = targetVelocity - m_moveVelocityXZ;
		const float diffLength = Vec2Op::Length(diffVec);
		const Vector2 accelerationVec = diffVec * std::fmin(1.0f, acceleration / diffLength);
		m_physBody.acceleration += Vec2Op::XZToVec3(accelerationVec);

		m_moveVelocityXZ += accelerationVec * dt; // Player 側で管理している移動速度にも加速度を反映する
	}
}

void Player::UpdatePostPhysics(float dt)
{
	// 物理世界上の位置をキャラの位置として反映する
	m_object.pos = m_physBody.pos;


	// 描画用の向きを更新
	{
		// キャラの向きを体が移動中の方向に向ける
		Vector3 dir = m_physBody.velocity;
		if (dir == Vec3Op::Zero()) {
			dir = m_object.dir; // ゼロベクトルなら前回の向きを利用する
		}

		SetDirection(dir);
	}

	// 要求関連をリセット
	_ResetRequest();
}

void Player::RequestMoveXZ(Vector2 direction)
{
	m_requestMoveDirXZ = direction;
}

void Player::RequstJump()
{
	m_isRequestedJump = true;
}

void Player::_ResetRequest()
{
	m_requestMoveDirXZ = Vec2Op::Zero();
	m_isRequestedJump = false;
}
