#pragma once
#include "Particle.h"
#include "Modes.h"
#include "GetInfo.h"
class Player :public Modes
{
public:
	void Update(char* keys, char* prekeys);
	void Draw(char*keys);
	void ToScreen();
	int GetScrollX() { return scrollX_; }
	Player();
	~Player();

private:
	int isArrave_;
	int x_;
	int y_;
	int scrollX_;
	int scrollY_;
	int screenX_;
	int screenY_;
	int xSpeed_;
	int ySpeed_;
	int baseLevel_ = 8 * GetInfo::GetBlockSize(); //èâä˙çÇìx
	int rightEnd_ = GetInfo::GetMapWidth() * GetInfo::GetBlockSize();
	Particle* particle_ = new Particle;
	Modes* mode_ = new Modes;
};

