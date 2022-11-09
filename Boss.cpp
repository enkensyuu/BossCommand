#include "Boss.h"

#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

void Boss::Normal()
{
	SelectCommand = rand() % 4;

	if (Hp <= 500)
	{
		phase_ = Phase::PowerUp;
	}
	
}

void Boss::PowerUp()
{
	BossDamage * 1.2;
	BossDamageUp * 1.2;
	BossGuard * 1.2;
	SelectCommand = rand() % 5;
}

void Boss::Initialize()
{
	Hp = 1000;
	BossDamage = 100;
	BossDamageUp = 25;
	BossGuard = 0.35f;
}

void Boss::Update()
{
	switch (phase_)
	{
	case Phase::Normal:
	default:
		Normal();
		break;
	case Phase::PowerUp:
		PowerUp();
		break;
	}

	if (AttackFlag)
	{
		RandomFlag = true;
		if (RandomFlag)
		{
			RandomFlag = false;
		}
	}
	if (SelectCommand == 0)
	{

	}
	else if (SelectCommand == 1)
	{

	}
	else if (SelectCommand == 2)
	{

	}
	else if (SelectCommand == 3)
	{

	}
	else if (SelectCommand == 4)
	{

	}
}

void Boss::Draw()
{
}

float Boss::BossHp()
{
	return Hp;
}

float Boss::BossSpeed()
{
	return Speed;
}

int Boss::Ransuu()
{
	return SelectCommand;
}
