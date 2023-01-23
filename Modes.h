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
		ACID
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
	int block_ = Novice::LoadTexture("./Resouce/block.png");
	int acid_= Novice::LoadTexture("./Resouce/acid.png");
	
};

