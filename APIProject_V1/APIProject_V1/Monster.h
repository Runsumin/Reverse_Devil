#pragma once
#include "SLDefine.h"
#include "Player.h"

//몬스터 상태
typedef enum _MosterState
{
	Idle, AttPrepar, RollAttack, AfterAttack, beforeLaser ,Laser, AfterLaser,Die
} Slime;

typedef enum _MosterMagician
{
	MagicianIdle, SwingMagician_Two_Side_ArmUP, SwingMagician_Two_Side_ArmAttack,
	SwingMagician_Two_Side_Arm_Down, SwingMagician_Left_ArmUP , SwingMagician_Left_ArmAttack,
	SwingMagician_Left_ArmDown, MagicianDie
} Magician;


// 몬스터의 메타정보를 담은 구조체
typedef struct _sMonster
{
	// 몬스터 위치
	int MonsterPosX;
	int MonsterPosY;
	// 몬스터 체력
	int MonsterHp;
	// 몬스터 충돌 박스
	RECT MonsterRect;


	// 몬스터 애니메이션 위한 변수들
	int NowMotionIndex;				// 현재 모션

	int MonsterSpriteNum;			/// 애니메이션 가로 (필요없음. 리소스에 들어있음)

	int MonsterAniDelayTime;		// 애니메이션 딜레이값

	int NowFrame;					// 애니메이션이 재생될 스프라이트 개수

	Slime MonsterState;				// FSM 위한 몬스터 상태

	// 몬스터 패턴 딜레이 타임
	DWORD MonsterDelayTime;


	// 몬스터 방향값
	int MonDirX;
	int MonDirY;

	// 애니메이션 물흐르듯 제어를 위한 변수들
	BOOL MonflowTime;
	int SeperTime;
	/// 리소스 정보
	OneCharacterRes* graphicRes;

	int totalFrameSet;

	/// 사운드
	BOOL MonsterSoundCheck;

}MONSTER;


typedef struct MonsterEffect
{
	// 좌표
	int MonEffectPosX;
	int MonEffectPosY;

	// 충돌박스
	RECT MonEffectCollRect;

	// 몬스터 애니메이션 위한 변수들
	int MonEffectNowMotionIndex;			// 현재 모션

	int MonEffectSpriteNum;					/// 애니메이션 가로 (필요없음. 리소스에 들어있음)

	int MonEffectAniDelayTime;				// 애니메이션 딜레이값

	int MonEffectNowFrame;					// 애니메이션이 재생될 스프라이트 개수

	BOOL MonEffectCheck;
	BOOL MonEffectIndexCheck;

	float Angle;
	float theta;


	BOOL MonEffectInitial;
	/// 리소스 정보
	OneCharacterRes* graphicRes;

	int EffecttotalFrameSet;

	/// 레이저를 위한 충돌 리전

	HRGN LaserRegion;

	POINT LaserCollPt[4];

} MONSTEREFFECT;



// 몬스터 정보 초기화
void InitializeMonster(MONSTER* sMonster, int MonPosX, int MonPosY, int MonsterHP);
void InitializMonEffect(MONSTEREFFECT* sEffect);

// 몬스터 충돌박스 정보 넘기기
void SetMonsterCollBox(MONSTER* sMonster);
void SetMonsterMagicianCollBox(MONSTER* sMonster);

// 몬스터에게 그래픽 리소스 할당
void SetMonsterGraphicsRes(MONSTER* sMonster, OneCharacterRes* graphicsRes);
void SetMonsterEffectGraphicsRes(MONSTEREFFECT* sEffect, OneCharacterRes* graphicsRes);

// 몬스터 FSM
void MonsterSlimeFSM(MONSTER* pMonster, PLAYER* pPlayer, MONSTEREFFECT* pLaser, SoundInfo* SlimeMove, SoundInfo* SlimeRollAtt, SoundInfo* SlimeBlowup, SoundInfo* SlimeLaser, SoundInfo* SlimeDie);
void MonsterMagicianFSM(MONSTER* pMagicianMonster, PLAYER* pPlayer, MONSTEREFFECT* pMonsterEffect, MONSTEREFFECT* pMonsterDonwAtt, SoundInfo* MagicianLeftArm, SoundInfo* MagicianTwoSiedArm, SoundInfo* MagicianAtt, SoundInfo* MagicianDie);
int MonsterHitEffect(MONSTER* pMonster, MONSTEREFFECT* pMonsterEffect, int PlusPosX, int PlusPosY);
// 마법사 가시 충돌박스 설정
void SetMonsterMagicianUpAttBox(MONSTEREFFECT* sEffect);
void SetMonsterMagicianDownAttBox(MONSTEREFFECT* sEffect);
void SetSlimeLaserCollBox(MONSTEREFFECT* pLaser);