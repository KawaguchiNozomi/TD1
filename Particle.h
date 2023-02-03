#pragma once
#include "Function.h"
#include <Novice.h>
#include <stdlib.h>
#include "Easing.h"

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
	struct Vector2
	{
		float x=0;
		float y=0;
	};
	struct Move
	{
		float t;
		Vector2 start;
		Vector2 target;
		float theta;
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
		Move move;
		/// <summary>
		/// ˆê“x‚¾‚¯•\Ž¦‚·‚é‚Æ‚«—p
		/// </summary>
		int oneTimeArrive = false;
	};



};

