#pragma once

struct Color;
struct CAPSULE;
struct SPHERE;

/// <summary>
/// 描画関数群
/// </summary>
class Draw3D {
public:
	static void
		DrawCapsule(const CAPSULE& capsule, int splitNum, const Color& color);

	static void
		DrawSphere(const SPHERE& sphere, const Color& color);
};
