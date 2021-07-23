#pragma once
#include "SLDefine.h"
#include "Player.h"
#include "Monster.h"
#include "TerrainObj.h"

BOOL PlayerWeapon_and_Monster_Coll(PLAYERWEAPON* pSword, MONSTER* pMonster, SLBitmap* WeaponBitmap);
BOOL PlayerWeapon_and_Magician_Coll(PLAYERWEAPON* pSword, MONSTER* pMonster, SLBitmap* WeaponBitmap);
BOOL Player_and_SlimeLaser_Coll(PLAYER* pPlayer, MONSTEREFFECT* pLaser, SoundInfo* pPlayerHit);
BOOL Player_and_Slime_Coll(PLAYER* pPlayer, MONSTER* sMonter, SoundInfo* pPlayerHit);
BOOL Player_and_Magician_Coll(PLAYER* pPlayer, MONSTER* sMonter);
BOOL PlayerAndStairColl(PLAYER* pPlayer, TERRAINOBJECT* pTerrainObj);
void CheckPlayerAndTerrainCollObj(PLAYER* pPlayer, COLLRECT* LeftRect, COLLRECT* RightRect);
BOOL Player_and_Magician_AttColl(PLAYER* pPlayer, MONSTEREFFECT* UpEffect, MONSTEREFFECT* DownEffect);