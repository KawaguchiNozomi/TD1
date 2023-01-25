#pragma once
#include "PlayerParticle.h"
#include "GetInfo.h"
#include "Modes.h"
class Player
{
public:
	void Update(char* keys, char* prekeys);
	void Draw(char*keys);
	void ToScreen();
	int GetScrollX() { return scrollX_; }
	int GetPosX() { return x_; }
	int GetPosY() { return y_; }
	void SetSpeedY(int y);
	void SetPosY(int posY);
	void SetStandLevel(int standlevel);
	void SetWhereStand(int block);
	void TranslateHead();
	Player();
	~Player();

private:
	struct Vector2
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
	//プレイヤー外見
	int playerSpriteHead_ = Novice::LoadTexture("./Resouce/playerHead.png");
	int playerSpriteBody_ = Novice::LoadTexture("./Resouce/playerBody.png");
	Vector2 headPos_;
	float headTheta_;
	PlayerParticle* particle_ = new PlayerParticle;
};

