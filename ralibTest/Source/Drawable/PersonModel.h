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
	/// デフォルトコンストラクタ
	/// </summary>
	/// <remarks>
	/// 身長 1.75[m]
	/// 肌色
	/// 描画10分割
	/// </remarks>
	PersonModel()
		: PersonModel(1.75f, 10, ColorOp::SkinColor)
	{
	}

	/// <summary>
	/// PersonModelクラスのコンストラクタ。高さ、高分割数、色を受け取り対応するメンバを初期化する。
	/// </summary>
	/// <param name="height">モデルの高さ（float）。</param>
	/// <param name="drawSplitNum">描画の分割数（int）。</param>
	/// <param name="color">モデルの色（Color）。</param>
	PersonModel(float height, int drawSplitNum, Color color)
		: m_height(height)
		, m_drawSplitNum(drawSplitNum)
		, m_color(color)
		, m_object(nullptr)
	{
	}

	/// <summary>
	/// 参照するオブジェクト情報を設定する
	/// </summary>
	/// <param name="object">参照するオブジェクト情報</param>
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
	const OBJECT* m_object; // 参照するオブジェクト情報
};
