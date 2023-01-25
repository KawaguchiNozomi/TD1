#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

/// <summary>
/// 角度の変換
/// </summary>
/// <param name="a">degree</param>
/// <returns></returns>
float DegreeToRadian(float a);

/// <summary>
/// 色の設定
/// </summary>
/// <param name="color">色の変数</param>
/// /// <param name="R">Rの値</param>
/// /// <param name="G">Gの値</param>
/// /// <param name="B">Bの値</param>
/// /// <param name="A">Aの値</param>
/// <returns></returns>
int SetColor(unsigned int color, int R, int G, int B, int A);