#include <raylib.h>
#include "Chr/Player.h"
#include "Input/KeyboardMouseInput.h"
#include "Drawable/SquareMap.h"
#include "Camera/ChrFollowCamera.h"
#include "Physics/PhysicsWorld.h"

int main(void)
{
	// ウィンドウ初期化
	{
		const int screenWidth = 800;
		const int screenHeight = 450;
		InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
		SetTargetFPS(60);
	}

	// ワールド
	PhysicsWorld::TRAIT worldTrait;
	worldTrait.gravity = Vector3{ 0.0f, -9.8f, 0.0f }; // 重力
	PhysicsWorld world(worldTrait);

	// プレイヤーの設定
	Player player;
	world.Register(&player.GetPhysicsBody()); // 物理世界に登録

	// カメラの設定
	ChrFollowCamera camera;
	camera.SetFollowee(&player);

	// マップの設定
	SquareMap map;

	// 入力
	Input* input = new KeyboardMouseInput();

	while (!WindowShouldClose())
	{
		const float dt = ::GetFrameTime();

		// 入力
		{
			// 入力を取得
			input->Update(dt);

			// 入力の処理
			{
				// todo: 斜めに動くと√2倍速く動く
				static constexpr float speed = 1.5f;
				Vector3 translation{
					speed * (static_cast<float>(input->DoesMoveFront()) - static_cast<float>(input->DoesMoveBack())),
					0.0f,
					speed * (static_cast<float>(input->DoesMoveRight()) - static_cast<float>(input->DoesMoveLeft())),
				};
				player.MoveRequest(translation);

				// 着地中のみジャンプ可能
				if (player.GetPhysicsBody().pos.y <= 0.0f && input->DoesJump()) {
					player.MoveRequest(Vector3{ 0.0f, 200.0f, 0.0f });
				}

				// todo: 値の範囲が分からない
				const float yaw = input->GetRotateHorizontal() / 50.0f * PI;
				player.Rotate(Vector3{ 0.0f, yaw, 0.0f });
			}
		}


		// 更新
		{
			// 物理ワールド更新
			world.Update(dt);

			// プレイヤーの位置を更新
			player.Update(dt);

			// カメラの更新
			camera.Update(dt);
		}

		// 描画
		{
			BeginDrawing();
			ClearBackground(RAYWHITE);
			BeginMode3D(camera.GetCamera());

			player.Draw();
			map.Draw();

			EndMode3D();
			EndDrawing();
		}
	}

	CloseWindow();

	return 0;
}
