#include "SceneMgr.h"
void InitializeSceneMgr(SCENEMGR* SceneMgr)
{
	SceneMgr->SceneIndex = 0;
	SceneMgr->SceneChange = FALSE;
	SceneMgr->ChangeFirstScene = FALSE;
}