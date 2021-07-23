#pragma once
#include "SLDefine.h"
typedef struct SceneMgr
{
	// 씬의 인덱스
	int SceneIndex;

	// 씬 넘어갈지 판정변수
	BOOL SceneChange;

	BOOL ChangeFirstScene;

}SCENEMGR;
void InitializeSceneMgr(SCENEMGR* SceneMgr);

