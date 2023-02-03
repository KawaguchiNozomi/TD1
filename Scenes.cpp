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
			officer_->SetMode(mode_->GetNowWorld());
			player_ = new Player;
			//cage_ = new CageParticle;
		}
		break;
	case Scenes::PLAY:
		mode_->SetClearFlag(officer_->GetFlag());
		if (player_->GetIsArraive() == true) {
			mode_->SetPlayerPos(player_->GetPosX(), player_->GetPosY());
			mode_->MapCollision();
			/*if (mode_->GetIsStand() == true) {
				player_->SetSpeedY(mode_->GetPlayerSpeedY());
				player_->SetPosY(mode_->GetPlayerPosY());
			}*/
			player_->SetStandLevel(mode_->GetStandLevel());
			mode_->SetMapScrollX(player_->GetScrollX());
			player_->SetWhereStand(mode_->GetWhereStand());
			player_->SetColloideX(mode_->GetColloideX());
			player_->Update(keys, prekeys);
			officer_->SetPlayerPos(player_->GetPosX(), player_->GetPosY());
			officer_->SetScrollPos(player_->GetScrollX());
		}
		officer_->Colloide(player_->GetPosX(), player_->GetPosY(), player_->GetRadius());
		//Ž€–SŽž
		if (player_->GetIsArraive() == false) {
			if ((keys[DIK_R] && prekeys[DIK_R] == 0)||(keys[DIK_SPACE]&&prekeys[DIK_SPACE]==0)) {
				player_->SetWhereStand(0);
				player_->SetIsArrave(1);
				officer_->SetActiveFalse();
				player_ = new Player;
			}
		}
		if (mode_->GetRemoveSelect() == true) {
			scene_ = SELECT;
		}
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
		mode_->MapDraw();
		//cage_->CageLigthUpdate();
	/*	for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				Novice::DrawBox(i * 64, j * 64, 64, 64, 0, BLUE, kFillModeWireFrame);
			}
		}
		*/
		officer_->Update(keys);
		player_->Draw(keys);
		//Ž€–SŽž
		if (player_->GetIsArraive() == false) {
			Novice::ScreenPrintf(GetInfo::GetWindowWidth() / 2, GetInfo::GetWindowHeight() / 2, "retry to R or SPACE");
		}
		break;
	default:
		break;
	}
}
