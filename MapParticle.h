#pragma once
#include "Particle.h"
/// <summary>
/// マップのパーティクル
/// </summary>
class CageParticle :public Particle
{
public:
	void CageLigthUpdate();
	void SetCageLigthOn(int posX,int posY);
	void SetTouched(int posX,int posY);
	int GetIsTouced() { return touched_.isTouched; }
	CageParticle();
	struct Touch
	{
		Vector2 savePos={0,0};
		int isTouched = false;
	};
private:
	
	static const int cageLigthMax_ = 10;
	Dust cageLigth_[cageLigthMax_];
	int cageLigthSprite= Novice::LoadTexture("./Resouce/howa.png");
	Touch touched_;
};

