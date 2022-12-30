#include "Scenes.h"
#include "Player.h"
#include <Novice.h>

void Scenes::Update(char keys[],char prekeys[])
{
	switch (scene_)
	{
	case Scenes::TITLE:
		if (keys[DIK_SPACE]) {
			scene_ = SELECT;
		}
		break;
	case Scenes::SELECT:
		if (keys[DIK_A]) {
			scene_ = PLAY;
			player_ = new Player;
		}
		break;
	case Scenes::PLAY:
		player_->Update(keys, prekeys);
		break;
	default:
		break;
	}
}

void Scenes::Draw()
{
	switch (scene_)
	{
	case Scenes::TITLE:
		Novice::DrawBox(0, 0, 100, 100, 0, WHITE, kFillModeSolid);
		break;
	case Scenes::SELECT:
		Novice::DrawBox(0, 0, 100, 100, 0, BLUE, kFillModeSolid);
		break;
	case Scenes::PLAY:
		Novice::DrawBox(0, 0, 100, 100, 0, RED, kFillModeSolid);
		player_->Draw();
		break;
	default:
		break;
	}
}
