#pragma once
#include "SLDefine.h"
#include "Sound.h"
#include "SLTime.h"

typedef struct _sPlayer
{
	// �÷��̾� ü��
	int PlayerHP;
	// �÷��̾� ���׹̳�
	int PlayerStamina;
	// �÷��̾� ����
	Direction PlayerDir;
	// �÷��̾� �ִϸ��̼� �ε���
	int PlayerAniIndex;
	// �÷��̾� ��������Ʈ �ε���
	int PlayerSpriteIndex;
	//�÷��̾� ��ġ
	int PlayerPosX;
	int PlayerPosY;


	///�浹 ó���� ���� ����ü
	RECT PlayerCollisionRect;


	// �÷��̾� ȸ�� �̵�����
	int PlayerDodgeX;
	int PlayerDodgeY;

	// �ѹ��� ��������
	BOOL DodgeTime;
	BOOL DodgeCheck;
	 
	// �÷��̾� ȸ�� �ӽñ���
	int PlayerDodgeContinueTime;

	/// ���ҽ� ����
	OneCharacterRes* graphicRes;
	 
	/// �÷��̾� ��������
	BOOL PlayerInvincibility;
	// �÷��̾ ����
	BOOL PlayerHit;
	int PlayerHitContinueTime;

	int PlayerStaminaTime;

	BOOL PlayerMoveSoundCheck;

	BOOL PlayerDeathCheck;

}PLAYER;

typedef struct _sWeapon
{
	// ������ ���� ��ġ
	int WeaPonPosX;
	int WeaPonPosY;

	// ������ ��� ��ġ
	int WeaPonWritePosX;
	int WeaPonWritePosY;

	// ����� �÷��̾��� �������
	float theta;
	float Angle;

	// ������ ���ݽ� ������ ���� ����
	int WeaPonPosAttX;
	int WeaPonPosAttY;
	float AngleAtt;

	//�浹 ó���� ���� ����ü
	//RECT WeaponCollisionRect;

	HRGN WeaponCollRegion;

	POINT WeaponCollPt[4];

	/// ������ ����
	// ������ ���ݷ�
	int WeaponAttStat;

	// ������ ���ݽð��� ī��Ʈ
	DWORD WeaponIndexCount;

	// ���콺�� �ԷµǾ��ִ��� üũ�ϴ� ����
	BOOL WeaponMouseCheck;

	// �÷��̾� ���� ���� ī��Ʈ
	int WeaponAttackCnt;


	// �÷��̾� ���� �浹 ���� �Ǵ� ����
	BOOL BeCollCheck;

	// ���� ���� ���� üũ
	BOOL WeaponSoundCheck;

	

} PLAYERWEAPON;


typedef struct PLAYEREFFECT
{
	// ����Ʈ ���� ��ġ
	int EffectPosX;
	int EffectPosY;

	// ����Ʈ �ִϸ��̼� ������ Ÿ��
	int EffectDelayTime;

	// ���� ����Ǵ� ����Ʈ �ε���
	int EffectNowIndex;

	//ȸ�� ���� ����
	float Effecttheta;
	float EffectAngle;

	/// ���ҽ� ����
	OneCharacterRes* graphicRes;

	// ����Ʈ �浹�ڽ�(����)
} SPLAYEREFFECT;



void InitializePlayer(PLAYER* Player, PLAYERWEAPON* Sword, SPLAYEREFFECT* PlayerEffect);
// �÷��̾� ���ҽ� ���� �ʱ�ȭ
void SetPlayerGraphicsRes(PLAYER* Player, SPLAYEREFFECT* pEffect, OneCharacterRes* graphicsRes, OneCharacterRes* graphicsRes2);
// ���� �÷��̾� ������
void PlayerMove(PLAYER* pPlayer, PLAYERWEAPON* WeaPon, SoundInfo* PlayerMoveSound, SoundInfo* PlayerDie, SoundInfo* PlayerDodge);
// �÷��̾� ���� ������
void PlayerWeaponMove(POINT MousePT, PLAYER* Player, PLAYERWEAPON* Sword, int ViewX, int ViewY, SPLAYEREFFECT* PlayerEffect, SoundInfo* PlayerAtt1, SoundInfo* PlayerAtt2, SoundInfo* PlayerAtt3);
void PlayerWeaponAttack(PLAYERWEAPON* Sword, POINT MousePt, PLAYER* Player, SPLAYEREFFECT* Effect);
// �÷��̾� ���� �浹�ڽ� ���� �ѱ��
void SetPlayerWeaponCollBox(PLAYERWEAPON* Sword, SLBitmap* SwordBitmap);
// �÷��̾� �浹�ڽ� ���� �ѱ��
void SetPlayerCollBox(PLAYER* pPlayer);