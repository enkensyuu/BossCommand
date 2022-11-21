#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete player_;
	delete boss_;
	delete turn_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();

	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

	// 自キャラの生成
	player_ = new Player();

	// 自キャラの初期化
	player_->Initialize();

	// 敵キャラの生成
	boss_ = new Boss();

	// 敵キャラの初期化
	boss_->Initialize();

	// ターンの生成
	turn_ = new Turn();

	// ターンの初期化
	turn_->Initialize();

}

void GameScene::Update() {
	if (player_->IsAttack())
	{
		player_->Update();
		boss_->Update();
		if (player_->IsAttack())
		{
			boss_->SetDamage(player_->Attack());
		}
		boss_->SetDamage2(player_->Attack());
		boss_->FinishFlag();
	}
	debugText_->SetPos(250, 250);
	debugText_->SetScale(3);
	debugText_->Printf("-%d", player_->Attack());
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
