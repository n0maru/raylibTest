#pragma once
#include "Pch.h"

class Chr;

/// <summary>
/// キャラ追従カメラ。
/// </summary>
class ChrFollowCamera
{
public:
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	ChrFollowCamera()
		: m_camera{}
		, m_followee(nullptr)
	{
		Init();
	}

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// ついていく対象のキャラを設定する
	/// </summary>
	/// <param name="followee"></param>
	void
		SetFollowee(const Chr* followee)
	{
		m_followee = followee;
	}

	/// <summary>
	/// カメラ情報として取得する
	/// </summary>
	/// <returns></returns>
	Camera
		GetCamera() const
	{
		return m_camera;
	}

	/// <summary>
	/// 内部状態の更新。
	/// ここで更新を行ってから描画を行うこと
	/// </summary>
	/// <param name="dt"></param>
	void
		Update(float dt);

public:
	Camera m_camera;
	const Chr* m_followee; // ついていくキャラ
};
