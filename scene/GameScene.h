#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "DebugText.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"Boss.h"
#include"Player.h"
#include"Stage.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugText* debugText_ = nullptr;
	ViewProjection viewProjection_;
	Boss* boss_ = nullptr;
	Player* player_ = nullptr;

	Model* Monster = nullptr;

	Stage* stage_ = nullptr;
	Model* stagemodel_ = nullptr;

	Sprite* CommandSelect = nullptr;
	Sprite* SelectWaku = nullptr;
	Sprite* Titl = nullptr;
	Sprite* GameCler = nullptr;
	Sprite* GameOver = nullptr;

	uint32_t textureHandle1_ = 0;
	uint32_t textureHandle2_ = 0;
	uint32_t textureHandle3_ = 0;
	uint32_t textureHandle4_ = 0;
	uint32_t textureHandle5_ = 0;

	int	scene = 1;
	int	damage1 = 75;
	int	damage2 = 50;
	int	damage3time = 150;
	int	kaihukutime = 150;
	int	kaihitime = 150;
	int	kaizyutime = 150;
	int	oowazatime = 150;
	int	bosstime = 150;
	int playerHP = 300;
	int BOSSAttack = 100;
	int BOSSAttack1 = 150;
	int BOSSAttack2 = 50;
	int BOSSAttack3 = 75;
	int BOSSAttack4 = 25;
	int poison = 25;
	int BOSSHP1 = 500;
	int BOSSHP2 = 750;
	int BOSSHP3 = 500;
	int BOSSHP4 = 500;
	int BOSSHP5 = 750;
	int playerAttack = 0;
	int	turn = 1;
	int	nexttime = 150;
	int	ransuu = 0;
	int timer = 120;

	Vector2 position;

	//フラグ-------------------------------------------
	int	keyflag = 1;
	int	leftflag = 0;
	int	cleftflag = 1;
	int	rightflag = 0;
	int	crightflag = 0;
	int	upflag = 1;
	int	downflag = 0;
	int	Bossdeth1flag = 0;
	int	Bossdeth2flag = 0;
	int	Bossdeth3flag = 0;
	int	Bossdeth4flag = 0;
	int	Bossdeth5flag = 0;
	int attackflag = 0;//攻撃
	int kaihiFlag = 0;//回避
	int bosskaihiFlag = 0;
	int	bossguardflag = 0;
	int kaifukuFlag = 0;//回復
	int kaizyuFlag = 0;//デバフ解呪
	int oowazaFlag = 0;//大技
	int BOSSFlag1 = 1;
	int BOSSFlag2 = 1;
	int BOSSFlag3 = 1;
	int BOSSFlag4 = 1;
	int BOSSFlag5 = 1;
	int playerflag = 1;
	int BOSSmove1 = 0;
	int BOSSmove2 = 0;
	int BOSSmove3 = 0;
	int BOSSmove4 = 0;
	int BOSSmove5 = 0;
	int BOSSAttackFlag = 0;
	int BOSSAttackKinds = 0;
	int	playerattackflag = 0;
	int	playerkaihukuflag = 0;
	int	playerkaihiflag = 0;
	int	playerkaizyuflag = 0;
	int	playeroowazaflag = 0;
	int	poisonflag = 0;
	int	turnend = 0;
	int	kaihukucooltime = 6;
	int	kaihukucooltimeflag = 1;
	int	kaihicooltime = 4;
	int	kaihicooltimeflag = 1;
	int	oowazacooltime = 0;
	int	oowazacooltimeflag = 0;
	int	charge = 0;
	int	chargeflag = 0;
	int	starttime = 100;
	int	battleflag = 0;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
