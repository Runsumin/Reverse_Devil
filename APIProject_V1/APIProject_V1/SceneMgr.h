#pragma once
#include "SLDefine.h"
typedef struct SceneMgr
{
	// ���� �ε���
	int SceneIndex;

	// �� �Ѿ�� ��������
	BOOL SceneChange;

	BOOL ChangeFirstScene;

}SCENEMGR;
void InitializeSceneMgr(SCENEMGR* SceneMgr);

