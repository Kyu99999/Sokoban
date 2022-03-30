#include "stdafx.h"
#include "Framework/Game.h" //main.c있는 폴더에서 상대참조로 한거
int main(void)
{
	if (false == Initialize())
	{
		puts("게임을 로딩하는데 문자가 생겼습니다.");
		return 1;
	}

	return Run();

}