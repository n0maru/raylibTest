#include <raylib.h>
#include "Chr/Player.h"

int main(void)
{
	// ウィンドウ初期化
	{
		const int screenWidth = 800;
		const int screenHeight = 450;
		InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
		SetTargetFPS(60);
	}

	// カメラの設定
	Camera camera = { 0 };
	{
		camera.position = Vector3{ 0.0f, 5.0f, 5.0f };
		camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
		camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
		camera.fovy = 45.0f;
		camera.projection = CAMERA_PERSPECTIVE;
	}

	// プレイヤーの設定
	Player player;
	{
		player.Init();
	}

	while (!WindowShouldClose())
	{
		// 入力
		{

		}

		// 更新
		{

		}

		// 描画
		{
			BeginDrawing();
			ClearBackground(RAYWHITE);
			BeginMode3D(camera);

			player.Draw();

			EndMode3D();
			EndDrawing();
		}
	}

	CloseWindow();

	return 0;
}
