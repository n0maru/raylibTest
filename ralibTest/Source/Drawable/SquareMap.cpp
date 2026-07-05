#include "Pch.h"
#include "SquareMap.h"
#include "Graphics/Draw3D.h"

void SquareMap::Draw() const
{
	// Z 軸に平行な線
	for (float x = m_squareSize; x < m_size.x; x += m_squareSize) {
		Vector3 startPos = m_object.pos;
		startPos.x += x;
		Vector3 endPos = startPos;
		endPos.z += m_size.z;

		Draw3D::DrawLine(LINE{ startPos, endPos }, ColorOp::Black);
	}

	// X 軸に平行な線
	for (float z = m_squareSize; z < m_size.z; z += m_squareSize) {
		Vector3 startPos = m_object.pos;
		startPos.z += z;
		Vector3 endPos = startPos;
		endPos.x += m_size.x;

		Draw3D::DrawLine(LINE{ startPos, endPos }, ColorOp::Black);
	}

	// 周りを取り囲む線
	{
		Vector3 startPos = m_object.pos;
		Vector3 endPos = startPos;
		endPos.x += m_size.x;
		Draw3D::DrawLine(LINE{ startPos, endPos }, ColorOp::Black);
	}
	{
		Vector3 startPos = m_object.pos;
		Vector3 endPos = startPos;
		endPos.z += m_size.z;
		Draw3D::DrawLine(LINE{ startPos, endPos }, ColorOp::Black);
	}
	{
		Vector3 startPos = m_object.pos;
		startPos.x += m_size.x;
		Vector3 endPos = startPos;
		Draw3D::DrawLine(LINE{ startPos, endPos }, ColorOp::Black);
	}
	{
		Vector3 startPos = m_object.pos;
		startPos.x += m_size.x;
		Vector3 endPos = startPos;
		endPos.z += m_size.z;
		Draw3D::DrawLine(LINE{ startPos, endPos }, ColorOp::Black);
	}
}
