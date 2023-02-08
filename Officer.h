#pragma once
#include "Novice.h"
#include "GetInfo.h"
#include "Function.h"
#include "OfficerParticle.h"
class Officer
{
public:
	void Update(char* keys);
	void SetMode(int world);
	void SetScrollPos(int x);
	void SetPlayerPos(int x, int y);
	void SetActiveFalse() { isActive_ = false; }
	void Colloide(int posX,int posY,int radius);
	int GetFlag() { return clearFlag_; }
	Officer();
	~Officer();
private:
	void FolestOfficer();
	void CityOfficer();
	struct Vector2
	{
		int x;
		int y;
	};
	Vector2 pos_;
	Vector2 playerPos_;
	int scrollPos_;
	int isArrive_;
	int isActive_ = false;
	int inColloide = false;
	int radius_ = GetInfo::GetBlockSize();
	int whereWorld_;
	int officer_[2] = { Novice::LoadTexture("./Resouce/officer.png"),
	                    Novice::LoadTexture("./Resouce/officer2.png")};
	int officerAct_[2] = { Novice::LoadTexture("./Resouce/officer_act.png"),
	                       Novice::LoadTexture("./Resouce/officer2_act.png")};
	bool clearFlag_ = false;
	OfficerParticle* particle_ = new OfficerParticle;

};

