#pragma once
#include "Pch.h"
#include "Draw3D.h"
#include <raylib.h>

void Draw3D::DrawCapsule(const CAPSULE& capsule, int splitNum, const Color& color)
{
	::DrawCapsule(capsule.startPos, capsule.endPos, capsule.radius, splitNum/* slices */, splitNum/* rings */, color);
}

void Draw3D::DrawSphere(const SPHERE& sphere, const Color& color)
{
	::DrawSphere(sphere.centerPos, sphere.radius, color);
}
