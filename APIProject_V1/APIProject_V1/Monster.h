#pragma once
#include "SLDefine.h"
#include "Player.h"

//���� ����
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


// ������ ��Ÿ������ ���� ����ü
typedef struct _sMonster
{
	// ���� ��ġ
	int MonsterPosX;
	int MonsterPosY;
	// ���� ü��
	int MonsterHp;
	// ���� �浹 �ڽ�
	RECT MonsterRect;


	// ���� �ִϸ��̼� ���� ������
	int NowMotionIndex;				// ���� ���

	int MonsterSpriteNum;			/// �ִϸ��̼� ���� (�ʿ����. ���ҽ��� �������)

	int MonsterAniDelayTime;		// �ִϸ��̼� �����̰�

	int NowFrame;					// �ִϸ��̼��� ����� ��������Ʈ ����

	Slime MonsterState;				// FSM ���� ���� ����

	// ���� ���� ������ Ÿ��
	DWORD MonsterDelayTime;


	// ���� ���Ⱚ
	int MonDirX;
	int MonDirY;

	// �ִϸ��̼� ���帣�� ��� ���� ������
	BOOL MonflowTime;
	int SeperTime;
	/// ���ҽ� ����
	OneCharacterRes* graphicRes;

	int totalFrameSet;

	/// ����
	BOOL MonsterSoundCheck;

}MONSTER;


typedef struct MonsterEffect
{
	// ��ǥ
	int MonEffectPosX;
	int MonEffectPosY;

	// �浹�ڽ�
	RECT MonEffectCollRect;

	// ���� �ִϸ��̼� ���� ������
	int MonEffectNowMotionIndex;			// ���� ���

	int MonEffectSpriteNum;					/// �ִϸ��̼� ���� (�ʿ����. ���ҽ��� �������)

	int MonEffectAniDelayTime;				// �ִϸ��̼� �����̰�

	int MonEffectNowFrame;					// �ִϸ��̼��� ����� ��������Ʈ ����

	BOOL MonEffectCheck;
	BOOL MonEffectIndexCheck;

	float Angle;
	float theta;


	BOOL MonEffectInitial;
	/// ���ҽ� ����
	OneCharacterRes* graphicRes;

	int EffecttotalFrameSet;

	/// �������� ���� �浹 ����

	HRGN LaserRegion;

	POINT LaserCollPt[4];

} MONSTEREFFECT;



// ���� ���� �ʱ�ȭ
void InitializeMonster(MONSTER* sMonster, int MonPosX, int MonPosY, int MonsterHP);
void InitializMonEffect(MONSTEREFFECT* sEffect);

// ���� �浹�ڽ� ���� �ѱ��
void SetMonsterCollBox(MONSTER* sMonster);
void SetMonsterMagicianCollBox(MONSTER* sMonster);

// ���Ϳ��� �׷��� ���ҽ� �Ҵ�
void SetMonsterGraphicsRes(MONSTER* sMonster, OneCharacterRes* graphicsRes);
void SetMonsterEffectGraphicsRes(MONSTEREFFECT* sEffect, OneCharacterRes* graphicsRes);

// ���� FSM
void MonsterSlimeFSM(MONSTER* pMonster, PLAYER* pPlayer, MONSTEREFFECT* pLaser, SoundInfo* SlimeMove, SoundInfo* SlimeRollAtt, SoundInfo* SlimeBlowup, SoundInfo* SlimeLaser, SoundInfo* SlimeDie);
void MonsterMagicianFSM(MONSTER* pMagicianMonster, PLAYER* pPlayer, MONSTEREFFECT* pMonsterEffect, MONSTEREFFECT* pMonsterDonwAtt, SoundInfo* MagicianLeftArm, SoundInfo* MagicianTwoSiedArm, SoundInfo* MagicianAtt, SoundInfo* MagicianDie);
int MonsterHitEffect(MONSTER* pMonster, MONSTEREFFECT* pMonsterEffect, int PlusPosX, int PlusPosY);
// ������ ���� �浹�ڽ� ����
void SetMonsterMagicianUpAttBox(MONSTEREFFECT* sEffect);
void SetMonsterMagicianDownAttBox(MONSTEREFFECT* sEffect);
void SetSlimeLaserCollBox(MONSTEREFFECT* pLaser);