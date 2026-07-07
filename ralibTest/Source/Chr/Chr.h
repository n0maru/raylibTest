#pragma once
#include "Drawable/Drawable.h"
#include "Object/Object.h"
#include "Physics/PhysicsBody.h"

/// <summary>
/// キャラクター
/// </summary>
class Chr : public Drawable
{
public:
	Vector3
		GetPos() const
	{
		return m_object.pos;
	}

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="dt"></param>
	virtual void
		Update(float dt) = 0;
protected:
	/// <summary>
	/// オブジェクト情報
	/// </summary>
	OBJECT m_object;
};
