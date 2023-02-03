#pragma once
#include <Novice.h>
#include "GetInfo.h"
class PlayerDeadHead
{
public:
	void Update();
	void Draw();
	void SetStart(int x,int y);
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
	Vector2 speed_;
	Vector2 unsignedSpeed_;
	Vector2 direction_ = { -1,-1 };
	int sprite_ = Novice::LoadTexture("./Resouce/PlayerDeadHead.png");
	int counter_ = 0;
	bool stop_ = false;
};

