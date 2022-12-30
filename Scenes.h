#pragma once
#include "Modes.h"
#include "Player.h"
class Scenes
{
public:
	void Update(char keys[], char prekeys[]);
	void Draw();

private:
	enum Scene
	{
		TITLE,
		SELECT,
		PLAY
	};
	Scene scene_ = TITLE;

	Modes* mode_;
	Player* player_;

};

