#include "Main.h"
#include "Sound.h"
BOOL DebugCheck;

BOOL MapChange;

BOOL SoundChange;
/// ��Ʈ�� �ε� 
// BackGround
SLBitmap StartSceneBitMap;		// ����ȭ��
SLBitmap InitSceneBitMap;		// �������ִ¹�
SLBitmap BackGroundBitMap;		// �����ӹ�
SLBitmap SceneMagicianBitMap;	// �������
SLBitmap SceneClearBitMap;		// Ŭ����
SLBitmap SceneDeathBitMap;		// �÷��̾� ���

// �÷��̾� ����
SLBitmap PlayerBitMap;
SLBitmap PlayerWeapon;
SLBitmap PlayerEffect;

// ���� ����
SLBitmap SlimeMonster;
SLBitmap SlimeLaser;
SLBitmap MagicianBitmap;
SLBitmap MagicianAttackBitmap;
SLBitmap MagicianDownAttBitmap;


// ���� ��Ʈ ����Ʈ
SLBitmap MonsterHitBitmap;

// UI ����
SLBitmap UI_HPBar;
SLBitmap UI_HPBardeath;
SLBitmap UI_StaminaBar;
SLBitmap UI_StaminaBarDeath;
SLBitmap UI_Cursur;


// ���� ������Ʈ ����
SLBitmap StairsBitmap;

/// ����ü ����

// �÷��̾� ���� ����ü ����
PLAYER _sPlayer;				// �÷��̾�
PLAYERWEAPON _sSword;			// ����
SPLAYEREFFECT _sPLAYEREffect;	// �÷��̾� ����Ʈ


// ���� ���� �ʱ�ȭ
MONSTER _sSlime;				// ������
MONSTER _Magician;				// ������

// ������ ���� �׷��� �ʱ�ȭ
MONSTEREFFECT _MagicianEffect;		// ������ ���ΰ���
MONSTEREFFECT _MagicianEffectDown;	// ������ �Ʒ��� ����
MONSTEREFFECT _SlimeLaser;			// ������ ������
MONSTEREFFECT _MonsgerHitEff;		// ���� ��Ʈ ����Ʈ

// ��� ���� ����ü
TERRAINOBJECT _Stairs;


///ȭ�� ��ȯ ���� ����
CHANGEWINVIEW ChangeView;

// ���ҽ� ���� ���� ����ü
OneCharacterRes _PlayerInfo;				// �÷��̾�
OneCharacterRes _PlayerEffectInfo;			// �÷��̾� ����Ʈ
OneCharacterRes _SlimeMonInfo;				// ������
OneCharacterRes _MagicianInfo;				// ������
OneCharacterRes _SlimeLaserInfo;			// ������ ������
OneCharacterRes _MagicianEffectInfo;		// ������ �������� ����Ʈ
OneCharacterRes _MagicianDownAttInfo;		// ������ ū����
OneCharacterRes _MonsterHitEffInfo;			// ���� ��Ʈ ����Ʈ


/// ����ȭ��׷��ش�
OneCharacterRes _MainSceneInfo;

///  ���� ���� ����ü
OneCharacterRes	_StairsInfo;

/// ������� ���� ����ü
OneCharacterRes	_MagicianRoomInfo;

/// ���Ŵ��� ���� ����
SCENEMGR	Scene;

/// ���콺 ���� �ٶǴ���
POINT Pt;

/// �������� �� ����
// ������ üũ�� ���� ����
int totalFrameCount = 0;

// �����浹 ���� ����
COLLRECT UpRect;
COLLRECT DownRect;
COLLRECT LeftRect;
COLLRECT RightRect;

/// ���� ���� �Լ�
/// �������
SoundInfo _Map1Bgm;
SoundInfo _Map2Bgm;
SoundInfo _Map3Bgm;
SoundInfo _Map4Bgm;

/// �÷��̾�
SoundInfo _PlayerMoveSound;
SoundInfo _PlayerAtt_1;
SoundInfo _PlayerAtt_2;
SoundInfo _PlayerAtt_3;
SoundInfo _PlayerHit;
SoundInfo _PlayerDie;
SoundInfo _PlayerDodge;
SoundInfo _PlayerAttHit;

/// ����

// ������
SoundInfo _SlimeMove;
SoundInfo _SlimeRollAtt;
SoundInfo _SlimeBlowUp;
SoundInfo _SlimeLaserSound;
SoundInfo _SlimeDie;

// ������
SoundInfo _MagicianLeftArm;
SoundInfo _Magician_TwoSied_Arm;
SoundInfo _MagicianAtt;
SoundInfo _MagicianDie;

COLLRECT TerrRect1;
COLLRECT TerrRect2;

int PlayerDeathTime;

void initialize()
{

	/// ��Ʈ�� �ε�
	// BackGround
	LoadBitmap_FromFile_LoadImage(&StartSceneBitMap, (char*)"./Resource/title_01_frame5_02.bmp");		// ����ȭ��
	LoadBitmap_FromFile_LoadImage(&InitSceneBitMap, (char*)"./Resource/standard_map_01.bmp");		// �������ִ¹�
	LoadBitmap_FromFile_LoadImage(&BackGroundBitMap, (char*)"./Resource/map_01_slime.bmp");			// �����ӹ�
	LoadBitmap_FromFile_LoadImage(&SceneMagicianBitMap, (char*)"./Resource/map_02_magician_loof.bmp");	// �������
	LoadBitmap_FromFile_LoadImage(&SceneClearBitMap, (char*)"./Resource/title_clear.bmp");		// Ŭ����
	LoadBitmap_FromFile_LoadImage(&SceneDeathBitMap, (char*)"./Resource/title_gameover.bmp");		// ���

	// Player
	LoadBitmap_FromFile_LoadImage(&PlayerBitMap, (char*)"./Resource/player_ldle_walk.bmp");

	// Player Weapon
	LoadBitmap_FromFile_LoadImage(&PlayerWeapon, (char*)"./Resource/player_weapon.bmp");

	// Player Effect
	LoadBitmap_FromFile_LoadImage(&PlayerEffect, (char*)"./Resource/attack_all_re_02.bmp");

	// Slime
	LoadBitmap_FromFile_LoadImage(&SlimeMonster, (char*)"./Resource/slime_boss01_ex.bmp");

	// Magican
	LoadBitmap_FromFile_LoadImage(&MagicianBitmap, (char*)"./Resource/boss_02.bmp");

	// Slime Monster Laser
	LoadBitmap_FromFile_LoadImage(&SlimeLaser, (char*)"./Resource/slime_atttck_Laser.bmp");

	// MAgician Attack
	LoadBitmap_FromFile_LoadImage(&MagicianAttackBitmap, (char*)"./Resource/boss_attack_01.bmp");

	// Magician Down Att
	LoadBitmap_FromFile_LoadImage(&MagicianDownAttBitmap, (char*)"./Resource/boss_attack_02.bmp");

	// Monster Hit Eff
	LoadBitmap_FromFile_LoadImage(&MonsterHitBitmap, (char*)"./Resource/hit_effect_01.bmp");

	// Stairs
	LoadBitmap_FromFile_LoadImage(&StairsBitmap, (char*)"./Resource/stairs_sprite.bmp");

	// UI
	LoadBitmap_FromFile_LoadImage(&UI_HPBar, (char*)"./Resource/icon_heart_01.bmp");
	LoadBitmap_FromFile_LoadImage(&UI_HPBardeath, (char*)"./Resource/icon_heart_02.bmp");
	LoadBitmap_FromFile_LoadImage(&UI_StaminaBar, (char*)"./Resource/icon_stamina_01.bmp");
	LoadBitmap_FromFile_LoadImage(&UI_StaminaBarDeath, (char*)"./Resource/icon_stamina_02.bmp");
	LoadBitmap_FromFile_LoadImage(&UI_Cursur, (char*)"./Resource/crosshead.bmp");


	// ������ ������ ���� �ʱ�ȭ

	// �÷��̾� ���� �ʱ�ȭ
	InitializePlayer(&_sPlayer, &_sSword, &_sPLAYEREffect);

	// ���� ���� �ʱ�ȭ
	InitializeMonster(&_sSlime, 600, 40 , MONSTERSLIMEHP);
	InitializeMonster(&_Magician, WINWIDTH / 2 - 110, WINHEIGHT / 2 - 200, MONSTERMAGICIANHP);
	// ������ ����Ʈ
	InitializMonEffect(&_MagicianEffect);
	InitializMonEffect(&_MagicianEffectDown);
	// ������ ����Ʈ
	InitializMonEffect(&_SlimeLaser);

	// ���� ��Ʈ ����Ʈ
	InitializMonEffect(&_MonsgerHitEff);

	// ��� ���� �ʱ�ȭ
	InitializeTerrainObj(&_Stairs);

	/// Resource �ʱ�ȭ
	// �÷��̾�	// ����Ʈ���� �ε�
	LoadCharacterInfo_Player(&_PlayerInfo, 10);
	LoadPlayerEffectInfo(&_PlayerEffectInfo, 3);
	CreateCharacterRes(&_PlayerInfo, &PlayerBitMap, 20, MAXSPRITENUM_CHARACTER);

	CreateCharacterRes(&_PlayerEffectInfo, &PlayerEffect, _sPLAYEREffect.EffectDelayTime, MAXSPRITENUM_PLAYEREFFECT);
	SetPlayerGraphicsRes(&_sPlayer, &_sPLAYEREffect, &_PlayerInfo, &_PlayerEffectInfo);

	// ������
	LoadCharacterInfo_Monster_Slime(&_SlimeMonInfo, 8);// ��Ÿ������ ���� �а�,
	CreateCharacterRes(&_SlimeMonInfo, &SlimeMonster, _sSlime.MonsterAniDelayTime, MAXSPRITENUM_MONSTER);
	SetMonsterGraphicsRes(&_sSlime, &_SlimeMonInfo);

	// ������
	LoadCharacterInfo_Monster_Magician(&_MagicianInfo, 8);// ��Ÿ������ ���� �а�,
	CreateCharacterRes(&_MagicianInfo, &MagicianBitmap, _Magician.MonsterAniDelayTime, MAXSPRITENUM_MAGICIAN);
	SetMonsterGraphicsRes(&_Magician, &_MagicianInfo);


	// ������ ������ �ʱ�ȭ
	LoadBossSlimeLaserInfo(&_SlimeLaserInfo, 1);// ��Ÿ������ ���� �а�,
	CreateCharacterRes(&_SlimeLaserInfo, &SlimeLaser, _SlimeLaser.MonEffectAniDelayTime, MAXSPRITENUM_SLIMELASER);
	SetMonsterEffectGraphicsRes(&_SlimeLaser, &_SlimeLaserInfo);

	// ������ ���ҽ� �ʱ�ȭ
	LoadBossMagicianEffectInfo(&_MagicianEffectInfo, 3);// ��Ÿ������ ���� �а�,
	CreateCharacterRes(&_MagicianEffectInfo, &MagicianAttackBitmap, _MagicianEffect.MonEffectAniDelayTime, MAXSPRITENUM_MAGICIANEFFECT);
	SetMonsterEffectGraphicsRes(&_MagicianEffect, &_MagicianEffectInfo);

	// ������ �ٿ���ݸ��ҽ� �ʱ�ȭ
	LoadMAgicianDownAttInfo(&_MagicianDownAttInfo, 1);// ��Ÿ������ ���� �а�,
	CreateCharacterRes(&_MagicianDownAttInfo, &MagicianDownAttBitmap, _MagicianEffectDown.MonEffectAniDelayTime, MAXSPRITENUM_MAGICIANDONWATT);
	SetMonsterEffectGraphicsRes(&_MagicianEffectDown, &_MagicianDownAttInfo);


	// ���� ��Ʈ ����Ʈ
	LoadMonsterHitEffectInfo(&_MonsterHitEffInfo, 1);// ��Ÿ������ ���� �а�,
	CreateCharacterRes(&_MonsterHitEffInfo, &MonsterHitBitmap, _MonsgerHitEff.MonEffectAniDelayTime, MAXSPRITENUM_MONSTERHIT);
	SetMonsterEffectGraphicsRes(&_MonsgerHitEff, &_MonsterHitEffInfo);

	// �������� ��� ���� ���ҽ�
	LoadTerrainObjectInfo(&_StairsInfo, 1);
	CreateCharacterRes(&_StairsInfo,&StairsBitmap,_Stairs.TerrainDelayFrame, MAXSPRITENUM_STAIR);
	SetTerrainObjGraphicsRes(&_Stairs, &_StairsInfo);

	// ����ȭ�� ���ҽ�
	LoadMainSceneInfo(&_MainSceneInfo, 1);
	CreateCharacterRes(&_MainSceneInfo, &StartSceneBitMap, 15, 5);

	// ������� ���ҽ�
	LoadMagicianSceneInfo(&_MagicianRoomInfo, 1);
	CreateCharacterRes(&_MagicianRoomInfo, &SceneMagicianBitMap, 30, 4);


	/// �� �Ŵ��� �ʱ�ȭ
	InitializeSceneMgr(&Scene);

	// �� ��ȯ �ӽ� ����
	MapChange = FALSE;

	/// �������
	soundOpen(&_Map1Bgm, "./Resource/Complete/Title_Main_BGM.mp3");
	soundOpen(&_Map2Bgm, "./Resource/Complete/Tutorial_Main_BGM.mp3");
	soundOpen(&_Map3Bgm, "./Resource/Complete/Boss_1_Main_BGM.mp3");
	soundOpen(&_Map4Bgm, "./Resource/Complete/Boss_2_Main_BGM.mp3");
	/// �÷��̾�
	soundOpen(&_PlayerMoveSound, "./Resource/Complete/Player_Move_Sound.mp3");
	soundOpen(&_PlayerAtt_1, "./Resource/Complete/Player_Attack_1_Sound.mp3");
	soundOpen(&_PlayerAtt_2, "./Resource/Complete/Player_Attack_2_Sound.mp3");
	soundOpen(&_PlayerAtt_3, "./Resource/Complete/Player_Attack_3_Sound.mp3");
	soundOpen(&_PlayerHit, "./Resource/Complete/Player_Hit_Sound.mp3");
	soundOpen(&_PlayerDie, "./Resource/Complete/Player_Die_Sound.mp3");
	soundOpen(&_PlayerDodge, "./Resource/Complete/Player_Dodge_Sound.mp3");
	soundOpen(&_PlayerAttHit, "./Resource/Complete/Player_Attack_Hit_Sound.mp3");
	

	/// ������
	soundOpen(&_SlimeMove, "./Resource/Complete/Boss_1_Move_Sound.mp3");
	soundOpen(&_SlimeRollAtt, "./Resource/Complete/Boss_1_MoveAttack_Sound.mp3");
	soundOpen(&_SlimeBlowUp, "./Resource/Complete/Boss_1_Blow_Up_Sound.mp3");
	soundOpen(&_SlimeLaserSound, "./Resource/Complete/Boss_1_BeamAttack_Sound.mp3");
	soundOpen(&_SlimeDie, "./Resource/Complete/Boss_1_Die_Sound.mp3");

	/// ������
	soundOpen(&_MagicianLeftArm, "./Resource/Complete/Boss_2_BigAttack_Sound.mp3");
	soundOpen(&_Magician_TwoSied_Arm, "./Resource/Complete/Boss_2_FollowAttack_Sound.mp3");
	soundOpen(&_MagicianAtt, "./Resource/Complete/Boss_2_Thorn_Sound.mp3");
	soundOpen(&_MagicianDie, "./Resource/Complete/Boss_2_Die_Sound.mp3");

	SoundChange = FALSE;


	/// ī�޶� ����ũ ȿ��
	ChangeView.WinViewX = 0;
	ChangeView.WinViewY = 0;

	PlayerDeathTime = 0;

	srand((unsigned int)time(NULL));
}

void GameLoop()
{
	// ȭ���ʱ�ȭ
	Clear();
	// ���콺 ��ǥ ��
	Pt = CheckMousePos();

	if (GetAsyncKeyState(VK_RETURN) & 0x8000 && Scene.SceneIndex == 0)
	{
		soundPause(&_Map1Bgm);
		soundPlayLooping(&_Map2Bgm);
		Scene.SceneChange = TRUE;
		SoundChange = FALSE;
		Scene.SceneIndex = 1;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// BackGround �׷��ֱ�
	DrawBackGround();
	DrawObject();
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// ����ϴ� �κ�
	PlayerMoveScene();
	MonsterMove();
	CollObject();
	CollCheck();
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// �׷��ִ� �κ�
	DrawMonster();
	DrawPlayer();
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// ����Ʈ �κ�
	DrawEffect();
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// UI �κ�
	DrawUI();

	DrawCurSur(Pt.x,Pt.y,&UI_Cursur);

	if (GetAsyncKeyState(VK_F1) & 0x8000)
	{
		if (DebugCheck == TRUE)
		{
			DebugCheck = FALSE;
		}
		else
		{
			DebugCheck = TRUE;
		}
	}

	if (DebugCheck == TRUE)
	{
		//// �÷��̾� ���� �浹�ڽ� �׷��ִ� �Լ�
		onDraw(_sSword.WeaponCollRegion, _sSword.WeaponCollPt[0], _sSword.WeaponCollPt[1], _sSword.WeaponCollPt[2], _sSword.WeaponCollPt[3]);
		// �÷��̾� �浹�ڽ�
		DrawDeBugRectangle(_sPlayer.PlayerCollisionRect.left, _sPlayer.PlayerCollisionRect.top,
			_sPlayer.PlayerCollisionRect.right, _sPlayer.PlayerCollisionRect.bottom);

		if (Scene.SceneIndex == 2)
		{
			// ������ ������ �浹�ڽ�
			onDraw(_SlimeLaser.LaserRegion, _SlimeLaser.LaserCollPt[0], _SlimeLaser.LaserCollPt[1], _SlimeLaser.LaserCollPt[2], _SlimeLaser.LaserCollPt[3]);

			// ������ �浹�ڽ�
			DrawDeBugRectangle(_sSlime.MonsterRect.left, _sSlime.MonsterRect.top,
				_sSlime.MonsterRect.right, _sSlime.MonsterRect.bottom);

			// ������ �浹�ڽ�
			DrawDeBugRectangle(_Magician.MonsterRect.left, _Magician.MonsterRect.top,
				_Magician.MonsterRect.right, _Magician.MonsterRect.bottom);
		}
		if (Scene.SceneIndex == 3)
		{
			// ������ �浹�ڽ�
			DrawDeBugRectangle(_Magician.MonsterRect.left, _Magician.MonsterRect.top,
				_Magician.MonsterRect.right, _Magician.MonsterRect.bottom);

			//// ������ �� ����Ʈ �浹�ڽ�
			//DrawDeBugRectangle(_MagicianEffect.MonEffectCollRect.left, _MagicianEffect.MonEffectCollRect.top,
			//	_MagicianEffect.MonEffectCollRect.right, _MagicianEffect.MonEffectCollRect.bottom);

			//// ������ �ٿ� ����Ʈ �浹�ڽ�
			//DrawDeBugRectangle(_MagicianEffectDown.MonEffectCollRect.left, _MagicianEffectDown.MonEffectCollRect.top,
			//	_MagicianEffectDown.MonEffectCollRect.right, _MagicianEffectDown.MonEffectCollRect.bottom);
		}

		// ������ ���� ����� ����
		_TT(0, 0, "TimeGetTimeTotal : %d", SLGetTime());
		_TT(0, 15, "TimeGetTimeElapsed : %d", SLGetElapsedTime());
		_TT(0, 30, "TimeGetTimeFPS : %f", SLGetFPS());

		// �÷��̾� ����� ����
		_TT(0, 60, "�÷��̾� X : %d / �÷��̾� Y : %d",_sPlayer.PlayerPosX, _sPlayer.PlayerPosY);
		_TT(0, 75, "�÷��̾� ü�� : %d", _sPlayer.PlayerHP);
		_TT(0, 90, "�÷��̾� ���׹̳� : %d", _sPlayer.PlayerStamina);
		_TT(0, 105, "�÷��̾� ȸ�� ��Ÿ�� : %d", _sPlayer.PlayerDodgeContinueTime);
		_TT(0, 120, "�÷��̾� ȸ�� ����Ÿ�� : %d", _sPlayer.PlayerStaminaTime);
		_TT(0, 135, "�÷��̾� ȸ������ : %d", _sPlayer.PlayerInvincibility);
		_TT(0, 150, "�÷��̾� ��Ʈ���� : %d", _sPlayer.PlayerHit);
		_TT(0, 175, "�÷��̾� ��Ʈ���� ���ӽð� : %d", _sPlayer.PlayerHitContinueTime);

		// ������ ����� ����
		_TT(200, 0, "������ X : %d / ������ Y : %d", _sSlime.MonsterPosX, _sSlime.MonsterPosY);
		_TT(200, 15, "������ ü�� : %d", _sSlime.MonsterHp);

		// ������ ����� ����
		_TT(400, 0, "������ X : %d / ������ Y : %d", _Magician.MonsterPosX, _Magician.MonsterPosY);
		_TT(400, 15, "������ ü�� : %d", _Magician.MonsterHp);
		_TT(400, 30, "��� �ε��� : %d", _Stairs.TerrainNowFrame);
	}

	DrawAllToScreen(&ChangeView);

	totalFrameCount++;

}
void DeleteREsourceHeap()
{
	DeleteAll(&_PlayerInfo,
		&_SlimeMonInfo,
		&_MagicianInfo,
		&_PlayerEffectInfo,
		&_MagicianEffectInfo,
		&_SlimeLaserInfo,
		&_MagicianDownAttInfo,
		&_MonsterHitEffInfo,
		&_StairsInfo,
		&_MainSceneInfo,
		&_MagicianRoomInfo);

}
void DrawBackGround()
{
	// ����ȭ��
	if(Scene.SceneIndex == 0)
	{
		Animate_PickPos(0, 0, &_MainSceneInfo, totalFrameCount, 0);
		if (SoundChange == FALSE)
		{
			soundPlayLooping(&_Map1Bgm);
			SoundChange = TRUE;
		}
	}
	// Ʃ�丮���
	else if (Scene.SceneIndex == 1)
	{
		DrawBitmap(0, 0, &InitSceneBitMap, 0, 0);
	}
	// �����ӹ�
	else if (Scene.SceneIndex == 2)
	{
		DrawBitmap(0, 0, &BackGroundBitMap, 0, 0);

		if (_sPlayer.PlayerHP == 0)
		{
			PlayerDeathTime += SLGetElapsedTime();
			//soundCloseAll();

			if (PlayerDeathTime > 3000)
			{
				Scene.SceneIndex = 4;
			}
		}
	}
	// �������
	else if (Scene.SceneIndex == 3)
	{
		Animate_PickPos(0, 0, &_MagicianRoomInfo, totalFrameCount, 0);

		if (_sPlayer.PlayerHP == 0)
		{
			PlayerDeathTime += SLGetElapsedTime();
			//soundCloseAll();

			if (PlayerDeathTime > 3000)
			{
				Scene.SceneIndex = 4;
			}
		}
	}
	// �׾��� ��
	else if (Scene.SceneIndex == 4)
	{
		DrawBitmap(0, 0, &SceneDeathBitMap, 0, 0);
		if (GetAsyncKeyState(VK_RETURN))
		{
			Scene.SceneIndex = 0;
			initialize();
		}
	}
	// Ŭ���� ���� ��
	else if (Scene.SceneIndex == 5)
	{
		DrawBitmap(0, 0, &SceneClearBitMap, 0, 0);
		if (GetAsyncKeyState(VK_RETURN))
		{
			Scene.SceneIndex = 0;
			initialize();
		}
		
	}
}
void DrawPlayer()
{
	if (Scene.SceneIndex == 0)
	{

	}
	else if (Scene.SceneIndex == 1)
	{
		// �÷��̾� ���� �׷��ֱ�
		DrawSpriteRotate(_sSword.WeaPonPosX, _sSword.WeaPonPosY, _sSword.Angle, &PlayerWeapon);

		// �÷��̾� �ִϸ��̼�
		Animate_PickPos(_sPlayer.PlayerPosX, _sPlayer.PlayerPosY, &_PlayerInfo, totalFrameCount, _sPlayer.PlayerAniIndex);
	}
	else if (Scene.SceneIndex == 2)
	{
		// �÷��̾� ���� �׷��ֱ�
		DrawSpriteRotate(_sSword.WeaPonPosX, _sSword.WeaPonPosY, _sSword.Angle, &PlayerWeapon);

		// �÷��̾� �ִϸ��̼�
		Animate_PickPos(_sPlayer.PlayerPosX, _sPlayer.PlayerPosY, &_PlayerInfo, totalFrameCount, _sPlayer.PlayerAniIndex);
	}
	else if (Scene.SceneIndex == 3)
	{
		// �÷��̾� ���� �׷��ֱ�
		DrawSpriteRotate(_sSword.WeaPonPosX, _sSword.WeaPonPosY, _sSword.Angle, &PlayerWeapon);

		// �÷��̾� �ִϸ��̼�
		Animate_PickPos(_sPlayer.PlayerPosX, _sPlayer.PlayerPosY, &_PlayerInfo, totalFrameCount, _sPlayer.PlayerAniIndex);
	}
}
void DrawMonster()
{
	if (Scene.SceneIndex == 0)
	{

	}
	else if (Scene.SceneIndex == 1)
	{

	}
	else if (Scene.SceneIndex == 2)
	{
		//���� ������ �ִϸ��̼�
		Animate_PickPos_Monster(_sSlime.MonsterPosX,
			_sSlime.MonsterPosY,
			&_SlimeMonInfo,
			-1, // �Ⱦ��� ����... ��Ż������
			_sSlime.NowMotionIndex,
			_sSlime.NowFrame);

		if (_sSlime.MonsterState == Laser || &_SlimeLaser.MonEffectNowFrame == 0)
		{
			//������ ������
			DrawSpriteRotate_ForPlayerEffect2(_SlimeLaser.MonEffectPosX, _SlimeLaser.MonEffectPosY,
				_SlimeLaser.Angle,
				&_SlimeLaserInfo, -1, _SlimeLaser.MonEffectNowMotionIndex, _SlimeLaser.MonEffectNowFrame);
		}

	}
	else if (Scene.SceneIndex == 3)
	{
		//���� ������ �ִϸ��̼�
		Animate_PickPos_Monster(_Magician.MonsterPosX,
			_Magician.MonsterPosY, 
			&_MagicianInfo,
			-1, // �Ⱦ��� ����... ��Ż������
			_Magician.NowMotionIndex, 
			_Magician.NowFrame);

		if (_Magician.MonsterState == SwingMagician_Two_Side_ArmAttack)
		{
			// �̶��� ���� ����Ʈ������
			Animate_PickPos_Monster(_MagicianEffect.MonEffectPosX, 
				_MagicianEffect.MonEffectPosY,
				&_MagicianEffectInfo, 
				-1,
				_MagicianEffect.MonEffectNowMotionIndex,
				_MagicianEffect.MonEffectNowFrame);
		}
		if (_Magician.MonsterState == SwingMagician_Left_ArmDown)
		{
			// �̶��� ���� ����Ʈ������
			Animate_PickPos_Monster(_MagicianEffectDown.MonEffectPosX, 
				_MagicianEffectDown.MonEffectPosY,
				&_MagicianDownAttInfo,
				-1,
				_MagicianEffectDown.MonEffectNowMotionIndex,
				_MagicianEffectDown.MonEffectNowFrame);
		}
	}
}
void PlayerMoveScene()
{
	if (Scene.SceneIndex == 0)
	{

	}
	else if (Scene.SceneIndex == 1)
	{
		// �÷��̾� ��ǥ ������
		PlayerMove(&_sPlayer, &_sSword,
			&_PlayerMoveSound,
			&_PlayerDie,
			&_PlayerDodge);
		// �÷��̾� ���� ������
		PlayerWeaponMove(Pt, &_sPlayer, &_sSword, ChangeView.WinViewX, ChangeView.WinViewY, &_sPLAYEREffect,
			&_PlayerAtt_1,
			&_PlayerAtt_2,
			&_PlayerAtt_3);
	}
	else if (Scene.SceneIndex == 2)
	{
		// �÷��̾� ��ǥ ������
		PlayerMove(&_sPlayer, &_sSword,
			&_PlayerMoveSound,
			&_PlayerDie,
			&_PlayerDodge);
		// �÷��̾� ���� ������
		PlayerWeaponMove(Pt, &_sPlayer, &_sSword, ChangeView.WinViewX, ChangeView.WinViewY, &_sPLAYEREffect,
			&_PlayerAtt_1,
			&_PlayerAtt_2,
			&_PlayerAtt_3);
	}
	else if (Scene.SceneIndex == 3)
	{
		// �÷��̾� ��ǥ ������
		PlayerMove(&_sPlayer, &_sSword,
			&_PlayerMoveSound,
			&_PlayerDie,
			&_PlayerDodge);
		// �÷��̾� ���� ������
		PlayerWeaponMove(Pt, &_sPlayer, &_sSword, ChangeView.WinViewX, ChangeView.WinViewY, &_sPLAYEREffect,
			&_PlayerAtt_1,
			&_PlayerAtt_2,
			&_PlayerAtt_3);
	}
}
void MonsterMove()
{
	if (Scene.SceneIndex == 0)
	{

	}
	else if (Scene.SceneIndex == 1)
	{

	}
	else if (Scene.SceneIndex == 2)
	{
		// ������ ���� FSM
		MonsterSlimeFSM(&_sSlime,
			&_sPlayer,
			&_SlimeLaser,
			&_SlimeMove,
			&_SlimeRollAtt,
			&_SlimeBlowUp,
			&_SlimeLaserSound,
			&_SlimeDie);
	}
	else if (Scene.SceneIndex == 3)
	{
		// ������ ���� FSM
		MonsterMagicianFSM(&_Magician, 
			&_sPlayer, 
			&_MagicianEffect,
			&_MagicianEffectDown,
			&_MagicianLeftArm,
			&_Magician_TwoSied_Arm,
			&_MagicianAtt,
			&_MagicianDie);
	}
}
void DrawEffect()
{
	if (Scene.SceneIndex == 0)
	{

	}
	else if (Scene.SceneIndex == 1)
	{
		// ���Ⱑ ���ɶ��� ���� ����Ʈ ���
		 if (_sSword.WeaponMouseCheck == TRUE)
		{
			DrawSpriteRotate_ForPlayerEffect(_sPLAYEREffect.EffectPosX, _sPLAYEREffect.EffectPosY,
				_sPLAYEREffect.EffectAngle,
				&_PlayerEffectInfo,
				totalFrameCount, _sPLAYEREffect.EffectNowIndex);
		}
	}
	else if (Scene.SceneIndex == 2)
	{

		// �÷��̾��� ����� ���Ͱ� �浹������ ��Ʈ ����Ʈ
		if (MonsterHitEffect(&_sSlime, &_MonsgerHitEff , 100, 200) == 2 &&
			PlayerWeapon_and_Monster_Coll(&_sSword, &_sSlime, &PlayerWeapon) == TRUE && 
			_sSlime.MonsterHp > 0)
		{
			Animate_PickPos_Monster(_MonsgerHitEff.MonEffectPosX,
				_MonsgerHitEff.MonEffectPosY,
				&_MonsterHitEffInfo,
				-1,
				_MonsgerHitEff.MonEffectNowMotionIndex,
				_MonsgerHitEff.MonEffectNowFrame);

			soundSeek(&_PlayerAttHit,0);
			soundPlay(&_PlayerAttHit);
		}

		// ���Ⱑ ���ɶ��� ���� ����Ʈ ���
		if (_sSword.WeaponMouseCheck == TRUE)
		{
			DrawSpriteRotate_ForPlayerEffect(_sPLAYEREffect.EffectPosX, _sPLAYEREffect.EffectPosY,
				_sPLAYEREffect.EffectAngle,
				&_PlayerEffectInfo,
				totalFrameCount, _sPLAYEREffect.EffectNowIndex);
		}
	}
	else if (Scene.SceneIndex == 3)
	{

		// �÷��̾��� ����� ���Ͱ� �浹������ ��Ʈ ����Ʈ
		if (MonsterHitEffect(&_Magician, &_MonsgerHitEff , 20 , 120) == 2 &&
			PlayerWeapon_and_Monster_Coll(&_sSword, &_Magician, &PlayerWeapon) == TRUE &&
			_Magician.MonsterHp > 0)
		{
			Animate_PickPos_Monster(_MonsgerHitEff.MonEffectPosX,
				_MonsgerHitEff.MonEffectPosY,
				&_MonsterHitEffInfo,
				-1,
				_MonsgerHitEff.MonEffectNowMotionIndex,
				_MonsgerHitEff.MonEffectNowFrame);
			soundSeek(&_PlayerAttHit, 0);
			soundPlay(&_PlayerAttHit);
		}

		if (_sSword.WeaponMouseCheck == TRUE)
		{
			DrawSpriteRotate_ForPlayerEffect(_sPLAYEREffect.EffectPosX, _sPLAYEREffect.EffectPosY,
				_sPLAYEREffect.EffectAngle,
				&_PlayerEffectInfo,
				totalFrameCount, _sPLAYEREffect.EffectNowIndex);
		}
	}
}
void DrawUI()
{
	// �����Ƽ� �밡�ٷ� ó��... �ε� ���ظ� �ٶ��ϴ�
	if (Scene.SceneIndex == 0)
	{

	}
	else if (Scene.SceneIndex == 1)
	{
		if (_sPlayer.PlayerHP == 5)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBar, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 4)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 3)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 2)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 1)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 0)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}

		if (_sPlayer.PlayerStamina == 3)
		{
			DrawBitmap_PickPos(80, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 110, &UI_StaminaBar, 0, 0, 80, 80);
		}
		if (_sPlayer.PlayerStamina == 2)
		{
			DrawBitmap_PickPos(80, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
		}
		if (_sPlayer.PlayerStamina == 1)
		{
			DrawBitmap_PickPos(80, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
		}
		if (_sPlayer.PlayerStamina == 0)
		{
			DrawBitmap_PickPos(80, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
		}
		//UI �׳� ������ ������ �׷��ִ� �κ�

	}
	else if (Scene.SceneIndex == 2)
	{
		if (_sPlayer.PlayerHP == 5)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBar, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 4)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 3)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 2)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 1)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}
		else if (_sPlayer.PlayerHP == 0)
		{
			DrawBitmap_PickPos(80, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
		}

		if (_sPlayer.PlayerStamina == 3)
		{
			DrawBitmap_PickPos(80, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 110, &UI_StaminaBar, 0, 0, 80, 80);
		}
		if (_sPlayer.PlayerStamina == 2)
		{
			DrawBitmap_PickPos(80, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
		}
		if (_sPlayer.PlayerStamina == 1)
		{
			DrawBitmap_PickPos(80, 110, &UI_StaminaBar, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
		}
		if (_sPlayer.PlayerStamina == 0)
		{
			DrawBitmap_PickPos(80, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(160, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
			DrawBitmap_PickPos(240, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
		}
	}
	else if (Scene.SceneIndex == 3)
	{
	if (_sPlayer.PlayerHP == 5)
	{
		DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(320, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(400, 30, &UI_HPBar, 0, 0, 80, 80);
	}
	else if (_sPlayer.PlayerHP == 4)
	{
		DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(320, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
	}
	else if (_sPlayer.PlayerHP == 3)
	{
		DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
	}
	else if (_sPlayer.PlayerHP == 2)
	{
		DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
	}
	else if (_sPlayer.PlayerHP == 1)
	{
		DrawBitmap_PickPos(80, 30, &UI_HPBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
	}
	else if (_sPlayer.PlayerHP == 0)
	{
		DrawBitmap_PickPos(80, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(320, 30, &UI_HPBardeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(400, 30, &UI_HPBardeath, 0, 0, 80, 80);
	}

	if (_sPlayer.PlayerStamina == 3)
	{
		DrawBitmap_PickPos(80, 110, &UI_StaminaBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 110, &UI_StaminaBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 110, &UI_StaminaBar, 0, 0, 80, 80);
	}
	if (_sPlayer.PlayerStamina == 2)
	{
		DrawBitmap_PickPos(80, 110, &UI_StaminaBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 110, &UI_StaminaBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
	}
	if (_sPlayer.PlayerStamina == 1)
	{
		DrawBitmap_PickPos(80, 110, &UI_StaminaBar, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
	}
	if (_sPlayer.PlayerStamina == 0)
	{
		DrawBitmap_PickPos(80, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(160, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
		DrawBitmap_PickPos(240, 110, &UI_StaminaBarDeath, 0, 0, 80, 80);
	}
	}
}
void CollCheck()
{
	if (Scene.SceneIndex == 0)
	{

	}
	else if (Scene.SceneIndex == 1)
	{
		// �浹ó�� ���� �Լ�
		//SetPlayerWeaponCollBox(&_sSword, &PlayerWeapon);
		// ��� �浹ó�� �Ŵ���
		if (PlayerAndStairColl(&_sPlayer, &_Stairs) == TRUE)
		{
			soundPause(&_Map2Bgm);
			soundPlay(&_Map3Bgm);
			Scene.SceneIndex = 2;
		}
	}
	else if (Scene.SceneIndex == 2)
	{
		// ���� ü���� 0���� Ŭ���� �浹
		if (_sSlime.MonsterHp > 0)
		{
			if (PlayerWeapon_and_Monster_Coll(&_sSword, &_sSlime, &PlayerWeapon) == TRUE)
			{
				for (int i = 0; i < 5; i++)
				{
					int RandX = rand() % 10;
					int RandY = rand() % 10;

					ChangeView.WinViewX = RandX;
					ChangeView.WinViewY = RandY;
				}
			}
			else
			{
				ChangeView.WinViewX = 0;
				ChangeView.WinViewY = 0;
			}
			Player_and_Slime_Coll(&_sPlayer, &_sSlime, &_PlayerHit);
			Player_and_SlimeLaser_Coll(&_sPlayer, &_SlimeLaser , &_PlayerHit);
		}
		if (_sSlime.MonsterHp < 0 && MapChange == FALSE)
		{
			_Stairs.TerraintotalFrame = 0;
			_Stairs.TerrainNowFrame = 0;
			Scene.SceneChange = TRUE;
			MapChange = TRUE;
		}
		if (MapChange == TRUE)
		{
			if (PlayerAndStairColl(&_sPlayer, &_Stairs) == TRUE)
			{
				soundPause(&_Map3Bgm);
				soundPlay(&_Map4Bgm);
				Scene.SceneIndex = 3;
				MapChange = FALSE;
			}
		}
		
	}
	else if (Scene.SceneIndex == 3)
	{
		Player_and_Magician_AttColl(&_sPlayer,&_MagicianEffect,&_MagicianEffectDown);

		if (_Magician.MonsterHp > 0)
		{
			if (PlayerWeapon_and_Magician_Coll(&_sSword, &_Magician, &PlayerWeapon) == TRUE)
			{
				for (int i = 0; i < 5; i++)
				{
					int RandX = rand() % 10;
					int RandY = rand() % 10;

					ChangeView.WinViewX = RandX;
					ChangeView.WinViewY = RandY;
				}
			}
			else
			{
				ChangeView.WinViewX = 0;
				ChangeView.WinViewY = 0;
			}
			Player_and_Magician_Coll(&_sPlayer, &_Magician);
		}
		if (_Magician.MonsterHp < 0 && MapChange == FALSE)
		{
			_Stairs.TerraintotalFrame = 0;
			_Stairs.TerrainNowFrame = 0;
			Scene.SceneChange = TRUE;
			MapChange = TRUE;
		}
		if (MapChange == TRUE)
		{
			if (PlayerAndStairColl(&_sPlayer, &_Stairs) == TRUE)
			{
				soundCloseAll();
				Scene.SceneIndex = 5;
				MapChange = FALSE;
			}
		}
		
	}
}
void DrawObject()
{
	if (Scene.SceneIndex == 0)
	{

	}
	else if (Scene.SceneIndex == 1)
	{
		SetStairTerrainObj(&_Stairs,&Scene);
		Animate_PickPos_Monster(_Stairs.TerrainPosX,
			_Stairs.TerrainPosY,
			&_StairsInfo,
			-1,
			_Stairs.TerrainNowMotionIndex,
			_Stairs.TerrainNowFrame);
	}
	else if (Scene.SceneIndex == 2)
	{
		SetStairTerrainObj(&_Stairs, &Scene);
		if (_sSlime.MonsterHp < 0)
		{
			Animate_PickPos_Monster(_Stairs.TerrainPosX,
				_Stairs.TerrainPosY,
				&_StairsInfo,
				-1,
				_Stairs.TerrainNowMotionIndex,
				_Stairs.TerrainNowFrame);
		}
	}
	else if (Scene.SceneIndex == 3)
	{
		SetStairTerrainObj(&_Stairs, &Scene);
		if (_Magician.MonsterHp < 0)
		{
			Animate_PickPos_Monster(_Stairs.TerrainPosX,
				_Stairs.TerrainPosY,
				&_StairsInfo,
				-1,
				_Stairs.TerrainNowMotionIndex,
				_Stairs.TerrainNowFrame);
		}
	}
}
void CollObject()
{
	if (Scene.SceneIndex == 0)
	{

	}
	else if (Scene.SceneIndex == 1)
	{

	}
	else if (Scene.SceneIndex == 2)
	{
	}
	else if (Scene.SceneIndex == 3)
	{
		CheckPlayerAndTerrainCollObj(&_sPlayer, &TerrRect1, &TerrRect2);

	}
}