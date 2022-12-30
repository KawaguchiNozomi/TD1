#pragma once
class Player
{
public:
	void Update(char* keys, char* prekeys);
	void Draw();
	Player();
	~Player();

	int isArrave_;
	int x_;
	int y_;
	int xSpeed_;
	int ySpeed_;
};

