#pragma once
#include "Pch.h"
#include "Drawable.h"

struct OBJECT;

/// <summary>
/// 描画可能な人のモデル
/// </summary>
class PersonModel : public Drawable
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	PersonModel()
		: PersonModel(1.75f, 10, ColorOp::SkinColor)
	{
	}

	PersonModel(float height, int drawSplitNum, Color color)
		: m_height(height)
		, m_drawSplitNum(drawSplitNum)
		, m_color(color)
	{
	}

	void
		SetObject(const OBJECT* object)
	{
		m_object = object;
	}

	/// <summary>
	/// 人間モデルを描画する
	/// </summary>
	virtual void
		Draw() const override;

private:
	float m_height; // 身長[m]
	int m_drawSplitNum; // 描画の分割数
	Color m_color; // 色
	const OBJECT* m_object;
};
