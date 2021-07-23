#include "CollisionMgr.h"

// 충돌해야하는 녀석들을 분리해주자
/*
1. 플레이어와 몬스터
2. 플레이어 무기와 몬스터
3. 몬스터의 공격과 플레이어
4. 지형과 플레이어
5. 지형과 몬스터
6. 
*/
// 1. 몬스터와 무기 충돌(슬라임)
BOOL PlayerWeapon_and_Monster_Coll(PLAYERWEAPON* pSword, MONSTER* pMonster, SLBitmap* WeaponBitmap)
{
	// 플레이어 충돌박스 세팅
	SetPlayerWeaponCollBox(pSword, WeaponBitmap);
	// 몬스터 충돌박스 세팅
	SetMonsterCollBox(pMonster);

	POINT Pt[4];

	Pt[0].x = pSword->WeaponCollPt[0].x;
	Pt[0].y = pSword->WeaponCollPt[0].y;

	Pt[1].x = pSword->WeaponCollPt[1].x;
	Pt[1].y = pSword->WeaponCollPt[1].y;

	Pt[2].x = pSword->WeaponCollPt[2].x;
	Pt[2].y = pSword->WeaponCollPt[2].y;

	Pt[3].x = pSword->WeaponCollPt[3].x;
	Pt[3].y = pSword->WeaponCollPt[3].y;

	pSword->WeaponCollRegion = CreatePolygonRgn(Pt, 4, ALTERNATE);

	if (pSword->BeCollCheck == TRUE)
	{
		// 무기와 슬라임 충돌
		if (RectInRegion(pSword->WeaponCollRegion, &pMonster->MonsterRect) == TRUE)
		{
			pMonster->MonsterHp -= pSword->WeaponAttStat;
			DeleteObject(pSword->WeaponCollRegion);
			return TRUE;
		}
	}
	DeleteObject(pSword->WeaponCollRegion);
	return FALSE;
}
// 1. 마법사와 충돌
BOOL PlayerWeapon_and_Magician_Coll(PLAYERWEAPON* pSword, MONSTER* pMonster, SLBitmap* WeaponBitmap)
{
	// 플레이어 충돌박스 세팅
	SetPlayerWeaponCollBox(pSword, WeaponBitmap);
	// 몬스터 충돌박스 세팅
	SetMonsterMagicianCollBox(pMonster);

	POINT Pt[4];

	Pt[0].x = pSword->WeaponCollPt[0].x;
	Pt[0].y = pSword->WeaponCollPt[0].y;

	Pt[1].x = pSword->WeaponCollPt[1].x;
	Pt[1].y = pSword->WeaponCollPt[1].y;

	Pt[2].x = pSword->WeaponCollPt[2].x;
	Pt[2].y = pSword->WeaponCollPt[2].y;

	Pt[3].x = pSword->WeaponCollPt[3].x;
	Pt[3].y = pSword->WeaponCollPt[3].y;

	pSword->WeaponCollRegion = CreatePolygonRgn(Pt, 4, ALTERNATE);

	if (pSword->BeCollCheck == TRUE)
	{
		// 무기와 슬라임 충돌
		if (RectInRegion(pSword->WeaponCollRegion, &pMonster->MonsterRect) == TRUE)
		{
			pMonster->MonsterHp -= pSword->WeaponAttStat;
			DeleteObject(pSword->WeaponCollRegion);
			return TRUE;
		}
	}
	DeleteObject(pSword->WeaponCollRegion);
	return FALSE;
}

BOOL Player_and_SlimeLaser_Coll(PLAYER* pPlayer, MONSTEREFFECT* pLaser , SoundInfo* pPlayerHit)
{
	// 플레이어 충돌박스 셋팅
	SetPlayerCollBox(pPlayer);
	// 몬스터 충돌박스 세팅
	SetSlimeLaserCollBox(pLaser);

	POINT Pt[4];

	Pt[0].x = pLaser->LaserCollPt[0].x;
	Pt[0].y = pLaser->LaserCollPt[0].y;
			  
	Pt[1].x = pLaser->LaserCollPt[1].x;
	Pt[1].y = pLaser->LaserCollPt[1].y;

	Pt[2].x = pLaser->LaserCollPt[2].x;
	Pt[2].y = pLaser->LaserCollPt[2].y;
			  
	Pt[3].x = pLaser->LaserCollPt[3].x;
	Pt[3].y = pLaser->LaserCollPt[3].y;

	pLaser->LaserRegion = CreatePolygonRgn(Pt, 4, ALTERNATE);

	if (pLaser->MonEffectInitial == TRUE)
	{
		// 무기와 슬라임 충돌
		if (RectInRegion(pLaser->LaserRegion, &pPlayer->PlayerCollisionRect) == TRUE
			&& pPlayer->PlayerHit == FALSE && pLaser->MonEffectNowFrame > 3 && pPlayer->PlayerDodgeContinueTime == FALSE)
		{
			soundSeek(pPlayerHit, 0);
			soundPlay(pPlayerHit);
			pPlayer->PlayerHP -= 1;
			pPlayer->PlayerHit = TRUE;
			DeleteObject(pLaser->LaserRegion);
			return TRUE;
		}
	}
	DeleteObject(pLaser->LaserRegion);
	return FALSE;
}



// 2. 플레이어와 몬스터 충돌
BOOL Player_and_Slime_Coll(PLAYER* pPlayer, MONSTER* sMonter, SoundInfo* pPlayerHit)
{
	// 플레이어 충돌박스 셋팅
	SetPlayerCollBox(pPlayer);
	// 몬스터 충돌박스 세팅
	SetMonsterCollBox(sMonter);
	RECT TempRect;

	// 렉트가 충돌하고 플레이어가 무적이 아닐때
	if (IntersectRect(&TempRect, &pPlayer->PlayerCollisionRect, &sMonter->MonsterRect) == TRUE
		&& pPlayer->PlayerHit == FALSE && pPlayer->PlayerDodgeContinueTime == FALSE)
	{
		soundSeek(pPlayerHit, 0);
		soundPlay(pPlayerHit);
		pPlayer->PlayerHP -= 1;
		pPlayer->PlayerHit = TRUE;
		return TRUE;
		// 여기서 플레이어와 슬라임 관련 충돌처리 처리
	}
	return FALSE;
}


// 2. 플레이어와 몬스터 충돌
BOOL Player_and_Magician_Coll(PLAYER* pPlayer, MONSTER* sMonter)
{
	// 플레이어 충돌박스 셋팅
	SetPlayerCollBox(pPlayer);
	// 몬스터 충돌박스 세팅
	SetMonsterMagicianCollBox(sMonter);
	RECT TempRect;

	// 렉트가 충돌하고 플레이어가 무적이 아닐때
	if (IntersectRect(&TempRect, &pPlayer->PlayerCollisionRect, &sMonter->MonsterRect) == TRUE
		&& pPlayer->PlayerHit == FALSE && pPlayer->PlayerDodgeContinueTime == FALSE)
	{
		pPlayer->PlayerHP -= 1;
		pPlayer->PlayerHit = TRUE;
		return TRUE;
		// 여기서 플레이어와 슬라임 관련 충돌처리 처리
	}
	return FALSE;
}

BOOL PlayerAndStairColl(PLAYER* pPlayer, TERRAINOBJECT* pTerrainObj)
{
	SetpTerrainStairObjCollBox(pTerrainObj);
	SetPlayerCollBox(pPlayer);
	RECT TempRect;
	if (IntersectRect(&TempRect, &pPlayer->PlayerCollisionRect, &pTerrainObj->TerrainCollBox) == TRUE)
	{
		return TRUE;
	}
	return FALSE;
}

void CheckPlayerAndTerrainCollObj(PLAYER* pPlayer,
	COLLRECT* LeftRect,
	COLLRECT* RightRect)
{
	InitializeTerrainCollRect(LeftRect, 325,465,478, 617);
	InitializeTerrainCollRect(RightRect, 1600, 671, 1445, 465);

	/*if (LeftRect->CollRect.top  < pPlayer->PlayerCollisionRect.bottom)
	{
		pPlayer->PlayerPosX -= 4;
	}
	if (LeftRect->CollRect.left < pPlayer->PlayerCollisionRect.right)
	{
		pPlayer->PlayerPosY -= 4;
	}
	if (LeftRect->CollRect.right > pPlayer->PlayerCollisionRect.left)
	{
		pPlayer->PlayerPosX += 4;
	}
	if (LeftRect->CollRect.bottom > pPlayer->PlayerCollisionRect.top)
	{
		pPlayer->PlayerPosY += 4;
	}*/
}

BOOL Player_and_Magician_AttColl(PLAYER* pPlayer, MONSTEREFFECT* UpEffect, MONSTEREFFECT* DownEffect)
{
	// 플레이어 충돌박스 셋팅
	SetPlayerCollBox(pPlayer);
	// 몬스터 충돌박스 세팅
	SetMonsterMagicianUpAttBox(UpEffect);
	SetMonsterMagicianDownAttBox(DownEffect);
	RECT TempRect;

	// 렉트가 충돌하고 플레이어가 무적이 아닐때
	if (IntersectRect(&TempRect, &pPlayer->PlayerCollisionRect, &UpEffect->MonEffectCollRect) == TRUE
		&& pPlayer->PlayerHit == FALSE && UpEffect->MonEffectIndexCheck == TRUE && pPlayer->PlayerDodgeContinueTime == FALSE)
	{
		pPlayer->PlayerHP -= 1;
		pPlayer->PlayerHit = TRUE;
		return TRUE;
		// 여기서 플레이어와 슬라임 관련 충돌처리 처리
	}
	// 렉트가 충돌하고 플레이어가 무적이 아닐때
	if (IntersectRect(&TempRect, &pPlayer->PlayerCollisionRect, &DownEffect->MonEffectCollRect) == TRUE
		&& pPlayer->PlayerHit == FALSE && DownEffect->MonEffectIndexCheck == TRUE && pPlayer->PlayerDodgeContinueTime == FALSE)
	{
		pPlayer->PlayerHP -= 1;
		pPlayer->PlayerHit = TRUE;
		return TRUE;
		// 여기서 플레이어와 슬라임 관련 충돌처리 처리
	}
	return FALSE;
}