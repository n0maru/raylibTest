#pragma once
#include "Chr.h"
#include "Drawable/PersonModel.h"

/// <summary>
/// プレイヤー
/// </summary>
class Player : public Chr
{
public:
	Player()
		: Chr()
		, m_personModel()
	{
		Init();
	}

	void
		Init();

	virtual void
		Draw() const override;

public:
	void Move(Vector3 translation);

	void Rotate(Vector3 rotation);

private:
	PersonModel m_personModel;
};