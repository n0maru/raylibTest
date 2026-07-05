#pragma once

/// <summary>
/// ハードウェアによらない抽象化された入力取得クラス
/// </summary>
/// <remarks>
/// ゲッターの呼び出しタイミングで結果が変わらないように、
/// Update() でシステムから情報を取得して、ゲッターから取得するのがよさそう。
/// </remarks>
class Input
{
public:
	Input()
		: m_doesMoveFront(false)
		, m_doesMoveBack(false)
		, m_doesMoveRight(false)
		, m_doesMoveLeft(false)
		, m_mouseDelta{}
	{
	}

public: // 更新
	virtual void
		Update(float dt) = 0;

public: // 取得
	virtual bool
		DoesMoveFront() const
	{
		return m_doesMoveFront;
	}

	virtual bool
		DoesMoveBack() const
	{
		return m_doesMoveBack;
	}

	virtual bool
		DoesMoveRight() const
	{
		return m_doesMoveRight;
	}

	virtual bool
		DoesMoveLeft() const
	{
		return m_doesMoveLeft;
	}

	virtual float
		GetRotateHorizontal() const
	{
		return m_mouseDelta.x;
	}

	virtual float
		GetRotateVertical() const
	{
		return m_mouseDelta.y;
	}

protected:
	bool m_doesMoveFront;
	bool m_doesMoveBack;
	bool m_doesMoveRight;
	bool m_doesMoveLeft;
	Vector2 m_mouseDelta; // 今フレームの移動量
};
