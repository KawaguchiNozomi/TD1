#pragma once
#include "Modes.h"
#include "Player.h"
//#include "MapParticle.h"
#include "Officer.h"
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
		PLAY
	};
	Scene scene_ = TITLE;

	Modes* mode_=new Modes;
	Player* player_;
	//CageParticle* cage_ = new CageParticle;
	Officer* officer_ = new Officer;

};

