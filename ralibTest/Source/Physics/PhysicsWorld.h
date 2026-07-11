#pragma once
#include "PhysicsBody.h"
#include <vector>

/// <summary>
/// 物理世界
/// </summary>
class PhysicsWorld
{
public:
	/// <summary>
	/// 物理特性
	/// </summary>
	struct TRAIT
	{
		Vector3 gravity; // 重力加速度[m/sec^2]

		TRAIT()
			: gravity{ 0.0f, 0.0f, 0.0f }
		{
		}
	};
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="trait"></param>
	explicit PhysicsWorld(const TRAIT& trait)
		: m_bodys()
		, m_trait(trait)
	{
	}

	/// <summary>
	/// 世界の更新
	/// </summary>
	/// <param name="dt"></param>
	void
		Update(float dt);

	/// <summary>
	/// 物体を登録をする。
	/// </summary>
	/// <param name="body"></param>
	void
		Register(PHYSICS_BODY* body)
	{
		if (body) {
			m_bodys.push_back(body);
		}
	}

	/// <summary>
	/// 登録解除する。
	/// 基本的に行わない想定のため処理が重い
	/// </summary>
	/// <param name="body"></param>
	void
		Unregister(const PHYSICS_BODY* body)
	{
		auto it = std::find(m_bodys.begin(), m_bodys.end(), body);
		if (it != m_bodys.end()) {
			std::swap(*it, m_bodys.back());
			m_bodys.resize(m_bodys.size() - 1);
		}
	}

	TRAIT&
		RefTrait()
	{
		return m_trait;
	}

	const TRAIT&
		GetTrait() const
	{
		return m_trait;
	}
private:
	std::vector<PHYSICS_BODY*> m_bodys; // 物体
	TRAIT m_trait; // 特性
};
