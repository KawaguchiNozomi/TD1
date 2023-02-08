#include "Player.h"
#include <Novice.h>
#include "Particle.h"
#include <math.h>
#define NOWARK keys[DIK_D]==0&&keys[DIK_RIGHT]==0&&keys[DIK_A]==0&&keys[DIK_LEFT]==0

void Player::Update(char* keys, char* prekeys)
{
	if (isArrave_ == true) {
		xSpeed_ = 0;
		if (keys[DIK_D] || keys[DIK_RIGHT]) {
			if (colloideX_ != true) {
				xSpeed_ = 5;
				direction_ = 1;
			}
		}
		if (keys[DIK_A] || keys[DIK_LEFT]) {
			if (colloideX_ != true) {
				xSpeed_ = -5;
				direction_ = -1;
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
		if (NOWARK) {
			LegDigreeL_ = 0;
			LegDigreeR_ = 0;
		}
		if (y_ < standLevel_) {
			ySpeed_ += 1;
		}
		else {
			ySpeed_ = 0;
			y_ = standLevel_;
			isPlayerJump_ = 0;
		}
		if (x_ + GetInfo::GetPlayerSpriteRadius() >= rightEnd_) {
			x_ = rightEnd_ - GetInfo::GetPlayerSpriteRadius();
		}
	}
	//shake_.x = deadHead_->GetShakeX();
	//shake_.y = deadHead_->GetShakeY();

	if (whereStand_ == 2||whereStand_==3) {
		isArrave_ = false;
		deadHead_->SetShakeRange(10, 20);
	}
	if (whereStand_ == 3) {
		deadHead_->SetStart(screenX_, screenY_);
		bladeDying = true;
	}
#ifdef DEBUG

	Novice::ScreenPrintf(0, 0, "where=%d,isArrive=%d", whereStand_,isArrave_);
#endif // DEBUG
	spriteTime_++;
	if (spriteTime_ >= 7) {
		spriteTime_ = 0;
		bodyCount_++;
	}
	if (bodyCount_ >= 4) {
		bodyCount_ = 0;
	}
}

void Player::Draw(char*keys)
{
	ToScreen();
	deadHead_->Shake();
	
	if (isArrave_ == true) {
         #ifdef DEBUG
		    Novice::DrawEllipse(screenX_, screenY_, 10, 10, 0, WHITE, kFillModeSolid);
         #endif // DEBUG
		//スプライト
			
			if (NOWARK||ySpeed_!=0) {
				Novice::DrawSprite(screenX_ - GetInfo::GetPlayerSpriteRadius() * direction_, y_ - GetInfo::GetPlayerSpriteSize(), playerSpriteLeg_, 1 * direction_, 1, 0, WHITE);
			}
			else{
				TranslateLeg();
				if (direction_ == 1) {
					Novice::DrawQuad(lTopPosR_.x, lTopPosR_.y, rTopPosR_.x, rTopPosR_.y, lBottomPosR_.x, lBottomPosR_.y, rBottomPosR_.x, rBottomPosR_.y, 0, 0, 64, 64, playerSpriteLegR_, WHITE);
					Novice::DrawQuad(lTopPos_.x, lTopPos_.y, rTopPos_.x, rTopPos_.y, lBottomPos_.x, lBottomPos_.y, rBottomPos_.x, rBottomPos_.y, 0, 0, 64, 64, playerSpriteLegL_, WHITE);
				}
				if (direction_ == -1) {
					Novice::DrawQuad(lTopPosR_.x, lTopPosR_.y, rTopPosR_.x, rTopPosR_.y, lBottomPosR_.x, lBottomPosR_.y, rBottomPosR_.x, rBottomPosR_.y, 64, 0, -64, 64, playerSpriteLegR_, WHITE);
					Novice::DrawQuad(lTopPos_.x, lTopPos_.y, rTopPos_.x, rTopPos_.y, lBottomPos_.x, lBottomPos_.y, rBottomPos_.x, rBottomPos_.y, 64, 0, -64, 64, playerSpriteLegL_, WHITE);
				}
			}
			if (ySpeed_ > 0) {
				Novice::DrawSpriteRect(screenX_ - GetInfo::GetPlayerSpriteRadius()*direction_, y_ - GetInfo::GetPlayerSpriteSize()-5, bodyCount_ * 64, 0, 64, 64, playerSpriteBody_, 0.25*direction_, 1, 0, WHITE);
			}else if(ySpeed_ < 0) {
				Novice::DrawSpriteRect(screenX_ - GetInfo::GetPlayerSpriteRadius() * direction_, y_ - GetInfo::GetPlayerSpriteSize() + 5, bodyCount_ * 64, 0, 64, 64, playerSpriteBody_, 0.25 * direction_, 1, 0, WHITE);
			}
			else {
				Novice::DrawSpriteRect(screenX_ - GetInfo::GetPlayerSpriteRadius()*direction_, y_ - GetInfo::GetPlayerSpriteSize(), bodyCount_ * 64, 0, 64, 64, playerSpriteBody_, 0.25*direction_, 1, 0, WHITE);
			}
		TranslateHead();
		Novice::DrawSpriteRect(screenX_ - GetInfo::GetPlayerSpriteRadius()*direction_,headPos_.y- GetInfo::GetPlayerSpriteSize()*1.9,0,0,64,64, playerSpriteHead_, 1*direction_,1, 0, WHITE);
		Novice::DrawSpriteRect(screenX_ - GetInfo::GetPlayerSpriteRadius() * direction_, headPos_.y - GetInfo::GetPlayerSpriteSize() * 1.9, 0, 0, 64, 64, playerSpriteEye_[eye_], 1 * direction_, 1, 0, WHITE);
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
			deadHead_->Draw(direction_);
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

void Player::SetRightEnd(int width)
{
	rightEnd_ = width * GetInfo::GetBlockSize();
}

void Player::SetEye(int num)
{
	eye_ = num;
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
	headPos_.y = (2 * cosf(headTheta_) + 2 * sinf(headTheta_)) + screenY_;
	headTheta_ += 0.05;

}

void Player::TranslateLeg()
{
	LegDigreeR_ += digreeSpeedR_;
	LegDigreeL_ += digreeSpeedL_;
	if (LegDigreeR_ >= 30) {
		digreeSpeedR_ = -digreeSpeedR_;
	}
	if (LegDigreeR_ <= -30) {
		digreeSpeedR_ = -digreeSpeedR_;
	}
	if (LegDigreeL_ >= 30) {
		digreeSpeedL_ = -digreeSpeedL_;
	}
	if (LegDigreeL_ <= -30) {
		digreeSpeedL_ = -digreeSpeedL_;
	}
	LegThetaR_ = DegreeToRadian(LegDigreeR_);
	thetaL_ = DegreeToRadian(LegDigreeL_);
	LegPosR_.x = screenX_;
	LegPosR_.y = screenY_-GetInfo::GetPlayerSpriteRadius();
	LegPosL_.x = screenX_;
	LegPosL_.y = screenY_ - GetInfo::GetPlayerSpriteRadius();;
	lTopR_.x = -GetInfo::GetPlayerSpriteRadius();
	rTopR_.x = GetInfo::GetPlayerSpriteRadius();
	lBottomR_.x = -GetInfo::GetPlayerSpriteRadius();
	rBottomR_.x = GetInfo::GetPlayerSpriteRadius();
	lTopR_.y = -GetInfo::GetPlayerSpriteRadius();
	rTopR_.y = -GetInfo::GetPlayerSpriteRadius();
	lBottomR_.y = GetInfo::GetPlayerSpriteRadius();
	rBottomR_.y = GetInfo::GetPlayerSpriteRadius();

	float LeftTopRotatedR_x = float(lTopR_.x * cosf(LegThetaR_) - lTopR_.y * sinf(LegThetaR_));
	float LeftTopRotatedR_y = lTopR_.y * cosf(LegThetaR_) + lTopR_.x * sinf(LegThetaR_);
	float LeftBottomRotatedR_x = lBottomR_.x * cosf(LegThetaR_) - lBottomR_.y * sinf(LegThetaR_);
	float LeftBottomRotatedR_y = lBottomR_.y * cosf(LegThetaR_) + lBottomR_.x * sinf(LegThetaR_);
	float RightTopRotatedR_x = rTopR_.x * cosf(LegThetaR_) - rTopR_.y * sinf(LegThetaR_);
	float RightTopRotatedR_y = rTopR_.y * cosf(LegThetaR_) + rTopR_.x * sinf(LegThetaR_);
	float RightBottomRotatedR_x = rBottomR_.x * cosf(LegThetaR_) - rBottomR_.y * sinf(LegThetaR_);
	float RightBottomRotatedR_y = rBottomR_.y * cosf(LegThetaR_) + rBottomR_.x * sinf(LegThetaR_);

	lTopPosR_.x = LeftTopRotatedR_x + LegPosR_.x;
	lTopPosR_.y = LeftTopRotatedR_y + LegPosR_.y;
	lBottomPosR_.x = LeftBottomRotatedR_x + LegPosR_.x;
	lBottomPosR_.y = LeftBottomRotatedR_y + LegPosR_.y;
	rTopPosR_.x = RightTopRotatedR_x + LegPosR_.x;
	rTopPosR_.y = RightTopRotatedR_y + LegPosR_.y;
	rBottomPosR_.x = RightBottomRotatedR_x + LegPosR_.x;
	rBottomPosR_.y = RightBottomRotatedR_y + LegPosR_.y;

	lTopL_.x = -GetInfo::GetPlayerSpriteRadius();
	rTopL_.x = GetInfo::GetPlayerSpriteRadius();
	lBottomL_.x = -GetInfo::GetPlayerSpriteRadius();
	rBottomL_.x = GetInfo::GetPlayerSpriteRadius();
	lTopL_.y = -GetInfo::GetPlayerSpriteRadius();
	rTopL_.y = -GetInfo::GetPlayerSpriteRadius();
	lBottomL_.y = GetInfo::GetPlayerSpriteRadius();
	rBottomL_.y = GetInfo::GetPlayerSpriteRadius();


	float LeftTopRotated_x = float(lTopL_.x * cosf(thetaL_) - lTopL_.y * sinf(thetaL_));
	float LeftTopRotated_y = lTopL_.y * cosf(thetaL_) + lTopL_.x * sinf(thetaL_);
	float LeftBottomRotated_x = lBottomL_.x * cosf(thetaL_) - lBottomL_.y * sinf(thetaL_);
	float LeftBottomRotated_y = lBottomL_.y * cosf(thetaL_) + lBottomL_.x * sinf(thetaL_);
	float RightTopRotated_x = rTopL_.x * cosf(thetaL_) - rTopL_.y * sinf(thetaL_);
	float RightTopRotated_y = rTopL_.y * cosf(thetaL_) + rTopL_.x * sinf(thetaL_);
	float RightBottomRotated_x = rBottomL_.x * cosf(thetaL_) - rBottomL_.y * sinf(thetaL_);
	float RightBottomRotated_y = rBottomL_.y * cosf(thetaL_) + rBottomL_.x * sinf(thetaL_);

	lTopPos_.x = LeftTopRotated_x + LegPosL_.x;
	lTopPos_.y = LeftTopRotated_y + LegPosL_.y;
	lBottomPos_.x = LeftBottomRotated_x + LegPosL_.x;
	lBottomPos_.y = LeftBottomRotated_y + LegPosL_.y;
	rTopPos_.x = RightTopRotated_x + LegPosL_.x;
	rTopPos_.y = RightTopRotated_y + LegPosL_.y;
	rBottomPos_.x = RightBottomRotated_x + LegPosL_.x;
	rBottomPos_.y = RightBottomRotated_y + LegPosL_.y;

#ifdef DEBUG
	Novice::ScreenPrintf(0, 700, "%d", LegDigreeL_);
#endif // _DEBUG


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
	this->shake_.x = 0;
	this->shake_.y = 0;
	this->direction_ = 1;
}

Player::~Player()
{
	
}
