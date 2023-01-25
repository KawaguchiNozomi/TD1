#pragma once
#include "Function.h"
#include <Novice.h>
#include <stdlib.h>

class Particle
{
public:
	
	Particle();

protected:
	struct Color
	{
		unsigned int R;
		unsigned int G;
		unsigned int B;
		unsigned int A;
		unsigned int color;
	};
	struct Dust
	{
		float x;
		float y;
		Color color;
		float size;
		int isArrive = false;
		float speedY;
		float speedX;
		int count = 0;
		int radius;
	};



};

