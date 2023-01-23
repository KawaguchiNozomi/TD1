#include "Player.h"
#include <Novice.h>
#include "Particle.h"

void Player::Update(char* keys, char* prekeys)
{
	xSpeed_ = 0;
	if (keys[DIK_D] || keys[DIK_RIGHT]) {
		xSpeed_ = 5;
	}
	if (keys[DIK_A] || keys[DIK_LEFT]) {
		xSpeed_ = -5;
	}
	if ((keys[DIK_SPACE] || keys[DIK_W] || keys[DIK_UP])&& (prekeys[DIK_SPACE] == 0 && prekeys[DIK_W] == 0&& prekeys[DIK_UP] == 0)) {
		ySpeed_ = -20;
	}
	x_ += xSpeed_;
	if (x_ <= 0) {
		x_ = 0;
	}
	if (x_ >= 500&& x_ < rightEnd_ - 500) {
		scrollX_ =x_-500;
	}
	if (x_ >= rightEnd_ - 500) {
		scrollX_ += 0;
	}
	y_ += ySpeed_;

	if (y_ < baseLevel_) {
		ySpeed_+=1;
	}
	else {
		ySpeed_ = 0;
		y_ = baseLevel_;
	}
	
}

void Player::Draw(char*keys)
{
	ToScreen();
	
	if (xSpeed_ != 0 && y_ == baseLevel_) {
		particle_->PlayerDust(x_, y_, baseLevel_, keys);
		particle_->PlayerDustDraw(x_, y_, scrollX_, scrollY_);
	}else{ particle_->SetPlayerDustIsArriveFalse(); }
	if (isArrave_ == true) {
		Novice::DrawEllipse(screenX_, screenY_, 10, 10, 0, WHITE, kFillModeSolid);
	}
}

void Player::ToScreen()
{
	screenX_ = x_ - scrollX_;
	screenY_ = y_ - scrollY_;
}



Player::Player()
{
	this->x_ = GetInfo::GetBlockSize()/2;
	this->y_ = baseLevel_;
	this->scrollX_ = 0;
	this->scrollY_ = 0;
	this->isArrave_ = true;
	this->xSpeed_ = 0;
	this->ySpeed_ = 0;
}

Player::~Player()
{
}
