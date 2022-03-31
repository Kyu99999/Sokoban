#pragma once

typedef enum MapType
{
	MAPTYPE_WALL = '#',
	MAPTYPE_PLAYER = 'P',
	MAPTYPE_BOX = 'a',
	MAPTYPE_GOAL = 'O',
	MAPTYPE_BOX_ON_GOAL = '@',
	MAPTYPE_PATH = ' '
} EMapType;

typedef enum StageLevel
{
	STAGE_01 = 1,
	STAGE_MAX
} EStageLevel;

///<summary>
/// 스테이지를 로딩한다.
///</summary>
void LoadStage(EStageLevel level);

/// <summary>
/// 스테이지를 업데이트한다.
/// </summary>
void UpdateStage();


///<summary>
/// 맵을 반환한다.
///</summary>
const char** GetMap();