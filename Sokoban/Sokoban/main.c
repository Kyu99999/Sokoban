#include "stdafx.h"
#include "Framework/Game.h" //main.c�ִ� �������� ��������� �Ѱ�
int main(void)
{
	if (false == Initialize())
	{
		puts("������ �ε��ϴµ� ���ڰ� ������ϴ�.");
		return 1;
	}

	return Run();

}