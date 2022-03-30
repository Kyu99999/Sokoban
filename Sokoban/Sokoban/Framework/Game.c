#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"

bool Initialize()
{
	if (false == InitializeRenderer())
	{
		return true;
	}
}

void processInput()
{

}

void update()
{


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