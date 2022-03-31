#pragma once


// ����
// 1. ���������� �ҷ���
// 2. �������� ���� ��Ȳ�� ����
// 3, ���������� Ŭ���� �ƴ���?

typedef enum MapType
{
	MAPTYPE_WALL = '#',
	MAPTYPE_Player = 'P',
	MAPTYPE_BOX = 'a',
	MAPTYPE_GOAL = 'O',
	MAPTYPE_BOX_ON_GOAL = '@',
	MAPTYPE_PATH = ' ',

}EMapType;

typedef enum StageLevel
{
	STAGE_01 = 1,
	STAGE_MAX
}EStageLevel;

/// <summary>
/// ���������� �ε��Ѵ�
/// </summary>
void LoadStage(EStageLevel level);
