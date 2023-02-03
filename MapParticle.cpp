#include "MapParticle.h"

void CageParticle::CageLigthUpdate()
{
	for (int i = 0; i < cageLigthMax_; i++)
	{   	cageLigth_[i].speedX = RandomRange(-3, 3);
			cageLigth_[i].speedY = RandomRange(-3, 3);
			Novice::DrawSprite(cageLigth_[i].x+cageLigth_[i].speedX, cageLigth_[i].y+cageLigth_[i].speedY, cageLigthSprite, 1, 1, 0, 0xFFFF00FF);
	}
}

void CageParticle::SetCageLigthOn(int posX,int posY)
{
	for (int i = 0; i < cageLigthMax_; i++)
	{
		cageLigth_[i].x = posX;
		cageLigth_[i].x = posY;
	}
}

void CageParticle::SetTouched(int posX, int posY)
{
	touched_.savePos.x = posX;
	touched_.savePos.y = posY;
	touched_.isTouched = true;
}

CageParticle::CageParticle()
{
	this->touched_.isTouched = false;
}
