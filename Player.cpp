#include "Player.h"
#include <Novice.h>

void Player::Update(char* keys, char* prekeys)
{
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
	y_ += ySpeed_;

	if (y_ < 500) {
		ySpeed_++;
	}
	else {
		ySpeed_ = 0;
		y_ = 500;
	}
	xSpeed_ = 0;
}

void Player::Draw()
{
	Novice::DrawEllipse(x_, y_, 10, 10, 0, WHITE, kFillModeSolid);
}

Player::Player()
{
	this->x_ = 500;
	this->y_ = 500;
	this->isArrave_ = true;
	this->xSpeed_ = 0;
	this->ySpeed_ = 0;
}

Player::~Player()
{
}
