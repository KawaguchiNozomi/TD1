#pragma once
#include <stdio.h>
#include <Novice.h>
#include "GetInfo.h"
class Modes
{
private:
	static const int mapHeight_ = 11;
	static const int mapWidth_ = 30;
public:
	void SelectDraw();
	void SelectUpdate(char*keys,char*preKeys);
	void Map1();
	void SetMap();
	int GetMapInfo(int a);
	void MapDraw();
	void SetMapScrollX(int x);
	void SetPlayerPos(int posX,int posY);
	void MapCollision();
	int GetPlayerSpeedY() { return playerYSpeed_; }
	int GetIsStand() { return isCollide_.y; }
	int GetPlayerPosY() {return playerMapPosY_;}
	int GetStandLevel() { return playerStandLevel_; }
	int GetWhereStand() { return whereStand_; }
	Modes();

	enum Mode
	{
		ROAD,
		BOSS
	};
	enum World
	{
		world1
	};
	enum MapInfo 
	{
		NONE,
		BLOCK,
		ACID,
		LIGHTCAGE
	};
	int map_[mapHeight_][mapWidth_];
private:
	//セレクト処理
	int select1R_ = Novice::LoadTexture("./Resouce/stageSelect.png");
	int selectColorR_ = WHITE;
	int nowSelect1_ = ROAD;
	int nowSelect2_= world1;

	//マップ情報
	int blockSize_ = GetInfo::GetBlockSize();
	int scrollX = 0;
	int block_ = Novice::LoadTexture("./Resouce/block.png");
	int acid_= Novice::LoadTexture("./Resouce/acid.png");
	int lightCage_ = Novice::LoadTexture("./Resouce/lightCage.png");

	//プレイヤーの位置情報
	int playerPosX_;
	int playerPosY_;
	int playerYSpeed_;
	int playerXSpeed_;
	int whereStand_;
	int playerMapPosX_;
	int playerMapPosY_ ;
	int playerStandLevel_;
	struct Vector2
	{
		int x;
		int y;
	};
	Vector2 isCollide_;
	
};

