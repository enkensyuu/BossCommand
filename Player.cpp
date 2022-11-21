#include "TextureManager.h"
#include <cassert>
#include"Player.h"
#include"Boss.h"
#include"Turn.h"
#include<time.h>
#include<math.h>


void Player::Initialize()
{
	PlayerHp_ = 500;
	isMoveFlag_ = false;
	isAttack = false;
	Select = 0;
	Random = false;
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();
}

void Player::Update()
{
	if (input_->TriggerKey(DIK_LEFT))
	{
		Select -= 1;
		if (Select < 0)
		{
			Select = 0;
		}
	}
	else if (input_->TriggerKey(DIK_RIGHT))
	{
		Select += 1;
		if (Select > 4)
		{
			Select = 4;
		}
	}

	if (input_->TriggerKey(DIK_SPACE))
	{
		isMoveFlag_ = true;
		Random = true;
	}

	if (isMoveFlag_)
	{
		if (Random)
		{
			PlayerAttack = rand() % 51 + 50;
			PlayerHeal = rand() % 51 + 150;
			Random = false;
		}

		if (Select == 0)
		{
			isAttack = true;
			PlayerSpeed = 2;
		}
		else if (Select == 1)
		{
			PlayerHp_ += PlayerHeal;
			PlayerSpeed = 3;
		}
		else if (Select == 2)
		{
			PlayerSpeed = 3;
		}
		else if (Select == 3)
		{
			PlayerSpeed = 3;
		}
		else if (Select == 4)
		{
			PlayerSpeed = 4;
		}
	}

	debugText_->SetPos(50, 50);
	debugText_->SetScale(5);
	debugText_->Printf("player:%d", PlayerHp_);
}

void Player::Draw()
{
	
}

int Player::Speed()
{
	return PlayerSpeed;
}

int Player::Hp()
{
	return PlayerHp_;
}

int Player::Attack()
{
	return PlayerAttack;
}

bool Player::IsMove()
{
	return isMoveFlag_;
}

bool Player::IsAttack()
{
	return isAttack;
}