#include "Monster.h"

void InitializeMonster(MONSTER* sMonster, int MonPosX, int MonPosY , int MonsterHP)
{
	// 몬스터 위치 초기화
	sMonster->MonsterPosX = MonPosX;
	sMonster->MonsterPosY = MonPosY;

	// 몬스터 체력 초기화
	sMonster->MonsterHp = MonsterHP;

	// 몬스터 충돌박스 초기화
	sMonster->MonsterRect.left	 = 0;
	sMonster->MonsterRect.top	 = 0;
	sMonster->MonsterRect.right	 = 0;
	sMonster->MonsterRect.bottom = 0;

	// 몬스터 애니메이션 위한 초기화
	sMonster->NowMotionIndex = 0;
	sMonster->MonsterSpriteNum = 6;

	sMonster->MonsterState = 0;

	// 몬스터 패턴 딜레이 타임 초기화
	sMonster->MonsterDelayTime = 0;

	// 몬스터 방향값
	sMonster->MonDirX = 0;
	sMonster->MonDirY = 0;

	// 몬스터의 애니메이션 딜레이 타임 
	sMonster->MonsterAniDelayTime = 10;

	// 현재 출력될 몬스터 애니메이션 스프라이트
	sMonster->NowFrame = 0;

	///
	sMonster->MonflowTime = FALSE;
	sMonster->SeperTime = 0;
	sMonster->totalFrameSet = 0;
	sMonster->MonsterSoundCheck = FALSE;

}
void InitializMonEffect(MONSTEREFFECT* sEffect)
{
	sEffect->MonEffectAniDelayTime = 10;
	sEffect->MonEffectNowFrame = 0;
	sEffect->MonEffectPosX = 100;
	sEffect->MonEffectPosY = 100;
	sEffect->MonEffectSpriteNum = 0;
	sEffect->MonEffectNowMotionIndex = 0;
	sEffect->MonEffectCheck = FALSE;
	sEffect->MonEffectIndexCheck = FALSE;
	sEffect->MonEffectInitial = FALSE;
	sEffect->Angle = 0;
	sEffect->theta = 0;
	sEffect->EffecttotalFrameSet = 0;
}

void SetMonsterCollBox(MONSTER* sMonster)
{
	// Left , Top
	sMonster->MonsterRect.left = sMonster->MonsterPosX + 55;
	sMonster->MonsterRect.top = sMonster->MonsterPosY + 125;

	// Right , Bottom
	sMonster->MonsterRect.right = sMonster->MonsterPosX + 
		sMonster->graphicRes->motions[sMonster->NowMotionIndex].sheet->Width / 13 - 40;
	sMonster->MonsterRect.bottom = sMonster->MonsterPosY +
		sMonster->graphicRes->motions[sMonster->NowMotionIndex].sheet->Height / 8 - 10;
	
}

void SetMonsterMagicianCollBox(MONSTER* sMonster)
{
	// Left , Top
	sMonster->MonsterRect.left = sMonster->MonsterPosX + 45;
	sMonster->MonsterRect.top = sMonster->MonsterPosY + 25;

	// Right , Bottom
	sMonster->MonsterRect.right = sMonster->MonsterPosX + 
		sMonster->graphicRes->motions[sMonster->NowMotionIndex].sheet->Width / 9 - 50;
	sMonster->MonsterRect.bottom = sMonster->MonsterPosY + 
		sMonster->graphicRes->motions[sMonster->NowMotionIndex].sheet->Height / 8 - 8;
}

void SetMonsterGraphicsRes(MONSTER* sMonster, OneCharacterRes* graphicsRes)
{
	sMonster->graphicRes = graphicsRes;
}

void SetMonsterEffectGraphicsRes(MONSTEREFFECT* sEffect, OneCharacterRes* graphicsRes)
{
	sEffect->graphicRes = graphicsRes;
}

void MonsterSlimeFSM(MONSTER* pMonster, PLAYER* pPlayer, MONSTEREFFECT* pLaser,
	SoundInfo* SlimeMove, SoundInfo* SlimeRollAtt, SoundInfo* SlimeBlowup , SoundInfo* SlimeLaser, SoundInfo* SlimeDie)
{
	/// 슬라임의 애니메이션 돌려주기
	//if (pMonster->MonsterState == Die && pMonster->NowFrame == 12)
	//{
	//	// 이때는 프레임값이 올라가지 않는다.
	//	soundPause(SlimeMove);
	//}
	//else
	//{
	//	pMonster->totalFrameSet++;
	//	pLaser->EffecttotalFrameSet++;
	//}
	//pMonster->NowFrame = (pMonster->totalFrameSet / pMonster->MonsterAniDelayTime) % 
	//	pMonster->graphicRes->motions[pMonster->NowMotionIndex].spriteNum;
	//pLaser->MonEffectNowFrame = (pLaser->EffecttotalFrameSet / pLaser->MonEffectAniDelayTime) %
	//	pLaser->graphicRes->motions[pLaser->MonEffectNowMotionIndex].spriteNum;
	//if (pLaser->MonEffectInitial == FALSE)
	//{	// 한번만 해줘야 될꺼...
	//	pLaser->theta = atan2f(((float)pMonster->MonsterPosX - ((float)pPlayer->PlayerPosX - 200)),
	//		((float)pMonster->MonsterPosY - ((float)pPlayer->PlayerPosY - 200)));
	//	pLaser->Angle = (pLaser->theta * 180.0f / PI);
	//	pLaser->MonEffectPosX = (pMonster->MonsterPosX - 400 * sin(pLaser->theta)) - 230;
	//	pLaser->MonEffectPosY = (pMonster->MonsterPosY - 400 * cos(pLaser->theta)) - 200;
	//	pLaser->MonEffectNowFrame = 0;
	//}

	// 레이저 애니메이션 돌려주기
	switch (pMonster->MonsterState)
	{
		// 슬라임 기본 & 이동
	case Idle:
		//pMonster->NowMotionIndex = 0;
		//pMonster->MonsterDelayTime += SLGetElapsedTime();
		//// 1초동안 이동한다
		//if (pMonster->MonsterDelayTime < 1000)
		//{
		//	if (SlimeMove->isPause == TRUE)
		//	{
		//		soundPlayLooping(SlimeMove);
		//	}
		//	pMonster->MonDirX = pPlayer->PlayerPosX - pMonster->MonsterPosX;
		//	pMonster->MonDirY = pPlayer->PlayerPosY - pMonster->MonsterPosY;
		//	if (pMonster->MonDirX != 0 && pMonster->MonDirY != 0)
		//	{
		//		float NorDirX = pMonster->MonDirX / abs(pMonster->MonDirX);
		//		float NorDirY = pMonster->MonDirY / abs(pMonster->MonDirY);
		//		pMonster->MonsterPosX = pMonster->MonsterPosX + ((NorDirX) * MONSTERIDLESPEED);
		//		pMonster->MonsterPosY = pMonster->MonsterPosY + ((NorDirY) * MONSTERIDLESPEED);
		//	}
		//	if (pMonster->MonsterHp < 0)
		//	{
		//		pMonster->MonsterSoundCheck = FALSE;
		//		pMonster->totalFrameSet = 0;
		//		// 몬스터 모션 바꿔주기
		//		pMonster->MonsterState = Die;
		//		// 시간 초기화
		//		pMonster->MonsterDelayTime = 0;
		//	}
		//}
		//// 1.2초동안 다음 행동 결정한다
		//else if (pMonster->MonsterDelayTime > 2200 && pMonster->NowFrame == 5)
		//{
		//	if (SlimeMove->isPause == FALSE)
		//	{
		//		soundPause(SlimeMove);
		//	}
		//	int RandomSlime = rand() % 2;
		//	if (pMonster->MonsterHp > MONSTERSLIMEHP / 2)
		//	{
		//		pMonster->totalFrameSet = 0;
		//		pMonster->MonsterState = AttPrepar;
		//		pMonster->MonsterDelayTime = 0;
		//	}
		//	if(pMonster->MonsterHp < MONSTERSLIMEHP / 2)
		//	{
		//		if (RandomSlime == 0)
		//		{
		//			pMonster->totalFrameSet = 0;
		//			pMonster->MonsterState = AttPrepar;
		//			pMonster->MonsterDelayTime = 0;
		//		}
		//		else if (RandomSlime == 1)
		//		{
		//			pMonster->totalFrameSet = 0;
		//			pMonster->MonsterState = beforeLaser;
		//			pMonster->MonsterDelayTime = 0;
		//		}
		//		else
		//		{
		//			pMonster->MonsterSoundCheck = FALSE;
		//			// 몬스터 모션 바꿔주기
		//			pMonster->MonsterState = Die;
		//			// 시간 초기화
		//			pMonster->MonsterDelayTime = 0;
		//			pMonster->totalFrameSet = 0;
		//		}
		//	}
		//	
		//	// 몬스터 모션 바꿔주기
		//}
		break;
	case AttPrepar:
		//pMonster->NowMotionIndex = 1;
		//if (pMonster->MonsterSoundCheck == FALSE)
		//{
		//	soundSeek(SlimeBlowup, 0);
		//	soundPlay(SlimeBlowup);
		//	pMonster->MonsterSoundCheck = TRUE;
		//}
		//if (pMonster->MonsterHp < 0)
		//{
		//	pMonster->MonsterSoundCheck = FALSE;
		//	// 몬스터 모션 바꿔주기
		//	pMonster->MonsterState = Die;
		//	// 시간 초기화
		//	pMonster->MonsterDelayTime = 0;
		//	pMonster->totalFrameSet = 0;
		//}
		//if (pMonster->NowFrame == 4)
		//{
		//	pMonster->MonsterSoundCheck = FALSE;
		//	pMonster->totalFrameSet = 0;
		//	pMonster->MonsterState = RollAttack;
		//	//pMonster->NowFrame = 0;
		//}
		break;
	case RollAttack:
	//	pMonster->NowMotionIndex = 3;
	//	pMonster->MonsterDelayTime += SLGetElapsedTime();
	//	if (pMonster->MonsterDelayTime < 2800)
	//	{
	//		if (SlimeRollAtt->isPause == TRUE)
	//		{
	//			soundPlayLooping(SlimeRollAtt);
	//		}
	//		if (pMonster->MonsterHp < 0)
	//		{
	//			pMonster->MonsterSoundCheck = FALSE;
	//			// 몬스터 모션 바꿔주기
	//			pMonster->MonsterState = Die;
	//			// 시간 초기화
	//			pMonster->MonsterDelayTime = 0;
	//			pMonster->totalFrameSet = 0;
	//		}
	//		else
	//		{
	//			// 몬스터 이동한당~
	//			pMonster->MonDirX = pPlayer->PlayerPosX - pMonster->MonsterPosX;
	//			pMonster->MonDirY = pPlayer->PlayerPosY - pMonster->MonsterPosY;
	//			if (pMonster->MonDirX != 0 && pMonster->MonDirY != 0)
	//			{
	//				int NorDirX = pMonster->MonDirX / abs(pMonster->MonDirX);
	//				int NorDirY = pMonster->MonDirY / abs(pMonster->MonDirY);
	//				pMonster->MonsterPosX = pMonster->MonsterPosX + NorDirX * MONSTERROLLATTACKSPEED;
	//				pMonster->MonsterPosY = pMonster->MonsterPosY + NorDirY * MONSTERROLLATTACKSPEED;
	//			}
	//		}
	//	}
	//	else if (pMonster->MonsterDelayTime > 2800 && pMonster->NowFrame == 4)
	//	{
	//		if (SlimeRollAtt->isPause == FALSE)
	//		{
	//			soundPause(SlimeRollAtt);
	//		}
	//		if (pMonster->MonsterHp < 0)
	//		{
	//			pMonster->MonsterSoundCheck = FALSE;
	//			// 몬스터 모션 바꿔주기
	//			pMonster->MonsterState = Die;
	//			// 시간 초기화
	//			pMonster->MonsterDelayTime = 0;
	//			pMonster->totalFrameSet = 0;
	//		}
	//		else
	//		{
	//			pMonster->totalFrameSet = 0;
	//			pMonster->MonsterState = AfterAttack;
	//			pMonster->MonsterDelayTime = 0;
	//		}
	//	}
	//	break;
	//case AfterAttack:
	//	pMonster->NowMotionIndex = 2;
	//	if (pMonster->NowFrame == 4)
	//	{
	//		pMonster->totalFrameSet = 0;
	//		pMonster->MonsterState = Idle;
	//	}
	//	if (pMonster->MonsterHp < 0)
	//	{
	//		pMonster->MonsterSoundCheck = FALSE;
	//		// 몬스터 모션 바꿔주기
	//		pMonster->MonsterState = Die;
	//		// 시간 초기화
	//		pMonster->MonsterDelayTime = 0;
	//		pMonster->totalFrameSet = 0;
	//	}
	//	break;
	//case beforeLaser:
	//	pMonster->NowMotionIndex = 5;
	//	if (pMonster->NowFrame == 4)
	//	{
	//		pMonster->totalFrameSet = 0;
	//		pMonster->MonsterState = Laser;
	//	}
	//	if (pMonster->MonsterHp < 0)
	//	{
	//		pMonster->MonsterSoundCheck = FALSE;
	//		// 몬스터 모션 바꿔주기
	//		pMonster->MonsterState = Die;
	//		// 시간 초기화
	//		pMonster->MonsterDelayTime = 0;
	//		pMonster->totalFrameSet = 0;
	//	}
		break;
	case Laser:
		//pMonster->NowMotionIndex = 7;
		//if (pLaser->MonEffectInitial == FALSE)
		//{	// 한번만 해줘야 될꺼...
		//	pLaser->theta = atan2f(((float)pMonster->MonsterPosX - ((float)pPlayer->PlayerPosX - 200)),
		//		((float)pMonster->MonsterPosY - ((float)pPlayer->PlayerPosY - 200)));
		//	pLaser->Angle = (pLaser->theta * 180 / PI);
		//	pLaser->MonEffectPosX = (pMonster->MonsterPosX - 400 * sin(pLaser->theta)) - 230;
		//	pLaser->MonEffectPosY = (pMonster->MonsterPosY - 400 * cos(pLaser->theta)) - 200;
		//	pLaser->MonEffectNowFrame = 0;
		//	pLaser->EffecttotalFrameSet = 0;
		//	pLaser->MonEffectInitial = TRUE;
		//	if (pMonster->MonsterSoundCheck == FALSE)
		//	{
		//		soundSeek(SlimeLaser, 0);
		//		soundPlay(SlimeLaser);
		//		pMonster->MonsterSoundCheck = TRUE;
		//	}
		//}
		//pMonster->MonsterDelayTime += SLGetElapsedTime();
		//if (pMonster->MonsterDelayTime > 400 && pLaser->MonEffectNowFrame == 6)
		//{
		//	if (pMonster->MonsterHp < 0)
		//	{
		//		pMonster->MonsterSoundCheck = FALSE;
		//		// 몬스터 모션 바꿔주기
		//		pMonster->MonsterState = Die;
		//		// 시간 초기화
		//		pMonster->MonsterDelayTime = 0;
		//		pMonster->totalFrameSet = 0;
		//	}
		//	else
		//	{
		//		pMonster->totalFrameSet = 0;
		//		pMonster->MonsterDelayTime = 0;
		//		pMonster->MonsterState = AfterLaser;
		//		pMonster->MonsterSoundCheck = FALSE;
		//		pLaser->MonEffectInitial = FALSE;
		//	}
		//}
		break;
	case AfterLaser:
	//	pMonster->NowMotionIndex = 6;
	//	if (pMonster->NowFrame == 4)
	//	{
	//		pMonster->totalFrameSet = 0;
	//		pMonster->MonsterState = Idle;
	//	}
	//	if (pMonster->MonsterHp < 0)
	//	{
	//		pMonster->MonsterSoundCheck = FALSE;
	//		// 몬스터 모션 바꿔주기
	//		pMonster->MonsterState = Die;
	//		// 시간 초기화
	//		pMonster->MonsterDelayTime = 0;
	//		pMonster->totalFrameSet = 0;
	//		pMonster->MonsterSoundCheck = FALSE;
	//	}
	//	break;
	//case Die:
	//	pMonster->NowMotionIndex = 4;
	//	pMonster->MonsterAniDelayTime = 20;
	//	if (pMonster->MonsterSoundCheck == FALSE)
	//	{
	//		soundSeek(SlimeDie, 0);
	//		soundPlay(SlimeDie);
	//		pMonster->MonsterSoundCheck = TRUE;
	//	}
		break;
	}
}

void MonsterMagicianFSM(MONSTER* pMagicianMonster, PLAYER* pPlayer, MONSTEREFFECT* pMonsterEffect , MONSTEREFFECT* pMonsterDonwAtt,
	SoundInfo* MagicianLeftArm, SoundInfo* MagicianTwoSiedArm, SoundInfo* MagicianAtt, SoundInfo* MagicianDieSound)
{
	//if (pMagicianMonster->MonsterState == Die && pMagicianMonster->NowFrame == 3)
	//{
	//	// 이때는 프레임값이 올라가지 않는다.
	//}
	//else
	//{
	//	// 이펙트
	//	pMonsterDonwAtt->EffecttotalFrameSet++;
	//	pMonsterEffect->EffecttotalFrameSet++;
	//	// 몬스터
	//	pMagicianMonster->totalFrameSet++;
	//}

	//// 마법사
	//pMagicianMonster->NowFrame = (pMagicianMonster->totalFrameSet / pMagicianMonster->MonsterAniDelayTime) %
	//	pMagicianMonster->graphicRes->motions[pMagicianMonster->NowMotionIndex].spriteNum;
	//// 가시 위로 올라오는 이펙트
	//pMonsterEffect->MonEffectNowFrame = (pMonsterEffect->EffecttotalFrameSet / pMonsterEffect->MonEffectAniDelayTime) %
	//	pMonsterEffect->graphicRes->motions[pMonsterEffect->MonEffectNowMotionIndex].spriteNum;
	//// 가시 아래로 내려가는 이펙트
	//pMonsterDonwAtt->MonEffectNowFrame = (pMonsterDonwAtt->EffecttotalFrameSet / pMonsterDonwAtt->MonEffectAniDelayTime) %
	//	pMonsterDonwAtt->graphicRes->motions[pMonsterDonwAtt->MonEffectNowMotionIndex].spriteNum;

	//if (pMonsterEffect->MonEffectCheck == FALSE)
	//{
	//	// 위치값 받아주기
	//	pMonsterEffect->MonEffectPosX = pPlayer->PlayerPosX;
	//	pMonsterEffect->MonEffectPosY = pPlayer->PlayerPosY;
	//}

	/// 마법시의 FSM 설정
	//1. 마법사의 기본상태
	switch (pMagicianMonster->MonsterState)
	{
	case MagicianIdle:
		//pMagicianMonster->NowMotionIndex = 0;
		//pMagicianMonster->MonsterDelayTime += SLGetElapsedTime();
		//if (pMagicianMonster->MonsterDelayTime < 2000)
		//{
		//	if (pMagicianMonster->MonsterHp < 0)
		//	{
		//		// 몬스터 모션 바꿔주기
		//		pMagicianMonster->MonsterState = Die;
		//		// 시간 초기화
		//		pMagicianMonster->MonsterDelayTime = 0;
		//	}
		//}
		//else if (pMagicianMonster->MonsterDelayTime > 2000 && pMagicianMonster->NowFrame == 7)
		//{
		//	int Random = rand() % 2;
		//	// 프레임값 초기화
		//	pMagicianMonster->totalFrameSet = 0;
		//	// 시간 초기화
		//	pMagicianMonster->MonsterDelayTime = 0;
		//	// 몬스터 모션 바꿔주기

		//	if (pMagicianMonster->MonsterHp > MONSTERMAGICIANHP / 2)
		//	{
		//		pMagicianMonster->MonsterState = SwingMagician_Two_Side_ArmUP;
		//	}
		//	if (pMagicianMonster->MonsterHp < MONSTERMAGICIANHP / 2)
		//	{
		//		if (Random == 0)
		//		{
		//			pMagicianMonster->MonsterState = SwingMagician_Two_Side_ArmUP;
		//		}
		//		else
		//		{
		//			pMagicianMonster->MonsterState = SwingMagician_Left_ArmUP;
		//		}
		//	}
		//}
		break;
	case SwingMagician_Two_Side_ArmUP:
		/*pMagicianMonster->NowMotionIndex = 1;
		if (pMagicianMonster->MonsterSoundCheck == FALSE)
		{
			soundSeek(MagicianTwoSiedArm, 0);
			soundPlay(MagicianTwoSiedArm);
			pMagicianMonster->MonsterSoundCheck = TRUE;
		}
		if (pMagicianMonster->NowFrame == 3)
		{
			pMagicianMonster->totalFrameSet = 0;
			pMagicianMonster->MonsterState = SwingMagician_Two_Side_ArmAttack;
			pMagicianMonster->MonsterSoundCheck = FALSE;
		}*/
		break;
	case SwingMagician_Two_Side_ArmAttack:
		/*if (pMonsterEffect->MonEffectCheck == FALSE)
		{
			// 위치값 받아주기
			pMonsterEffect->MonEffectPosX = pPlayer->PlayerPosX;
			pMonsterEffect->MonEffectPosY = pPlayer->PlayerPosY;
			// 이펙트 프레임셋 초기화
			pMonsterEffect->EffecttotalFrameSet = 0;
			pMonsterEffect->MonEffectNowFrame = 0;
			pMonsterEffect->MonEffectNowMotionIndex = 0;
			//한번만 받아야될 정보들
			pMonsterEffect->MonEffectCheck = TRUE;
		}
		pMagicianMonster->NowMotionIndex = 2;
		pMagicianMonster->MonsterDelayTime += SLGetElapsedTime();

		if (pMagicianMonster->MonsterDelayTime > 3000
			&& pMonsterEffect->MonEffectNowFrame == 7 && pMonsterEffect->MonEffectNowMotionIndex == 2)
		{
			pMonsterEffect->MonEffectIndexCheck = FALSE;
			pMagicianMonster->MonsterDelayTime = 0;
			pMagicianMonster->totalFrameSet = 0;
			pMagicianMonster->MonsterState = SwingMagician_Two_Side_Arm_Down;
			pMonsterEffect->MonEffectCheck = FALSE;
		}
		else
		{
			if (pMonsterEffect->MonEffectNowMotionIndex == 0 && pMonsterEffect->MonEffectNowFrame == 7)
			{
				if (pMagicianMonster->MonsterSoundCheck == FALSE)
				{
					soundSeek(MagicianAtt, 0);
					soundPlay(MagicianAtt);
					pMagicianMonster->MonsterSoundCheck = TRUE;
				}
				pMonsterEffect->MonEffectNowFrame = 0;
				pMonsterEffect->EffecttotalFrameSet = 0;
				pMonsterEffect->MonEffectNowMotionIndex = 2;
			}
			if (pMonsterEffect->MonEffectNowMotionIndex == 2 && pMonsterEffect->MonEffectNowFrame == 0)
			{
				pMonsterEffect->MonEffectIndexCheck = TRUE;
			}
			if (pMonsterEffect->MonEffectNowMotionIndex == 2 && pMonsterEffect->MonEffectNowFrame == 7)
			{
				pMonsterEffect->MonEffectIndexCheck = FALSE;
				pMonsterEffect->EffecttotalFrameSet = 0;
				pMonsterEffect->MonEffectNowMotionIndex = 0;
				pMonsterEffect->MonEffectCheck = FALSE;
				pMagicianMonster->MonsterSoundCheck = FALSE;
			}
			// 여기서 가시 움직여주기

		}*/
		break;
	case SwingMagician_Two_Side_Arm_Down:
		/*pMagicianMonster->NowMotionIndex = 3;
		if (pMagicianMonster->NowFrame == 1)
		{
			pMagicianMonster->totalFrameSet = 0;
			pMagicianMonster->MonsterState = MagicianIdle;
		}*/
		break;
	case SwingMagician_Left_ArmUP:
		/*pMagicianMonster->NowMotionIndex = 4;
		if (pMagicianMonster->MonsterSoundCheck == FALSE)
		{
			soundSeek(MagicianLeftArm, 0);
			soundPlay(MagicianLeftArm);
			pMagicianMonster->MonsterSoundCheck = TRUE;
		}
		if (pMagicianMonster->NowFrame == 4)
		{
			pMagicianMonster->totalFrameSet = 0;
			pMagicianMonster->MonsterState = SwingMagician_Left_ArmAttack;
			pMagicianMonster->MonsterSoundCheck = FALSE;
		}*/
		break;
	case SwingMagician_Left_ArmAttack:
		// 가시 내려찍을 위치 정보 저장
		//pMagicianMonster->NowMotionIndex = 5;
		//if (pMonsterDonwAtt->MonEffectCheck == FALSE)
		//{
		//	pMonsterDonwAtt->MonEffectPosX = pPlayer->PlayerPosX - 200;
		//	pMonsterDonwAtt->MonEffectPosY = 0;
		//	pMonsterDonwAtt->MonEffectCheck = TRUE;
		//	//한번만 받아야될 정보들
		//}
		//if (pMagicianMonster->NowFrame == 4)
		//{
		//	// 이펙트 프레임셋 초기화
		//	pMonsterDonwAtt->EffecttotalFrameSet = 0;
		//	pMagicianMonster->totalFrameSet = 0;
		//	pMagicianMonster->MonsterState = SwingMagician_Left_ArmDown;
		//	pMonsterDonwAtt->MonEffectCheck = FALSE;
		//}
		break;
	case SwingMagician_Left_ArmDown:
		//pMagicianMonster->NowMotionIndex = 6;
		//if (pMonsterDonwAtt->MonEffectCheck == FALSE)
		//{	// 위치값 받아주기
		//	pMonsterDonwAtt->EffecttotalFrameSet = 0;
		//	pMonsterDonwAtt->MonEffectNowFrame = 0;
		//	pMonsterDonwAtt->MonEffectCheck = TRUE;

		//	pMonsterDonwAtt->MonEffectIndexCheck = TRUE;
		//}
		//if (pMagicianMonster->MonsterSoundCheck == FALSE)
		//{
		//	soundSeek(MagicianAtt, 0);
		//	soundPlay(MagicianAtt);
		//	pMagicianMonster->MonsterSoundCheck = TRUE;
		//}
		//if (pMagicianMonster->NowFrame == 3)
		//{
		//	
		//	pMagicianMonster->totalFrameSet = 0;
		//	pMagicianMonster->MonsterState = MagicianIdle;
		//	pMonsterDonwAtt->MonEffectCheck = FALSE;
		//	pMonsterDonwAtt->MonEffectIndexCheck = FALSE;
		//	pMagicianMonster->MonsterSoundCheck = FALSE;
		//}
		break;
	case MagicianDie:
		pMagicianMonster->NowMotionIndex = 7;
		break;
	}



}

int MonsterHitEffect(MONSTER* pMonster, MONSTEREFFECT* pMonsterEffect , int PlusPosX, int PlusPosY)
{
	pMonsterEffect->EffecttotalFrameSet++;
	pMonsterEffect->MonEffectNowFrame = (pMonsterEffect->EffecttotalFrameSet / pMonsterEffect->MonEffectAniDelayTime) %
		pMonsterEffect->graphicRes->motions[pMonsterEffect->MonEffectNowMotionIndex].spriteNum;

	pMonsterEffect->MonEffectPosX = pMonster->MonsterPosX + PlusPosX;
	pMonsterEffect->MonEffectPosY = pMonster->MonsterPosY + PlusPosY;

	if (pMonsterEffect->MonEffectCheck == TRUE)
	{
		pMonsterEffect->EffecttotalFrameSet = 0;
		pMonsterEffect->MonEffectCheck = FALSE;
	}

	if (pMonsterEffect->MonEffectNowFrame >= 0 && pMonsterEffect->MonEffectNowFrame < 5)
	{
		return 2;
	}
	return 0;
	/*else
	{
		pMonsterEffect->MonEffectCheck = TRUE;
	}*/
}
void SetMonsterMagicianUpAttBox(MONSTEREFFECT* sEffect)
{
	sEffect->MonEffectCollRect.left = sEffect->MonEffectPosX;
	sEffect->MonEffectCollRect.top = sEffect->MonEffectPosY;

	sEffect->MonEffectCollRect.right = sEffect->MonEffectPosX +
		sEffect->graphicRes->motions[sEffect->MonEffectNowMotionIndex].sheet->Width / 8;
	sEffect->MonEffectCollRect.bottom = sEffect->MonEffectPosY +
		sEffect->graphicRes->motions[sEffect->MonEffectNowMotionIndex].sheet->Height / 3;

}

void SetMonsterMagicianDownAttBox(MONSTEREFFECT* sEffect)
{
	sEffect->MonEffectCollRect.left = sEffect->MonEffectPosX;
	sEffect->MonEffectCollRect.top = sEffect->MonEffectPosY;

	sEffect->MonEffectCollRect.right = sEffect->MonEffectPosX +
		sEffect->graphicRes->motions[sEffect->MonEffectNowMotionIndex].sheet->Width / 6;
	sEffect->MonEffectCollRect.bottom = sEffect->MonEffectPosY +
		sEffect->graphicRes->motions[sEffect->MonEffectNowMotionIndex].sheet->Height;

}

void SetSlimeLaserCollBox(MONSTEREFFECT* pLaser)
{
	int XCenter, YCenter;
	int _width, _height;

	_width = pLaser->graphicRes->motions[pLaser->MonEffectNowMotionIndex].sheet->Width / 7;
	_height = pLaser->graphicRes->motions[pLaser->MonEffectNowMotionIndex].sheet->Height;

	XCenter = _width / 2;
	YCenter = _height / 2;

	int ChangeMemdcSize = sqrt(pow(_width, 2), pow(_width, 2));

	//
	int PosPlus = ChangeMemdcSize / 2 - 46;

	pLaser->LaserCollPt[0].x = XCenter + pLaser->MonEffectPosX + (-XCenter) * sin(pLaser->theta) - (-YCenter) * cos(pLaser->theta);
	pLaser->LaserCollPt[0].y = YCenter + pLaser->MonEffectPosY + PosPlus + (-XCenter) * cos(pLaser->theta) + (-YCenter) * sin(pLaser->theta);
	
	pLaser->LaserCollPt[1].x = XCenter + pLaser->MonEffectPosX + ((double)_width - XCenter) * sin(pLaser->theta) - (-YCenter) * cos(pLaser->theta);
	pLaser->LaserCollPt[1].y = YCenter + pLaser->MonEffectPosY + PosPlus + ((double)_width - XCenter) * cos(pLaser->theta) + (-YCenter) * sin(pLaser->theta);
	
	pLaser->LaserCollPt[2].x = XCenter + pLaser->MonEffectPosX + ((double)_width -XCenter) * sin(pLaser->theta) - ((double)_height - YCenter) * cos(pLaser->theta);
	pLaser->LaserCollPt[2].y = YCenter + pLaser->MonEffectPosY + PosPlus + ((double)_width -XCenter) * cos(pLaser->theta) + ((double)_height - YCenter) * sin(pLaser->theta);
	
	pLaser->LaserCollPt[3].x = XCenter + pLaser->MonEffectPosX + (-XCenter) * sin(pLaser->theta) - ((double)_height - YCenter) * cos(pLaser->theta);
	pLaser->LaserCollPt[3].y = YCenter + pLaser->MonEffectPosY + PosPlus + (-XCenter) * cos(pLaser->theta) + ((double)_height - YCenter) * sin(pLaser->theta);

}
