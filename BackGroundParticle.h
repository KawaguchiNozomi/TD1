#pragma once
#include "Particle.h"
class BackGroundParticle:public Particle
{
public:
	void Howa();
	void Title();
private:
	static const int howaMax_ = 5;
	Dust howa_[howaMax_];
	int titleImage_ = Novice::LoadTexture("./Resouce/title.png");
	Dust title_[5];
	int titleTime_=0;

};

