#pragma once
#include <Novice.h>
#include "GetInfo.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Function.h"
class PlayerDeadHead
{
public:
	void Update();
	void Draw(int direction);
	void SetStart(int x,int y);
	int GetShakeX() { return Shake_.x; }
	int GetShakeY() { return Shake_.y; }
	void SetShakeRange(int x,int y);
	void Shake();
private:
	typedef struct Vector2 {
		int x;
		int y;
	};
	Vector2 headCenter_;
	Vector2 rTop_;
	Vector2 lTop_;
	Vector2 rBottom_;
	Vector2 lBottom_;
	Vector2 rTopPos_;
	Vector2 lTopPos_;
	Vector2 rBottomPos_;
	Vector2 lBottomPos_;
	Vector2 speed_;
	Vector2 unsignedSpeed_;
	Vector2 direction_ = { -1,-1 };
	Vector2 Shake_={0,0};
	Vector2 ShakeRange_ = { 5,5 };
	float theta_ = 0;
	float rotateSpeed_ = (1.0 / 64.0) * M_PI;
	int sprite_ = Novice::LoadTexture("./Resouce/PlayerNewDeadHead.png");
	int counter_ = 0;
	int rollingTime_ = 0;
	bool stop_ = false;
};

