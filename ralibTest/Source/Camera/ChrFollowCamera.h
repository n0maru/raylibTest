#pragma once
#include <raylib.h>

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
		, m_camRot(Vec2Op::Zero())

		, m_requestedRotation(Vec2Op::Zero())
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


public: // 要求
	/// <summary>
	/// カメラの回転を要求。
	/// 複数回要求されたら回転量を加算する
	/// </summary>
	/// <param name="rotation">回転量[rad]</param>
	void
		RequestRotate(Vector2 rotation);

private:
	void
		_ResetRequest();
public:
	Camera m_camera;
	const Chr* m_followee; // ついていくキャラ
	Vector2 m_camRot; // カメラ向き[rad]

	Vector2 m_requestedRotation; // 要求された回転量[rad]
};
