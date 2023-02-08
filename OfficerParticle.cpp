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

void OfficerParticle::CubeUpdate(int x)
{
	cubeCoolTime_++;
	for (int i = 0; i < cubeMax_; i++) {
		if (cube_[i].isArrive == false&&cubeCoolTime_>=5) {
			cube_[i].x = RandomRange(-10, 1010);
			cube_[i].y = RandomRange(-150,-90);
			cube_[i].speedY = 0;
			cube_[i].radius = 0.8;
			cube_[i].color.A = 255;
			cube_[i].color.R = RandomRange(100,150);
			cube_[i].color.G = RandomRange(150, 200);
			cube_[i].color.B = RandomRange(200, 255);
			cube_[i].isArrive = true;
			cube_[i].count = 0;
			cubeCoolTime_ = 0;
			break;
		}
	}
	for (int i = 0; i < cubeMax_; i++)
	{
		cube_[i].color.color = SetColorReturn(cube_[i].color.color, cube_[i].color.R, cube_[i].color.G, cube_[i].color.B, cube_[i].color.A);
		if(cube_[i].isArrive==true){
			float airResist = k_ * -cube_[i].speedY;
			float airResistAccel = airResist / cubeMass_;
			cubeAccel_[i] = cubeGravity + airResistAccel;
			cube_[i].speedY += (cubeAccel_[i] / 60.0f);
			cube_[i].y += (cube_[i].speedY);
			cube_[i].color.A -= 1;
			if (cube_[i].y >= 1000) {
				cube_[i].isArrive = false;
			}
		}
	}
}

void OfficerParticle::CubeDraw(int x)
{
	for (int i = 0; i < cubeMax_; i++)
	{
		if (cube_[i].isArrive == true) {
			if (i% 2 == 0) {
				Novice::SetBlendMode(BlendMode::kBlendModeAdd);
			}
			if (i % 2 == 1) {
				Novice::SetBlendMode(BlendMode::kBlendModeSubtract);
			}
			Novice::DrawSprite(cube_[i].x, cube_[i].y, cubeSprite_, 1, 1, 0, cube_[i].color.color);
		}
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




