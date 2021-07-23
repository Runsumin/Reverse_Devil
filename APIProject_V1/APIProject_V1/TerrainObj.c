#include "TerrainObj.h"

/// 계단과의 충돌
void InitializeTerrainObj(TERRAINOBJECT* pTerrainObj)
{
	pTerrainObj->TerrainPosX = 1440;
	pTerrainObj->TerrainPosY = 300;
	pTerrainObj->TerrainDelayFrame = 10;
	pTerrainObj->TerrainNowFrame = 0;
	pTerrainObj->TerrainNowMotionIndex = 0;
}

void SetTerrainObjGraphicsRes(TERRAINOBJECT* pTerrainObj, OneCharacterRes* graphicsRes)
{
	pTerrainObj->graphicRes = graphicsRes;
}

void SetStairTerrainObj(TERRAINOBJECT* pTerrainObj , SCENEMGR* SceneMgr)
{
	pTerrainObj->TerrainNowFrame = (pTerrainObj->TerraintotalFrame / pTerrainObj->TerrainDelayFrame) %
		pTerrainObj->graphicRes->motions[pTerrainObj->TerrainNowMotionIndex].spriteNum;

	if (SceneMgr->SceneChange == TRUE)
	{
		pTerrainObj->TerraintotalFrame++;

		if (pTerrainObj->TerrainNowFrame == 7)
		{
			SceneMgr->SceneChange = FALSE;
		}
	}
	
}

void SetpTerrainStairObjCollBox(TERRAINOBJECT* pTerrainObj)
{
	// Left , Top
	pTerrainObj->TerrainCollBox.left = pTerrainObj->TerrainPosX;
	pTerrainObj->TerrainCollBox.top = pTerrainObj->TerrainPosY;
	// Right , Bottom
	pTerrainObj->TerrainCollBox.right = pTerrainObj->TerrainPosX + 159;
	pTerrainObj->TerrainCollBox.bottom = pTerrainObj->TerrainPosY + 159;
}


/// 지형과의 충돌
void InitializeTerrainCollRect(COLLRECT* CollRect, int left, int top, int right, int bottom)
{
	CollRect->CollRect.left = left;
	CollRect->CollRect.top = top;
	CollRect->CollRect.right = right;
	CollRect->CollRect.bottom = bottom;
}