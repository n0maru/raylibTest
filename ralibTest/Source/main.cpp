#include <raylib.h>
#include "Chr/Player.h"
#include "Input/KeyboardMouseInput.h"
#include "Drawable/SquareMap.h"

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

	// マップの設定
	SquareMap map;

	// 入力
	Input* input = new KeyboardMouseInput();

	while (!WindowShouldClose())
	{
		const float dt = ::GetFrameTime();

		// 入力
		{
			input->Update(dt);
		}

		// 更新
		{
			// todo: 斜めに動くと√2倍速く動く
			static constexpr float speed = 0.2f;
			Vector3 translation{
				speed * (static_cast<float>(input->DoesMoveFront()) - static_cast<float>(input->DoesMoveBack())),
				0.0f,
				speed * (static_cast<float>(input->DoesMoveRight()) - static_cast<float>(input->DoesMoveLeft())),
			};
			player.Move(translation);

			// todo: 値の範囲が分からない
			const float yaw = input->GetRotateHorizontal() / 50.0f * PI;
			player.Rotate(Vector3{ 0.0f, yaw, 0.0f });
		}

		// 描画
		{
			BeginDrawing();
			ClearBackground(RAYWHITE);
			BeginMode3D(camera);

			player.Draw();
			map.Draw();

			EndMode3D();
			EndDrawing();
		}
	}

	CloseWindow();

	return 0;
}
