#pragma once
#include "Drawable/Drawable.h"
#include "Object/Object.h"

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

protected:
	/// <summary>
	/// オブジェクト情報
	/// </summary>
	OBJECT m_object;
};
