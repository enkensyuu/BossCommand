#include "Turn.h"
#include "Player.h"
#include "Boss.h"

void Turn::Initialize()
{
	TurnCount=1;
	PlayerCount=0;
	BossCount=0;
	UlteCount=3;
}

void Turn::Update()
{
	TurnCount += 1;
	BossCount += 1;
}

float Turn::PlayerUlte()
{
	return PlayerCount;
}

float Turn::BossUlte()
{
	return BossCount;
}

float Turn::BossUlteCounrt()
{
	return UlteCount;
}
