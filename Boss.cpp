#include "Boss.h"
#include"Player.h"
#include"Turn.h"
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
	SelectCommand = rand() % 5;
}

void Boss::Initialize()
{
	input_ = Input::GetInstance();

	debugText_ = DebugText::GetInstance();

	Hp = 1000;
	attack_ = 100;
	damageUp_ = 125;
	guard_ = 0.65f;
	ulte_ = 25;
	isAttack_ = false;
	isBossDamageUp_ = false;
	isBossGuard_ = false;
	isRandomFlag_ = false;
	isBossUlte_ = false;
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

	if (player_->IsAttack())
	{
		isRandomFlag_ = true;
		if (isRandomFlag_)
		{
			isRandomFlag_ = false;
		}
	}
	if (SelectCommand == 0)
	{
		if (!isBossDamageUp_)
		{
			player_->Hp() - attack_;
		}
		else
		{
			player_->Hp() - damageUp_;
			isBossDamageUp_ = false;
		}
	}
	else if (SelectCommand == 1)
	{
		isBossDamageUp_ = true;
	}
	else if (SelectCommand == 2)
	{
		isBossGuard_ = true;
	}
	else if (SelectCommand == 3)
	{
		if (turn_->BossUlte() >= 5)
		{
			isBossUlte_ = true;
		}
		else
		{
			SelectCommand != 3;
		}
	}
	else if (SelectCommand == 4)
	{
		isBossAvoid_ = true;
	}

	debugText_->SetPos(50, 150);
	debugText_->SetScale(5);
	debugText_->Printf("Boss:%d", Hp);

}

void Boss::Draw()
{
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
	return attack_;
}

int Boss::DamageUp()
{
	return damageUp_;
}

int Boss::Ulte()
{
	return ulte_;
}

bool Boss::IsAttack()
{
	return isAttack_;
}

bool Boss::IsDamageUp()
{
	return isBossDamageUp_;
}

bool Boss::IsGuard()
{
	return isBossGuard_;
}

bool Boss::IsUlteFlag()
{
	return isBossUlte_;
}

int Boss::Ransuu()
{
	return SelectCommand;
}

void Boss::FinishFlag()
{
	isAttack_ = false;
	isBossDamageUp_ = false;
	isBossGuard_ = false;
}
