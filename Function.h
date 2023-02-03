#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>

/// <summary>
/// 角度の変換
/// </summary>
/// <param name="a">degree</param>
/// <returns></returns>
float DegreeToRadian(float a);

/// <summary>
/// 色の設定(void)
/// </summary>
/// <param name="color">色の変数</param>
/// /// <param name="R">Rの値</param>
/// /// <param name="G">Gの値</param>
/// /// <param name="B">Bの値</param>
/// /// <param name="A">Aの値</param>
/// <returns></returns>
void SetColor(unsigned int color, int R, int G, int B, int A);
/// <summary>
/// 色の設定(int)
/// </summary>
/// <param name="color">色の変数</param>
/// /// <param name="R">Rの値</param>
/// /// <param name="G">Gの値</param>
/// /// <param name="B">Bの値</param>
/// /// <param name="A">Aの値</param>
/// <returns></returns>
int SetColorReturn(unsigned int color, int R, int G, int B, int A);
/// <summary>
/// 整数で範囲をランダムに出す
/// </summary>
/// <param name="min">最小値</param>
/// <param name="max">最大値</param>
/// <returns></returns>
int RandomRange(int min, int max);
/// <summary>
/// 円の衝突判定
/// </summary>
/// <param name="aX">円１　x</param>
/// <param name="aY">円１　y</param>
/// <param name="aRadius">円１　半径</param>
/// <param name="bX">円２　x</param>
/// <param name="bY">円２　y</param>
/// <param name="bRadius">円２　半径</param>
/// <returns></returns>
int CircleCollision(float aX, float aY, float aRadius, float bX, float bY, float bRadius);
