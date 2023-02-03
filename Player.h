#pragma once
#include "PlayerParticle.h"
#include "GetInfo.h"
#include "Modes.h"
#include "PlayerDeadHead.h"
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
	void SetSpeedY(int y);
	void SetPosY(int posY);
	void SetStandLevel(int standlevel);
	void SetWhereStand(int block);
	void SetIsArrave(int isArrive);
	void SetColloideX(int colloideX);
	void Reset();
	void TranslateHead();
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
	//プレイヤー外見
	int playerSpriteHead_ = Novice::LoadTexture("./Resouce/playerHead.png");
	int playerSpriteBody_ = Novice::LoadTexture("./Resouce/playerBody.png");
	Vector2 headPos_;
	float headTheta_;
	int bladeDying = false;
	PlayerParticle* particle_ = new PlayerParticle;
	PlayerDeadHead* deadHead_ = new PlayerDeadHead;
};

