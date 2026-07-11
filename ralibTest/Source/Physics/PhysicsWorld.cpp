#include "PhysicsWorld.h"
#include "PhysicsCalculator.h"

void
PhysicsWorld::Update(float dt)
{
	for (PHYSICS_BODY* body : m_bodys) {
		if (body) {
			PhysicsCalc::Move(*body, m_trait, dt);
		}
	}
}
