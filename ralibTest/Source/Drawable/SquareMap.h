#pragma once
#include "Drawable.h"
#include "Object/Object.h"
#include "Pch.h"

/// <summary>
/// 正方形のマップ
/// </summary>
class SquareMap : public Drawable
{
public:
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	SquareMap()
		: m_size{ 100.0f, 0.0f, 100.0f }
		, m_squareSize{ 1.0f }
		, m_object{}
	{
		m_object.pos -= m_size / 2.0f;
	}

	void Draw() const override;

private:
	Vector3 m_size; // 水平面上の全体の大きさ
	float m_squareSize; // 描画する正方形のサイズ

	/// <summary>
	/// オブジェクト情報。
	/// 位置はステージの隅。向きは使わない。
	/// </summary>
	OBJECT m_object;
};
