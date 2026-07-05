#include "KeyboardMouseInput.h"

void
KeyboardMouseInput::Update(float dt)
{
	m_doesMoveFront = ::IsKeyDown(KEY_W);
	m_doesMoveBack = ::IsKeyDown(KEY_S);
	m_doesMoveLeft = ::IsKeyDown(KEY_A);
	m_doesMoveRight = ::IsKeyDown(KEY_D);
	m_mouseDelta = ::GetMouseDelta();
}

