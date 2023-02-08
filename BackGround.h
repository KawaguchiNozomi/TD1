#pragma once
#include <Novice.h>
#include "BackGroundParticle.h"
class BackGround
{
//������1000�c720 �n��512
public:
	void Draw();
	void SelectBackDraw();
	void TitleBackDraw();
	void ManualBackDraw();
    void SetMode(int world);
	void SetScroll(int scrollX);
private:
	int whereWorld_;
	int scroll_ = 0;
	int back_[2] = { Novice::LoadTexture("./Resouce/Back1.png"),
	                 Novice::LoadTexture("./Resouce/Back2.png")};
	int manual_ =  Novice::LoadTexture("./Resouce/manual.png") ;
	BackGroundParticle* particle_ = new BackGroundParticle;
};

