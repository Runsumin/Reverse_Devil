#include "Player.h"

// 리턴값에 따른 플레이어 애니메이션 출력

void InitializePlayer(PLAYER* Player, PLAYERWEAPON* Sword, SPLAYEREFFECT* PlayerEffect)
{
	// 플레이어 초기화
	Player->PlayerPosX = WINWIDTH / 2;
	Player->PlayerPosY = WINHEIGHT / 2;
	Player->PlayerDir = NoneRight;
	Player->PlayerAniIndex = 0;
	Player->PlayerSpriteIndex = 2;
	Player->PlayerHP = 5;
	Player->PlayerStamina = 3;
	Player->PlayerDodgeX = 0;
	Player->PlayerDodgeY = 0;

	Player->DodgeTime = FALSE;
	Player->DodgeCheck = FALSE;
	Player->PlayerDodgeContinueTime = 0;
	Player->PlayerInvincibility = FALSE;
	Player->PlayerHit = FALSE;
	Player->PlayerHitContinueTime = 0;
	Player->PlayerStaminaTime = 0;
	Player->PlayerDeathCheck = FALSE;
	
	// 플레이어 무기 초기화
	Sword->WeaPonPosX = 0;
	Sword->WeaPonPosY = 0;
	Sword->WeaPonWritePosX = 0;
	Sword->WeaPonWritePosY = 0;
	Sword->Angle = 0.f;
	Sword->theta = 0.f;

	// 무기 공격 관련 초기화
	Sword->WeaPonPosAttX = 0;
	Sword->WeaPonPosAttY = 0;
	Sword->AngleAtt = 0;
	Sword->WeaponAttStat = 1;

	Sword->WeaponCollPt[0].x = 0;
	Sword->WeaponCollPt[0].y = 0;
	Sword->WeaponCollPt[1].x = 0;
	Sword->WeaponCollPt[1].y = 0;
	Sword->WeaponCollPt[2].x = 0;
	Sword->WeaponCollPt[2].y = 0;
	Sword->WeaponCollPt[3].x = 0;
	Sword->WeaponCollPt[3].y = 0;

	Sword->WeaponIndexCount = 0;

	Sword->WeaponMouseCheck = FALSE;

	Sword->WeaponAttackCnt = 0;
	Sword->BeCollCheck = FALSE;
	Sword->WeaponSoundCheck = FALSE;



	// 이펙트 관련 초기화
	PlayerEffect->EffectPosX = 0;
	PlayerEffect->EffectPosY = 0;
	PlayerEffect->EffectDelayTime = 10;
	PlayerEffect->EffectNowIndex = 0;
}
void SetPlayerGraphicsRes(PLAYER* Player, SPLAYEREFFECT* pEffect, OneCharacterRes* graphicsRes, OneCharacterRes* graphicsRes2)
{
	Player->graphicRes = graphicsRes;
	pEffect->graphicRes = graphicsRes2;
}

void PlayerMove(PLAYER* pPlayer, PLAYERWEAPON* WeaPon , 
	SoundInfo* PlayerMoveSound,
	SoundInfo* PlayerDie,
	SoundInfo* PlayerDodge)
{
	// 플레이어 체력이 0일때
	if (pPlayer->PlayerHP == 0)
	{
		if (pPlayer->PlayerDir == UpLeft ||
			pPlayer->PlayerDir == DownLeft ||
			pPlayer->PlayerDir == Left ||
			pPlayer->PlayerDir == Down)
		{
			if (pPlayer->PlayerDeathCheck == FALSE)
			{
				soundSeek(PlayerDie, 0);
				soundPlay(PlayerDie);
				pPlayer->PlayerDeathCheck = TRUE;

			}
			pPlayer->PlayerAniIndex = 9;
		}
		else
		{
			if (pPlayer->PlayerDeathCheck == FALSE)
			{
				soundSeek(PlayerDie, 0);
				soundPlay(PlayerDie);
				pPlayer->PlayerDeathCheck = TRUE;

			}
			pPlayer->PlayerAniIndex = 8;
		}
	}
	// 플레이어 이동 제어
	else
	{
		// 화면 밖으로 안나가게
		if (pPlayer->PlayerPosX < 80)
		{
			pPlayer->PlayerPosX += PLAYER_SPEED ;
		}
		if (pPlayer->PlayerPosX > 1760)
		{
			pPlayer->PlayerPosX -= PLAYER_SPEED ;
		}
		if (pPlayer->PlayerPosY < 80)
		{
			pPlayer->PlayerPosY += PLAYER_SPEED;

		}
		if (pPlayer->PlayerPosY > 880)
		{
			pPlayer->PlayerPosY -= PLAYER_SPEED;
		}
		if (GetAsyncKeyState(VK_W) & 0x8000)
		{
			if (GetAsyncKeyState(VK_A) & 0x8000)
			{
				pPlayer->PlayerAniIndex = 3;
				pPlayer->PlayerPosX -= PLAYER_SPEED;
				pPlayer->PlayerDir = UpLeft;
			}
			else if (GetAsyncKeyState(VK_D) & 0x8000)
			{
				pPlayer->PlayerAniIndex = 1;
				pPlayer->PlayerPosX += PLAYER_SPEED;
				pPlayer->PlayerDir = UpRight;
			}
			pPlayer->PlayerAniIndex = 1;
			pPlayer->PlayerPosY -= PLAYER_SPEED;
			pPlayer->PlayerDir = Up;
			if (PlayerMoveSound->isPause == TRUE)
			{
				soundPlayLooping(PlayerMoveSound);
			}
		}
		else if (GetAsyncKeyState(VK_S) & 0x8000)
		{
			if (GetAsyncKeyState(VK_A) & 0x8000)
			{
				pPlayer->PlayerAniIndex = 3;
				pPlayer->PlayerPosX -= PLAYER_SPEED;
				pPlayer->PlayerDir = DownLeft;
			}
			else if (GetAsyncKeyState(VK_D) & 0x8000)
			{
				pPlayer->PlayerAniIndex = 1;
				pPlayer->PlayerPosX += PLAYER_SPEED;
				pPlayer->PlayerDir = DownRight;
			}
			pPlayer->PlayerAniIndex = 3;
			pPlayer->PlayerPosY += PLAYER_SPEED;
			pPlayer->PlayerDir = Down;
			if (PlayerMoveSound->isPause == TRUE)
			{
				soundPlayLooping(PlayerMoveSound);
			}
		}
		else if (GetAsyncKeyState(VK_A) & 0x8000)
		{
			if (GetAsyncKeyState(VK_W) & 0x8000)
			{
				pPlayer->PlayerAniIndex = 3;
				pPlayer->PlayerPosY -= PLAYER_SPEED;
				pPlayer->PlayerDir = UpLeft;
			}
			else if (GetAsyncKeyState(VK_S) & 0x8000)
			{
				pPlayer->PlayerAniIndex = 3;
				pPlayer->PlayerPosY += PLAYER_SPEED;
				pPlayer->PlayerDir = DownLeft;
			}

			pPlayer->PlayerPosX -= PLAYER_SPEED;
			pPlayer->PlayerAniIndex = 3;
			pPlayer->PlayerDir = Left;
			if (PlayerMoveSound->isPause == TRUE)
			{
				soundPlayLooping(PlayerMoveSound);
			}
		}
		else if (GetAsyncKeyState(VK_D) & 0x8000)
		{
			if (GetAsyncKeyState(VK_W) & 0x8000)
			{
				pPlayer->PlayerAniIndex = 1;
				pPlayer->PlayerPosY -= PLAYER_SPEED;
				pPlayer->PlayerDir = UpRight;

			}
			else if (GetAsyncKeyState(VK_S) & 0x8000)
			{
				pPlayer->PlayerAniIndex = 1;
				pPlayer->PlayerPosY += PLAYER_SPEED;
				pPlayer->PlayerDir = DownRight;
			}
			pPlayer->PlayerPosX += PLAYER_SPEED;
			pPlayer->PlayerAniIndex = 1;
			pPlayer->PlayerDir = Right;
			if (PlayerMoveSound->isPause == TRUE)
			{
				soundPlayLooping(PlayerMoveSound);
			}
		}
		else
		{
			if (PlayerMoveSound->isPause == FALSE)
			{
				soundPause(PlayerMoveSound);
			}

			if (pPlayer->PlayerDir == UpLeft ||
				pPlayer->PlayerDir == DownLeft ||
				pPlayer->PlayerDir == Left ||
				pPlayer->PlayerDir == Down)
			{
				pPlayer->PlayerAniIndex = 2;
			}
			else
			{
				pPlayer->PlayerAniIndex = 0;
			}
		}
		/// 회피 관련
		if (pPlayer->PlayerStamina > 0)
		{
			if (GetAsyncKeyState(VK_RBUTTON) & 0x8000 && pPlayer->DodgeTime == FALSE && pPlayer->DodgeCheck == FALSE)
			{
				soundSeek(PlayerDodge, 0);
				soundPlay(PlayerDodge);
				pPlayer->PlayerDir = Dodge;
				pPlayer->DodgeTime = TRUE;
				pPlayer->DodgeCheck = TRUE;
				pPlayer->PlayerStamina -= 1;
			}
		}

		if (pPlayer->PlayerStamina > 0)
		{
			/// 플레이어 회피 위한 함수
			if (pPlayer->DodgeTime == TRUE)
			{
				pPlayer->PlayerDodgeContinueTime += SLGetElapsedTime();

			}
			// 0.05초 동안 이동한다
			if (pPlayer->PlayerDodgeContinueTime > 50)
			{
				pPlayer->DodgeCheck = FALSE;
			}
			if (pPlayer->PlayerDodgeContinueTime > PLAYER_INVICIBILITY)
			{
				// 플레이어 무적
				pPlayer->PlayerInvincibility = FALSE;
			}
			if (pPlayer->PlayerDodgeContinueTime > PLAYER_DODGE_COOLTIME)
			{
				pPlayer->PlayerDodgeContinueTime = 0;
				pPlayer->DodgeTime = FALSE;
			}

			// 플레이어가 무기가 가리키는 방향(마우스 방향) 으로 움직인다
			if (pPlayer->DodgeCheck == TRUE)
			{
				pPlayer->PlayerInvincibility = TRUE;
				pPlayer->PlayerAniIndex = 6;

				pPlayer->PlayerDodgeX = WeaPon->WeaPonPosX - pPlayer->PlayerPosX;
				pPlayer->PlayerDodgeY = WeaPon->WeaPonPosY - pPlayer->PlayerPosY;

				if (pPlayer->PlayerDodgeX != 0 && pPlayer->PlayerDodgeY != 0)
				{
					float NorDirX = pPlayer->PlayerDodgeX / abs(pPlayer->PlayerDodgeX);
					float NorDirY = pPlayer->PlayerDodgeY / abs(pPlayer->PlayerDodgeY);
					pPlayer->PlayerPosX = pPlayer->PlayerPosX + (NorDirX * PLAYER_DODGE_POS);// 플레이어 회피 거리
					pPlayer->PlayerPosY = pPlayer->PlayerPosY + (NorDirY * PLAYER_DODGE_POS);
				}
			}
		}

		/// 플레이어 피격시
		if (pPlayer->PlayerHit == TRUE)
		{
			pPlayer->PlayerAniIndex = 7;
			pPlayer->PlayerHitContinueTime += SLGetElapsedTime();
		}
		// 무적이 된다
		if (pPlayer->PlayerHitContinueTime > PLAYER_HITTIME)
		{
			pPlayer->PlayerHit = FALSE;
			pPlayer->PlayerHitContinueTime = 0;
		}


		/// 스태미나 채워주기
		if (pPlayer->PlayerStamina < 3)
		{
			pPlayer->PlayerStaminaTime += SLGetElapsedTime();

			if (pPlayer->PlayerStaminaTime > PLAYER_STAMINACHARGE)
			{
				pPlayer->PlayerStamina += 1;
				pPlayer->PlayerStaminaTime = 0;
			}
		}

	}
	
	
}
// 플레이어 무기 회전
void PlayerWeaponMove(POINT MousePT, PLAYER* Player, PLAYERWEAPON* Sword ,int ViewX, int ViewY , SPLAYEREFFECT* PlayerEffect,
	SoundInfo* PlayerAtt1, SoundInfo* PlayerAtt2, SoundInfo* PlayerAtt3)
{
	Sword->theta = atan2f((((float)Player->PlayerPosX + 80 )- (float)MousePT.x),
		(((float)Player->PlayerPosY + 80) - (float)MousePT.y));
	Sword->Angle = (Sword->theta * 180 / PI);

	PlayerEffect->EffectAngle = Sword->Angle;

	Sword->WeaPonPosX = (Player->PlayerPosX - 80 * sin(Sword->theta));
	Sword->WeaPonPosY = (Player->PlayerPosY - 80 * cos(Sword->theta));

	PlayerEffect->EffectPosX = (Player->PlayerPosX - 80 * sin(Sword->theta));
	PlayerEffect->EffectPosY = (Player->PlayerPosY - 80 * cos(Sword->theta));


	// 마우스를 클릭해주면 루프를 시작한다
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && Sword->WeaponMouseCheck == FALSE)
	{
		Sword->WeaponMouseCheck = TRUE;
	}
	// 눌러진 상태라면 무기의 공격시간초 카운트를 해준다
	if (Sword->WeaponMouseCheck == TRUE)
	{
		// 어텍 모션 바꿔준다
		PlayerWeaponAttack(Sword, MousePT, Player, PlayerEffect);
		// 0.5초 카운트 시작
		Sword->WeaponIndexCount += SLGetElapsedTime();
		// 충돌 가능하다 알려주는 변수
		Sword->BeCollCheck = TRUE;
	}	
	// 일정 시간이 지나가면 공격시간초를 초기화해준다
	if (Sword->WeaponIndexCount > 500)
	{
		// 어텍 모션 올려주기
		Sword->WeaponAttackCnt += 1;
		// 어텍 카운트 오버되면 초기화
		if (Sword->WeaponAttackCnt > 2)
		{
			Sword->WeaponAttackCnt = 0;
		}
		// 카운트 초기화
		Sword->WeaponIndexCount = 0;
		// 충돌 불가능으로 바꿔주기
		Sword->BeCollCheck = FALSE;
		// 마우스 입력값 초기화
		Sword->WeaponMouseCheck = FALSE;

		Sword->WeaponSoundCheck = FALSE;
	}
	if (Sword->BeCollCheck == TRUE)
	{
		if (Sword->WeaponAttackCnt == 0 && Sword->WeaponSoundCheck == FALSE)
		{
			soundSeek(PlayerAtt1, 0);
			soundPlay(PlayerAtt1);
			Sword->WeaponSoundCheck = TRUE;
		}
		else if (Sword->WeaponAttackCnt == 1 && Sword->WeaponSoundCheck == FALSE)
		{
			soundSeek(PlayerAtt2, 0);
			soundPlay(PlayerAtt2);
			Sword->WeaponSoundCheck = TRUE;
		}
		else if (Sword->WeaponAttackCnt == 2 && Sword->WeaponSoundCheck == FALSE)
		{
			soundSeek(PlayerAtt3, 300);
			soundPlay(PlayerAtt3);
			Sword->WeaponSoundCheck = TRUE;
		}
	}

}
// 플레이어 무기 공격
void PlayerWeaponAttack(PLAYERWEAPON* Sword, POINT MousePt, PLAYER* Player , SPLAYEREFFECT* Effect)
{
	// 첫번째 공격
	if (Sword->WeaponAttackCnt == 0)
	{
		Effect->EffectNowIndex = 0;
		if (Sword->WeaponIndexCount > 0 && Sword->WeaponIndexCount < 500)
		{
			// 1. 클릭됫을때의 마우스 좌표에 따른 각도를 구해준다
			// 2. 그 각도만큼 움직여준다
			Sword->Angle -= 90;
			float theta2 = (Sword->Angle * PI) / 180.0f;
			Sword->WeaPonPosX = (Player->PlayerPosX - 80 * sin(theta2));
			Sword->WeaPonPosY = (Player->PlayerPosY - 80 * cos(theta2));

			Effect->EffectPosX = Sword->WeaPonPosX;
			Effect->EffectPosY = Sword->WeaPonPosY;

		}
	}
	// 두번째 공격
	else if (Sword->WeaponAttackCnt == 1)
	{
		
		if (Sword->WeaponIndexCount > 0 && Sword->WeaponIndexCount < 100 ||
			Sword->WeaponIndexCount > 200 && Sword->WeaponIndexCount < 300 ||
			Sword->WeaponIndexCount > 400 && Sword->WeaponIndexCount < 500)
		{
			Effect->EffectNowIndex = 1;
			/// 무기가 나아가야할 방향
			Sword->WeaPonPosAttX = Sword->WeaPonPosX - Player->PlayerPosX;
			Sword->WeaPonPosAttY = Sword->WeaPonPosY - Player->PlayerPosY;

			/// 무기가 나아가야할 방향
			Sword->WeaPonPosX = Sword->WeaPonPosX + (Sword->WeaPonPosAttX) / 2;
			Sword->WeaPonPosY = Sword->WeaPonPosY + (Sword->WeaPonPosAttY) / 2;

			Effect->EffectPosX = Sword->WeaPonPosX + (Sword->WeaPonPosAttX);
			Effect->EffectPosY = Sword->WeaPonPosY + (Sword->WeaPonPosAttY);
		}
	}
	// 세번째 공격
	else if (Sword->WeaponAttackCnt == 2)
	{
		Effect->EffectNowIndex = 2;
		if (Sword->WeaponIndexCount > 0 && Sword->WeaponIndexCount < 500)
		{
			/// 무기가 나아가야할 방향
			Sword->WeaPonPosAttX = Sword->WeaPonPosX - Player->PlayerPosX;
			Sword->WeaPonPosAttY = Sword->WeaPonPosY - Player->PlayerPosY;

			/// 무기가 나아가야할 방향
			Sword->WeaPonPosX = Sword->WeaPonPosX + (Sword->WeaPonPosAttX);
			Sword->WeaPonPosY = Sword->WeaPonPosY + (Sword->WeaPonPosAttY);

			Effect->EffectPosX = Sword->WeaPonPosX + (Sword->WeaPonPosAttX);
			Effect->EffectPosY = Sword->WeaPonPosY + (Sword->WeaPonPosAttY);
		}
	}
}

// 플레이어 무기 충돌을 위한 리전 설정
void SetPlayerWeaponCollBox(PLAYERWEAPON* Sword, SLBitmap* SwordBitmap)
{
	///변수 설정
	int XCenter, YCenter;

	int changeMemdcSize = max(SwordBitmap->Width, SwordBitmap->Height);

	// Lefttop, Righttop, RightBottom, LeftBottom

	XCenter = SwordBitmap->Width / 2;
	YCenter = SwordBitmap->Height / 2;

	// 4점의 회전
	// Lefttop
	Sword->WeaponCollPt[0].x = XCenter + Sword->WeaPonPosX  + ((double)0 - XCenter) * sin(Sword->theta) - ((double)20 - YCenter) * cos(Sword->theta);
	Sword->WeaponCollPt[0].y = YCenter + Sword->WeaPonPosY  + changeMemdcSize / 4 + ((double)0 - XCenter) * cos(Sword->theta) + ((double)20 - YCenter) * sin(Sword->theta);

	// RightTop
	Sword->WeaponCollPt[1].x = XCenter + Sword->WeaPonPosX + ((double)SwordBitmap->Width - XCenter) * sin(Sword->theta) - ((double)20 - YCenter) * cos(Sword->theta);
	Sword->WeaponCollPt[1].y = YCenter + Sword->WeaPonPosY + changeMemdcSize / 4 + ((double)SwordBitmap->Width - XCenter) * cos(Sword->theta) + ((double)20 - YCenter) * sin(Sword->theta);

	//RightBottom
	Sword->WeaponCollPt[2].x = XCenter + Sword->WeaPonPosX + ((double)SwordBitmap->Width - XCenter) * sin(Sword->theta) - ((double)SwordBitmap->Height - 20 - YCenter) * cos(Sword->theta);
	Sword->WeaponCollPt[2].y = YCenter + Sword->WeaPonPosY + changeMemdcSize / 4 + ((double)SwordBitmap->Width - XCenter) * cos(Sword->theta) + ((double)SwordBitmap->Height - 20 - YCenter) * sin(Sword->theta);

	//LeftBottom
	Sword->WeaponCollPt[3].x = XCenter + Sword->WeaPonPosX + ((double)0 - XCenter) * sin(Sword->theta) - ((double)SwordBitmap->Height - 20 - YCenter) * cos(Sword->theta);
	Sword->WeaponCollPt[3].y = YCenter + Sword->WeaPonPosY + changeMemdcSize / 4 + ((double)0 - XCenter) * cos(Sword->theta) + ((double)SwordBitmap->Height - 20 - YCenter) * sin(Sword->theta);

}

void SetPlayerCollBox(PLAYER* pPlayer)
{
	// Left, Top
	pPlayer->PlayerCollisionRect.left = pPlayer->PlayerPosX;
	pPlayer->PlayerCollisionRect.top = pPlayer->PlayerPosY;

	// Right, Bottom
	pPlayer->PlayerCollisionRect.right = pPlayer->PlayerPosX + pPlayer->graphicRes->sheet->Width / 5;
	pPlayer->PlayerCollisionRect.bottom = pPlayer->PlayerPosY + pPlayer->graphicRes->sheet->Height / 8;
}
