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

class Boss;
class Turn;

class Player
{
private:
	int PlayerHp_;

	bool isMoveFlag_;

	bool Random;

	int PlayerSpeed;

	int PlayerAttack;
	bool isAttack;

	int PlayerHeal;
	bool isHeal;

	int PlayerGuard;
	int Select;

	Input* input_ = nullptr;

	DebugText* debugText_ = nullptr;

	Boss* boss_ = nullptr;
	Turn* turn_ = nullptr;

public:
	void Initialize();

	void Update();

	void Draw();

	int Speed();

	int Hp();

	int Attack();
	bool IsAttack();

	bool IsMove();

	void SetDamage(int damage) { PlayerHp_ -= damage; }
};
