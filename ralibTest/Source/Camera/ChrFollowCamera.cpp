#include "Pch.h"
#include "ChrFollowCamera.h"
#include "Chr/Chr.h"
#include <algorithm>

void
ChrFollowCamera::Init()
{
	m_raylibCamera.up = Vec3Op::WorldUp(); // 上方向
	m_raylibCamera.fovy = 90.0f;// 視野角[deg]
	m_raylibCamera.projection = CAMERA_PERSPECTIVE; // 透視投影

	SetFollowee(nullptr);

	m_camRot = Vec2Op::Zero();

	_ResetRequest();
}

Vector3 ChrFollowCamera::CalcGetFrontDir() const
{
	return Vec3Op::WorldFront() * ::MatrixRotateZYX(Vector3{ m_camRot.x, m_camRot.y, 0.0f });
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

	// ::TraceLog(LOG_DEBUG, "m_camRot: (%.2f,%.2f)", m_camRot.x, m_camRot.y);

	// raylib 用カメラの更新
	_UpdateRaylibCamera();
	// 要求リセット
	_ResetRequest();
}

void ChrFollowCamera::_UpdateRaylibCamera()
{
	static constexpr float relativeDist = 2.0f; // キャラからカメラへの距離[m]
	static constexpr Vector3 chrOffset = Vector3{ 0.0f, 1.7f, 0.0f }; // キャラの位置に対する注視点のオフセット[m]

	m_raylibCamera.target = m_followee->GetPos() + chrOffset; // 注視点
	const Vector3 chrRelativePos = CalcGetFrontDir() * -relativeDist; // キャラからカメラへの相対位置
	m_raylibCamera.position = m_raylibCamera.target + chrRelativePos; // カメラ位置
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
