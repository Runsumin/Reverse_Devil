#pragma once

/// Slash Engine���� ����ϴ�
/// ����ü, define, enum��
/// [11/16/2019 LeHideHome]

#include <windows.h>
#include <math.h>
#include <time.h>


// ���ǵ�
//138 90 157
#define PI 3.14159265358979323846
#define COLORKEY_PINK RGB(0,255,0)
#define WINWIDTH	1920
#define WINHEIGHT	1080

/// �󸶳� �ڸ���?
#define CUTX		30
#define CUTY		30
///Ÿ��ũ��
#define TILEWIDTH	50
#define TILEHEIGHT	50

/// �ϳ��� ��������Ʈ ��Ʈ���� �����ϴ� �ִ� ��������Ʈ �� (����)
#define MAXSPRITENUM_CHARACTER 5
#define MAXSPRITENUM_MONSTER 13
#define MAXSPRITENUM_MAGICIAN 9
#define MAXSPRITENUM_PLAYEREFFECT 6
#define MAXSPRITENUM_MAGICIANEFFECT 8
#define MAXSPRITENUM_SLIMELASER 7
#define MAXSPRITENUM_MAGICIANDONWATT 6
#define MAXSPRITENUM_MONSTERHIT 6
#define MAXSPRITENUM_STAIR 8

/// 1000 - 1��

/// ���� ���� ����� ����
#define  MONSTERIDLESPEED  2
#define  MONSTERROLLATTACKSPEED  3
#define	 MONSTERSLIMEHP				3600	// ������ ü��
#define	 MONSTERMAGICIANHP			3600	// ������ ü��

/// �÷��̾� ���� ����� ����
#define PLAYER_DODGE_POS		60				// �÷��̾� ȸ�� �̵��Ÿ�
#define PLAYER_DODGE_COOLTIME	2000			// �÷��̾� ȸ�� ��Ÿ��
#define PLAYER_SPEED			4				// �÷��̾� �̵��ӵ�	
#define PLAYER_INVICIBILITY		1000			// �÷��̾� ȸ�� �����ð�	
#define PLAYER_HITTIME			3000			// �÷��̾� �ǰ� �����ð�	
#define PLAYER_STAMINACHARGE	3000			// �÷��̾� ȸ�� �����ð�	


// ��Ʈ�� �ϳ��� ����ü
typedef struct _tagSLBitmap
{
	// �⺻
	HDC hMemDC;			// ��Ʈ���� ����Ǵ� memory device comtext handle
	HBITMAP hBitmap;	// ��Ʈ�� ���ҽ��� �ٷ�� �ڵ�

	// ��Ʈ�� ����
	int Width;			// ��
	int Height;			// ����

	// ��������Ʈ ����
	int KeyColor;		// Ű �÷� (TransparentBlt�� ���)

	//// �ִϸ��̼� ����
	//int CenterPosX;		// ��Ʈ���� �߽� (ĳ������ �� ��ġ ��)
	//int CenterPosY;
	int DelayFrame;		// �ִϸ��̼ǿ����� Frame

	//// ���� ����
	//RECT Collision1;	// �浹����1 (eg. �ǰ�)
	//RECT Collision2;	// �浹����2 (eg. ����)
	//int Damage;			/// ��ݷ�

	///�� ���� ��Ʈ��
	int BitMapIndexForTool;

} SLBitmap;

/// �� ���� ��������Ʈ�� ������ ����
///
typedef struct _tagOneSprite
{
	int oriX;			// ��Ʈ �������� ��ġ
	int oriY;

	int width;			// ��Ʈ �������� ��
	int height;			// ��Ʈ �������� ����

	/// ������ ���� ����
	int delayFrame;		// �� ��������Ʈ�� ������ ������

} OneSprite;


/// ������ ������ �ִϸ��̼� ����ü
typedef struct _tagOneMotion
{
	// ū �ϳ��� ��Ʈ�� ��Ʈ
	SLBitmap* sheet;
	// ��� �ȿ����� ��������Ʈ ����
	int spriteNum;

	// �����Ҵ� �� ��������Ʈ�� (�� ��ǿ� ����ִ� ��������Ʈ)
	OneSprite* sprites;


} OneMotion;


/// ��ü ĳ���� ����ü
typedef struct _tagOneCharacterRes
{
	/// ��� ���� ��������Ʈ ��Ʈ (ĳ���� �� �ϳ�)
	SLBitmap* sheet;	// ū �ϳ��� ��Ʈ�� ��Ʈ

	// ����� ����
	int motionNum;

	// ��ǵ�
	OneMotion* motions;


	/// ĳ���ͺ� ���� (�ӵ�, ü��..)
	int PosX;
	int PosY;


	// ��������Ʈ�� �ε��ϱ� ���� ��Ÿ����
	int* SpritesNum;

} OneCharacterRes;


/////////////////////////////////////////////////////////////////////////////

///Ÿ�ϸ� �׸���
typedef struct _STILERECT
{
	RECT Tile;			//Ÿ���� �簢�� ����
	int BitMapInDex;	//Ÿ���� ������ ��Ʈ�� ����
	int TileNum;		//Ÿ���� �ѹ�(����)

}TILERECT;


typedef struct _SCHANGEWINVIEW
{
	int WinViewX;
	int WinViewY;

}CHANGEWINVIEW;

//����Ű
#define  VK_W 0x57
#define  VK_S 0x53
#define  VK_A 0x41
#define  VK_D 0x44

//����
typedef enum _Direction
{
	NoneLeft, NoneRight,Up, Down, Left, Right, UpLeft, UpRight, DownLeft, DownRight, Dodge
} Direction;