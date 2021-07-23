#pragma once
#include "SLDefine.h"
#include "Sound.h"
#include "SLTime.h"

typedef struct _sPlayer
{
	// 플레이어 체력
	int PlayerHP;
	// 플레이어 스테미나
	int PlayerStamina;
	// 플레이어 방향
	Direction PlayerDir;
	// 플레이어 애니메이션 인덱스
	int PlayerAniIndex;
	// 플레이어 스프라이트 인덱스
	int PlayerSpriteIndex;
	//플레이어 위치
	int PlayerPosX;
	int PlayerPosY;


	///충돌 처리를 위한 구조체
	RECT PlayerCollisionRect;


	// 플레이어 회피 이동범위
	int PlayerDodgeX;
	int PlayerDodgeY;

	// 한번만 눌러주자
	BOOL DodgeTime;
	BOOL DodgeCheck;
	 
	// 플레이어 회피 임시구현
	int PlayerDodgeContinueTime;

	/// 리소스 정보
	OneCharacterRes* graphicRes;
	 
	/// 플레이어 무적판정
	BOOL PlayerInvincibility;
	// 플레이어가 맞음
	BOOL PlayerHit;
	int PlayerHitContinueTime;

	int PlayerStaminaTime;

	BOOL PlayerMoveSoundCheck;

	BOOL PlayerDeathCheck;

}PLAYER;

typedef struct _sWeapon
{
	// 무기의 실제 위치
	int WeaPonPosX;
	int WeaPonPosY;

	// 무기의 출력 위치
	int WeaPonWritePosX;
	int WeaPonWritePosY;

	// 무기와 플레이어의 각도계산
	float theta;
	float Angle;

	// 무기의 공격시 움직임 관련 변수
	int WeaPonPosAttX;
	int WeaPonPosAttY;
	float AngleAtt;

	//충돌 처리를 위한 구조체
	//RECT WeaponCollisionRect;

	HRGN WeaponCollRegion;

	POINT WeaponCollPt[4];

	/// 무기의 스텟
	// 무기의 공격력
	int WeaponAttStat;

	// 무기의 공격시간초 카운트
	DWORD WeaponIndexCount;

	// 마우스가 입력되어있는지 체크하는 변수
	BOOL WeaponMouseCheck;

	// 플레이어 공격 유형 카운트
	int WeaponAttackCnt;


	// 플레이어 무기 충돌 가능 판단 변수
	BOOL BeCollCheck;

	// 무기 사운드 가능 체크
	BOOL WeaponSoundCheck;

	

} PLAYERWEAPON;


typedef struct PLAYEREFFECT
{
	// 이펙트 생성 위치
	int EffectPosX;
	int EffectPosY;

	// 이펙트 애니메이션 딜레이 타임
	int EffectDelayTime;

	// 현재 재생되는 이펙트 인덱스
	int EffectNowIndex;

	//회전 위한 정보
	float Effecttheta;
	float EffectAngle;

	/// 리소스 정보
	OneCharacterRes* graphicRes;

	// 이펙트 충돌박스(몬스터)
} SPLAYEREFFECT;



void InitializePlayer(PLAYER* Player, PLAYERWEAPON* Sword, SPLAYEREFFECT* PlayerEffect);
// 플레이어 리소스 정보 초기화
void SetPlayerGraphicsRes(PLAYER* Player, SPLAYEREFFECT* pEffect, OneCharacterRes* graphicsRes, OneCharacterRes* graphicsRes2);
// 실제 플레이어 움직임
void PlayerMove(PLAYER* pPlayer, PLAYERWEAPON* WeaPon, SoundInfo* PlayerMoveSound, SoundInfo* PlayerDie, SoundInfo* PlayerDodge);
// 플레이어 무기 움직임
void PlayerWeaponMove(POINT MousePT, PLAYER* Player, PLAYERWEAPON* Sword, int ViewX, int ViewY, SPLAYEREFFECT* PlayerEffect, SoundInfo* PlayerAtt1, SoundInfo* PlayerAtt2, SoundInfo* PlayerAtt3);
void PlayerWeaponAttack(PLAYERWEAPON* Sword, POINT MousePt, PLAYER* Player, SPLAYEREFFECT* Effect);
// 플레이어 무기 충돌박스 정보 넘기기
void SetPlayerWeaponCollBox(PLAYERWEAPON* Sword, SLBitmap* SwordBitmap);
// 플레이어 충돌박스 정보 넘기기
void SetPlayerCollBox(PLAYER* pPlayer);