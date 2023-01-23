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
		mode_->SelectUpdate(keys,prekeys);
		if (keys[DIK_SPACE]&&prekeys[DIK_SPACE]==0) {
			scene_ = PLAY;
			mode_->SetMap();
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


void Scenes::Draw(char*keys)
{
	Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
	switch (scene_)
	{
	case Scenes::TITLE:
		Novice::DrawBox(0, 0, 100, 100, 0, WHITE, kFillModeSolid);
		break;
	case Scenes::SELECT:
		Novice::DrawBox(0, 0, 100, 100, 0, BLUE, kFillModeSolid);
		mode_->SelectDraw();
		break;
	case Scenes::PLAY:
		Novice::DrawBox(0, 0, 100, 100, 0, RED, kFillModeSolid);
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				Novice::DrawBox(i * 64, j * 64, 64, 64, 0, BLUE, kFillModeWireFrame);
			}
		}
		player_->Draw(keys);
		break;
	default:
		break;
	}
}
