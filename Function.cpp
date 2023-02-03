#include "Function.h"
float DegreeToRadian(float a) {
	float radian;
	radian = a * (M_PI / 180.0f);
	return radian;
}

void SetColor(unsigned int color, int R, int G, int B, int A) {
	int r = R / 16; int g = G / 16; int b = B / 16; int a = A / 16;
	int r2 = R % 16; int g2 = G % 16; int b2 = B % 16; int a2 = A % 16;
	int r3 = (r * 0x10) + (r2 * 0x1);
	int g3 = (g * 0x10) + (g2 * 0x1);
	int b3 = (b * 0x10) + (b2 * 0x1);
	int a3 = (a * 0x10) + (a2 * 0x1);
	R = 0x1000000 * r3;
	G = 0x10000 * g3;
	B = 0x100 * b3;
	A = 0x1 * a3;
	color = R + G + B + A;
}

int SetColorReturn(unsigned int color, int R, int G, int B, int A)
{
	int r = R / 16; int g = G / 16; int b = B / 16; int a = A / 16;
	int r2 = R % 16; int g2 = G % 16; int b2 = B % 16; int a2 = A % 16;
	int r3 = (r * 0x10) + (r2 * 0x1);
	int g3 = (g * 0x10) + (g2 * 0x1);
	int b3 = (b * 0x10) + (b2 * 0x1);
	int a3 = (a * 0x10) + (a2 * 0x1);
	R = 0x1000000 * r3;
	G = 0x10000 * g3;
	B = 0x100 * b3;
	A = 0x1 * a3;
	return color = R + G + B + A;
}

int RandomRange(int min, int max)
{
	unsigned int range = 0;
	int a = 0;
	srand(time(nullptr) * rand());
	if (min < 0) {
		range = max + (-min) + 1;

	}
	if (min > 0) {
		range = max - min + 1;
	}
	if (min == 0) {
		range = max + 1;
	}
	a = min;
	int num = rand() % range + min;
	return num;
}

int CircleCollision(float aX, float aY, float aRadius, float bX, float bY, float bRadius) {
	float pos = (aX - bX) * (aX - bX) + (aY - bY) * (aY - bY);
	float radius = (aRadius + bRadius) * (aRadius + bRadius);
	if (pos < radius) {
		return true;
	}
	else {
		return false;
	}
}


