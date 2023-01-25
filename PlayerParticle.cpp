#include "PlayerParticle.h"

void PlayerParticle::PlayerDust(int playerX, int playerY, int level, char* keys)
{
	for (int i = 0; i < playerDustMax_; i++) {
		if (playerDust_[i].isArrive == false) {
			playerDust_[i].x = playerX;
			playerDust_[i].y = level + 10;
			playerDust_[i].color.A = 255;
			playerDust_[i].size = 3;
			playerDust_[i].color.B = 255;
			playerDust_[i].color.R = 255;
			playerDust_[i].color.G = 255;
			playerDust_[i].speedY = rand() % 6 - 1;
			playerDust_[i].count = 0;
			playerDust_[i].isArrive = true;
			break;
		}

	}
	for (int i = 0; i < playerDustMax_; i++) {
		if (playerDust_[i].isArrive == true) {
			playerDust_[i].color.A -= 30;
			playerDust_[i].count++;
			playerDust_[i].y -= playerDust_[i].speedY;
			if (playerDust_[i].color.A <= 0) {
				playerDust_[i].color.A = 0;
			}
			SetColor(playerDust_[i].color.color, playerDust_[i].color.R, playerDust_[i].color.G, playerDust_[i].color.B, playerDust_[i].color.A);
			if (playerDust_[i].count >= 9) {
				playerDust_[i].isArrive = false;
			}

		}
		if (keys == 0) {
			playerDust_[i].isArrive = false;
		}
	}
}

void PlayerParticle::PlayerDustDraw(float x, float y, float sclX, float sclY)
{
	float x_[playerDustMax_];
	for (int i = 0; i < playerDustMax_; i++) {
		x_[i] = playerDust_[i].x - sclX;
		//Novice::SetBlendMode(BlendMode::kBlendModeAdd);
		Novice::DrawEllipse(x_[i], playerDust_[i].y, playerDust_[i].size, playerDust_[i].size, 0, playerDust_[i].color.color, kFillModeSolid);
		Novice::SetBlendMode(BlendMode::kBlendModeNormal);
	}
}

void PlayerParticle::SetPlayerDustIsArriveFalse()
{
	for (int i = 0; i < playerDustMax_; i++) {
		playerDust_[i].isArrive = false;
	}
}

void PlayerParticle::PlayerDead(int playerX, int playerY)
{
	for (int i = 0; i < playerDeadMax_; i++) {
		if (playerDead_[i].isArrive == false) {
			playerDead_[i].x = playerX;
			playerDead_[i].y = playerY;
			playerDead_[i].speedY = rand() % 5 + 15;
			playerDead_[i].speedX = rand() % 10 - 5;
			playerDead_[i].radius = rand() % 6 + 4;
			playerDead_[i].isArrive = true;
		}
		if (playerDead_[i].isArrive == true) {
			playerDead_[i].y -= playerDead_[i].speedY;
			playerDead_[i].x -= playerDead_[i].speedX;
			playerDead_[i].speedY -= 1;

		}
	}
}

void PlayerParticle::PlayerDeadDraw()
{
	for (int i = 0; i < playerDeadMax_; i++)
	{
		Novice::DrawEllipse(playerDead_[i].x, playerDead_[i].y, playerDead_[i].radius, playerDead_[i].radius, 0, RED, kFillModeSolid);
	}
}

