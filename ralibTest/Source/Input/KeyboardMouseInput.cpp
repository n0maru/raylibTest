#include "KeyboardMouseInput.h"

void
KeyboardMouseInput::Update(float dt)
{
	m_doesMoveFront = ::IsKeyDown(KEY_W);
	m_doesMoveBack = ::IsKeyDown(KEY_S);
	m_doesMoveLeft = ::IsKeyDown(KEY_A);
	m_doesMoveRight = ::IsKeyDown(KEY_D);
	m_doesJump = ::IsKeyDown(KEY_SPACE);

	// マウス移動量
	const Vector2 mousePos = ::GetMousePosition();
	if (m_prevMousePos) {
		m_mouseDelta = mousePos - m_prevMousePos.value();
	}
	else {
		m_mouseDelta = Vec2Op::Zero();
	}
	m_prevMousePos = mousePos;
}

