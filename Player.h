#pragma once
#include "PlayerParticle.h"
#include "GetInfo.h"
#include "Modes.h"
#include "PlayerDeadHead.h"
#include "Function.h"
class Player
{
public:
	void Update(char* keys, char* prekeys);
	void Draw(char*keys);
	void ToScreen();
	int GetScrollX() { return scrollX_; }
	int GetPosX() { return x_; }
	int GetPosY() { return y_; }
	int GetIsArraive() { return isArrave_; }
	int GetRadius() { return GetInfo::GetPlayerSpriteRadius(); }
	int GetShakeX() { shake_.x = deadHead_->GetShakeX();  return shake_.x; }
	int GetShakeY() { shake_.y = deadHead_->GetShakeY();  return shake_.y; }
	void SetSpeedY(int y);
	void SetPosY(int posY);
	void SetStandLevel(int standlevel);
	void SetWhereStand(int block);
	void SetIsArrave(int isArrive);
	void SetColloideX(int colloideX);
	void SetRightEnd(int width);
	void SetEye(int num);
	void Reset();
	void TranslateHead();
	void TranslateLeg();
	Player();
	~Player();

private:
	typedef struct Vector2
	{
		int x;
		int y;
	};
	int isArrave_;
	int x_;
	int y_;
	int scrollX_;
	int scrollY_;
	int screenX_;
	int screenY_;
	int xSpeed_;
	int ySpeed_;
	int baseLevel_ = 8 * GetInfo::GetBlockSize(); //初期高度
	int standLevel_ = 0;//地面
	int rightEnd_ = GetInfo::GetMapWidth() * GetInfo::GetBlockSize();
	int isPlayerJump_ = 0;
	int whereStand_ = 0;
	int colloideX_ = false;
	Vector2 shake_={0,0};
	//プレイヤー外見
	int playerSpriteHead_ = Novice::LoadTexture("./Resouce/playerNewHead.png");
	int playerSpriteBody_ = Novice::LoadTexture("./Resouce/playerBody.png");
	int playerSpriteLeg_ = Novice::LoadTexture("./Resouce/playerLeg.png");
	int playerSpriteEye_[3] = { Novice::LoadTexture("./Resouce/playerEye.png"),
	                            Novice::LoadTexture("./Resouce/playerEye2.png"),
	Novice::LoadTexture("./Resouce/playerEye3.png") };
	int playerSpriteLegL_ = Novice::LoadTexture("./Resouce/playerLegL.png");
	int playerSpriteLegR_ = Novice::LoadTexture("./Resouce/playerLegR.png");
	int playerSpriteNoLegs_ = Novice::LoadTexture("./Resouce/playerNoLeg.png");
	int bodyCount_ = 0;
	int spriteTime_ = 0;
	Vector2 headPos_;
	float headTheta_;
	int eye_;
	//右足
	Vector2 LegPosR_;
	Vector2 lTopR_;
	Vector2 lBottomR_;
	Vector2 rTopR_;
	Vector2 rBottomR_;
	Vector2 lTopPosR_;
	Vector2 lBottomPosR_;
	Vector2 rTopPosR_;
	Vector2 rBottomPosR_;
	float LegThetaR_;
	int LegDigreeR_=0;
	int digreeSpeedR_=5;
	//左足
	Vector2 LegPosL_;
	Vector2 lTopL_;
	Vector2 lBottomL_;
	Vector2 rTopL_;
	Vector2 rBottomL_;
	Vector2 lTopPos_;
	Vector2 lBottomPos_;
	Vector2 rTopPos_;
	Vector2 rBottomPos_;
	float thetaL_;
	int LegDigreeL_ = 0;
	int digreeSpeedL_ = -5;

	float LegThetaL_;
	int bladeDying = false;
	int direction_ = 1;
	PlayerParticle* particle_ = new PlayerParticle;
	PlayerDeadHead* deadHead_ = new PlayerDeadHead;
};

