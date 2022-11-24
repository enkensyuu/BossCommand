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

class Player
{
private:
	int PlayerHp_;
	int PlayerSpeed;
	int PlayerAttack;
	int PlayerHeal;
	int PlayerGuard;
	int PlayerUlte;
	int Select;
	int AttackCount;
	int Turn;
	int MoveTimer;
	int EndTime;
	bool isMoveFlag_;
	bool Random;
	bool isAttack;
	bool isHeal;
	bool isGuard;
	bool isCounter;
	bool isCounterSealed;
	bool isUlte;
	bool isUlteSealed;
	bool KeyInput;
	bool isAttackMove;
	bool isHealMove;
	bool isGuardMove;
	bool isCounterMove;
	bool isUlteMove;
	bool isEndTurn;

	Input* input_ = nullptr;

	DebugText* debugText_ = nullptr;

public:
	void Initialize();

	void Update();

	void isSelect();

	void Draw();

	int Speed();

	int Guard();

	int Ulte();

	int Attack();
	bool IsAttack();

	bool IsGuard();

	bool IsMove();

	bool IsEndTurn();

	bool IsCounter();

	bool IsUlte();

	bool IsRandam();

	void FinishFlag();

	void FinishTurn();

	void SetDamage(int damage) { PlayerHp_ -= damage; }

	void SetGuardDamage(int damage) { PlayerHp_ -= PlayerGuard / 100 * damage; }
};
