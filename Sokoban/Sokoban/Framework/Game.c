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
	//// 0.5�� �������� Ư�� �޼��� �����̱�
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
	//	SetMessage("¥��");
	//}

}

void render()
{
	RenderMap();
}

int32_t Run()
{
	// Game Loop => �÷��̾�κ����� �Է��� �ϵ����� �и���Ų��.
	// https://www.gameprogrammingpatterns.com/game-loop.html

	// Game Loop�� ��ü�� Frame

	while (true)
	{
		// �Է� ó��
		processInput();
		// ������Ʈ
		update();
		// ������
		render();

	}
}