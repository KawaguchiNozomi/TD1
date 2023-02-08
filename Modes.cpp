#include "Modes.h"
#include <Novice.h>

void Modes::SelectDraw()
{
	Novice::DrawSprite(0, 0, manualButton_, 1, 1, 0, WHITE);
	Novice::DrawSprite(350, 200, select1R_, 1, 1, 0, selectColor1_);
	Novice::DrawSprite(350, 400, select2R_, 1, 1, 0, selectColor2_);
	Novice::DrawSprite(20, 650, title_, 1, 1, 0, WHITE);
}

void Modes::SelectUpdate(char* keys, char* preKeys)
{
	if (keys[DIK_UP] || keys[DIK_W]) {
		selectColor1_ = 0xFFFF00FF;
		selectColor2_ = WHITE;
		nowSelect2_ = world1;
	}
	if (keys[DIK_DOWN] || keys[DIK_S]) {
		selectColor1_ = WHITE;
		selectColor2_ = 0xFFFF00FF;
		nowSelect2_ = world2;
	}
}

void Modes::SetMap()
{
	if (nowSelect1_ == ROAD && nowSelect2_ == world1) {
		Map1();
	}
	if (nowSelect1_ == ROAD && nowSelect2_ == world2) {
		Map2();
	}
}

int Modes::GetMapInfo(int a)
{
	if (a == 1) {
		return block_;
	}
	if (a == 2) {
		return acid_;
	}
	if (a == 3) {
		return lightCage_;
	}
	if (a == 4) {
		return earth_;
	}
	if (a == 5) {
		return clearGate_;
	}
	if (a == 6) {
		return blead_;
	}
	return 0;
}

void Modes::MapDraw()
{
	time_++;
	if (time_ == 0) {
		difrection_.x = 1;
		difrection_.y = 1;
	}
	if (time_ == 7) {
		difrection_.x = 1;
		difrection_.y = -1;
	}
	if (time_ == 14) {
		difrection_.x = -1;
		difrection_.y = 1;
	}
	if (time_ == 21) {
		difrection_.x = -1;
		difrection_.y = -1;
	}
	if (time_ == 28) {
		time_ = 0;
	}
	for (int y = 0; y < GetInfo::GetMapHeigth(); y++) {
		for (int x = 0; x < GetInfo::GetMapWidth(); x++) {
			int posX = (x * GetInfo::GetBlockSize())-scrollX;
			if (map_[y][x] == BLOCK) {
				Novice::DrawSprite(posX+shakeX_, y * GetInfo::GetBlockSize() + shakeY_, GetMapInfo(1), 1, 1, 0, WHITE);
			}
			if (map_[y][x] == ACID) {
				Novice::DrawSprite(posX+shakeX_, y * GetInfo::GetBlockSize() + shakeY_, GetMapInfo(2), 1, 1, 0, WHITE);
			}
			if (map_[y][x] == LIGHTCAGE) {
				if (touched_.isTouched == true) {
					CageLigthUpdate();
				}
				Novice::DrawSprite(posX+shakeX_, y * GetInfo::GetBlockSize() + shakeY_, GetMapInfo(3), 1, 1, 0, WHITE);
			}
			if (map_[y][x] == EARTH) {
				Novice::DrawSprite(posX+shakeX_, y * GetInfo::GetBlockSize() + shakeY_, GetMapInfo(4), 1, 1, 0, WHITE);
			}
			if (map_[y][x] == CLEARGATE) {
				Novice::DrawSprite(posX+shakeX_, y* GetInfo::GetBlockSize() + shakeY_, GetMapInfo(5), 1, 1, 0, WHITE);
			}
			if (map_[y][x] == BLADE) {
				Novice::DrawSprite(posX+shakeX_, y * GetInfo::GetBlockSize() + shakeY_, GetMapInfo(6), 1 , 1, 0, WHITE);
			}
		}
	}
   #ifdef DEBUG
	   Novice::ScreenPrintf(0, 100, "x=%d,y=%d,level=%d,x=%d", playerMapPosX_, playerMapPosY_, playerStandLevel_, playerPosX_);
	   Novice::ScreenPrintf(0, 160, "Flag=%d shake=%d,%d", clearFlag_,shakeX_,shakeY_);
   #endif // _DEBUG

	
}

void Modes::SetMapScrollX(int x)
{
	scrollX = x;
}

void Modes::SetPlayerPos(int posX,int posY)
{
	playerPosX_ = posX;
	playerPosY_ = posY;
}

void Modes::SetClearFlag(bool flag)
{
	clearFlag_ = flag;
}

void Modes::SetShake(int shakeX, int shakeY)
{
	shakeX_ = shakeX;
	shakeY_ = shakeY;
}

void Modes::MapCollision(char*keys)
{
	playerMapPosX_ = playerPosX_ / 64;
	playerMapPosY_ = playerPosY_ / 64;
	for (int y = 0; y < GetInfo::GetMapHeigth(); y++) {
		if (map_[playerMapPosY_][playerMapPosX_] == LIGHTCAGE) {
				if (touched_.isTouched == false) {
			SetCageLigthOn(playerPosX_, playerPosY_);
			SetTouched(playerMapPosX_, playerMapPosY_);
					break;
				
			}
		}
	}
	for (int y = 0; y < GetInfo::GetMapHeigth(); y++) {
		if (map_[y][playerMapPosX_] == BLOCK|| map_[y][playerMapPosX_] == EARTH) {
			playerStandLevel_ = y * 64;
			if (y >= playerMapPosY_) {
				break;
			}
		}
	}
	isCollide_.x = false;
	if (map_[playerMapPosY_][playerMapPosX_] == BLOCK) {
		playerYSpeed_ = 0;
		isCollide_.y = true;
		whereStand_ = 1;
	}
	else if (map_[playerMapPosY_][playerMapPosX_] == ACID) {
		isCollide_.y = false;
		whereStand_ = 2;
	}
	else if (map_[playerMapPosY_][playerMapPosX_] == EARTH) {
		playerYSpeed_ = 0;
		isCollide_.y = true;
		whereStand_ = 1;
	}
	else if (map_[playerMapPosY_][playerMapPosX_] == BLADE) {
		isCollide_.y = false;
		whereStand_ = 3;
	}
	else {
		whereStand_ = 0;
		isCollide_.y = false; }
	if (playerMapPosY_ > 1) {
		if (map_[playerMapPosY_ - 1][playerMapPosX_] == CLEARGATE) {
			if (clearFlag_ == true) {
				if (keys[DIK_Z] || keys[DIK_RETURN]) {
					removeSelect = true;
				}
			}
		}
	}
	/*if (map_[playerMapPosY_][playerMapPosX_ + 1] == BLOCK) {
		isCollide_.x = true;
	}*/
}


void Modes::Map1()
{
	worldWidth_ = worldWidth1_;
	int map1[mapHeight_][worldWidth1_] = { 
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0},
		{4,4,4,4,4,2,2,4,2,2,4,2,2,4,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	for (int i = 0; i < mapHeight_; i++) {
		for (int j = 0; j < mapWidth_; j++) {
			map_[i][j] = map1[i][j];
		}
	}
}

void Modes::Map2()
{
	worldWidth_ = worldWidth2_;
	int map2[mapHeight_][worldWidth2_] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,6,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0},
		{0,0,0,0,0,0,0,0,0,6,0,0,6,0,0,0,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
		{0,0,0,0,0,0,0,0,0,0,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0},
		{4,4,4,4,4,2,2,4,2,2,4,2,2,4,2,4,4,6,4,6,4,6,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	for (int i = 0; i < mapHeight_; i++) {
		for (int j = 0; j < mapWidth_; j++) {
			map_[i][j] = map2[i][j];
		}
	}
}



Modes::Modes()
{
	this->touched_.isTouched = false;
	this->removeSelect = false;
	this->clearFlag_ = false;
	this->shakeX_ = 0;
	this->shakeY_ = 0;
}

void Modes::CageLigthUpdate()
{
	for (int i = 0; i < cageLigthMax_; i++)
	{
		cageLigth_[i].speedX = RandomRange(-3, 3);
		cageLigth_[i].speedY = RandomRange(-3, 3);
		Novice::DrawSprite(cageLigth_[i].x-scrollX + cageLigth_[i].speedX, cageLigth_[i].y + cageLigth_[i].speedY, cageLigthSprite, 1, 1, 0, 0xFFFF00FF);
	}
}

void Modes::SetCageLigthOn(int posX, int posY)
{
	for (int i = 0; i < cageLigthMax_; i++)
	{
		cageLigth_[i].x = posX;
		cageLigth_[i].x = posY;
	}
}

void Modes::SetTouched(int posX, int posY)
{
	touched_.savePos.x = posX;
	touched_.savePos.y = posY;
	touched_.isTouched = true;
}

