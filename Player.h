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

class Player
{
private:
	int PlayerHp_;
	int PlayerAttackFlag_;
	float PlayerSpeed;
	int Select;
	Input* input_ = nullptr;
public:
	void Initialize();
	void Update();
	void Draw();
	float Speed();


};
