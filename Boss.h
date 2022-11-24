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

class Boss
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Command();

	void Normal();

	void PowerUp();

	int BossHp();
	
	int BossSpeed();
	
	int Attack();
	
	int Ulte();

	bool IsAttack();

	bool IsDamageUp();

	bool IsGuard();

	bool IsUlteFlag();

	void FinishFlag();

	bool IsEndTurn();

	void FinishTurn();

	void SetDamage(int damage) { Hp -= damage; }

	void SetGuardDamage(int damage) { Hp -= damage * guard_; }

	void SetCounterDamage() { Hp -= AttackDamage * 1.2; }

private:
	WorldTransform worldTransform_;

	Input* input_ = nullptr;

	DebugText* debugText_ = nullptr;

	int SelectCommand;

	int Hp;
	int Speed;
	
	int attack_;
	int damageUp_;
	int AttackDamage;
	int guard_;
	int ulte_;
	int Turn;
	int MoveTimer;
	int EndTime;
	bool isAttack_;
	bool isBossDamageUp_;
	bool isBossGuard_;
	bool isUlteSealed;
	bool isAvoidSealed;
	bool isEndTurn;

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

