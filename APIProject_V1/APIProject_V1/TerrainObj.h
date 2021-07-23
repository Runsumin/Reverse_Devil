#pragma once
#include "SLDefine.h"
#include "SceneMgr.h"
typedef struct TerrainObj
{
	int TerrainPosX;
	int TerrainPosY;

	int TerrainDelayFrame;

	int TerrainNowFrame;

	int TerraintotalFrame;

	int TerrainNowMotionIndex;
	RECT TerrainCollBox;

	/// 리소스 정보
	OneCharacterRes* graphicRes;

}TERRAINOBJECT;

typedef struct CollRectTerrain
{
	RECT CollRect;
}COLLRECT;

/// 계단과의 충돌...
void InitializeTerrainObj(TERRAINOBJECT* pTerrainObj);
void SetTerrainObjGraphicsRes(TERRAINOBJECT* pTerrainObj, OneCharacterRes* graphicsRes);
void SetStairTerrainObj(TERRAINOBJECT* pTerrainObj, SCENEMGR* SceneMgr);
void SetpTerrainStairObjCollBox(TERRAINOBJECT* pTerrainObj);


// 지형 만들어주기

void InitializeTerrainCollRect(COLLRECT* CollRect, int left, int top, int right, int bottom);