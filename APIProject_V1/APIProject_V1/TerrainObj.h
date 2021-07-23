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

	/// ���ҽ� ����
	OneCharacterRes* graphicRes;

}TERRAINOBJECT;

typedef struct CollRectTerrain
{
	RECT CollRect;
}COLLRECT;

/// ��ܰ��� �浹...
void InitializeTerrainObj(TERRAINOBJECT* pTerrainObj);
void SetTerrainObjGraphicsRes(TERRAINOBJECT* pTerrainObj, OneCharacterRes* graphicsRes);
void SetStairTerrainObj(TERRAINOBJECT* pTerrainObj, SCENEMGR* SceneMgr);
void SetpTerrainStairObjCollBox(TERRAINOBJECT* pTerrainObj);


// ���� ������ֱ�

void InitializeTerrainCollRect(COLLRECT* CollRect, int left, int top, int right, int bottom);