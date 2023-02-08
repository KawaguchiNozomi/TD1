#include "PlayerDeadHead.h"

void PlayerDeadHead::Update()
{
	
	unsignedSpeed_.y ++;
	unsignedSpeed_.x -= 0.2;
	speed_.y++;
	//speed_.x = unsignedSpeed_.x * direction_.x;
	//speed_.y = unsignedSpeed_.y * direction_.y;

	//°ƒoƒEƒ“ƒh
	if (headCenter_.y + GetInfo::GetPlayerSpriteRadius() >= GetInfo::GetBaseLevel()) {
		headCenter_.y = GetInfo::GetBaseLevel() - GetInfo::GetPlayerSpriteRadius();
		direction_.y = -direction_.y;
		speed_.y -=10-counter_;
		if (counter_ <= 10) {
			rotateSpeed_ += (1.0 / 64.0) * M_PI;
		}
		if (counter_ <= 1) {
			ShakeRange_.y += 10;
		}
		counter_++;
	}
	if (headCenter_.y <= 0) {
		direction_.y = -direction_.y;
		speed_.y = -speed_.y/1.1;
	}
	if (headCenter_.x - GetInfo::GetPlayerSpriteRadius() <= 0) {
		direction_.x = -direction_.x;
		speed_.x = -speed_.x / 1.1;
		ShakeRange_.x += 10;
	}
	if (headCenter_.x - GetInfo::GetPlayerSpriteRadius() >= GetInfo::GetWindowWidth()) {
		direction_.x = -direction_.x;
		ShakeRange_.x += 10;
	}
	rotateSpeed_ -= 0.001;
	if (counter_ >= 10) {
		speed_.y = 0;
		stop_ = true;
		rotateSpeed_ = 0.002;
		rollingTime_++;
		if (rollingTime_ >= 60) {
			rotateSpeed_ = 0;
		}
	}
	if (stop_==true) {
		speed_.x = 0;
	}
	theta_ += rotateSpeed_;
	if (rotateSpeed_ <= 0) {
		rotateSpeed_ = 0;
	}

	headCenter_.x += speed_.x;
	headCenter_.y += speed_.y;
	/*
	lTop_.x = headCenter_.x -GetInfo::GetPlayerSpriteRadius();
	rTop_.x= headCenter_.x + GetInfo::GetPlayerSpriteRadius();
	lBottom_.x = headCenter_.x - GetInfo::GetPlayerSpriteRadius();
	rBottom_.x = headCenter_.x + GetInfo::GetPlayerSpriteRadius();
	lTop_.y=headCenter_.y- GetInfo::GetPlayerSpriteRadius();
	rTop_.y=headCenter_.y- GetInfo::GetPlayerSpriteRadius();
	lBottom_.y=headCenter_.y+ GetInfo::GetPlayerSpriteRadius();
	rBottom_.y=headCenter_.y+GetInfo::GetPlayerSpriteRadius();
	*/
	lTop_.x =  -GetInfo::GetPlayerSpriteRadius();
	rTop_.x =  GetInfo::GetPlayerSpriteRadius();
	lBottom_.x = -GetInfo::GetPlayerSpriteRadius();
	rBottom_.x =  GetInfo::GetPlayerSpriteRadius();
	lTop_.y =  -GetInfo::GetPlayerSpriteRadius();
	rTop_.y = -GetInfo::GetPlayerSpriteRadius();
	lBottom_.y =  GetInfo::GetPlayerSpriteRadius();
	rBottom_.y =  GetInfo::GetPlayerSpriteRadius();

	float LeftTopRotated_x = float(lTop_.x * cosf(theta_) - lTop_.y * sinf(theta_));
	float LeftTopRotated_y = lTop_.y * cosf(theta_) + lTop_.x * sinf(theta_);
	float LeftBottomRotated_x = lBottom_.x * cosf(theta_) - lBottom_.y * sinf(theta_);
	float LeftBottomRotated_y = lBottom_.y* cosf(theta_) + lBottom_.x * sinf(theta_);
	float RightTopRotated_x = rTop_.x * cosf(theta_) - rTop_.y * sinf(theta_);
	float RightTopRotated_y = rTop_.y * cosf(theta_) + rTop_.x * sinf(theta_);
	float RightBottomRotated_x = rBottom_.x * cosf(theta_) - rBottom_.y * sinf(theta_);
	float RightBottomRotated_y = rBottom_.y * cosf(theta_) + rBottom_.x * sinf(theta_);

	lTopPos_.x = LeftTopRotated_x+headCenter_.x;
	lTopPos_.y = LeftTopRotated_y+headCenter_.y;
	lBottomPos_.x = LeftBottomRotated_x+headCenter_.x;
	lBottomPos_.y = LeftBottomRotated_y+headCenter_.y;
	rTopPos_.x = RightTopRotated_x+headCenter_.x;
	rTopPos_.y = RightTopRotated_y+headCenter_.y;
	rBottomPos_.x = RightBottomRotated_x+headCenter_.x;
	rBottomPos_.y = RightBottomRotated_y+headCenter_.y;
}

void PlayerDeadHead::Draw(int direction)
{
	if (direction >= 1) {
		Novice::DrawQuad(lTopPos_.x, lTopPos_.y, rTopPos_.x, rTopPos_.y, lBottomPos_.x, lBottomPos_.y, rBottomPos_.x, rBottomPos_.y, 0, 0, 64, 64, sprite_, WHITE);
	}
	if (direction <= -1) {
		Novice::DrawQuad(lTopPos_.x, lTopPos_.y, rTopPos_.x, rTopPos_.y, lBottomPos_.x, lBottomPos_.y, rBottomPos_.x, rBottomPos_.y, 64, 0, -64, 64, sprite_, WHITE);
	}
	//Novice::DrawQuad(lTop_.x, lTop_.y, rTop_.x, rTop_.y, lBottom_.x, lBottom_.y, rBottom_.x, rBottom_.y, 0, 0, 64, 64, sprite_, WHITE);
}

void PlayerDeadHead::SetStart(int x, int y)
{
	ShakeRange_.x = 10;
	ShakeRange_.y = 20;
	Shake_.x = 0;
	Shake_.y = 0;
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
	theta_=0;
	rotateSpeed_= (1.0 / 64.0) * M_PI;
	rollingTime_ = 0;
}

void PlayerDeadHead::SetShakeRange(int x,int y)
{
	ShakeRange_.x += x;
	ShakeRange_.y += y;
}

void PlayerDeadHead::Shake()
{
	Shake_.x = RandomRange(-ShakeRange_.x, ShakeRange_.x);
	Shake_.y = RandomRange(-ShakeRange_.y, ShakeRange_.y);
	ShakeRange_.x--;
	ShakeRange_.y--;
	if (ShakeRange_.x <= 0) {
		ShakeRange_.x = 0;
	}
	if (ShakeRange_.y <= 0) {
		ShakeRange_.y = 0;
	}
}
