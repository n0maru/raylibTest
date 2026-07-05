#pragma once
#include "Pch.h"

class Chr;

class ChrFollowCamera
{
public:
	ChrFollowCamera()
		: m_camera{}
		, m_followee(nullptr)
	{
		Init();
	}

	void Init();

	void
		SetFollowee(const Chr* followee)
	{
		m_followee = followee;
	}

	Camera
		GetCamera() const
	{
		return m_camera;
	}

	void
		Update(float dt);

public:
	Camera m_camera;
	const Chr* m_followee; // ついていくキャラ
};
