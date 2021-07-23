#pragma once

/// Slash Engine에서 사용하는
/// 구조체, define, enum등
/// [11/16/2019 LeHideHome]

#include <windows.h>
#include <math.h>
#include <time.h>


// 정의들
//138 90 157
#define PI 3.14159265358979323846
#define COLORKEY_PINK RGB(0,255,0)
#define WINWIDTH	1920
#define WINHEIGHT	1080

/// 얼마나 자를까?
#define CUTX		30
#define CUTY		30
///타일크기
#define TILEWIDTH	50
#define TILEHEIGHT	50

/// 하나의 스프라이트 시트에서 등장하는 최대 스프라이트 수 (고정)
#define MAXSPRITENUM_CHARACTER 5
#define MAXSPRITENUM_MONSTER 13
#define MAXSPRITENUM_MAGICIAN 9
#define MAXSPRITENUM_PLAYEREFFECT 6
#define MAXSPRITENUM_MAGICIANEFFECT 8
#define MAXSPRITENUM_SLIMELASER 7
#define MAXSPRITENUM_MAGICIANDONWATT 6
#define MAXSPRITENUM_MONSTERHIT 6
#define MAXSPRITENUM_STAIR 8

/// 1000 - 1초

/// 몬스터 관련 디버깅 정보
#define  MONSTERIDLESPEED  2
#define  MONSTERROLLATTACKSPEED  3
#define	 MONSTERSLIMEHP				3600	// 슬라임 체력
#define	 MONSTERMAGICIANHP			3600	// 마법사 체력

/// 플레이어 관련 디버깅 정보
#define PLAYER_DODGE_POS		60				// 플레이어 회피 이동거리
#define PLAYER_DODGE_COOLTIME	2000			// 플레이어 회피 쿨타임
#define PLAYER_SPEED			4				// 플레이어 이동속도	
#define PLAYER_INVICIBILITY		1000			// 플레이어 회피 무적시간	
#define PLAYER_HITTIME			3000			// 플레이어 피격 무적시간	
#define PLAYER_STAMINACHARGE	3000			// 플레이어 회피 충전시간	


// 비트맵 하나의 구조체
typedef struct _tagSLBitmap
{
	// 기본
	HDC hMemDC;			// 비트맵이 내장되는 memory device comtext handle
	HBITMAP hBitmap;	// 비트맵 리소스를 다루는 핸들

	// 비트맵 관련
	int Width;			// 폭
	int Height;			// 높이

	// 스프라이트 관련
	int KeyColor;		// 키 컬러 (TransparentBlt의 경우)

	//// 애니메이션 관련
	//int CenterPosX;		// 비트맵의 중심 (캐릭터의 발 위치 등)
	//int CenterPosY;
	int DelayFrame;		// 애니메이션에서의 Frame

	//// 게임 관련
	//RECT Collision1;	// 충돌영역1 (eg. 피격)
	//RECT Collision2;	// 충돌영역2 (eg. 공격)
	//int Damage;			/// 충격량

	///툴 관련 비트맵
	int BitMapIndexForTool;

} SLBitmap;

/// 한 개의 스프라이트의 논리적인 내용
///
typedef struct _tagOneSprite
{
	int oriX;			// 시트 내에서의 위치
	int oriY;

	int width;			// 시트 내에서의 폭
	int height;			// 시트 내에서의 높이

	/// 프레임 제어 관련
	int delayFrame;		// 이 스프라이트가 가지는 딜레이

} OneSprite;


/// 논리적인 픽포스 애니메이션 구조체
typedef struct _tagOneMotion
{
	// 큰 하나의 비트맵 시트
	SLBitmap* sheet;
	// 모션 안에서의 스프라이트 갯수
	int spriteNum;

	// 동적할당 될 스프라이트들 (한 모션에 들어있는 스프라이트)
	OneSprite* sprites;


} OneMotion;


/// 전체 캐릭터 구조체
typedef struct _tagOneCharacterRes
{
	/// 통맵 원본 스프라이트 시트 (캐릭터 당 하나)
	SLBitmap* sheet;	// 큰 하나의 비트맵 시트

	// 모션의 갯수
	int motionNum;

	// 모션들
	OneMotion* motions;


	/// 캐릭터별 정보 (속도, 체력..)
	int PosX;
	int PosY;


	// 스프라이트를 로드하기 위한 메타정보
	int* SpritesNum;

} OneCharacterRes;


/////////////////////////////////////////////////////////////////////////////

///타일맵 그리드
typedef struct _STILERECT
{
	RECT Tile;			//타일의 사각형 정보
	int BitMapInDex;	//타일이 저장할 비트맵 정보
	int TileNum;		//타일의 넘버(순서)

}TILERECT;


typedef struct _SCHANGEWINVIEW
{
	int WinViewX;
	int WinViewY;

}CHANGEWINVIEW;

//방향키
#define  VK_W 0x57
#define  VK_S 0x53
#define  VK_A 0x41
#define  VK_D 0x44

//방향
typedef enum _Direction
{
	NoneLeft, NoneRight,Up, Down, Left, Right, UpLeft, UpRight, DownLeft, DownRight, Dodge
} Direction;