#include "stdafx.h"
#include "Timer.h"

static clock_t s_prevTick;
static float s_deltaTime;

void InitializeTimer()
{
	s_prevTick = clock();	
}
//���α׷��� ������ ���� ����̳� ƽŷ�� �����
//Ŭ�� Ƚ�� ��ȯ

void UpdateTimer()
{
	clock_t currentTick = clock();

	s_deltaTime = (currentTick - s_prevTick) / (float)CLOCKS_PER_SEC;
	
	s_prevTick = currentTick;
}
// 1 : deltaTime = x:1
	// x= 1/deltaTime
float GetDeltaTime()
{
	return s_deltaTime;
}