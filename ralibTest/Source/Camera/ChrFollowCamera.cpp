#include "Pch.h"
#include "ChrFollowCamera.h"
#include "Chr/Chr.h"
#include <algorithm>

void
ChrFollowCamera::Init()
{
	m_camera.up = Vec3Op::WorldUp(); // 上方向
	m_camera.fovy = 90.0f;// 視野角[deg]
	m_camera.projection = CAMERA_PERSPECTIVE; // 透視投影

	_ResetRequest();
}

void
ChrFollowCamera::Update(float dt)
{
	if (!m_followee) {
		::TraceLog(LOG_ERROR, "[ChrFollowCamera] Set Followee before call Update()");
		return;
	}
	m_camRot = Vec2Op::ModAngles(m_camRot + m_requestedRotation);

	// ピッチ角度制限
	static constexpr float maxPitch = CrtOp::DegToRad(70.0f);
	m_camRot.x = std::clamp(m_camRot.x, -maxPitch, maxPitch);

	const Vector3 chrRelativePos = Vec3Op::WorldFront() * 2.0f * ::MatrixRotateXYZ(Vector3{ m_camRot.x, m_camRot.y, 0.0f }); // 相対位置

	const Vector3 followeePos = m_followee->GetPos();
	m_camera.target = followeePos + Vector3{ 0.0f, 1.7f, 0.0f }; // 注視点
	m_camera.position = m_camera.target + chrRelativePos; // カメラ位置

	_ResetRequest();
}

void ChrFollowCamera::RequestRotate(Vector2 rotation)
{
	m_requestedRotation += rotation;
}

void
ChrFollowCamera::_ResetRequest()
{
	m_requestedRotation = Vec2Op::Zero();
}
