#pragma once
#include "Player.h"

void Player::Init()
{
	m_personModel.SetObject(&m_object);
	m_object.dir = Vector3{ 1.0f, 0.0f, 0.0f };
}

void Player::Draw() const
{
	m_personModel.Draw();
}

void Player::Move(Vector3 translation)
{
	// todo: 衝突判定が必要？？？
	m_object.pos += translation;
}

void Player::Rotate(Vector3 rotation)
{
	// todo: クォータニオンでやりたい？？
	// todo: ジンバルロック
	const Matrix mtx = ::MatrixRotateXYZ(rotation);
	m_object.dir = m_object.dir * mtx;
}
