#pragma once
#include "Pch.h"
#include "PersonModel.h"
#include "Graphics/Draw3D.h"

void PersonModel::Draw() const
{
	static constexpr float headRate = 1.0f / 7.0f;

	// ヌルチェック
	if (!m_object) {
		ERROR_LOG("a PersonModel must refer object before call Draw()");
		return;
	}

	const float headRadius = m_height * headRate / 2.0f; // 頭の半径

	// モデル空間 -> ワールド空間 変換行列
	// VEC3_LOG(m_object->dir);
	const float yaw = Vec3Op::GetYaw(m_object->dir);
	// DEBUG_LOG("yaw: %.3f(%.3f)", yaw, CrtOp::RadToDeg(yaw));
	const Quaternion rotation = ::QuaternionFromEuler(0.0f, yaw, 0.0f); // 向きの平面成分だけを使う
	const Matrix modelToWorldMtx = ::MatrixCompose(m_object->pos, rotation, Vector3{ 1.0f, 1.0f, 1.0f });

	// 頭
	{
		const Vector3 headCenter{
			0.0f,
			m_height - headRadius,
			0.0f,
		};
		const SPHERE head{ headCenter * modelToWorldMtx, headRadius };
		Draw3D::DrawSphere(head, m_color); // 描画
	}

	// 胴体
	{
		const float torsoRadius = headRadius * 0.9f; // 胴体の半径
		const Vector3 startPos{
			0.0f,
			torsoRadius,
			0.0f,
		};
		const Vector3 endPos{
			0.0f,
			m_height - headRadius * 2.0f - torsoRadius,
			0.0f,
		};
		const CAPSULE torso{ startPos * modelToWorldMtx, endPos * modelToWorldMtx, torsoRadius };
		Draw3D::DrawCapsule(torso, m_drawSplitNum, m_color); // 描画
	}

	// 鼻
	{
		const float noseRadius = headRadius * 0.5f; // 鼻の半径
		const Vector3 startPos{
			0.0f,
			m_height - headRadius, // 頭の中心から生えている
			0.0f,
		};
		const Vector3 endPos = startPos + Vec3Op::WorldFront() * headRadius * 2.0f;
		const CAPSULE nose{ startPos * modelToWorldMtx, endPos * modelToWorldMtx, noseRadius };
		Draw3D::DrawCapsule(nose, m_drawSplitNum, ColorOp::Red);// 描画
	}

}
