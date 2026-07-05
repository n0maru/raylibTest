#pragma once
#include "Chr.h"
#include "Drawable/PersonModel.h"

/// <summary>
/// プレイヤー
/// </summary>
class Player : public Chr
{
public:
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Player()
		: Chr()
		, m_personModel()
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

public:
	/// <summary>
	/// 移動
	/// </summary>
	/// <param name="translation">移動量</param>
	void Move(Vector3 translation);

	/// <summary>
	/// 回転
	/// </summary>
	/// <param name="rotation">回転量</param>
	void Rotate(Vector3 rotation);

private:
	/// <summary>
	/// 人間型モデル
	/// </summary>
	PersonModel m_personModel;
};