#include "Player.h"

// ���ϰ��� ���� �÷��̾� �ִϸ��̼� ���

void InitializePlayer(PLAYER* Player, PLAYERWEAPON* Sword, SPLAYEREFFECT* PlayerEffect)
{
	// �÷��̾� �ʱ�ȭ
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
	
	// �÷��̾� ���� �ʱ�ȭ
	Sword->WeaPonPosX = 0;
	Sword->WeaPonPosY = 0;
	Sword->WeaPonWritePosX = 0;
	Sword->WeaPonWritePosY = 0;
	Sword->Angle = 0.f;
	Sword->theta = 0.f;

	// ���� ���� ���� �ʱ�ȭ
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



	// ����Ʈ ���� �ʱ�ȭ
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
	// �÷��̾� ü���� 0�϶�
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
	// �÷��̾� �̵� ����
	else
	{
		// ȭ�� ������ �ȳ�����
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
		/// ȸ�� ����
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
			/// �÷��̾� ȸ�� ���� �Լ�
			if (pPlayer->DodgeTime == TRUE)
			{
				pPlayer->PlayerDodgeContinueTime += SLGetElapsedTime();

			}
			// 0.05�� ���� �̵��Ѵ�
			if (pPlayer->PlayerDodgeContinueTime > 50)
			{
				pPlayer->DodgeCheck = FALSE;
			}
			if (pPlayer->PlayerDodgeContinueTime > PLAYER_INVICIBILITY)
			{
				// �÷��̾� ����
				pPlayer->PlayerInvincibility = FALSE;
			}
			if (pPlayer->PlayerDodgeContinueTime > PLAYER_DODGE_COOLTIME)
			{
				pPlayer->PlayerDodgeContinueTime = 0;
				pPlayer->DodgeTime = FALSE;
			}

			// �÷��̾ ���Ⱑ ����Ű�� ����(���콺 ����) ���� �����δ�
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
					pPlayer->PlayerPosX = pPlayer->PlayerPosX + (NorDirX * PLAYER_DODGE_POS);// �÷��̾� ȸ�� �Ÿ�
					pPlayer->PlayerPosY = pPlayer->PlayerPosY + (NorDirY * PLAYER_DODGE_POS);
				}
			}
		}

		/// �÷��̾� �ǰݽ�
		if (pPlayer->PlayerHit == TRUE)
		{
			pPlayer->PlayerAniIndex = 7;
			pPlayer->PlayerHitContinueTime += SLGetElapsedTime();
		}
		// ������ �ȴ�
		if (pPlayer->PlayerHitContinueTime > PLAYER_HITTIME)
		{
			pPlayer->PlayerHit = FALSE;
			pPlayer->PlayerHitContinueTime = 0;
		}


		/// ���¹̳� ä���ֱ�
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
// �÷��̾� ���� ȸ��
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


	// ���콺�� Ŭ�����ָ� ������ �����Ѵ�
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && Sword->WeaponMouseCheck == FALSE)
	{
		Sword->WeaponMouseCheck = TRUE;
	}
	// ������ ���¶�� ������ ���ݽð��� ī��Ʈ�� ���ش�
	if (Sword->WeaponMouseCheck == TRUE)
	{
		// ���� ��� �ٲ��ش�
		PlayerWeaponAttack(Sword, MousePT, Player, PlayerEffect);
		// 0.5�� ī��Ʈ ����
		Sword->WeaponIndexCount += SLGetElapsedTime();
		// �浹 �����ϴ� �˷��ִ� ����
		Sword->BeCollCheck = TRUE;
	}	
	// ���� �ð��� �������� ���ݽð��ʸ� �ʱ�ȭ���ش�
	if (Sword->WeaponIndexCount > 500)
	{
		// ���� ��� �÷��ֱ�
		Sword->WeaponAttackCnt += 1;
		// ���� ī��Ʈ �����Ǹ� �ʱ�ȭ
		if (Sword->WeaponAttackCnt > 2)
		{
			Sword->WeaponAttackCnt = 0;
		}
		// ī��Ʈ �ʱ�ȭ
		Sword->WeaponIndexCount = 0;
		// �浹 �Ұ������� �ٲ��ֱ�
		Sword->BeCollCheck = FALSE;
		// ���콺 �Է°� �ʱ�ȭ
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
// �÷��̾� ���� ����
void PlayerWeaponAttack(PLAYERWEAPON* Sword, POINT MousePt, PLAYER* Player , SPLAYEREFFECT* Effect)
{
	// ù��° ����
	if (Sword->WeaponAttackCnt == 0)
	{
		Effect->EffectNowIndex = 0;
		if (Sword->WeaponIndexCount > 0 && Sword->WeaponIndexCount < 500)
		{
			// 1. Ŭ���������� ���콺 ��ǥ�� ���� ������ �����ش�
			// 2. �� ������ŭ �������ش�
			Sword->Angle -= 90;
			float theta2 = (Sword->Angle * PI) / 180.0f;
			Sword->WeaPonPosX = (Player->PlayerPosX - 80 * sin(theta2));
			Sword->WeaPonPosY = (Player->PlayerPosY - 80 * cos(theta2));

			Effect->EffectPosX = Sword->WeaPonPosX;
			Effect->EffectPosY = Sword->WeaPonPosY;

		}
	}
	// �ι�° ����
	else if (Sword->WeaponAttackCnt == 1)
	{
		
		if (Sword->WeaponIndexCount > 0 && Sword->WeaponIndexCount < 100 ||
			Sword->WeaponIndexCount > 200 && Sword->WeaponIndexCount < 300 ||
			Sword->WeaponIndexCount > 400 && Sword->WeaponIndexCount < 500)
		{
			Effect->EffectNowIndex = 1;
			/// ���Ⱑ ���ư����� ����
			Sword->WeaPonPosAttX = Sword->WeaPonPosX - Player->PlayerPosX;
			Sword->WeaPonPosAttY = Sword->WeaPonPosY - Player->PlayerPosY;

			/// ���Ⱑ ���ư����� ����
			Sword->WeaPonPosX = Sword->WeaPonPosX + (Sword->WeaPonPosAttX) / 2;
			Sword->WeaPonPosY = Sword->WeaPonPosY + (Sword->WeaPonPosAttY) / 2;

			Effect->EffectPosX = Sword->WeaPonPosX + (Sword->WeaPonPosAttX);
			Effect->EffectPosY = Sword->WeaPonPosY + (Sword->WeaPonPosAttY);
		}
	}
	// ����° ����
	else if (Sword->WeaponAttackCnt == 2)
	{
		Effect->EffectNowIndex = 2;
		if (Sword->WeaponIndexCount > 0 && Sword->WeaponIndexCount < 500)
		{
			/// ���Ⱑ ���ư����� ����
			Sword->WeaPonPosAttX = Sword->WeaPonPosX - Player->PlayerPosX;
			Sword->WeaPonPosAttY = Sword->WeaPonPosY - Player->PlayerPosY;

			/// ���Ⱑ ���ư����� ����
			Sword->WeaPonPosX = Sword->WeaPonPosX + (Sword->WeaPonPosAttX);
			Sword->WeaPonPosY = Sword->WeaPonPosY + (Sword->WeaPonPosAttY);

			Effect->EffectPosX = Sword->WeaPonPosX + (Sword->WeaPonPosAttX);
			Effect->EffectPosY = Sword->WeaPonPosY + (Sword->WeaPonPosAttY);
		}
	}
}

// �÷��̾� ���� �浹�� ���� ���� ����
void SetPlayerWeaponCollBox(PLAYERWEAPON* Sword, SLBitmap* SwordBitmap)
{
	///���� ����
	int XCenter, YCenter;

	int changeMemdcSize = max(SwordBitmap->Width, SwordBitmap->Height);

	// Lefttop, Righttop, RightBottom, LeftBottom

	XCenter = SwordBitmap->Width / 2;
	YCenter = SwordBitmap->Height / 2;

	// 4���� ȸ��
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
