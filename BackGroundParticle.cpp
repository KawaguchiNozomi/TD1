#include "BackGroundParticle.h"

void BackGroundParticle::Howa()
{
	for (int i = 0; i < howaMax_; i++)
	{
		if (howa_[i].isArrive == false) {
			howa_[i].x = RandomRange(50, 950);
			howa_[i].y = RandomRange(50, 680);
			howa_[i].count = 0;
			howa_[i].radius = RandomRange(50, 70);
			howa_[i].color.A = 10;
			howa_[i].isArrive = true;
		}
	}
}

void BackGroundParticle::Title()
{
	titleTime_++;
	for (int i = 0; i < 5; i++)
	{
		if (titleTime_ >= 20) {
			title_[i].x = RandomRange(-2, 2);
			title_[i].y = RandomRange(-2, 2);
			titleTime_ = 0;
		}
		title_[i].color.A = 35;
		title_[i].color.R = 50 * i;
		title_[i].color.G = 255 - 10 * i;
		title_[i].color.B = 200;
		
	}
	Novice::DrawSprite(0, 0, titleImage_, 1, 1, 0, WHITE);
	Novice::SetBlendMode(BlendMode::kBlendModeAdd);
	for (int i = 0; i < 5; i++)
	{
			title_[i].color.color = SetColorReturn(title_[i].color.color, title_[i].color.R, title_[i].color.G, title_[i].color.B, title_[i].color.A);
			Novice::DrawSprite(title_[i].x, title_[i].y, titleImage_, 1, 1, 0, title_[i].color.color);
	}
	Novice::SetBlendMode(BlendMode::kBlendModeNormal);
}
