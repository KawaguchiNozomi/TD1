#include "BackGround.h"

void BackGround::Draw()
{
	Novice::DrawBox(0, 0, 1000, 720, 0, BLACK, kFillModeSolid);
	if (whereWorld_ == 0) {
		Novice::DrawSpriteRect(0, 0, 0+scroll_/2, 0, 2000, 720, back_[0], 1, 1, 0, WHITE);
	}
	if (whereWorld_ == 1) {
		Novice::DrawSpriteRect(0, 0, 0 + scroll_ / 2, 0, 2000, 720, back_[1], 1, 1, 0, WHITE);
	}
	Novice::DrawBox(0, 512, 1000, 720 - 512, 0, BLACK, kFillModeSolid);
}

void BackGround::SelectBackDraw()
{
	Novice::DrawBox(0, 0, 1000, 720, 0, BLACK, kFillModeSolid);

}

void BackGround::TitleBackDraw()
{
	Novice::DrawBox(0, 0, 1000, 720, 0, BLACK, kFillModeSolid);
	particle_->Title();
}

void BackGround::ManualBackDraw()
{
	Novice::DrawBox(0, 0, 1000, 720, 0, BLACK, kFillModeSolid);
	Novice::DrawSprite(0, 0, manual_, 1, 1, 0, WHITE);
}

void BackGround::SetMode(int world)
{
	whereWorld_ = world;
}

void BackGround::SetScroll(int scrollX)
{
	scroll_ = scrollX;
}
