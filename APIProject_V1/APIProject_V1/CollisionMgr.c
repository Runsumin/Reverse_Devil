#include "CollisionMgr.h"

// �浹�ؾ��ϴ� �༮���� �и�������
/*
1. �÷��̾�� ����
2. �÷��̾� ����� ����
3. ������ ���ݰ� �÷��̾�
4. ������ �÷��̾�
5. ������ ����
6. 
*/
// 1. ���Ϳ� ���� �浹(������)
BOOL PlayerWeapon_and_Monster_Coll(PLAYERWEAPON* pSword, MONSTER* pMonster, SLBitmap* WeaponBitmap)
{
	// �÷��̾� �浹�ڽ� ����
	SetPlayerWeaponCollBox(pSword, WeaponBitmap);
	// ���� �浹�ڽ� ����
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
		// ����� ������ �浹
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
// 1. ������� �浹
BOOL PlayerWeapon_and_Magician_Coll(PLAYERWEAPON* pSword, MONSTER* pMonster, SLBitmap* WeaponBitmap)
{
	// �÷��̾� �浹�ڽ� ����
	SetPlayerWeaponCollBox(pSword, WeaponBitmap);
	// ���� �浹�ڽ� ����
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
		// ����� ������ �浹
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
	// �÷��̾� �浹�ڽ� ����
	SetPlayerCollBox(pPlayer);
	// ���� �浹�ڽ� ����
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
		// ����� ������ �浹
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



// 2. �÷��̾�� ���� �浹
BOOL Player_and_Slime_Coll(PLAYER* pPlayer, MONSTER* sMonter, SoundInfo* pPlayerHit)
{
	// �÷��̾� �浹�ڽ� ����
	SetPlayerCollBox(pPlayer);
	// ���� �浹�ڽ� ����
	SetMonsterCollBox(sMonter);
	RECT TempRect;

	// ��Ʈ�� �浹�ϰ� �÷��̾ ������ �ƴҶ�
	if (IntersectRect(&TempRect, &pPlayer->PlayerCollisionRect, &sMonter->MonsterRect) == TRUE
		&& pPlayer->PlayerHit == FALSE && pPlayer->PlayerDodgeContinueTime == FALSE)
	{
		soundSeek(pPlayerHit, 0);
		soundPlay(pPlayerHit);
		pPlayer->PlayerHP -= 1;
		pPlayer->PlayerHit = TRUE;
		return TRUE;
		// ���⼭ �÷��̾�� ������ ���� �浹ó�� ó��
	}
	return FALSE;
}


// 2. �÷��̾�� ���� �浹
BOOL Player_and_Magician_Coll(PLAYER* pPlayer, MONSTER* sMonter)
{
	// �÷��̾� �浹�ڽ� ����
	SetPlayerCollBox(pPlayer);
	// ���� �浹�ڽ� ����
	SetMonsterMagicianCollBox(sMonter);
	RECT TempRect;

	// ��Ʈ�� �浹�ϰ� �÷��̾ ������ �ƴҶ�
	if (IntersectRect(&TempRect, &pPlayer->PlayerCollisionRect, &sMonter->MonsterRect) == TRUE
		&& pPlayer->PlayerHit == FALSE && pPlayer->PlayerDodgeContinueTime == FALSE)
	{
		pPlayer->PlayerHP -= 1;
		pPlayer->PlayerHit = TRUE;
		return TRUE;
		// ���⼭ �÷��̾�� ������ ���� �浹ó�� ó��
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
	// �÷��̾� �浹�ڽ� ����
	SetPlayerCollBox(pPlayer);
	// ���� �浹�ڽ� ����
	SetMonsterMagicianUpAttBox(UpEffect);
	SetMonsterMagicianDownAttBox(DownEffect);
	RECT TempRect;

	// ��Ʈ�� �浹�ϰ� �÷��̾ ������ �ƴҶ�
	if (IntersectRect(&TempRect, &pPlayer->PlayerCollisionRect, &UpEffect->MonEffectCollRect) == TRUE
		&& pPlayer->PlayerHit == FALSE && UpEffect->MonEffectIndexCheck == TRUE && pPlayer->PlayerDodgeContinueTime == FALSE)
	{
		pPlayer->PlayerHP -= 1;
		pPlayer->PlayerHit = TRUE;
		return TRUE;
		// ���⼭ �÷��̾�� ������ ���� �浹ó�� ó��
	}
	// ��Ʈ�� �浹�ϰ� �÷��̾ ������ �ƴҶ�
	if (IntersectRect(&TempRect, &pPlayer->PlayerCollisionRect, &DownEffect->MonEffectCollRect) == TRUE
		&& pPlayer->PlayerHit == FALSE && DownEffect->MonEffectIndexCheck == TRUE && pPlayer->PlayerDodgeContinueTime == FALSE)
	{
		pPlayer->PlayerHP -= 1;
		pPlayer->PlayerHit = TRUE;
		return TRUE;
		// ���⼭ �÷��̾�� ������ ���� �浹ó�� ó��
	}
	return FALSE;
}