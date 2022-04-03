#include "stdafx.h"
#include "Stage.h"
#include "Framework\Input.h"

static char s_map[MAP_SIZE][MAP_SIZE];
//static char clear_map[MAP_SIZE][MAP_SIZE]=
//{ 
//  "############",
//  "#  Clear   #",
//  "############"
//};
static int32_t s_goalCount = 0;
static int32_t s_boxOnGoalCount = 0;
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;

static EStageLevel level = 1;

bool parseMapType(int i, int j, char mapType)
{
	switch (mapType)
	{
	case MAPTYPE_WALL:	//��
		return true;
		break;
	case MAPTYPE_PLAYER:	//�÷��̾�
		s_playerX = j;
		s_playerY = i;
		return true;
		break;
	case MAPTYPE_BOX:	//�ڽ�
		return true;
		break;
	case MAPTYPE_GOAL:
		s_goalCount++;
		return true;
		break;
	case MAPTYPE_BOX_ON_GOAL:
		s_goalCount++;
		s_boxOnGoalCount++;
		return true;
		break;
	case MAPTYPE_PATH:
		return true;
	case '\0':
		return true;
	default :
		return false;
		// �� �� Ÿ�Ժ��� ����� �ϴ� �ϵ�
	}

	// ��ȯ�� �࿡ �ٴٶ��� ��
}

void clearStage()
{
	memset(s_map, ' ', sizeof(s_map));
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
	s_goalCount = 0;
	s_boxOnGoalCount = 0;
	s_playerX = 0;
	s_playerY = 0;
}

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level <= STAGE_MAX);

	static char path[MAX_PATH] = { 0 };
	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", (int32_t)level);

	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	clearStage();

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (false == parseMapType(i, j, ch))
			{
				break;
			}
			else
				s_map[i][j] = ch;
		}

		if (feof(fp))
		{
			break;
		}
	}

	fclose(fp);
}

void MovePlayer()
{
	if (GetButtonDown(KEYCODE_W))
	{	//�浹ó�� �ڽ�ó��, �ڽ��� O �ȿ� ���� ó��.
		if (s_map[s_playerY - 1][s_playerX] == '#') //�浹ó��
		{
			return 0;
		}

		else if (s_map[s_playerY - 1][s_playerX] == 'a') //�ڽ�ó��
		{
			if (s_map[s_playerY - 2][s_playerX] == '#') // ���̸� ��ȿ
			{
				return 0;
			}
			else if (s_map[s_playerY - 2][s_playerX] == 'O')
			{
				s_map[s_playerY - 2][s_playerX] = '@';
				s_map[s_playerY - 1][s_playerX] = 'P';
				s_map[s_playerY][s_playerX] = ' ';
				s_playerY -= 1;
			}
			else if (s_map[s_playerY - 2][s_playerX] == ' ')
			{
				s_map[s_playerY - 2][s_playerX] = 'a';
				s_map[s_playerY-1][s_playerX] = 'P';
				s_map[s_playerY][s_playerX] = ' ';
				s_playerY -= 1;
			}
		}
		else if ((s_map[s_playerY - 1][s_playerX] == ' '))
		{
			s_map[s_playerY - 1][s_playerX] = 'P';
			s_map[s_playerY][s_playerX] = ' ';
			s_playerY -= 1;
		}
	}
	else if (GetButtonDown(KEYCODE_A))
	{
		//�浹ó�� �ڽ�ó��, �ڽ��� O �ȿ� ���� ó��.
		if (s_map[s_playerY][s_playerX - 1] == '#') //�浹ó��
		{
			return 0;
		}

		else if (s_map[s_playerY][s_playerX - 1] == 'a') //�ڽ�ó��
		{
			if (s_map[s_playerY][s_playerX - 2] == '#')
			{
				return 0;
			}
			else if (s_map[s_playerY][s_playerX - 2] == 'O')
			{
				s_map[s_playerY][s_playerX - 2] = '@';
				s_map[s_playerY][s_playerX - 1] = 'P';
				s_map[s_playerY][s_playerX] = ' ';
				s_playerX -= 1;
			}
			else if (s_map[s_playerY][s_playerX-2] == ' ')
			{
				s_map[s_playerY][s_playerX-2] = 'a';
				s_map[s_playerY][s_playerX-1] = 'P';
				s_map[s_playerY][s_playerX] = ' ';
				s_playerX -= 1;
			}
		}

		else if (s_map[s_playerY][s_playerX - 1] == ' ')
		{
		    s_map[s_playerY][s_playerX - 1] = 'P';
			s_map[s_playerY][s_playerX] = ' ';
			s_playerX -= 1;
		}
		


	}
	else if (GetButtonDown(KEYCODE_S))
	{
		//�浹ó�� �ڽ�ó��, �ڽ��� O �ȿ� ���� ó��.
		if (s_map[s_playerY+1][s_playerX] == '#') //�浹ó��
		{
			return 0;
		}

		else if (s_map[s_playerY + 1][s_playerX] == 'a') //�ڽ�ó��
		{
			if (s_map[s_playerY + 2][s_playerX] == '#')
			{
				return 0;
			}
			else if (s_map[s_playerY + 2][s_playerX] == 'O')
			{
				s_map[s_playerY + 2][s_playerX] = '@';
				s_map[s_playerY + 1][s_playerX] = 'P';
				s_map[s_playerY][s_playerX] = ' ';
				s_playerY += 1;
			}
			else if (s_map[s_playerY + 2][s_playerX] == ' ')
			{
				s_map[s_playerY + 2][s_playerX] = 'a';
				s_map[s_playerY + 1][s_playerX] = 'P';
				s_map[s_playerY][s_playerX] = ' ';
				s_playerY += 1;
			}
		}

		else if (s_map[s_playerY + 1][s_playerX] == ' ')
		{
			s_map[s_playerY + 1][s_playerX] = 'P';
			s_map[s_playerY][s_playerX] = ' ';
			s_playerY += 1;
		}
	
	}
	else if (GetButtonDown(KEYCODE_D))
	{
		//�浹ó�� �ڽ�ó��, �ڽ��� O �ȿ� ���� ó��.
		if (s_map[s_playerY][s_playerX + 1] == '#') //�浹ó��
		{
			return 0;
		}

		else if (s_map[s_playerY][s_playerX + 1]== 'a') //�ڽ�ó��
		{
			if (s_map[s_playerY][s_playerX + 2] == '#')
			{
				return 0;
			}
			else if (s_map[s_playerY][s_playerX + 2] == 'O')
			{
				s_map[s_playerY][s_playerX + 2] = '@';
				s_map[s_playerY][s_playerX + 1] = 'P';
				s_map[s_playerY][s_playerX] = ' ';
				s_playerX += 1;
			}
			else if (s_map[s_playerY][s_playerX+2] == ' ')
			{
				s_map[s_playerY][s_playerX+2] = 'a';
				s_map[s_playerY][s_playerX+1] = 'P';
				s_map[s_playerY][s_playerX] = ' ';
				s_playerX += 1;
			}
		}

		else if (s_map[s_playerY][s_playerX + 1] == ' ')
		{
			s_map[s_playerY][s_playerX + 1] = 'P';
			s_map[s_playerY][s_playerX] = ' ';
			s_playerX += 1;
		}
	}
}

int check_boxOnGoal()
{
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			

			if (s_map[i][j]=='@')
			{
				s_boxOnGoalCount++;
			}
		}
	}
	return s_boxOnGoalCount;
}

//static int32_t s_goalCount = 0;
//static int32_t s_boxOnGoalCount = 0;

void UpdateStage()
{
	size_t i = 0;
	size_t j = 0;

	MovePlayer();

	if (level == 4)
	{
		puts("Clear!");
	}

	else if (s_goalCount == check_boxOnGoal())
	{
		++level;
		if (level == 4)
		{
			puts("Clear!");
		}
		else
			LoadStage(level);
	}
	else
	{
		s_boxOnGoalCount = 0;
	}


	//if (level == 4)
	//{
	//	memcpy(s_map, clear_map, sizeof(s_map));
	//}
	//else if (s_goalCount == check_boxOnGoal())
	//{
	//	LoadStage(level); //�̰� ��������1������ 2 3 4 �ö󰥼��ְ�
	//}
	//else
	//{
	//	s_boxOnGoalCount = 0;
	//}



	// �Է¿� ���ؼ� ó���� �� 

	// ������ Ŭ���� �ƴ����� �ľ���
	//s_goalCount, s_boxOnGoalCount �� ���� ������ Ȯ���ϸ� �ɵ�? 

}

const char** GetMap()
{
	return s_map;
}