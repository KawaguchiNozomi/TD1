#pragma once
class Particle
{
public:
	void PlayerDust(int playerX, int playerY, int level,char*keys);
	void PlayerDustDraw(float x, float y, float sclX, float sclY);
	void SetPlayerDustIsArriveFalse();
	Particle();

private:
	struct Color
	{
		unsigned int R;
		unsigned int G;
		unsigned int B;
		unsigned int A;
		unsigned int color;
	};
	struct Dust
	{
		float x;
		float y;
		Color color;
		float size;
		int isArrive = false;
		float speedY;
		int count = 0;
	};
	static const int playerDustMax_ = 10;
	Dust playerDust_[playerDustMax_];

};

