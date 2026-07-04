#pragma once

/// <summary>
/// 描画物。
/// 3Dモデルの描画や形状の描画を抽象化する。
/// </summary>
class Drawable
{
public:
	/// <summary>
	/// 描画する
	/// </summary>
	virtual void
		Draw() const = 0;
};
