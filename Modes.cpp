#include "Modes.h"
#include <Novice.h>

void Modes::SelectDraw()
{
	Novice::DrawSprite(200, 200, select1R_, 1, 1, 0, selectColorR_);
}

void Modes::SelectUpdate(char* keys, char* preKeys)
{
	if (keys[DIK_UP] || keys[DIK_W]) {
		selectColorR_ = 0xFFFF00FF;
		nowSelect1_ = ROAD;
	}
	if (keys[DIK_DOWN] || keys[DIK_S]) {
		selectColorR_ = WHITE;
		nowSelect1_ = BOSS;
	}
}

void Modes::SetMap()
{
	if (nowSelect1_ == ROAD && nowSelect2_ == world1) {
		Map1();
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
	return 0;
}

void Modes::MapDraw()
{
	for (int y = 0; y < GetInfo::GetMapHeigth(); y++) {
		for (int x = 0; x < GetInfo::GetMapWidth(); x++) {
			int posX = (x * GetInfo::GetBlockSize());
			if (map_[y][x] == BLOCK) {
				Novice::DrawSprite(posX, y * GetInfo::GetBlockSize(), GetMapInfo(1), 1, 1, 0, WHITE);
			}
			if (map_[y][x] == ACID) {
				Novice::DrawSprite(posX, y * GetInfo::GetBlockSize(), GetMapInfo(2), 1, 1, 0, WHITE);
			}
		}
	}
}

void Modes::Map1()
{
	int map1[mapHeight_][mapWidth_] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	for (int i = 0; i < mapHeight_; i++) {
		for (int j = 0; j < mapWidth_; j++) {
			map_[i][j] = map1[i][j];
		}
	}
}


Modes::Modes()
{
	this->select1R_;
}
