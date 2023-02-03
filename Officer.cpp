#include "Officer.h"
#include "Player.h"

void Officer::Update(char* keys)
{
	if (inColloide == true) {
		if (keys[DIK_Z] || keys[DIK_RETURN]) {
			isActive_ = true;
		}
	}
	if (isActive_ == true) {
		clearFlag_ = true;
	}
	if (whereWorld_ == 0) {
		FolestOfficer();
	}
#ifdef _DEBUG
	Novice::DrawEllipse(pos_.x-scrollPos_+radius_, pos_.y+radius_, radius_, radius_, 0, BLUE, kFillModeWireFrame);
#endif // DEBUG

}

void Officer::SetMode(int world)
{
	whereWorld_ = world;
}

void Officer::SetScrollPos(int x)
{
	scrollPos_ = x;
}

void Officer::SetPlayerPos(int x, int y)
{
	playerPos_.x = x;
	playerPos_.y = y;
}

void Officer::Colloide(int posX, int posY, int radius)
{
	inColloide = CircleCollision(pos_.x+radius_, pos_.y+radius_, radius_, posX, posY, radius);
}

Officer::Officer()
{
}

Officer::~Officer() = default;

void Officer::FolestOfficer()
{
	pos_.x = GetInfo::GetBlockSize() * 25;
	pos_.y = GetInfo::GetBaseLevel()-128;
	if (isActive_ == false) {
		Novice::DrawSprite(pos_.x - scrollPos_, pos_.y, officer_[0], 1, 1, 0, WHITE);
	}
	if (isActive_ == true) {
		particle_->FireUpdate(pos_.x);
		particle_->FireDraw(scrollPos_);
		Novice::DrawSprite(pos_.x - scrollPos_, pos_.y, officerAct_[0], 1, 1, 0, WHITE);	
	}
}