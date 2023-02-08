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
	Novice::SetBlendMode(BlendMode::kBlendModeNormal);
	float x_[playerDustMax_];
	for (int i = 0; i < playerDustMax_; i++) {
		x_[i] = playerDust_[i].x - sclX;
		//Novice::SetBlendMode(BlendMode::kBlendModeAdd);
		Novice::DrawEllipse(x_[i], playerDust_[i].y, playerDust_[i].size, playerDust_[i].size, 0, playerDust_[i].color.color, kFillModeSolid);
	}
	Novice::SetBlendMode(BlendMode::kBlendModeNormal);
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
	for (int i = 0; i < playerDeadMistMax_; i++) {
		if (playerDeadMist_[i].isArrive == false && playerDeadMist_[i].oneTimeArrive == false) {
			playerDeadMist_[i].color.R = 255; playerDeadMist_[i].color.G = 255; playerDeadMist_[i].color.B = 255; playerDeadMist_[i].color.A = 200;
			playerDeadMist_[i].x = playerX-deadMistSize_/2;
			playerDeadMist_[i].y = playerY - deadMistSize_ / 2;
			playerDeadMist_[i].move.start.x = playerX;
			playerDeadMist_[i].move.start.y = playerY;
			playerDeadMist_[i].move.t = 0;
			playerDeadMist_[i].move.theta = DegreeToRadian(rand() % 360);
			playerDeadMist_[i].move.target.x = (100 * cosf(playerDeadMist_[i].move.theta) - 100 * sinf(playerDeadMist_[i].move.theta)) + playerX;
			playerDeadMist_[i].move.target.y = (100 * cosf(playerDeadMist_[i].move.theta) + 100 * sinf(playerDeadMist_[i].move.theta)) + playerY;
			playerDeadMist_[i].size = RandomRange(9, 10)/10;
			playerDeadMist_[i].isArrive = true;
		}
		if (playerDeadMist_[i].isArrive == true) {
			playerDeadMist_[i].color.A -= 5;
			playerDeadMist_[i].color.color=SetColorReturn(playerDeadMist_[i].color.color, playerDeadMist_[i].color.R, playerDeadMist_[i].color.G, playerDeadMist_[i].color.B, playerDeadMist_[i].color.A);
			playerDeadMist_[i].move.t += 0.005;
			playerDeadMist_[i].x = (1.0 - playerDeadMist_[i].move.t) * playerDeadMist_[i].move.start.x + playerDeadMist_[i].move.t * playerDeadMist_[i].move.target.x;
			playerDeadMist_[i].y = (1.0 - playerDeadMist_[i].move.t) * playerDeadMist_[i].move.start.y + playerDeadMist_[i].move.t * playerDeadMist_[i].move.target.y;
			if (playerDeadMist_[i].color.A <= 0) {
				playerDeadMist_[i].color.A = 0;
				playerDeadMist_[i].oneTimeArrive = true;
				playerDeadMist_[i].isArrive = false;
			}
			if (playerDeadMist_[i].move.t >= 0.5) {
				playerDeadMist_[i].oneTimeArrive = true;
				playerDeadMist_[i].isArrive = false;
			}
		}
	}
}

void PlayerParticle::PlayerDeadDraw()
{
	for (int i = 0; i < playerDeadMax_; i++)
	{
		if (playerDead_[i].isArrive == true) {
			Novice::DrawEllipse(playerDead_[i].x, playerDead_[i].y, playerDead_[i].radius, playerDead_[i].radius, 0, RED, kFillModeSolid);
		}
	}
	for (int i = 0; i < playerDeadMistMax_; i++) {
		Novice::SetBlendMode(BlendMode::kBlendModeAdd);
		if (playerDeadMist_[i].isArrive == true) {
			Novice::DrawSprite(playerDeadMist_[i].x, playerDeadMist_[i].y, deadMist_, (float)playerDeadMist_[i].size, (float)playerDeadMist_[i].size, 0, playerDeadMist_[i].color.color);
		}
		Novice::SetBlendMode(BlendMode::kBlendModeNormal);
	}
}

