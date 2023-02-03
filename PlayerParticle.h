#pragma once
#include "Particle.h"
class PlayerParticle:public Particle
{
public:
	/// <summary>
	/// ëñÇÈÇ∆Ç´Ç…èoÇÈÇŸÇ±ÇË
	/// </summary>
	/// <param name="playerX"></param>
	/// <param name="playerY"></param>
	/// <param name="level"></param>
	/// <param name="keys"></param>
	void PlayerDust(int playerX, int playerY, int level, char* keys);
	void PlayerDustDraw(float x, float y, float sclX, float sclY);
	void SetPlayerDustIsArriveFalse();
	void PlayerDead(int playerX, int playerY);
	void PlayerDeadDraw();

private:
	static const int playerDustMax_ = 10;
	static const int playerDeadMax_ = 15;
	static const int playerDeadMistMax_ = 20;
	Dust playerDust_[playerDustMax_];
	Dust playerDead_[playerDeadMax_];
	Dust playerDeadMist_[playerDeadMistMax_];
	int deadMist_ = Novice::LoadTexture("./Resouce/howa.png");
	static const int deadMistSize_ = 32;
};

