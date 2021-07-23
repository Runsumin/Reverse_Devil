#include "Main.h"
#include "Sound.h"
BOOL DebugCheck;

BOOL MapChange;

BOOL SoundChange;
/// 비트맵 로드 
// BackGround
SLBitmap StartSceneBitMap;		// 시작화면
SLBitmap InitSceneBitMap;		// 설명해주는방
SLBitmap BackGroundBitMap;		// 슬라임방
SLBitmap SceneMagicianBitMap;	// 마법사방
SLBitmap SceneClearBitMap;		// 클리어
SLBitmap SceneDeathBitMap;		// 플레이어 사망

// 플레이어 관련
SLBitmap PlayerBitMap;
SLBitmap PlayerWeapon;
SLBitmap PlayerEffect;

// 몬스터 관련
SLBitmap SlimeMonster;
SLBitmap SlimeLaser;
SLBitmap MagicianBitmap;
SLBitmap MagicianAttackBitmap;
SLBitmap MagicianDownAttBitmap;


// 몬스터 히트 이펙트
SLBitmap MonsterHitBitmap;

// UI 관련
SLBitmap UI_HPBar;
SLBitmap UI_HPBardeath;
SLBitmap UI_StaminaBar;
SLBitmap UI_StaminaBarDeath;
SLBitmap UI_Cursur;


// 지형 오브젝트 관련
SLBitmap StairsBitmap;

/// 구조체 선언

// 플레이어 관련 구조체 선언
PLAYER _sPlayer;				// 플레이어
PLAYERWEAPON _sSword;			// 무기
SPLAYEREFFECT _sPLAYEREffect;	// 플레이어 이펙트


// 몬스터 관련 초기화
MONSTER _sSlime;				// 슬라임
MONSTER _Magician;				// 마법사

// 마법사 몬스터 그래픽 초기화
MONSTEREFFECT _MagicianEffect;		// 마법사 위로공격
MONSTEREFFECT _MagicianEffectDown;	// 마법사 아래로 공격
MONSTEREFFECT _SlimeLaser;			// 슬라임 레이저
MONSTEREFFECT _MonsgerHitEff;		// 몬스터 히트 이펙트

// 계단 관련 구조체
TERRAINOBJECT _Stairs;


///화면 전환 관련 변수
CHANGEWINVIEW ChangeView;

// 리소스 정보 관련 구조체
OneCharacterRes _PlayerInfo;				// 플레이어
OneCharacterRes _PlayerEffectInfo;			// 플레이어 이펙트
OneCharacterRes _SlimeMonInfo;				// 슬라임
OneCharacterRes _MagicianInfo;				// 마법사
OneCharacterRes _SlimeLaserInfo;			// 슬라임 레이저
OneCharacterRes _MagicianEffectInfo;		// 마법사 작은가시 이펙트
OneCharacterRes _MagicianDownAttInfo;		// 마법사 큰가시
OneCharacterRes _MonsterHitEffInfo;			// 몬스터 히트 이펙트


/// 메인화면그려준다
OneCharacterRes _MainSceneInfo;

///  지형 관련 구조체
OneCharacterRes	_StairsInfo;

/// 마법사방 관련 구조체
OneCharacterRes	_MagicianRoomInfo;

/// 씬매니저 관련 변수
SCENEMGR	Scene;

/// 마우스 정보 겟또다제
POINT Pt;

/// 전역성을 띈 변수
// 프레임 체크를 위한 변수
int totalFrameCount = 0;

// 지형충돌 위한 변수
COLLRECT UpRect;
COLLRECT DownRect;
COLLRECT LeftRect;
COLLRECT RightRect;

/// 사운드 관련 함수
/// 배경음악
SoundInfo _Map1Bgm;
SoundInfo _Map2Bgm;
SoundInfo _Map3Bgm;
SoundInfo _Map4Bgm;

/// 플레이어
SoundInfo _PlayerMoveSound;
SoundInfo _PlayerAtt_1;
SoundInfo _PlayerAtt_2;
SoundInfo _PlayerAtt_3;
SoundInfo _PlayerHit;
SoundInfo _PlayerDie;
SoundInfo _PlayerDodge;
SoundInfo _PlayerAttHit;

/// 몬스터

// 슬라임
SoundInfo _SlimeMove;
SoundInfo _SlimeRollAtt;
SoundInfo _SlimeBlowUp;
SoundInfo _SlimeLaserSound;
SoundInfo _SlimeDie;

// 마법사
SoundInfo _MagicianLeftArm;
SoundInfo _Magician_TwoSied_Arm;
SoundInfo _MagicianAtt;
SoundInfo _MagicianDie;

COLLRECT TerrRect1;
COLLRECT TerrRect2;

int PlayerDeathTime;

void initialize()
{

	/// 비트맵 로드
	// BackGround
	LoadBitmap_FromFile_LoadImage(&StartSceneBitMap, (char*)"./Resource/title_01_frame5_02.bmp");		// 시작화면
	LoadBitmap_FromFile_LoadImage(&InitSceneBitMap, (char*)"./Resource/standard_map_01.bmp");		// 설명해주는방
	LoadBitmap_FromFile_LoadImage(&BackGroundBitMap, (char*)"./Resource/map_01_slime.bmp");			// 슬라임방
	LoadBitmap_FromFile_LoadImage(&SceneMagicianBitMap, (char*)"./Resource/map_02_magician_loof.bmp");	// 마법사방
	LoadBitmap_FromFile_LoadImage(&SceneClearBitMap, (char*)"./Resource/title_clear.bmp");		// 클리어
	LoadBitmap_FromFile_LoadImage(&SceneDeathBitMap, (char*)"./Resource/title_gameover.bmp");		// 사망

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


	// 슬라임 레이저 관련 초기화

	// 플레이어 관련 초기화
	InitializePlayer(&_sPlayer, &_sSword, &_sPLAYEREffect);

	// 몬스터 관련 초기화
	InitializeMonster(&_sSlime, 600, 40 , MONSTERSLIMEHP);
	InitializeMonster(&_Magician, WINWIDTH / 2 - 110, WINHEIGHT / 2 - 200, MONSTERMAGICIANHP);
	// 마법사 이펙트
	InitializMonEffect(&_MagicianEffect);
	InitializMonEffect(&_MagicianEffectDown);
	// 슬라임 이펙트
	InitializMonEffect(&_SlimeLaser);

	// 몬스터 히트 이펙트
	InitializMonEffect(&_MonsgerHitEff);

	// 계단 관련 초기화
	InitializeTerrainObj(&_Stairs);

	/// Resource 초기화
	// 플레이어	// 이펙트정보 로드
	LoadCharacterInfo_Player(&_PlayerInfo, 10);
	LoadPlayerEffectInfo(&_PlayerEffectInfo, 3);
	CreateCharacterRes(&_PlayerInfo, &PlayerBitMap, 20, MAXSPRITENUM_CHARACTER);

	CreateCharacterRes(&_PlayerEffectInfo, &PlayerEffect, _sPLAYEREffect.EffectDelayTime, MAXSPRITENUM_PLAYEREFFECT);
	SetPlayerGraphicsRes(&_sPlayer, &_sPLAYEREffect, &_PlayerInfo, &_PlayerEffectInfo);

	// 슬라임
	LoadCharacterInfo_Monster_Slime(&_SlimeMonInfo, 8);// 메타정보를 먼저 읽고,
	CreateCharacterRes(&_SlimeMonInfo, &SlimeMonster, _sSlime.MonsterAniDelayTime, MAXSPRITENUM_MONSTER);
	SetMonsterGraphicsRes(&_sSlime, &_SlimeMonInfo);

	// 마법사
	LoadCharacterInfo_Monster_Magician(&_MagicianInfo, 8);// 메타정보를 먼저 읽고,
	CreateCharacterRes(&_MagicianInfo, &MagicianBitmap, _Magician.MonsterAniDelayTime, MAXSPRITENUM_MAGICIAN);
	SetMonsterGraphicsRes(&_Magician, &_MagicianInfo);


	// 슬라임 레이저 초기화
	LoadBossSlimeLaserInfo(&_SlimeLaserInfo, 1);// 메타정보를 먼저 읽고,
	CreateCharacterRes(&_SlimeLaserInfo, &SlimeLaser, _SlimeLaser.MonEffectAniDelayTime, MAXSPRITENUM_SLIMELASER);
	SetMonsterEffectGraphicsRes(&_SlimeLaser, &_SlimeLaserInfo);

	// 마법사 리소스 초기화
	LoadBossMagicianEffectInfo(&_MagicianEffectInfo, 3);// 메타정보를 먼저 읽고,
	CreateCharacterRes(&_MagicianEffectInfo, &MagicianAttackBitmap, _MagicianEffect.MonEffectAniDelayTime, MAXSPRITENUM_MAGICIANEFFECT);
	SetMonsterEffectGraphicsRes(&_MagicianEffect, &_MagicianEffectInfo);

	// 마법사 다운공격리소스 초기화
	LoadMAgicianDownAttInfo(&_MagicianDownAttInfo, 1);// 메타정보를 먼저 읽고,
	CreateCharacterRes(&_MagicianDownAttInfo, &MagicianDownAttBitmap, _MagicianEffectDown.MonEffectAniDelayTime, MAXSPRITENUM_MAGICIANDONWATT);
	SetMonsterEffectGraphicsRes(&_MagicianEffectDown, &_MagicianDownAttInfo);


	// 몬스터 히트 이펙트
	LoadMonsterHitEffectInfo(&_MonsterHitEffInfo, 1);// 메타정보를 먼저 읽고,
	CreateCharacterRes(&_MonsterHitEffInfo, &MonsterHitBitmap, _MonsgerHitEff.MonEffectAniDelayTime, MAXSPRITENUM_MONSTERHIT);
	SetMonsterEffectGraphicsRes(&_MonsgerHitEff, &_MonsterHitEffInfo);

	// 내려가는 계단 관련 리소스
	LoadTerrainObjectInfo(&_StairsInfo, 1);
	CreateCharacterRes(&_StairsInfo,&StairsBitmap,_Stairs.TerrainDelayFrame, MAXSPRITENUM_STAIR);
	SetTerrainObjGraphicsRes(&_Stairs, &_StairsInfo);

	// 메인화면 리소스
	LoadMainSceneInfo(&_MainSceneInfo, 1);
	CreateCharacterRes(&_MainSceneInfo, &StartSceneBitMap, 15, 5);

	// 마법사방 리소스
	LoadMagicianSceneInfo(&_MagicianRoomInfo, 1);
	CreateCharacterRes(&_MagicianRoomInfo, &SceneMagicianBitMap, 30, 4);


	/// 씬 매니저 초기화
	InitializeSceneMgr(&Scene);

	// 맵 변환 임시 변수
	MapChange = FALSE;

	/// 배경음악
	soundOpen(&_Map1Bgm, "./Resource/Complete/Title_Main_BGM.mp3");
	soundOpen(&_Map2Bgm, "./Resource/Complete/Tutorial_Main_BGM.mp3");
	soundOpen(&_Map3Bgm, "./Resource/Complete/Boss_1_Main_BGM.mp3");
	soundOpen(&_Map4Bgm, "./Resource/Complete/Boss_2_Main_BGM.mp3");
	/// 플레이어
	soundOpen(&_PlayerMoveSound, "./Resource/Complete/Player_Move_Sound.mp3");
	soundOpen(&_PlayerAtt_1, "./Resource/Complete/Player_Attack_1_Sound.mp3");
	soundOpen(&_PlayerAtt_2, "./Resource/Complete/Player_Attack_2_Sound.mp3");
	soundOpen(&_PlayerAtt_3, "./Resource/Complete/Player_Attack_3_Sound.mp3");
	soundOpen(&_PlayerHit, "./Resource/Complete/Player_Hit_Sound.mp3");
	soundOpen(&_PlayerDie, "./Resource/Complete/Player_Die_Sound.mp3");
	soundOpen(&_PlayerDodge, "./Resource/Complete/Player_Dodge_Sound.mp3");
	soundOpen(&_PlayerAttHit, "./Resource/Complete/Player_Attack_Hit_Sound.mp3");
	

	/// 슬라임
	soundOpen(&_SlimeMove, "./Resource/Complete/Boss_1_Move_Sound.mp3");
	soundOpen(&_SlimeRollAtt, "./Resource/Complete/Boss_1_MoveAttack_Sound.mp3");
	soundOpen(&_SlimeBlowUp, "./Resource/Complete/Boss_1_Blow_Up_Sound.mp3");
	soundOpen(&_SlimeLaserSound, "./Resource/Complete/Boss_1_BeamAttack_Sound.mp3");
	soundOpen(&_SlimeDie, "./Resource/Complete/Boss_1_Die_Sound.mp3");

	/// 마법사
	soundOpen(&_MagicianLeftArm, "./Resource/Complete/Boss_2_BigAttack_Sound.mp3");
	soundOpen(&_Magician_TwoSied_Arm, "./Resource/Complete/Boss_2_FollowAttack_Sound.mp3");
	soundOpen(&_MagicianAtt, "./Resource/Complete/Boss_2_Thorn_Sound.mp3");
	soundOpen(&_MagicianDie, "./Resource/Complete/Boss_2_Die_Sound.mp3");

	SoundChange = FALSE;


	/// 카메라 쉐이크 효과
	ChangeView.WinViewX = 0;
	ChangeView.WinViewY = 0;

	PlayerDeathTime = 0;

	srand((unsigned int)time(NULL));
}

void GameLoop()
{
	// 화면초기화
	Clear();
	// 마우스 좌표 겟
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
	// BackGround 그려주기
	DrawBackGround();
	DrawObject();
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// 계산하는 부분
	PlayerMoveScene();
	MonsterMove();
	CollObject();
	CollCheck();
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// 그려주는 부분
	DrawMonster();
	DrawPlayer();
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// 이펙트 부분
	DrawEffect();
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// UI 부분
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
		//// 플레이어 무기 충돌박스 그려주는 함수
		onDraw(_sSword.WeaponCollRegion, _sSword.WeaponCollPt[0], _sSword.WeaponCollPt[1], _sSword.WeaponCollPt[2], _sSword.WeaponCollPt[3]);
		// 플레이어 충돌박스
		DrawDeBugRectangle(_sPlayer.PlayerCollisionRect.left, _sPlayer.PlayerCollisionRect.top,
			_sPlayer.PlayerCollisionRect.right, _sPlayer.PlayerCollisionRect.bottom);

		if (Scene.SceneIndex == 2)
		{
			// 슬라임 레이저 충돌박스
			onDraw(_SlimeLaser.LaserRegion, _SlimeLaser.LaserCollPt[0], _SlimeLaser.LaserCollPt[1], _SlimeLaser.LaserCollPt[2], _SlimeLaser.LaserCollPt[3]);

			// 슬라임 충돌박스
			DrawDeBugRectangle(_sSlime.MonsterRect.left, _sSlime.MonsterRect.top,
				_sSlime.MonsterRect.right, _sSlime.MonsterRect.bottom);

			// 마법사 충돌박스
			DrawDeBugRectangle(_Magician.MonsterRect.left, _Magician.MonsterRect.top,
				_Magician.MonsterRect.right, _Magician.MonsterRect.bottom);
		}
		if (Scene.SceneIndex == 3)
		{
			// 마법사 충돌박스
			DrawDeBugRectangle(_Magician.MonsterRect.left, _Magician.MonsterRect.top,
				_Magician.MonsterRect.right, _Magician.MonsterRect.bottom);

			//// 마법사 업 이펙트 충돌박스
			//DrawDeBugRectangle(_MagicianEffect.MonEffectCollRect.left, _MagicianEffect.MonEffectCollRect.top,
			//	_MagicianEffect.MonEffectCollRect.right, _MagicianEffect.MonEffectCollRect.bottom);

			//// 마법사 다운 이펙트 충돌박스
			//DrawDeBugRectangle(_MagicianEffectDown.MonEffectCollRect.left, _MagicianEffectDown.MonEffectCollRect.top,
			//	_MagicianEffectDown.MonEffectCollRect.right, _MagicianEffectDown.MonEffectCollRect.bottom);
		}

		// 프레임 관련 디버깅 정보
		_TT(0, 0, "TimeGetTimeTotal : %d", SLGetTime());
		_TT(0, 15, "TimeGetTimeElapsed : %d", SLGetElapsedTime());
		_TT(0, 30, "TimeGetTimeFPS : %f", SLGetFPS());

		// 플레이어 디버깅 정보
		_TT(0, 60, "플레이어 X : %d / 플레이어 Y : %d",_sPlayer.PlayerPosX, _sPlayer.PlayerPosY);
		_TT(0, 75, "플레이어 체력 : %d", _sPlayer.PlayerHP);
		_TT(0, 90, "플레이어 스테미나 : %d", _sPlayer.PlayerStamina);
		_TT(0, 105, "플레이어 회피 쿨타임 : %d", _sPlayer.PlayerDodgeContinueTime);
		_TT(0, 120, "플레이어 회피 충전타임 : %d", _sPlayer.PlayerStaminaTime);
		_TT(0, 135, "플레이어 회피판정 : %d", _sPlayer.PlayerInvincibility);
		_TT(0, 150, "플레이어 히트판정 : %d", _sPlayer.PlayerHit);
		_TT(0, 175, "플레이어 히트무적 지속시간 : %d", _sPlayer.PlayerHitContinueTime);

		// 슬라임 디버깅 정보
		_TT(200, 0, "슬라임 X : %d / 슬라임 Y : %d", _sSlime.MonsterPosX, _sSlime.MonsterPosY);
		_TT(200, 15, "슬라임 체력 : %d", _sSlime.MonsterHp);

		// 마법사 디버깅 정보
		_TT(400, 0, "마법사 X : %d / 마법사 Y : %d", _Magician.MonsterPosX, _Magician.MonsterPosY);
		_TT(400, 15, "마법사 체력 : %d", _Magician.MonsterHp);
		_TT(400, 30, "계단 인덱스 : %d", _Stairs.TerrainNowFrame);
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
	// 시작화면
	if(Scene.SceneIndex == 0)
	{
		Animate_PickPos(0, 0, &_MainSceneInfo, totalFrameCount, 0);
		if (SoundChange == FALSE)
		{
			soundPlayLooping(&_Map1Bgm);
			SoundChange = TRUE;
		}
	}
	// 튜토리얼방
	else if (Scene.SceneIndex == 1)
	{
		DrawBitmap(0, 0, &InitSceneBitMap, 0, 0);
	}
	// 슬라임방
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
	// 마법사방
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
	// 죽었을 때
	else if (Scene.SceneIndex == 4)
	{
		DrawBitmap(0, 0, &SceneDeathBitMap, 0, 0);
		if (GetAsyncKeyState(VK_RETURN))
		{
			Scene.SceneIndex = 0;
			initialize();
		}
	}
	// 클리어 했을 때
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
		// 플레이어 무기 그려주기
		DrawSpriteRotate(_sSword.WeaPonPosX, _sSword.WeaPonPosY, _sSword.Angle, &PlayerWeapon);

		// 플레이어 애니메이션
		Animate_PickPos(_sPlayer.PlayerPosX, _sPlayer.PlayerPosY, &_PlayerInfo, totalFrameCount, _sPlayer.PlayerAniIndex);
	}
	else if (Scene.SceneIndex == 2)
	{
		// 플레이어 무기 그려주기
		DrawSpriteRotate(_sSword.WeaPonPosX, _sSword.WeaPonPosY, _sSword.Angle, &PlayerWeapon);

		// 플레이어 애니메이션
		Animate_PickPos(_sPlayer.PlayerPosX, _sPlayer.PlayerPosY, &_PlayerInfo, totalFrameCount, _sPlayer.PlayerAniIndex);
	}
	else if (Scene.SceneIndex == 3)
	{
		// 플레이어 무기 그려주기
		DrawSpriteRotate(_sSword.WeaPonPosX, _sSword.WeaPonPosY, _sSword.Angle, &PlayerWeapon);

		// 플레이어 애니메이션
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
		//몬스터 슬라임 애니메이션
		Animate_PickPos_Monster(_sSlime.MonsterPosX,
			_sSlime.MonsterPosY,
			&_SlimeMonInfo,
			-1, // 안쓰는 인자... 토탈프레임
			_sSlime.NowMotionIndex,
			_sSlime.NowFrame);

		if (_sSlime.MonsterState == Laser || &_SlimeLaser.MonEffectNowFrame == 0)
		{
			//슬라임 레이저
			DrawSpriteRotate_ForPlayerEffect2(_SlimeLaser.MonEffectPosX, _SlimeLaser.MonEffectPosY,
				_SlimeLaser.Angle,
				&_SlimeLaserInfo, -1, _SlimeLaser.MonEffectNowMotionIndex, _SlimeLaser.MonEffectNowFrame);
		}

	}
	else if (Scene.SceneIndex == 3)
	{
		//몬스터 마법사 애니메이션
		Animate_PickPos_Monster(_Magician.MonsterPosX,
			_Magician.MonsterPosY, 
			&_MagicianInfo,
			-1, // 안쓰는 인자... 토탈프레임
			_Magician.NowMotionIndex, 
			_Magician.NowFrame);

		if (_Magician.MonsterState == SwingMagician_Two_Side_ArmAttack)
		{
			// 이때만 공격 이펙트랜더링
			Animate_PickPos_Monster(_MagicianEffect.MonEffectPosX, 
				_MagicianEffect.MonEffectPosY,
				&_MagicianEffectInfo, 
				-1,
				_MagicianEffect.MonEffectNowMotionIndex,
				_MagicianEffect.MonEffectNowFrame);
		}
		if (_Magician.MonsterState == SwingMagician_Left_ArmDown)
		{
			// 이때만 공격 이펙트랜더링
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
		// 플레이어 좌표 움직임
		PlayerMove(&_sPlayer, &_sSword,
			&_PlayerMoveSound,
			&_PlayerDie,
			&_PlayerDodge);
		// 플레이어 무기 움직임
		PlayerWeaponMove(Pt, &_sPlayer, &_sSword, ChangeView.WinViewX, ChangeView.WinViewY, &_sPLAYEREffect,
			&_PlayerAtt_1,
			&_PlayerAtt_2,
			&_PlayerAtt_3);
	}
	else if (Scene.SceneIndex == 2)
	{
		// 플레이어 좌표 움직임
		PlayerMove(&_sPlayer, &_sSword,
			&_PlayerMoveSound,
			&_PlayerDie,
			&_PlayerDodge);
		// 플레이어 무기 움직임
		PlayerWeaponMove(Pt, &_sPlayer, &_sSword, ChangeView.WinViewX, ChangeView.WinViewY, &_sPLAYEREffect,
			&_PlayerAtt_1,
			&_PlayerAtt_2,
			&_PlayerAtt_3);
	}
	else if (Scene.SceneIndex == 3)
	{
		// 플레이어 좌표 움직임
		PlayerMove(&_sPlayer, &_sSword,
			&_PlayerMoveSound,
			&_PlayerDie,
			&_PlayerDodge);
		// 플레이어 무기 움직임
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
		// 슬라임 몬스터 FSM
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
		// 마법사 몬스터 FSM
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
		// 무기가 사용될때만 무기 이펙트 출력
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

		// 플레이어의 무기와 몬스터가 충돌했을때 히트 이펙트
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

		// 무기가 사용될때만 무기 이펙트 출력
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

		// 플레이어의 무기와 몬스터가 충돌했을때 히트 이펙트
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
	// 귀찮아서 노가다로 처리... 부디 양해를 바랍니다
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
		//UI 그냥 느낌만 볼려고 그려주는 부분

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
		// 충돌처리 관련 함수
		//SetPlayerWeaponCollBox(&_sSword, &PlayerWeapon);
		// 모든 충돌처리 매니저
		if (PlayerAndStairColl(&_sPlayer, &_Stairs) == TRUE)
		{
			soundPause(&_Map2Bgm);
			soundPlay(&_Map3Bgm);
			Scene.SceneIndex = 2;
		}
	}
	else if (Scene.SceneIndex == 2)
	{
		// 몬스터 체력이 0보다 클때만 충돌
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