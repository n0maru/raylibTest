#include "ChrFollowCamera.h"
#include "Chr/Chr.h"

void
ChrFollowCamera::Init()
{
	m_camera.up = Vec3Op::WorldUp(); // 上方向
	m_camera.fovy = 90.0f;// 視野角[deg]
	m_camera.projection = CAMERA_PERSPECTIVE; // 透視投影
}

void
ChrFollowCamera::Update(float dt)
{
	if (!m_followee) {
		::TraceLog(LOG_ERROR, "[ChrFollowCamera] Set Followee before call Update()");
		return;
	}

	const Vector3 followeePos = m_followee->GetPos();
	m_camera.position = followeePos + Vector3{ 1.0f, 3.0f, 1.0f };
	m_camera.target = followeePos;
}
