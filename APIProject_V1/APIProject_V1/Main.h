#pragma once
#include "SLDefine.h"
#include "dbg_memory.h"
#include "SLEngine.h"
#include "resource.h"
#include "SLTime.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"
#include "TerrainObj.h"


void initialize();
void GameLoop();
void DeleteREsourceHeap();

/// 레이어 분리
void DrawBackGround();
void DrawPlayer();
void DrawMonster();
void PlayerMoveScene();
void MonsterMove();
void DrawUI();
void CollCheck();
void DrawEffect();
void DrawObject();
void CollObject();