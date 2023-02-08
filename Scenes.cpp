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
			officer_ = new Officer;
			officer_->SetMode(mode_->GetNowWorld());
			backGround_->SetMode(mode_->GetNowWorld());
			player_ = new Player;
			player_->SetRightEnd(mode_->GetWorldWidth());
			player_->SetEye(eye_);
			//cage_ = new CageParticle;
		}
		if (keys[DIK_M]&&prekeys[DIK_M]==0) {
			scene_ = MANUAL;
		}
		if (keys[DIK_R] && prekeys[DIK_R] == 0) {
			scene_ = TITLE;
		}
		break;
	case Scenes::PLAY:
	
		mode_->SetPlayerPos(player_->GetPosX(), player_->GetPosY());
		if (player_->GetIsArraive() == true) {
			
			switch (pause_)
			{
			case Scenes::PAUSEOFF:
				mode_->MapCollision(keys);
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
				backGround_->SetScroll(player_->GetScrollX());

				if (keys[DIK_R] && prekeys[DIK_R] == 0) {
					pause_ = PAUSEON;
				}

				break;
			case Scenes::PAUSEON:
				if (keys[DIK_R] && prekeys[DIK_R] == 0) {
					pause_ = PAUSEOFF;
				}
				break;
			default:

				break;
			}
			
		}
		officer_->Colloide(player_->GetPosX(), player_->GetPosY(), player_->GetRadius());
		//Ž€–SŽž
		if (player_->GetIsArraive() == false) {
			mode_->SetShake(player_->GetShakeX(), player_->GetShakeY());
			if ((keys[DIK_R] && prekeys[DIK_R] == 0)||(keys[DIK_SPACE]&&prekeys[DIK_SPACE]==0)) {
				player_->SetWhereStand(0);
				player_->SetIsArrave(1);
				officer_->SetActiveFalse();
				mode_->SetShake(0, 0);
				player_ = new Player;
				player_->SetEye(eye_);
				player_->SetRightEnd(mode_->GetWorldWidth());
			}
		}
		mode_->SetClearFlag(officer_->GetFlag());
		if (mode_->GetRemoveSelect() == true) {
			mode_ = new Modes;
			scene_ = SELECT;
		}
		break;
	case Scenes::MANUAL:
		if (keys[DIK_M] && prekeys[DIK_M] == 0) {
			scene_ = SELECT;
		}
		if ((keys[DIK_D]|| keys[DIK_RIGHT])&&prekeys[DIK_RIGHT]==0 && prekeys[DIK_D] == 0) {
			eye_++;
		}
		if ((keys[DIK_A] || keys[DIK_LEFT])&&prekeys[DIK_A]==0&&prekeys[DIK_LEFT]==0) {
			eye_--;
			}
		if (eye_ < 0) {
			eye_ = 2;
		}
		if (eye_ > 2) {
			eye_ = 0;
		}
		break;
	default:
		break;
	}
}


void Scenes::Draw(char*keys)
{
	//Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
	switch (scene_)
	{
	case Scenes::TITLE:
		backGround_->TitleBackDraw();
		Novice::DrawSprite(20, 620, warning_, 1, 1, 0, WHITE);
		//Novice::DrawBox(0, 0, 100, 100, 0, WHITE, kFillModeSolid);
		break;
	case Scenes::SELECT:
		backGround_->SelectBackDraw();
	//	Novice::DrawBox(0, 0, 100, 100, 0, BLUE, kFillModeSolid);
		mode_->SelectDraw();
		break;
	case Scenes::PLAY:
		backGround_->Draw();
	//	Novice::DrawBox(0, 0, 100, 100, 0, RED, kFillModeSolid);
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
			Novice::DrawBox(GetInfo::GetWindowWidth() / 2 - 60, GetInfo::GetWindowHeight() / 2 - 20, 180, 30, 0, BLACK, kFillModeSolid);
			Novice::ScreenPrintf(GetInfo::GetWindowWidth() / 2-60, GetInfo::GetWindowHeight() / 2-20, "retry to R or SPACE");
		}
		if (pause_ == PAUSEON) {
			Novice::DrawBox(GetInfo::GetWindowWidth() / 2 - 40, GetInfo::GetWindowHeight() / 2 - 20, 120, 50, 0, BLACK, kFillModeSolid);
			Novice::ScreenPrintf(GetInfo::GetWindowWidth() / 2-40, GetInfo::GetWindowHeight() / 2-20, "..PauseNow..");
			Novice::ScreenPrintf(GetInfo::GetWindowWidth() / 2-40, GetInfo::GetWindowHeight() / 2, "Continue to R");
		}
		break;
	case Scenes::MANUAL:
		backGround_->ManualBackDraw();
		Novice::DrawSprite(200, 200, playerHead_, 1, 1, 0, WHITE);
		Novice::DrawSprite(200, 200, playerEye_[eye_], 1, 1, 0, WHITE);
		//Novice::DrawSpriteRect(200, 200, 64 * eye_, 0, 64, 64, playerEye_[eye_], 0.25, 1, 0, WHITE);
		break;
	default:
		break;
	}
}
