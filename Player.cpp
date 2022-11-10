#include "TextureManager.h"
#include <cassert>
#include<Player.h>
#include<random>


void Player::Initialize()
{
	PlayerHp_ = 500;
	PlayerAttackFlag_ = 0;
	Select = 0;
	input_ = Input::GetInstance();
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float>PlayerDamage(50.0f, 100.0f);
	std::uniform_real_distribution<float>PlayerHeal(150.0f, 200.0f);
	std::uniform_real_distribution<float>PlayerGuard(0.5f, 0.75f);

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
	if (Select == 0)
	{
		PlayerSpeed = 2;
	}
	else if (Select == 1)
	{
		PlayerSpeed = 3;
	}
	else if (Select == 2)
	{
		PlayerSpeed = 3;
	}
	else if (Select == 4)
	{
		PlayerSpeed = 4;
	}
}

void Player::Draw()
{
}

float Player::Speed()
{
	return PlayerSpeed;
}
