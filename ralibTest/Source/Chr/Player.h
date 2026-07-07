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
	/// 更新
	/// </summary>
	/// <param name="dt"></param>
	/// <remarks>
	/// 事前に物理世界の更新が終わっている必要がある（＝m_physBody が更新済みであること）
	/// </remarks>
	virtual void
		Update(float dt) override;

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
	/// 移動
	/// </summary>
	/// <param name="translation">速度[m/sec]</param>
	void MoveRequest(Vector3 speed);

	/// <summary>
	/// 回転
	/// </summary>
	/// <param name="rotation">回転量</param>
	// todo: 回転量の単位が [rad/frame] になっているのを [rad/sec] にする
	void Rotate(Vector3 rotation);

private:
	/// <summary>
	/// 人間型モデル
	/// </summary>
	PersonModel m_personModel;

	/// <summary>
	/// 物理ボディ
	/// </summary>
	PHYSICS_BODY m_physBody;
};