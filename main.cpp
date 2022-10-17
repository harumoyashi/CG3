#include "WinApp.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include <chrono>

//FPS固定
int fpsDelay(std::chrono::system_clock::time_point& preTime, const long long& fps)
{
	std::chrono::system_clock::time_point nowTime = std::chrono::system_clock::now();
	std::chrono::milliseconds
		premillisec = std::chrono::duration_cast<std::chrono::milliseconds>(preTime.time_since_epoch()),
		nowmillisec = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime.time_since_epoch());
	long long lNowMilli = nowmillisec.count();
	long long nextMilli = premillisec.count() + (1000 / fps);
	long long leftDelay = nextMilli - lNowMilli;

	if (0 > leftDelay)
	{
		preTime = nowTime;
		return 0;
	}
	return 1;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// 汎用機能
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	GameScene* gameScene = nullptr;

	//fps固定用
	std::chrono::system_clock::time_point preTime;
	const long long fps = 60;	//FPS

	// ゲームウィンドウの作成
	win = WinApp::GetInstance();
	win->CreateGameWindow();

	// DirectX初期化処理
	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(win);

#pragma region 汎用機能初期化
	// 入力の初期化
	input = new Input();
	input->Initialize(win->GetHInstance(), win->GetHwnd());

	// スプライト静的初期化
	Sprite::StaticInitialize(dxCommon->GetDevice(), WinApp::kWindowWidth, WinApp::kWindowHeight);

	// 3Dオブジェクト静的初期化
	Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::kWindowWidth, WinApp::kWindowHeight);
#pragma endregion

	// ゲームシーンの初期化
	gameScene = new GameScene();
	gameScene->Initialize(dxCommon, input);

	preTime = std::chrono::system_clock::now();	//fps固定用
	bool continueFlag = true;

	// メインループ
	while (true)
	{
		// メッセージ処理
		if (win->ProcessMessage()) { continueFlag = false; }
		if (continueFlag == false) { break; }

		//fps固定用
		if (fpsDelay(preTime, fps) && continueFlag) { continue; }

		// 入力関連の毎フレーム処理
		input->Update();
		// ゲームシーンの毎フレーム処理
		gameScene->Update();

		// 描画開始
		dxCommon->PreDraw();
		// ゲームシーンの描画
		gameScene->Draw();
		// 描画終了
		dxCommon->PostDraw();
	}
	// 各種解放
	delete gameScene;
	delete input;

	// DirectX終了処理
	dxCommon->Finalize();
	// ゲームウィンドウの破棄
	win->TerminateGameWindow();

	return 0;
}