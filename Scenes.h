#pragma once
#include "Modes.h"
#include "Player.h"
//#include "MapParticle.h"
#include "Officer.h"
#include "BackGround.h"
#include <Novice.h>
class Scenes
{
public:
	void Update(char keys[], char prekeys[]);
	void Draw(char*keys);

private:
	enum Scene
	{
		TITLE,
		SELECT,
		PLAY,
		MANUAL
	};
	Scene scene_ = TITLE;

	enum Pause {
		PAUSEON,
		PAUSEOFF
	};
	Pause pause_ = PAUSEOFF;
	Modes* mode_=new Modes;
	Player* player_;
	//CageParticle* cage_ = new CageParticle;
	Officer* officer_ = new Officer;
	BackGround* backGround_ = new BackGround;
	int playerHead_ = Novice::LoadTexture("./Resouce/playerHeadx3.png");
	int playerEye_[3] = { Novice::LoadTexture("./Resouce/playerEyex3.png"),
	Novice::LoadTexture("./Resouce/playerEye2x3.png"),
	Novice::LoadTexture("./Resouce/playerEye3x3.png")};
	int warning_ =Novice::LoadTexture("./Resouce/warning.png");
	int eye_ = 0;

};

