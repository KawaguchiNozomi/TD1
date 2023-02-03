#pragma once
#include <stdio.h>
#include <Novice.h>
#include "GetInfo.h"
#include "Particle.h"
class Modes:public Particle
{
private:
	static const int mapHeight_ = 11;
	static const int mapWidth_ = 30;
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
	void SetClearFlag(int flag);
	void MapCollision();
	int GetPlayerSpeedY() { return playerYSpeed_; }
	int GetIsStand() { return isCollide_.y; }
	int GetColloideX() { return isCollide_.x; }
	int GetPlayerPosY() {return playerMapPosY_;}
	int GetStandLevel() { return playerStandLevel_; }
	int GetWhereStand() { return whereStand_; }
	int GetNowWorld() { return nowSelect2_; }
	int GetRemoveSelect() { return removeSelect; }
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
		/// ��ԁ@�O
		/// </summary>
		NONE,
		/// <summary>
		/// �u���b�N�@�P
		/// </summary>
		BLOCK,
		/// <summary>
		/// �ŏ��@������Ǝ��ʁ@�Q
		/// </summary>
		ACID,
		/// <summary>
		/// �����ā@�R
		/// </summary>
		LIGHTCAGE,
		/// <summary>
		/// �n�ʁ@�S
		/// </summary>
		EARTH,
		/// <summary>
		/// �S�[���Q�[�g
		/// </summary>
		CLEARGATE,
		/// <summary>
		/// ������Ǝ���
		/// </summary>
		BLADE
	};
	int map_[mapHeight_][mapWidth_];
private:
	//�Z���N�g����
	int select1R_ = Novice::LoadTexture("./Resouce/stageSelect.png");
	int selectColorR_ = WHITE;
	int nowSelect1_ = ROAD;
	int nowSelect2_= world1;

	//�}�b�v���
	int blockSize_ = GetInfo::GetBlockSize();
	int scrollX = 0;
	int clearFlag_ = false;
	int block_ = Novice::LoadTexture("./Resouce/block.png");
	int acid_= Novice::LoadTexture("./Resouce/acid.png");
	int lightCage_ = Novice::LoadTexture("./Resouce/lightCage.png");
	int earth_ = Novice::LoadTexture("./Resouce/map4.png");
	int blead_ = Novice::LoadTexture("./Resouce/map6.png");
	//���C�g

	//�v���C���[�̈ʒu���
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

