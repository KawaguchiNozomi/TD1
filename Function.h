#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>

/// <summary>
/// �p�x�̕ϊ�
/// </summary>
/// <param name="a">degree</param>
/// <returns></returns>
float DegreeToRadian(float a);

/// <summary>
/// �F�̐ݒ�(void)
/// </summary>
/// <param name="color">�F�̕ϐ�</param>
/// /// <param name="R">R�̒l</param>
/// /// <param name="G">G�̒l</param>
/// /// <param name="B">B�̒l</param>
/// /// <param name="A">A�̒l</param>
/// <returns></returns>
void SetColor(unsigned int color, int R, int G, int B, int A);
/// <summary>
/// �F�̐ݒ�(int)
/// </summary>
/// <param name="color">�F�̕ϐ�</param>
/// /// <param name="R">R�̒l</param>
/// /// <param name="G">G�̒l</param>
/// /// <param name="B">B�̒l</param>
/// /// <param name="A">A�̒l</param>
/// <returns></returns>
int SetColorReturn(unsigned int color, int R, int G, int B, int A);
/// <summary>
/// �����Ŕ͈͂������_���ɏo��
/// </summary>
/// <param name="min">�ŏ��l</param>
/// <param name="max">�ő�l</param>
/// <returns></returns>
int RandomRange(int min, int max);
/// <summary>
/// �~�̏Փ˔���
/// </summary>
/// <param name="aX">�~�P�@x</param>
/// <param name="aY">�~�P�@y</param>
/// <param name="aRadius">�~�P�@���a</param>
/// <param name="bX">�~�Q�@x</param>
/// <param name="bY">�~�Q�@y</param>
/// <param name="bRadius">�~�Q�@���a</param>
/// <returns></returns>
int CircleCollision(float aX, float aY, float aRadius, float bX, float bY, float bRadius);
