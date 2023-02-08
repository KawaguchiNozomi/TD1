#include <Novice.h>
#include "Scenes.h"
#include "GetInfo.h"

const char kWindowTitle[] = "GC1A_09_カワグチノゾミ_BlackNoon";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, GetInfo::GetWindowWidth(), GetInfo::GetWindowHeight());

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int clearFlag[6]; //使ってない
	Scenes* scene = new Scenes;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		scene->Update(keys, preKeys);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		scene->Draw(keys);
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
