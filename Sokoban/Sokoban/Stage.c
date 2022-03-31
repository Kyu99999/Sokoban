#include "stdafx.h"
#include "Stage.h"

typedef struct tagStage
{
	char Map[MAP_SIZE][MAP_SIZE];
}Stage;

static Stage s_currentStage;

void LoadStage(EStageLevel level)
{
	assert(STAGE_1 <= level && level < STAGE_MAX);

	static char path[MAX_PATH] = { 0 };


}