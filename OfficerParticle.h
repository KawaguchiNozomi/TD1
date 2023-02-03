#pragma once
#include "Particle.h"
#include "GetInfo.h"
class OfficerParticle:public Particle
{
public:
	void FireUpdate(int x);
	void FireDraw(int x);
	OfficerParticle();
private:
	static const int fireMax_ = 50;
	Dust fire_[fireMax_];
};

