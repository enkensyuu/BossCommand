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
#include"Turn.h"

class Player;

class Boss
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Normal();

	void PowerUp();

	int BossHp();
	
	int BossSpeed();
	
	int Attack();
	
	int DamageUp();
	
	int Ulte();

	bool IsAttack();

	bool IsDamageUp();

	bool IsGuard();

	bool IsUlteFlag();

	int Ransuu();

	void FinishFlag();

	void SetDamage(int damage) { Hp -= damage; }

	void SetDamage2(int damage) { Hp -= damage * guard_; }

private:
	WorldTransform worldTransform_;

	Input* input_ = nullptr;

	DebugText* debugText_ = nullptr;

	Player* player_ = nullptr;

	Turn* turn_ = nullptr;

	int SelectCommand;

	int Hp;
	int Speed;
	
	int attack_;
	int damageUp_;
	int guard_;
	int ulte_;
	bool isAttack_;
	bool isBossDamageUp_;
	bool isBossGuard_;

	// �t���O
	bool isRandomFlag_ = false;
	bool isBossUlte_;
	bool isBossAvoid_;

	// �s���t�F�[�Y
	enum class Phase
	{
		Normal,		//	�ʏ�
		PowerUp,	//	����
	};

	// �t�F�[�Y
	Phase phase_ = Phase::Normal;
};

