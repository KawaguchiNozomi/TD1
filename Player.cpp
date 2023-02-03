#include "Player.h"
#include <Novice.h>
#include "Particle.h"
#include <math.h>

void Player::Update(char* keys, char* prekeys)
{
	if (isArrave_ == true) {
		xSpeed_ = 0;
		if (keys[DIK_D] || keys[DIK_RIGHT]) {
			if (colloideX_ != true) {
				xSpeed_ = 5;
			}
		}
		if (keys[DIK_A] || keys[DIK_LEFT]) {
			if (colloideX_ != true) {
				xSpeed_ = -5;
			}
		}
		if ((keys[DIK_SPACE] || keys[DIK_W] || keys[DIK_UP]) && (prekeys[DIK_SPACE] == 0 && prekeys[DIK_W] == 0 && prekeys[DIK_UP] == 0) && (isPlayerJump_ == 0 || isPlayerJump_ == 1) == 1) {
			if (isPlayerJump_ == 1) {
				ySpeed_ = -18;
				isPlayerJump_ = 2;
			}
			if (isPlayerJump_ == 0) {
				ySpeed_ = -20;
				isPlayerJump_ = 1;
			}
		}
		x_ += xSpeed_;
		if (x_ <= 0+GetInfo::GetPlayerSpriteRadius()) {
			x_ = 0+ GetInfo::GetPlayerSpriteRadius();
		}
		if (x_ >= 500 && x_ < rightEnd_ - 500) {
			scrollX_ = x_ - 500;
		}
		if (x_ >= rightEnd_ - 500) {
			scrollX_ += 0;
		}
		if (x_ >= GetInfo::GetBlockSize() * GetInfo::GetMapWidth() - GetInfo::GetPlayerSpriteRadius()) {
			x_ = GetInfo::GetBlockSize() * GetInfo::GetMapWidth()-GetInfo::GetPlayerSpriteRadius();
		}
		y_ += ySpeed_;

		if (y_ < standLevel_) {
			ySpeed_ += 1;
		}
		else {
			ySpeed_ = 0;
			y_ = standLevel_;
			isPlayerJump_ = 0;
		}
	}
	if (whereStand_ == 2||whereStand_==3) {
		isArrave_ = false;
	}
	if (whereStand_ == 3) {
		deadHead_->SetStart(screenX_, screenY_);
		bladeDying = true;
	}
	Novice::ScreenPrintf(0, 0, "where=%d,isArrive=%d", whereStand_,isArrave_);
	
}

void Player::Draw(char*keys)
{
	ToScreen();
	
	
	if (isArrave_ == true) {
		Novice::DrawEllipse(screenX_, screenY_, 10, 10, 0, WHITE, kFillModeSolid);
		//スプライト
		Novice::DrawSprite(screenX_ - GetInfo::GetPlayerSpriteRadius(), screenY_ - GetInfo::GetPlayerSpriteSize(), playerSpriteBody_, 1, 1, 0, WHITE);
		TranslateHead();
		Novice::DrawSprite(screenX_ - GetInfo::GetPlayerSpriteRadius(),headPos_.y- GetInfo::GetPlayerSpriteSize()*2, playerSpriteHead_, 1, 1, 0, WHITE);
		//砂埃
		if (xSpeed_ != 0 && y_ == baseLevel_) {
			particle_->PlayerDust(x_, y_, baseLevel_, keys);
			particle_->PlayerDustDraw(x_, y_, scrollX_, scrollY_);
		}
		else { particle_->SetPlayerDustIsArriveFalse(); }
	}
	if (isArrave_ == false) {
		particle_->PlayerDead(screenX_, screenY_);
		particle_->PlayerDeadDraw();
		if (bladeDying==true) {
			deadHead_->Update();
			deadHead_->Draw();
		}
	}
}

void Player::ToScreen()
{
	screenX_ = x_ - scrollX_;
	screenY_ = y_ - scrollY_;
}



void Player::SetSpeedY(int y)
{
	ySpeed_ = y;
}

void Player::SetPosY(int posY)
{
	y_ = posY;
}

void Player::SetStandLevel(int standlevel)
{
	standLevel_ = standlevel;
}

void Player::SetWhereStand(int block)
{
	whereStand_ = block;
}

void Player::SetIsArrave(int isArrive)
{
	isArrave_ = isArrive;
}

void Player::SetColloideX(int colloideX)
{
	colloideX_ = colloideX;
}

void Player::Reset()
{
	x_ = GetInfo::GetBlockSize() / 2;
	y_ = baseLevel_ - 50;
	scrollX_ = 0;
	scrollY_ = 0;
	screenX_ = 0;
	screenY_ = 0;
	standLevel_ = 0;
	isArrave_ = true;
	xSpeed_ = 0;
	ySpeed_ = 0;
	whereStand_ = 0;
}

void Player::TranslateHead()
{
	headPos_.y = (3 * cosf(headTheta_) + 3 * sinf(headTheta_)) + screenY_;
	headTheta_ += 0.05;

}

Player::Player()
{
	this->x_ = GetInfo::GetBlockSize()/2;
	this->y_ = baseLevel_-50;
	this->scrollX_ = 0;
	this->scrollY_ = 0;
	this->screenX_ = 0;
	this->screenY_ = 0;
	this->standLevel_ = 0;
	this->isArrave_ = true;
	this->xSpeed_ = 0;
	this->ySpeed_ = 0;
	this->whereStand_ = 0;
}

Player::~Player()
{
	
}
