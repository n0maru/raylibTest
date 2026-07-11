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
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Input()
		: m_doesMoveFront(false)
		, m_doesMoveBack(false)
		, m_doesMoveRight(false)
		, m_doesMoveLeft(false)
		, m_mouseDelta{}
	{
	}

public: // 更新

	/// <summary>
	/// 入力情報をシステムから取得する
	/// </summary>
	/// <param name="dt">前フレームからの経過時間</param>
	virtual void
		Update(float dt) = 0;

public: // 取得

	/// <summary>
	/// 前移動しているか
	/// </summary>
	virtual bool
		DoesMoveFront() const
	{
		return m_doesMoveFront;
	}

	/// <summary>
	/// 後ろ移動しているか
	/// </summary>
	/// <returns></returns>
	virtual bool
		DoesMoveBack() const
	{
		return m_doesMoveBack;
	}

	/// <summary>
	/// 右移動しているか
	/// </summary>
	/// <returns></returns>
	virtual bool
		DoesMoveRight() const
	{
		return m_doesMoveRight;
	}

	/// <summary>
	/// 左に移動しているか
	/// </summary>
	/// <returns></returns>
	virtual bool
		DoesMoveLeft() const
	{
		return m_doesMoveLeft;
	}

	/// <summary>
	/// 水平方向回転
	/// </summary>
	/// <returns>右向きがプラス、左向きがマイナス</returns>
	virtual float
		GetRotateHorizontal() const
	{
		return m_mouseDelta.x;
	}

	/// <summary>
	/// 垂直方向回転
	/// </summary>
	/// <returns>下方向がプラス、上方向がマイナス</returns>
	virtual float
		GetRotateVertical() const
	{
		return m_mouseDelta.y;
	}

	/// <summary>
	/// ジャンプしたか
	/// </summary>
	/// <returns></returns>
	virtual bool
		DoesJump() const
	{
		return m_doesJump;
	}
protected:
	bool m_doesMoveFront; // 前移動入力
	bool m_doesMoveBack; // 後ろ移動入力
	bool m_doesMoveRight; // 右方向入力
	bool m_doesMoveLeft; // 左方向入力
	bool m_doesJump; // ジャンプしたか
	Vector2 m_mouseDelta; // 今フレームの移動量
};
