#pragma once
#include <stdio.h>
#include <Novice.h>
#include "GetInfo.h"
#include "Particle.h"
class Modes:public Particle
{
private:
	static const int mapHeight_ = 11;
	static const int mapWidth_ = 100;
	static const int worldWidth1_ = 30;
	static const int worldWidth2_ = 40;
	int worldWidth_;
public:
	void SelectDraw();
	void SelectUpdate(char*keys,char*preKeys);
	void Map1();
	void Map2();
	void SetMap();
	int GetMapInfo(int a);
	void MapDraw();
	void SetMapScrollX(int x);
	void SetPlayerPos(int posX,int posY);
	void SetClearFlag(bool flag);
	void SetShake(int shakeX, int shakeY);
	void MapCollision(char*keys);
	int GetPlayerSpeedY() { return playerYSpeed_; }
	int GetIsStand() { return isCollide_.y; }
	int GetColloideX() { return isCollide_.x; }
	int GetPlayerPosY() {return playerMapPosY_;}
	int GetStandLevel() { return playerStandLevel_; }
	int GetWhereStand() { return whereStand_; }
	int GetNowWorld() { return nowSelect2_; }
	int GetRemoveSelect() { return removeSelect; }
	int GetWorldWidth() { return worldWidth_; }
	Modes();

	enum Mode
	{
		ROAD,
		BOSS
	};
	enum World
	{
		/// <summary>
		/// 0
		/// </summary>
		world1,
		world2
	};
	enum MapInfo 
	{
		/// <summary>
		/// 空間　０
		/// </summary>
		NONE,
		/// <summary>
		/// ブロック　１
		/// </summary>
		BLOCK,
		/// <summary>
		/// 毒沼　当たると死ぬ　２
		/// </summary>
		ACID,
		/// <summary>
		/// 光の籠　３
		/// </summary>
		LIGHTCAGE,
		/// <summary>
		/// 地面　４
		/// </summary>
		EARTH,
		/// <summary>
		/// ゴールゲート
		/// </summary>
		CLEARGATE,
		/// <summary>
		/// 当たると死ぬ
		/// </summary>
		BLADE
	};
	int map_[mapHeight_][mapWidth_];
	//横の長さ
private:
	int shakeX_ = 0;
	int shakeY_ = 0;
	//セレクト処理
	int manualButton_ = Novice::LoadTexture("./Resouce/manualButton.png");
	int select1R_ = Novice::LoadTexture("./Resouce/stageSelect1.png");
	int select2R_ = Novice::LoadTexture("./Resouce/stageSelect2.png");
	int title_ = Novice::LoadTexture("./Resouce/titleb.png");
	int selectColor1_ = 0xFFFF00FF;
	int selectColor2_ = WHITE;
	int nowSelect1_ = ROAD;
	int nowSelect2_= world1;

	//マップ情報
	int blockSize_ = GetInfo::GetBlockSize();
	int scrollX = 0;
	int clearFlag_ = false;
	int block_ = Novice::LoadTexture("./Resouce/block.png");
	int acid_= Novice::LoadTexture("./Resouce/acid.png");
	int lightCage_ = Novice::LoadTexture("./Resouce/lightCage.png");
	int earth_ = Novice::LoadTexture("./Resouce/map4.png");
	int clearGate_=Novice::LoadTexture("./Resouce/map5.png");
	int blead_ = Novice::LoadTexture("./Resouce/map6.png");
	int time_=0;
	Vector2 difrection_ = {1,1};
	//ライト

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
	int removeSelect = false;

public:
	void CageLigthUpdate();
	void SetCageLigthOn(int posX, int posY);
	void SetTouched(int posX, int posY);
	int GetIsTouced() { return touched_.isTouched; }
	struct Touch
	{
		Vector2 savePos = { 0,0 };
		int isTouched = false;
	};
private:
	static const int cageLigthMax_ = 10;
	Dust cageLigth_[cageLigthMax_];
	int cageLigthSprite = Novice::LoadTexture("./Resouce/howa.png");
	Touch touched_;
};

