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

class Player;

class Boss
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Normal();

	void PowerUp();

	float BossHp();
	float BossSpeed();

	int Ransuu();

	void SetPlayer(Player* player) { player_ = player; }

private:
	WorldTransform worldTransform_;

	Player* player_ = nullptr;

	Input* input_ = nullptr;

	int SelectCommand;

	float Hp;
	float Speed;

	float BossDamage;
	float BossDamageUp;
	float BossGuard;
	bool RandomFlag;
	bool AttackFlag;

	// �s���t�F�[�Y
	enum class Phase
	{
		Normal,		//	�ʏ�
		PowerUp,	//	����
	};

	// �t�F�[�Y
	Phase phase_ = Phase::Normal;
};

