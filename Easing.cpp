#include "Easing.h"
float easeOutCirc(float t) {
	return sqrt(1 - pow(t - 1, 2));
}
float easeOutSine(float t) {
	return sin((M_PI * t) / 2);
}