#include "Stage.h"
#include "Procession.h"
#include <cassert>

//初期化
void Stage::Initilize(Model*model)
{
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.scale_ = { 100,100,100 };
	worldTransform_.translation_ = { 0,0,0 };
}
//更新
void Stage::Update()
{
	worldTransform_.rotation_ += {0, 0.001f, 0};
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_,worldTransform_.rotation_,worldTransform_.translation_);
	worldTransform_.TransferMatrix();

}
//描画
void Stage::Draw(ViewProjection&viewProjection)
{
	model_->Draw(worldTransform_, viewProjection);
}
