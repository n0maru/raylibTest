#pragma once
#include "Pch.h"
#include "Input.h"
#include <optional>

/// <summary>
/// キーボード入力クラス
/// </summary>
class KeyboardMouseInput final : public Input
{
public:
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	KeyboardMouseInput()
		: Input()
		, m_prevMousePos(std::nullopt)
	{
	}

public: // 更新
	void
		Update(float dt) override;

private:
	std::optional<Vector2> m_prevMousePos; // 前フレームでのマウス位置
};