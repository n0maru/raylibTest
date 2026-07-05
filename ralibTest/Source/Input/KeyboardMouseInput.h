#pragma once
#include "Pch.h"
#include "Input.h"

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
	{
	}

public: // 更新
	void
		Update(float dt) override;
};