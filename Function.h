#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

/// <summary>
/// �p�x�̕ϊ�
/// </summary>
/// <param name="a">degree</param>
/// <returns></returns>
float DegreeToRadian(float a);

/// <summary>
/// �F�̐ݒ�
/// </summary>
/// <param name="color">�F�̕ϐ�</param>
/// /// <param name="R">R�̒l</param>
/// /// <param name="G">G�̒l</param>
/// /// <param name="B">B�̒l</param>
/// /// <param name="A">A�̒l</param>
/// <returns></returns>
int SetColor(unsigned int color, int R, int G, int B, int A);