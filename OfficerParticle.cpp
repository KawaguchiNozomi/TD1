#include "OfficerParticle.h"

void OfficerParticle::FireUpdate(int x)
{
	for (int i = 0; i < fireMax_; i++)
	{
		if (fire_[i].isArrive == false) {
			fire_[i].x=x;
			fire_[i].y = GetInfo::GetBaseLevel();
			fire_[i].color.R = RandomRange(200, 255);
			fire_[i].color.G = RandomRange(100, 200);
			fire_[i].color.B = 0;
			fire_[i].color.A = 255;
			fire_[i].radius = 30;
			fire_[i].move.start.x = x;
			fire_[i].move.start.y = GetInfo::GetBaseLevel();
			fire_[i].move.target.x = x + RandomRange(-50, 50);
			fire_[i].move.target.y = GetInfo::GetBaseLevel() - RandomRange(200, 250);
			fire_[i].move.t = 0;
			fire_[i].isArrive = true;
			break;
		}
	}
	for (int i = 0; i < fireMax_; i++)
	{
		if (fire_[i].isArrive == true) {
			fire_[i].move.t+=0.05;
			fire_[i].y = (1.0 - fire_[i].move.t)*fire_[i].move.start.y + fire_[i].move.t * fire_[i].move.target.y;
			fire_[i].x = (1.0 - fire_[i].move.t)*fire_[i].move.start.x + fire_[i].move.t * fire_[i].move.target.x+RandomRange(-5,5);
			fire_[i].color.A -= 8; //ƒ~ƒX‚Á‚Ä‚é‚¯‚Ç‚È‚ñ‚©‚©‚Á‚±‚æ‚©‚Á‚½‚Ì‚Å‚±‚Ì‚Ü‚Ü‚Å
			fire_[i].radius -= 1;
			if (fire_[i].color.A <= 1||fire_[i].y<=-50) {
				fire_[i].color.A = 0;
				fire_[i].isArrive = false;
			}
		}
		fire_[i].color.color=SetColorReturn(fire_[i].color.color, fire_[i].color.R, fire_[i].color.G, fire_[i].color.B, fire_[i].color.A);
	}
}

void OfficerParticle::FireDraw(int x)
{
	Novice::SetBlendMode(BlendMode::kBlendModeAdd);
	for (int i = 0; i < fireMax_; i++)
	{
		if (fire_[i].isArrive == true) {
			Novice::DrawEllipse(fire_[i].x-x, fire_[i].y, fire_[i].radius, fire_[i].radius, 0, fire_[i].color.color, kFillModeSolid);
		}
    #ifdef DEBUG
	    	 Novice::ScreenPrintf(0, 140 + 20 * i, "posx=%.1f posy=%.1f", fire_[i].x,fire_[i].y);
    #endif // DEBUG
	}
	Novice::SetBlendMode(BlendMode::kBlendModeNormal);
   
}

OfficerParticle::OfficerParticle() {
	for (int i = 0; i < fireMax_; i++)
	{
		this->fire_[i].x = 0;
		this->fire_[i].y = 0;
	}
};




