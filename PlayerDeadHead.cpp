#include "PlayerDeadHead.h"

void PlayerDeadHead::Update()
{
	
	unsignedSpeed_.y ++;
	unsignedSpeed_.x -= 0.2;
	speed_.y++;
	//speed_.x = unsignedSpeed_.x * direction_.x;
	//speed_.y = unsignedSpeed_.y * direction_.y;
	if (headCenter_.y + GetInfo::GetPlayerSpriteRadius() >= GetInfo::GetBaseLevel()) {
		headCenter_.y = GetInfo::GetBaseLevel() - GetInfo::GetPlayerSpriteRadius();
		direction_.y = -direction_.y;
		speed_.y -=10-counter_;
		counter_++;
	}
	if (headCenter_.y <= 0) {
		direction_.y = -direction_.y;
		speed_.y = -speed_.y/1.1;
	}
	if (headCenter_.x - GetInfo::GetPlayerSpriteRadius() <= 0) {
		direction_.x = -direction_.x;
		speed_.x = -speed_.x / 1.1;
	}
	if (headCenter_.x - GetInfo::GetPlayerSpriteRadius() >= GetInfo::GetWindowWidth()) {
		direction_.x = -direction_.x;
	}
	if (counter_ >= 10) {
		speed_.y = 0;
		stop_ = true;
	}
	if (stop_==true) {
		speed_.x = 0;
	}
	headCenter_.x += speed_.x;
	headCenter_.y += speed_.y;
	lTop_.x = headCenter_.x -GetInfo::GetPlayerSpriteRadius();
	rTop_.x= headCenter_.x + GetInfo::GetPlayerSpriteRadius();
	lBottom_.x = headCenter_.x - GetInfo::GetPlayerSpriteRadius();
	rBottom_.x = headCenter_.x + GetInfo::GetPlayerSpriteRadius();
	lTop_.y=headCenter_.y- GetInfo::GetPlayerSpriteRadius();
	rTop_.y=headCenter_.y- GetInfo::GetPlayerSpriteRadius();
	lBottom_.y=headCenter_.y+ GetInfo::GetPlayerSpriteRadius();
	rBottom_.y=headCenter_.y+GetInfo::GetPlayerSpriteRadius();

}

void PlayerDeadHead::Draw()
{
	Novice::DrawQuad(lTop_.x, lTop_.y, rTop_.x, rTop_.y, lBottom_.x, lBottom_.y, rBottom_.x, rBottom_.y, 0, 0, 64, 64, sprite_, WHITE);
}

void PlayerDeadHead::SetStart(int x, int y)
{
	headCenter_.x = x;
	headCenter_.y = y;
	unsignedSpeed_.x = 10;
	unsignedSpeed_.y = 30;
	direction_.x = -1;
	direction_.y = -1;
	speed_.y = -30;
	speed_.x = -10;
	counter_ = 0;
	stop_ = false;
}
