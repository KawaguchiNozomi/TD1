#pragma once
#include "Particle.h"
#include "GetInfo.h"
class OfficerParticle:public Particle
{
public:
	void FireUpdate(int x);
	void FireDraw(int x);
	void CubeUpdate(int x);
	void CubeDraw(int x);
	OfficerParticle();
private:
	static const int fireMax_ = 50;
	Dust fire_[fireMax_];
	static const int cubeMax_ = 90;
	Dust cube_[cubeMax_];
	float cubeGravity = 9.8;
	float cubeAccel_[cubeMax_];
	float k_ = 0.6;
	float cubeMass_ = 2;
	int cubeCoolTime_ = 0;
	int cubeSprite_ = Novice::LoadTexture("./Resouce/cube.png");
};

