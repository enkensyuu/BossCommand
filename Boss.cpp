#include "Boss.h"
#include"Player.h"
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
	attack_ * 1.2;
	damageUp_ * 1.2;
	guard_ * 1.2;
	isAvoidSealed = false;
}

void Boss::Initialize()
{
	Hp = 1000;
	attack_ = 100;
	damageUp_ = 125;
	guard_ = 0.65f;
	ulte_ = 250;
	isAttack_ = false;
	isBossDamageUp_ = false;
	isBossGuard_ = false;
	isRandomFlag_ = false;
	isBossUlte_ = false;
	Turn = 0;
	isUlteSealed = true;
	isAvoidSealed = true;
	MoveTimer = 300;
	EndTime = 1;
	isEndTurn = false;

	input_ = Input::GetInstance();

	debugText_ = DebugText::GetInstance();
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
	debugText_->SetPos(350, 700);
	debugText_->SetScale(3);
	debugText_->Printf("-%d", SelectCommand);

}

void Boss::Draw()
{
}

void Boss::Command()
{
	MoveTimer--;
	isRandomFlag_ = true;
	if (isRandomFlag_)
	{
		SelectCommand = rand() % 5;
		isRandomFlag_ = false;
	}

	// UŒ‚
	if (SelectCommand == 0)
	{
		/*debugText_->SetPos(350, 700);
		debugText_->SetScale(3);
		debugText_->Printf("-%d", SelectCommand);*/
		if (MoveTimer < 0)
		{
			isAttack_ = true;
			EndTime--;
		}

		if (!isBossDamageUp_)
		{
			AttackDamage = attack_;
		}
		else
		{
			AttackDamage = damageUp_;
		}
	}

	// —­‚ß
	else if (SelectCommand == 1)
	{
		Speed = 1;
		if (MoveTimer < 0)
		{
			isBossDamageUp_ = true;
			EndTime--;
		}

	}

	// ƒK[ƒh
	else if (SelectCommand == 2)
	{
		Speed = 2;
		if (MoveTimer < 0)
		{
			isBossGuard_ = true;
			EndTime = 1;
		}

	}

	// •KŽE‹Z
	else if (SelectCommand == 3 && !isUlteSealed)
	{
		Speed = 4;
		if (MoveTimer < 0)
		{
			isBossUlte_ = true;
			EndTime--;
		}

	}

	// ‰ñ”ð
	else if (SelectCommand == 4 && !isAvoidSealed)
	{
		Speed = 3;
		if (MoveTimer < 0)
		{
			isBossAvoid_ = true;
			EndTime--;
		}

	}

	if (Turn >= 5)
	{
		isUlteSealed = false;
	}

	if (EndTime < 0)
	{
		isEndTurn = true;
		FinishFlag();
	}
}

int Boss::BossHp()
{
	return Hp;
}


int Boss::BossSpeed()
{
	return Speed;
}

int Boss::Attack()
{
	return AttackDamage;
}

int Boss::Ulte()
{
	return ulte_;
}

bool Boss::IsAttack()
{
	return isAttack_;
}

bool Boss::IsGuard()
{
	return isBossGuard_;
}

bool Boss::IsUlteFlag()
{
	return isBossUlte_;
}

void Boss::FinishFlag()
{
	isAttack_ = false;
	if (isAttack_)
	{
		isBossDamageUp_ = false;
	}
	isBossGuard_ = false;
	Turn += 1;
	if (isBossUlte_)
	{
		Turn = 0;
		isUlteSealed = true;
	}
	isBossAvoid_ = false;
	MoveTimer = 300;
	EndTime = 1;
	
}

bool Boss::IsEndTurn()
{
	return isEndTurn;
}

void Boss::FinishTurn()
{
	isEndTurn = false;
}
