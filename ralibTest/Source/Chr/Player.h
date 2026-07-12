#pragma once
#include "Chr.h"
#include "Drawable/PersonModel.h"

/// <summary>
/// プレイヤー
/// </summary>
/// <remarks>
/// プレイヤーの位置は m_object.pos と m_physBody.pos で二重管理になっている。
/// m_object.pos は描画位置としてもつかわれる。
/// </remarks>
class Player : public Chr
{
public:
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Player()
		: Chr()
		, m_personModel()
		, m_physBody()
		, m_moveVelocityXZ(0.0f)
		, m_requestMoveDirXZ(Vec2Op::Zero())
		, m_isRequestedJump(false)
	{
		Init();
	}

	/// <summary>
	/// 初期化
	/// </summary>
	void
		Init();

	/// <summary>
	/// 描画
	/// </summary>
	virtual void
		Draw() const override;

	/// <summary>
	/// 物理世界更新前の更新処理
	/// </summary>
	/// <param name="dt"></param>
	void
		UpdatePrePysics(float dt);

	/// <summary>
	/// 物理世界更新後の更新
	/// </summary>
	/// <param name="dt"></param>
	/// <remarks>
	/// 事前に物理世界の更新が終わっている必要がある（＝m_physBody が更新済みであること）
	/// </remarks>
	virtual void
		UpdatePostPhysics(float dt);

	PHYSICS_BODY&
		GetPhysicsBody()
	{
		return m_physBody;
	}

	const PHYSICS_BODY&
		GetPhysicsBody() const
	{
		return m_physBody;
	}
public:
	/// <summary>
	/// 水平移動要求。
	/// 複数回要求された場合、上書きされる。
	/// </summary>
	/// <param name="direction">方向</param>
	void RequestMoveXZ(Vector2 direction);

	/// <summary>
	/// ジャンプ要求
	/// </summary>
	void RequstJump();
private:
	/// <summary>
	/// 要求をリセットする。
	/// </summary>
	void
		_ResetRequest();
private:
	/// <summary>
	/// 人間型モデル
	/// </summary>
	PersonModel m_personModel;

	/// <summary>
	/// 物理ボディ
	/// </summary>
	PHYSICS_BODY m_physBody;

	/// <summary>
	/// 移動速度[m/sec]
	/// </summary>
	Vector2 m_moveVelocityXZ;

	/// <summary>
	/// 要求移動方向
	/// </summary>
	Vector2 m_requestMoveDirXZ;

	/// <summary>
	/// ジャンプが要求されたか
	/// </summary>
	bool m_isRequestedJump;
};