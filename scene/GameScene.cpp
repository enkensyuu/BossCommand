#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete stagemodel_;
	delete CommandSelect;
	delete SelectWaku;
	delete Titl;
	delete GameCler;
	delete GameOver;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();

	textureHandle1_ = TextureManager::Load("command.png");
	textureHandle2_ = TextureManager::Load("select.png");
	textureHandle3_ = TextureManager::Load("game_start.png");
	textureHandle4_ = TextureManager::Load("game_over.png");
	textureHandle5_ = TextureManager::Load("game_clear.png");

	CommandSelect = Sprite::Create(textureHandle1_, { 0,950 });
	Titl = Sprite::Create(textureHandle3_, { 0,0 });
	GameCler = Sprite::Create(textureHandle5_, { 0,0 });
	GameOver = Sprite::Create(textureHandle4_, { 0,0 });

	stagemodel_ = Model::CreateFromOBJ("Stage", true);

	stage_ = new Stage();
	stage_->Initilize(stagemodel_);

	// 自キャラの生成
	player_ = new Player();

	// 自キャラの初期化
	player_->Initialize();

	// 敵キャラの生成
	boss_ = new Boss();

	// 敵キャラの初期化
	boss_->Initialize();

	playerHP = 500;
	Bossdeth1flag = 0;
	Bossdeth2flag = 0;
	Bossdeth3flag = 0;
	Bossdeth4flag = 0;
	Bossdeth5flag = 0;
	BOSSHP1 = 500;
	BOSSHP2 = 750;
	BOSSHP3 = 500;
	BOSSHP4 = 500;
	BOSSHP5 = 1000;

	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

}

void GameScene::Update() {
	switch (scene)
	{
	case 1:
		timer--;
		Initialize();
		if (input_->TriggerKey(DIK_SPACE) && timer < 0)
		{
			timer = 120;
			scene = 2;
		}
		break;
	case 2:
		if (BOSSHP5 < 0)
		{
			scene = 3;
		}
		if (playerHP < 0)
		{
			scene = 4;
		}
		stage_->Update();

		if (input_->TriggerKey(DIK_A) && attackflag == 0 && BOSSFlag1 == 1 && keyflag == 1)
		{
			attackflag = 1;
			kaifukuFlag = 0;
			kaihiFlag = 0;
			kaizyuFlag = 0;
			oowazaFlag = 0;
		}
		if (attackflag == 1 && input_->TriggerKey(DIK_SPACE))
		{
			playerattackflag = 1;
			keyflag = 0;
		}
		if (playerattackflag == 1)
		{
			if (bossguardflag == 0 && bosskaihiFlag == 0)
			{
				debugText_->SetPos(590, 0);
				debugText_->SetScale(5);
				debugText_->Printf("-100");
			}
			if (bossguardflag == 1 && bosskaihiFlag == 0)
			{
				debugText_->SetPos(590, 0);
				debugText_->SetScale(5);
				debugText_->Printf("-75");
			}
			damage3time--;
			ransuu = 1;
		}
		if (damage3time <= 0)
		{
			if (bossguardflag == 0 && bosskaihiFlag == 0)
			{
				BOSSHP5 -= 100;
			}
			if (bossguardflag == 1 && bosskaihiFlag == 0)
			{
				BOSSHP5 -= 75;
			}
			attackflag = 0;
			damage3time = 150;
			playerattackflag = 0;
			bossguardflag = 0;
			BOSSmove5 = 1;
			bosskaihiFlag = 0;
			bossguardflag = 0;
		}
		//回復
		if (kaihukucooltime >= 6)
		{
			kaihukucooltimeflag = 1;
		}
		if (kaihukucooltimeflag == 1)
		{
			if (input_->TriggerKey(DIK_S) && kaifukuFlag == 0 && playerflag == 1 && keyflag == 1)
			{
				attackflag = 0;
				kaifukuFlag = 1;
				kaihiFlag = 0;
				kaizyuFlag = 0;
				oowazaFlag = 0;
			}
			if (kaifukuFlag == 1 && input_->TriggerKey(DIK_SPACE))
			{
				playerkaihukuflag = 1;
				keyflag = 0;
			}
			if (playerkaihukuflag == 1)
			{
				debugText_->SetPos(590, 850);
				debugText_->SetScale(5);
				debugText_->Printf("+200");
				kaihukutime--;
				ransuu = 1;
			}
			if (kaihukutime <= 0)
			{
				playerHP += 200;
				kaifukuFlag = 0;
				if (playerHP >= 500)
				{
					playerHP = 500;
				}
				kaihukutime = 150;
				playerkaihukuflag = 0;
				kaihukucooltime = 0;
				kaihukucooltimeflag = 0;
				bossguardflag = 0;
				BOSSmove5 = 1;
				bosskaihiFlag = 0;
				bossguardflag = 0;
			}
		}
		//回避
		if (kaihicooltime >= 4)
		{
			kaihicooltimeflag = 1;
		}
		if (kaihicooltimeflag == 1)
		{
			if (input_->TriggerKey(DIK_D) && kaihiFlag == 0 && playerflag == 1 && keyflag == 1)
			{
				attackflag = 0;
				kaifukuFlag = 0;
				kaihiFlag = 1;
				kaizyuFlag = 0;
				oowazaFlag = 0;
			}
			if (kaihiFlag == 1 && input_->TriggerKey(DIK_SPACE))
			{
				keyflag = 0;
				playerkaihiflag = 1;
			}
			if (playerkaihiflag == 1)
			{
				kaihitime--;
				ransuu = 1;
			}
			if (kaihitime <= 0)
			{
				BOSSAttack = 0;
				kaihitime = 150;
				playerkaihiflag = 0;
				kaihicooltime = 0;
				kaihicooltimeflag = 0;
				bossguardflag = 0;
				BOSSmove5 = 1;
				bosskaihiFlag = 0;
				bossguardflag = 0;
			}
		}
		//デバフ解呪
		if (input_->TriggerKey(DIK_F) && kaizyuFlag == 0 && playerflag == 1 && keyflag == 1)
		{
			attackflag = 0;
			kaifukuFlag = 0;
			kaihiFlag = 0;
			kaizyuFlag = 1;
			oowazaFlag = 0;
		}
		if (kaizyuFlag == 1 && input_->TriggerKey(DIK_SPACE))
		{
			playerkaizyuflag = 1;
			keyflag = 0;
		}
		if (playerkaizyuflag == 1)
		{
			debugText_->SetPos(590, 0);
			debugText_->SetScale(5);
			debugText_->Printf("-150");
			kaizyutime--;
			ransuu = 1;
		}
		if (kaizyutime <= 0)
		{
			BOSSHP5 -= 150;
			poisonflag = 0;
			kaizyuFlag = 0;
			playerkaizyuflag = 0;
			kaizyutime = 150;
			bossguardflag = 0;
			BOSSmove5 = 1;
			bosskaihiFlag = 0;
			bossguardflag = 0;
		}

		if (oowazacooltime >= 3)
		{
			oowazacooltimeflag = 1;
		}
		if (oowazacooltimeflag == 1)
		{
			if (input_->TriggerKey(DIK_G) && oowazaFlag == 0 && keyflag == 1)
			{
				attackflag = 0;
				kaifukuFlag = 0;
				kaihiFlag = 0;
				kaizyuFlag = 0;
				oowazaFlag = 1;
			}
			if (oowazaFlag == 1 && input_->TriggerKey(DIK_SPACE))
			{
				playeroowazaflag = 1;
			}
			if (playeroowazaflag == 1)
			{
				debugText_->SetPos(590, 0);
				debugText_->SetScale(5);
				debugText_->Printf("-250");
				oowazatime--;
				keyflag = 0;
			}
			if (oowazatime <= 0)
			{
				BOSSHP5 -= 250;
				oowazacooltime = 0;
				oowazacooltimeflag = 0;
				turnend = 1;
				kaihukucooltime += 1;
				kaihicooltime += 1;
				oowazacooltime += 1;
				oowazatime = 150;
				oowazaFlag = 0;
				playeroowazaflag = 0;
			}
		}

		if (BOSSmove5 == 1)
		{
			bosstime--;
			BOSSAttackFlag = 1;
		}
		if (BOSSAttackFlag == 1)
		{
			if (ransuu == 1)
			{
				srand(time(nullptr));
				BOSSAttackKinds = rand() % 3 + 1;
			}
			if (BOSSAttackKinds == 1)//攻撃
			{
				ransuu = 0;
				if (kaihiFlag == 1)
				{
					debugText_->SetPos(590, 850);
					debugText_->SetScale(5);
					debugText_->Printf("-75");
				}
				if (bosstime <= 0 && kaihiFlag == 1)
				{

					playerHP -= 75;
					turnend = 1;
					bosstime = 150;
					BOSSAttackFlag = 0;
					BOSSmove5 = 0;
					kaihukucooltime += 1;
					kaihicooltime += 1;
					oowazacooltime += 1;
				}
				if (kaihiFlag == 0)
				{
					if (charge == 0)
					{
						debugText_->SetPos(590, 850);
						debugText_->SetScale(5);
						debugText_->Printf("-120");
					}
					if (charge == 1)
					{
						debugText_->SetPos(590, 850);
						debugText_->SetScale(5);
						debugText_->Printf("-150");
					}
					if (bosstime <= 0)
					{
						if (charge == 0)
						{
							playerHP -= 120;
						}
						if (charge == 1)
						{
							playerHP -= 150;
							charge = 0;
						}
						turnend = 1;
						bosstime = 150;
						BOSSAttackFlag = 0;
						BOSSmove5 = 0;
						kaihukucooltime += 1;
						kaihicooltime += 1;
						oowazacooltime += 1;
					}
				}
			}
			if (BOSSAttackKinds == 2)//ためる
			{
				ransuu = 0;
				if (bosstime <= 0)
				{
					charge = 1;
					BOSSAttackFlag = 0;
					BOSSmove5 = 0;
					bosstime = 150;
					turnend = 1;
					kaihukucooltime += 1;
					kaihicooltime += 1;
					oowazacooltime += 1;
				}
			}
			if (BOSSAttackKinds == 3)//ガード
			{
				ransuu = 0;
				if (bosstime <= 0)
				{
					BOSSAttackFlag = 0;
					BOSSmove5 = 0;
					bosstime = 150;
					turnend = 1;
					bossguardflag = 1;
					kaihukucooltime += 1;
					kaihicooltime += 1;
					oowazacooltime += 1;
				}
			}
		}
		if (turnend == 1)
		{
			turn += 1;
			if (poisonflag == 1)
			{
				playerHP -= poison;
			}
			turnend = 0;
			keyflag = 1;
			kaihiFlag = 0;
			playerkaihiflag = 0;
		}

		debugText_->SetPos(50, 0);
		debugText_->SetScale(5);
		debugText_->Printf("Boss:%d", BOSSHP5);

		debugText_->SetPos(1500, 0);
		debugText_->SetScale(5);
		debugText_->Printf("Turn:%d", turn);

		debugText_->SetPos(50, 850);
		debugText_->Printf("Player:%d", playerHP);

		break;

	case 3:
		timer--;
		if (input_->TriggerKey(DIK_SPACE) && timer < 0)
		{
			scene = 1;
		}
		break;

	case 4:
		timer--;
		if (input_->TriggerKey(DIK_SPACE) && timer < 0)
		{
			scene = 1;
		}
		break;
	}
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
	stage_->Draw(viewProjection_);
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	switch (scene)
	{
	case 1:
		Titl->Draw();
		break;
	case 2:
		CommandSelect->Draw();

		if (attackflag == 1)
		{
			SelectWaku = Sprite::Create(textureHandle2_, { 15,950 });
			SelectWaku->Draw();
		}
		if (kaifukuFlag == 1)
		{
			SelectWaku = Sprite::Create(textureHandle2_, { 394,950 });
			SelectWaku->Draw();
		}
		if (kaihiFlag == 1)
		{
			SelectWaku = Sprite::Create(textureHandle2_, { 773,950 });
			SelectWaku->Draw();
		}
		if (kaizyuFlag == 1)
		{
			SelectWaku = Sprite::Create(textureHandle2_, { 1142,950 });
			SelectWaku->Draw();
		}
		if (oowazaFlag == 1)
		{
			SelectWaku = Sprite::Create(textureHandle2_, { 1521,950 });
			SelectWaku->Draw();
		}
		break;
	case 3:
		GameCler->Draw();
		break;
	case 4:
		GameOver->Draw();
		break;
	}
	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
