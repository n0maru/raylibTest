#pragma once

struct Color;
struct CAPSULE;
struct SPHERE;

/// <summary>
/// 描画関数群
/// </summary>
class Draw3D {
public:
	/// <summary>
	/// 指定したカプセルを指定の色と分割数で描画します。
	/// </summary>
	/// <param name="capsule">描画するカプセルを表す CAPSULE 構造体への const 参照。</param>
	/// <param name="splitNum">カプセルの分割数。描画の細かさ（例: 円周方向の分割数）を指定します。正の整数を想定します。</param>
	/// <param name="color">描画に使用する色を表す Color オブジェクトへの const 参照。</param>
	static void
		DrawCapsule(const CAPSULE& capsule, int splitNum, const Color& color);

	/// <summary>
	/// 指定した色で球を描画します。
	/// </summary>
	/// <param name="sphere">描画する球を表す const SPHERE&。位置や半径などの情報を含みます。</param>
	/// <param name="color">描画に使用する色を表す const Color&。</param>
	static void
		DrawSphere(const SPHERE& sphere, const Color& color);
};
