#pragma once

class Player;
class Boss;

class Turn
{
public:
	void Initialize();

	void Update();

	float PlayerUlte();

	float BossUlte();

	float BossUlteCounrt();

private:
	Player* player_ = nullptr;
	Boss* boss_ = nullptr;

	float TurnCount;
	float PlayerCount;
	float BossCount;
	float UlteCount;
};

