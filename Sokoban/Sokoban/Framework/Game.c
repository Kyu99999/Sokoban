#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Timer.h"
bool Initialize()
{
	if (false == InitializeRenderer())
	{
		return true;
	}
	InitializeTimer();
}

void processInput()
{ 
	
}

void update() {
	//// 0.5초 간격으로 특정 메세지 깜박이기
	//static float elapsedTime = 0.0f;
	//static bool canShowMessage = false;
	//elapsedTime += GetDeltaTime();
	//if (elapsedTime > 0.5F)
	//{
	//	elapsedTime = 0.0f;
	//	canShowMessage = !canShowMessage;
	//}

	//if (canShowMessage)
	//{
	//	SetMessage("짜잔");
	//}

}

void render()
{
	RenderMap();
}

int32_t Run()
{
	// Game Loop => 플레이어로부터의 입력을 하드웨어와 분리시킨다.
	// https://www.gameprogrammingpatterns.com/game-loop.html

	// Game Loop의 전체를 Frame

	while (true)
	{
		// 입력 처리
		processInput();
		// 업데이트
		update();
		// 렌더링
		render();

	}
}