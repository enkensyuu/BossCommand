#include "TextureManager.h"
#include <cassert>
#include"Player.h"
#include<time.h>
#include<math.h>


void Player::Initialize()
{
	PlayerHp_ = 500;
	isMoveFlag_ = false;
	Select = 0;
	isAttack;
	Random = false;
	isHeal = false;
	isGuard = false;
	isCounter = false;
	isCounterSealed = true;
	isUlte = false;
	isUlteSealed = true;
	isAttackMove = false;
	isHealMove = false;
	isGuardMove = false;
	isCounterMove = false;
	isUlteMove = false;
	AttackCount = 0;
	PlayerUlte = 200;
	EndTime = 1;
	Turn = 0;
	KeyInput = true;
	MoveTimer = 300;
	isEndTurn = false;
	debugText_ = DebugText::GetInstance();
	input_ = Input::GetInstance();
}

void Player::Update()
{
	if (KeyInput)
	{
		// UŒ‚
		if (Select == 0 && input_->TriggerKey(DIK_SPACE))
		{
			isMoveFlag_ = true;
			Random = true;
			KeyInput = false;
			isAttackMove = true;
		}

		// ‰ñ•œ
		else if (Select == 1 && input_->TriggerKey(DIK_SPACE))
		{
			isMoveFlag_ = true;
			Random = true;
			KeyInput = false;
			isHealMove = true;
		}

		// ƒK[ƒh
		else if (Select == 2 && input_->TriggerKey(DIK_SPACE))
		{
			isMoveFlag_ = true;
			Random = true;
			KeyInput = false;
			isGuardMove = true;
		}

		// ƒJƒEƒ“ƒ^[
		else if (Select == 3 && input_->TriggerKey(DIK_SPACE) && !isCounterSealed)
		{
			isMoveFlag_ = true;
			Random = true;
			KeyInput = false;
			isCounterMove = true;

		}

		// •KŽE‹Z
		else if (Select == 4 && input_->TriggerKey(DIK_SPACE) && !isUlteSealed)
		{
			isMoveFlag_ = true;
			Random = true;
			KeyInput = false;
			isUlteMove = true;
		}
	}


	if (isMoveFlag_)
	{
		MoveTimer--;

		if (Random)
		{
			PlayerAttack = rand() % 51 + 50;
			PlayerHeal = rand() % 51 + 150;
			PlayerGuard = rand() % 26 + 50;
			Random = false;
		}
		if (isAttackMove)
		{
			AttackCount += 1;
			PlayerSpeed = 2;
			debugText_->SetPos(250, 100);
			debugText_->SetScale(3);
			debugText_->Printf("-%d", PlayerAttack);
			if (MoveTimer < 0)
			{
				isAttack = true;
				EndTime--;
			}
		}

		else if (isHealMove)
		{
			PlayerSpeed = 3;
			debugText_->SetPos(350, 700);
			debugText_->SetScale(3);
			debugText_->Printf("+%d", PlayerHeal);
			if (MoveTimer < 0)
			{
				isHeal = true;
				EndTime--;
			}

			if (isHeal)
			{
				PlayerHp_ += PlayerHeal;
			}
			if (PlayerHp_ > 500)
			{
				PlayerHp_ = 500;
			}
		}

		else if (isGuardMove)
		{
			PlayerSpeed = 3;
			if (MoveTimer < 0)
			{
				isGuard = true;
				EndTime--;
			}
		}

		else if (isCounterMove)
		{
			PlayerSpeed = 3;
			if (MoveTimer < 0)
			{
				isCounter = true;
				EndTime--;
			}
		}

		else if (isUlteMove)
		{
			PlayerSpeed = 4;
			if (MoveTimer < 0)
			{
				isUlte = true;
				EndTime--;
			}
		}
	}

	if (AttackCount >= 3)
	{
		isUlteSealed = true;
	}

	if (Turn >= 5)
	{
		isCounterSealed = false;
	}

	if (EndTime < 0)
	{
		isEndTurn = true;
		FinishFlag();
		EndTime = 1;
	}
}

void Player::isSelect()
{
	if (KeyInput)
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

	}
}

void Player::Draw()
{
	/*debugText_->SetPos(50, 750);
	debugText_->SetScale(5);
	debugText_->Printf("Select:%d", Select);*/

	debugText_->SetPos(50, 600);
	debugText_->Printf("Player:%d", PlayerHp_);
}

int Player::Speed()
{
	return PlayerSpeed;
}

int Player::Guard()
{
	return PlayerGuard;
}

int Player::Ulte()
{
	return PlayerUlte;
}

int Player::Attack()
{
	return PlayerAttack;
}

bool Player::IsMove()
{
	return isMoveFlag_;
}

void Player::FinishFlag()
{
	isAttackMove = false;
	isHealMove = false;
	isGuardMove = false;
	isCounterMove = false;
	isUlteMove = false;
	Turn += 1;
	isMoveFlag_ = false;
	isAttack = false;
	isHeal = false;
	isGuard = false;
	isCounter = false;
	isUlte = false;
	MoveTimer = 300;
	if (isUlte)
	{
		isUlteSealed = true;
		AttackCount = 0;
	}
}

bool Player::IsAttack()
{
	return isAttack;
}

bool Player::IsGuard()
{
	return isGuard;
}

bool Player::IsEndTurn()
{
	return isEndTurn;
}

void Player::FinishTurn()
{
	KeyInput = true;
	isEndTurn = false;
}

bool Player::IsUlte()
{
	return isUlte;
}

bool Player::IsCounter()
{
	return isCounter;
}

bool Player::IsRandam()
{
	return Random;
}