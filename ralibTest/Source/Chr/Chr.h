#pragma once
#include "Drawable/Drawable.h"
#include "Object/Object.h"

/// <summary>
/// キャラクター
/// </summary>
class Chr : public Drawable
{
protected:
	/// <summary>
	/// オブジェクト情報
	/// </summary>
	OBJECT m_object;
};
