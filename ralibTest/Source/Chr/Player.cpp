#pragma once
#include "Player.h"

void Player::Init()
{
	// 物理特性の設定
	m_physBody.trait.gravityMagnification = Vector3{ 1.0f, 1.0f, 1.0f };
	m_physBody.trait.shape = BoundingBox{ Vector3{-1.0f, 0.0f, -1.0f}, Vector3{1.0f, 1.75f, 1.0f} };

	// 物理状態のリセット
	m_physBody.acceleration = Vector3{ 0.0f, 0.0f, 0.0f };
	m_physBody.velocity = Vector3{ 0.0f, 0.0f, 0.0f };
	m_physBody.pos = Vector3{ 0.0f, 0.0f, 0.0f };

	m_personModel.SetObject(&m_object);
	m_object.pos = m_physBody.pos;

	// 向きの設定
	m_object.dir = Vector3{ 1.0f, 0.0f, 0.0f };
}

void Player::Draw() const
{
	m_personModel.Draw();
}

void Player::Update(float dt)
{
	// 物理世界上の位置をキャラの位置として反映する
	m_object.pos = m_physBody.pos;
}

void Player::MoveRequest(Vector3 translation)
{
	m_physBody.velocity += translation;
}

void Player::Rotate(Vector3 rotation)
{
	// todo: クォータニオンでやりたい？？
	// todo: ジンバルロック
	const Matrix mtx = ::MatrixRotateXYZ(rotation);
	m_object.dir = m_object.dir * mtx;
}
