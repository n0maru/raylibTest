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
