#pragma once
#include "Chr.h"
#include "Drawable/PersonModel.h"

class Player : public Chr
{
public:
	Player()
		: Chr()
		, m_personModel()
	{
	}

	void
		Init();

	virtual void
		Draw() const override;

private:
	PersonModel m_personModel;
};