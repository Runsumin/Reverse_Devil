#include "SLEngine.h"
#include <stdio.h>
#include <math.h>

#pragma comment(lib, "Msimg32.lib")


/// ��� �������� ������ ������

HINSTANCE g_hInst;	// �ν��Ͻ� �ڵ�
HWND g_hWnd;		// �׸��⸦ �� ���� (1����� ����)
HDC g_hDCMain;		// ����DC. ȭ�鿡 �׸��� �뵵
SLBitmap Backbuffer;// �����

/// Ÿ�� ���� ����� ����ü
TILERECT TileRect[CUTX][CUTY];

/// �ʱ�ȭ ����

// �׷��Ƚ� ���̺귯���� �ʿ��� ���� �������� ���´�.
// �� ��, ������ 1����� �����Ѵ�. �׸��� ȭ�鵵 1����� ������
void InitilizeSLEngine(HINSTANCE hinst, HWND hWnd, HDC hDC)
{
	g_hInst = hinst;
	g_hWnd = hWnd;
	g_hDCMain = hDC;

	Backbuffer.hMemDC = CreateCompatibleDC(g_hDCMain);
	Backbuffer.hBitmap = CreateCompatibleBitmap(g_hDCMain, WINWIDTH, WINHEIGHT);
	SelectObject(Backbuffer.hMemDC, Backbuffer.hBitmap);
	Backbuffer.Width = WINWIDTH;
	Backbuffer.Height = WINHEIGHT;
}

/// ĳ���� ���ҽ� ��Ÿ���� ����
void LoadCharacterInfo_Player(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 5;
	character->SpritesNum[1] = 4;
	character->SpritesNum[2] = 5;
	character->SpritesNum[3] = 4;
	character->SpritesNum[4] = 5;
	character->SpritesNum[5] = 5;
	character->SpritesNum[6] = 2;
	character->SpritesNum[7] = 2;
	character->SpritesNum[8] = 1;
	character->SpritesNum[9] = 1;
}

void LoadCharacterInfo_Monster_Slime(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 6;
	character->SpritesNum[1] = 5;
	character->SpritesNum[2] = 5;
	character->SpritesNum[3] = 5;
	character->SpritesNum[4] = 13;
	character->SpritesNum[5] = 5;
	character->SpritesNum[6] = 5;
	character->SpritesNum[7] = 1;
}
void LoadCharacterInfo_Monster_Magician(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 9;
	character->SpritesNum[1] = 4;
	character->SpritesNum[2] = 4;
	character->SpritesNum[3] = 2;
	character->SpritesNum[4] = 5;
	character->SpritesNum[5] = 5;
	character->SpritesNum[6] = 4;
	character->SpritesNum[7] = 4;
}
void LoadPlayerEffectInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 5;
	character->SpritesNum[1] = 6;
	character->SpritesNum[2] = 5;
}
void LoadBossMagicianEffectInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 8;
	character->SpritesNum[1] = 1;
	character->SpritesNum[2] = 8;
}

void LoadBossSlimeLaserInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 7;


}
void LoadMAgicianDownAttInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 6;


}

void LoadMonsterHitEffectInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 6;


}

void LoadTerrainObjectInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 8;


}

void LoadMainSceneInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 5;


}
void LoadMagicianSceneInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : ���Ͽ��� ��ü ����� ������ �о� �� ���̴�.
	character->motionNum = motionNum;

	/// ��� ������ �������, �� ��Ǵ� ��������Ʈ�� ������ ��� �迭�� �����Ҵ��Ѵ�.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// ���Ͽ��� �� ��Ǵ� ��������Ʈ�� ������ �ε��Ѵ�.
	character->SpritesNum[0] = 4;


}

/// �ɸ��� ���ҽ� ����
void CreateCharacterRes(OneCharacterRes* character, SLBitmap* sheet, int DelayFrame, int maxSpriteNum)
{
	// ���� ��Ʈ
	character->sheet = sheet;

	// ����� �����Ҵ��Ѵ�.
	character->motions = (OneMotion*)malloc(sizeof(OneMotion) * character->motionNum);

	// ���� �Ҵ� �� ��� ���� �ʱ�ȭ �Ѵ�.
	for (int i = 0; i < character->motionNum; i++)
	{
		// �� ����� �ʱ�ȭ
		character->motions[i].sheet = sheet;
		character->motions[i].spriteNum = character->SpritesNum[i];

		// ��ǿ� �ټ��� ��������Ʈ���� �����Ҵ� �� �ʱ�ȭ�� �� �ش�.
		CreateSprites(&character->motions[i], sheet, i, character->motionNum, DelayFrame, maxSpriteNum);
	}
}

/// ����� �������ش�. ��������Ʈ ���� ������ش�.
void CreateSprites(OneMotion* motion, SLBitmap* sheet, int motionIndex,
	int MotionNum, int DelayFrame, int maxSpriteNum)
{
	motion->sheet = sheet;

	// ��������Ʈ ������ �������� �Ҵ��Ѵ�.
	motion->sprites = (OneSprite*)malloc(sizeof(OneSprite) * motion->spriteNum);

	//free(motion->sprites);
	for (int i = 0; i < motion->spriteNum; i++)
	{
		// ���� ��ü ��Ʈ�� ��������Ʈ�� ������ ���� ������ ��
		motion->sprites[i].width = (sheet->Width / maxSpriteNum);
		motion->sprites[i].height = (sheet->Height / MotionNum);

		// ���� ��ġ�� �ε������� ���� ���̸� ������ ��ġ
		motion->sprites[i].oriX = motion->sprites[i].width * i;
		motion->sprites[i].oriY = motion->sprites[i].height * motionIndex;

		motion->sprites[i].delayFrame = DelayFrame;
	}
}

/// ���ϸ��̼� ����
/// 
void DrawBitmap_PickPos_And_Play(int dstX, int dstY, OneCharacterRes* character,
	int motionIndex, int spriteIndex)
{
	DrawBitmap_PickPos(dstX, dstY, character->sheet,
		character->motions[motionIndex].sprites[spriteIndex].oriX,
		character->motions[motionIndex].sprites[spriteIndex].oriY,
		character->motions[motionIndex].sprites[spriteIndex].width,
		character->motions[motionIndex].sprites[spriteIndex].height);
}

void Animate_PickPos_Monster(int dstX, int dstY, OneCharacterRes* character,
	int totalFrame, int motionIndex , int NowFrame)
{
	//int NowFrame = (totalFrame / character->motions->sprites->delayFrame) % character->motions[motionIndex].spriteNum;

	DrawBitmap_PickPos(dstX, dstY, character->sheet,
		character->motions[motionIndex].sprites[NowFrame].oriX,
		character->motions[motionIndex].sprites[NowFrame].oriY,
		character->motions[motionIndex].sprites[NowFrame].width,
		character->motions[motionIndex].sprites[NowFrame].height);
}
void Animate_PickPos(int dstX, int dstY, OneCharacterRes* character,
	int totalFrame, int motionIndex)
{
	int nowFrame = (totalFrame / character->motions->sprites->delayFrame) % character->motions[motionIndex].spriteNum;

	DrawBitmap_PickPos(dstX, dstY, character->sheet,
		character->motions[motionIndex].sprites[nowFrame].oriX,
		character->motions[motionIndex].sprites[nowFrame].oriY,
		character->motions[motionIndex].sprites[nowFrame].width,
		character->motions[motionIndex].sprites[nowFrame].height);
}
void Animate_PickPos_PlayerEffect(int dstX, int dstY, OneCharacterRes* character,
	int totalFrame, int motionIndex)
{
	int NowFrame = (totalFrame / character->motions->sprites->delayFrame) % character->motions[motionIndex].spriteNum;

	DrawBitmap_PickPos(dstX, dstY, character->sheet,
		character->motions[motionIndex].sprites[NowFrame].oriX,
		character->motions[motionIndex].sprites[NowFrame].oriY,
		character->motions[motionIndex].sprites[NowFrame].width,
		character->motions[motionIndex].sprites[NowFrame].height);
}
void DrawSpriteRotate_ForPlayerEffect(int x, int y, double angle, OneCharacterRes* character,
	int totalFrame, int motionIndex)
{
	int NowFrame = (totalFrame / character->motions->sprites->delayFrame) % character->motions[motionIndex].spriteNum;

	// �̹��� ��ü�� �ڵ� �߰�
	HDC MemDC, MemDC2;
	HBITMAP hBitmap, hBitmap2;
	HBITMAP OldBitmap, OldBitmap2;
	HBRUSH newBrush, oldBrush;

	int _width, _height;
	POINT pt[3];

	_width = character->motions[motionIndex].sprites[NowFrame].width;
	_height = character->motions[motionIndex].sprites[NowFrame].height;

	int memDC2Size = sqrt(pow(_width, 2), pow(_height, 2));

	MemDC = CreateCompatibleDC(Backbuffer.hMemDC);
	hBitmap = CreateCompatibleBitmap(Backbuffer.hMemDC, _width, _height);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBitmap);

	MemDC2 = CreateCompatibleDC(Backbuffer.hMemDC);
	hBitmap2 = CreateCompatibleBitmap(Backbuffer.hMemDC, memDC2Size, memDC2Size);
	OldBitmap2 = (HBITMAP)SelectObject(MemDC2, hBitmap2);


	int XCenter = _width / 2;
	int YCenter = _height / 2;
	double theta = (angle + 180) * (PI / 180.0);

	pt[0].x = XCenter + (-XCenter) * sin(theta) - (-YCenter) * cos(theta);	//upper-left in target
	pt[0].y = YCenter + (-XCenter) * cos(theta) + ((double)0 - YCenter) * sin(theta);
	pt[1].x = XCenter + ((double)_width - XCenter) * sin(theta) - (-YCenter) * cos(theta);	//upper-right in target
	pt[1].y = YCenter + ((double)_width - XCenter) * cos(theta) + ((double)0 - YCenter) * sin(theta);
	pt[2].x = XCenter + (-XCenter) * sin(theta) - ((double)_height - YCenter) * cos(theta);	//lower left in target
	pt[2].y = YCenter + (-XCenter) * cos(theta) + ((double)_height - YCenter) * sin(theta);


	/// ���� ����Ʈ �̹���
	BitBlt(MemDC, 0, 0, _width, _height,
		character->sheet->hMemDC,
		character->motions[motionIndex].sprites[NowFrame].oriX,
		character->motions[motionIndex].sprites[NowFrame].oriY, SRCCOPY);


	/// memDC2�� ������ �÷�Ű�� ���� ����ش�.
	newBrush = CreateSolidBrush(RGB(0, 255, 0));
	oldBrush = SelectObject(MemDC2, newBrush);
	Rectangle(MemDC2, -1, -1, memDC2Size + 1, memDC2Size + 1);
	
	/// ȸ�����Ѽ� MemDC2��
	PlgBlt(MemDC2, pt, MemDC, 0, 0,
		_width, _height, NULL, 0, 0);

	/// MemDC2�� ����ۿ� �ܼ��� Trans��
	TransparentBlt(Backbuffer.hMemDC, x, y, memDC2Size, memDC2Size,
		MemDC2, 0, 0, memDC2Size, memDC2Size,
		character->sheet->KeyColor);

	SelectObject(MemDC2, OldBitmap2);
	DeleteObject(hBitmap2);
	DeleteDC(MemDC2);

	SelectObject(MemDC, OldBitmap);
	DeleteObject(hBitmap);

	SelectObject(MemDC, oldBrush);
	DeleteObject(newBrush);

	DeleteDC(MemDC);

}
void DrawSpriteRotate_ForPlayerEffect2(int x, int y, double angle, OneCharacterRes* character,
	int totalFrame, int motionIndex , int NowFrame)
{
	//int NowFrame = (totalFrame / character->motions->sprites->delayFrame) % character->motions[motionIndex].spriteNum;

	// �̹��� ��ü�� �ڵ� �߰�
	HDC MemDC, MemDC2;
	HBITMAP hBitmap, hBitmap2;
	HBITMAP OldBitmap, OldBitmap2;
	HBRUSH newBrush, oldBrush;

	int _width, _height;
	POINT pt[3];

	_width = character->motions[motionIndex].sprites[NowFrame].width;
	_height = character->motions[motionIndex].sprites[NowFrame].height;

	int memDC2Size = sqrt(pow(_width, 2), pow(_height, 2));

	MemDC = CreateCompatibleDC(Backbuffer.hMemDC);
	hBitmap = CreateCompatibleBitmap(Backbuffer.hMemDC, _width, _height);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBitmap);

	MemDC2 = CreateCompatibleDC(Backbuffer.hMemDC);
	hBitmap2 = CreateCompatibleBitmap(Backbuffer.hMemDC, memDC2Size, memDC2Size);
	OldBitmap2 = (HBITMAP)SelectObject(MemDC2, hBitmap2);


	int XCenter = _width / 2;
	int YCenter = _height / 2;
	double theta = (angle + 180) * (PI / 180.0);

	pt[0].x = XCenter + (-XCenter) * sin(theta) - (-YCenter) * cos(theta);	//upper-left in target
	pt[0].y = YCenter + memDC2Size / 2 - 46 + (-XCenter) * cos(theta) + ((double)0 - YCenter) * sin(theta);

	pt[1].x = XCenter + ((double)_width - XCenter) * sin(theta) - (-YCenter) * cos(theta);	//upper-right in target
	pt[1].y = YCenter + memDC2Size / 2 - 46 + ((double)_width - XCenter) * cos(theta) + ((double)0 - YCenter) * sin(theta);

	pt[2].x = XCenter + (-XCenter) * sin(theta) - ((double)_height - YCenter) * cos(theta);	//lower left in target
	pt[2].y = YCenter + memDC2Size / 2 - 46 + (-XCenter) * cos(theta) + ((double)_height - YCenter) * sin(theta);


	/// ���� ����Ʈ �̹���
	BitBlt(MemDC, 0, 0, _width, _height,
		character->sheet->hMemDC,
		character->motions[motionIndex].sprites[NowFrame].oriX,
		character->motions[motionIndex].sprites[NowFrame].oriY, SRCCOPY);


	//// memDC2�� ������ �÷�Ű�� ���� ����ش�.
	newBrush = CreateSolidBrush(RGB(0, 255, 0));
	oldBrush = SelectObject(MemDC2, newBrush);
	Rectangle(MemDC2, -1, -1, memDC2Size + 1, memDC2Size + 1);

	/// ȸ�����Ѽ� MemDC2��
	PlgBlt(MemDC2, pt, MemDC, 0, 0,
		_width, _height, NULL, 0, 0);
		
		

	/// MemDC2�� ����ۿ� �ܼ��� Trans��
	TransparentBlt(Backbuffer.hMemDC, x, y, memDC2Size, memDC2Size,
		MemDC2 , 0, 0, memDC2Size, memDC2Size,
		character->sheet->KeyColor);

	SelectObject(MemDC2, OldBitmap2);
	DeleteObject(hBitmap2);
	DeleteDC(MemDC2);

	SelectObject(MemDC, OldBitmap);
	DeleteObject(hBitmap);

	SelectObject(MemDC, oldBrush);
	DeleteObject(newBrush);

	DeleteDC(MemDC);

}
///�׸��� �Լ�
void DrawBitmap_PickPos(int dstX, int dstY, SLBitmap* sheet, int oriX, int oriY, int width, int height)
{
	TransparentBlt(Backbuffer.hMemDC, dstX, dstY, width, height,
		sheet->hMemDC, oriX, oriY, width, height, sheet->KeyColor);

}

///�׸��� �Լ�
void DrawBitmap_PickPos2(int dstX, int dstY, SLBitmap* sheet, HDC MemDc, int oriX, int oriY, int width, int height)
{
	TransparentBlt(Backbuffer.hMemDC, dstX, dstY, width, height,
		MemDc, oriX, oriY, width, height, sheet->KeyColor);
}

void DrawCurSur(int x, int y, SLBitmap* sheet)
{
	TransparentBlt(Backbuffer.hMemDC, x, y, 80, 80,
		sheet->hMemDC, 0, 0, 80, 80, sheet->KeyColor);
}


void DrawSpriteRotate(int x, int y, double angle, SLBitmap* sprite)
{
	// �̹��� ��ü�� �ڵ� �߰�
	HDC MemDC;
	HBITMAP hBitmap;
	HBITMAP OldBitmap;
	HBRUSH newBrush, oldBrush;

	int bx, by;
	POINT pt[3];

	int changeMemdcSize = max(sprite->Width, sprite->Height);
	MemDC = CreateCompatibleDC(Backbuffer.hMemDC);
	hBitmap = CreateCompatibleBitmap(Backbuffer.hMemDC, changeMemdcSize, changeMemdcSize);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBitmap);

	newBrush = CreateSolidBrush(RGB(0, 255, 0));
	oldBrush = SelectObject(MemDC, newBrush);

	Rectangle(MemDC, -1, -1, changeMemdcSize + 1, changeMemdcSize + 1);

	bx = sprite->Width;
	by = sprite->Height;

	int XCenter = bx / 2;
	int YCenter = by / 2;
	double theta = angle * PI / 180.0;

	pt[0].x = XCenter + (-XCenter) * sin(theta) - (-YCenter) * cos(theta);	//upper-left in target
	pt[0].y = YCenter + changeMemdcSize / 4 + (-XCenter) * cos(theta) + ((double)0 - YCenter) * sin(theta);
	pt[1].x = XCenter + ((double)bx - XCenter) * sin(theta) - (-YCenter) * cos(theta);	//upper-right in target
	pt[1].y = YCenter + changeMemdcSize / 4 + ((double)bx - XCenter) * cos(theta) + ((double)0 - YCenter) * sin(theta);
	pt[2].x = XCenter + (-XCenter) * sin(theta) - ((double)by - YCenter) * cos(theta);	//lower left in target
	pt[2].y = YCenter + changeMemdcSize / 4 + (-XCenter) * cos(theta) + ((double)by - YCenter) * sin(theta);

	PlgBlt(MemDC, pt, sprite->hMemDC, 0, 0, bx, by, NULL, 0, 0);

	TransparentBlt(Backbuffer.hMemDC, x, y, changeMemdcSize, changeMemdcSize,
		MemDC, 0, 0, changeMemdcSize, changeMemdcSize, sprite->KeyColor);

	SelectObject(MemDC, OldBitmap);
	DeleteObject(hBitmap);
	SelectObject(MemDC, oldBrush);
	DeleteObject(newBrush);
	DeleteDC(MemDC);
}



//�ӽ� �׸��� ����
void onDraw(HRGN CollRegion, POINT Pt1, POINT Pt2, POINT Pt3, POINT Pt4)
{
	SelectObject(Backbuffer.hMemDC, GetStockObject(WHITE_BRUSH));	// �귯��

	POINT Pt[4];

	Pt[0].x = Pt1.x;
	Pt[0].y = Pt1.y;

	Pt[1].x = Pt2.x;
	Pt[1].y = Pt2.y;

	Pt[2].x = Pt3.x;
	Pt[2].y = Pt3.y;

	Pt[3].x = Pt4.x;
	Pt[3].y = Pt4.y;

	CollRegion = CreatePolygonRgn(Pt, 4, WINDING);

	PaintRgn(Backbuffer.hMemDC, CollRegion);

	DeleteObject(CollRegion);

}

// �ϳ��� ��������Ʈ�� �׸���. �� ����� Solid(SRCCOPY)
void DrawBitmap(int posX, int posY, SLBitmap* bitmap, int srcX, int srcY)
{
	BitBlt(Backbuffer.hMemDC, posX, posY, bitmap->Width, bitmap->Height,
		bitmap->hMemDC, srcX, srcY, SRCCOPY);
}

/// ������ �浹�ڽ� �׸��� �Լ�
void DrawDeBugRectangle(long left, long top, long right, long bottom)
{
	SelectObject(Backbuffer.hMemDC, GetStockObject(WHITE_BRUSH));	// �귯��
	Rectangle(Backbuffer.hMemDC, left, top, right, bottom);
}

//������ ���ۿ� ��
void DrawAllToScreen(CHANGEWINVIEW* changeWinView)
{
	BitBlt(g_hDCMain, 0, 0, WINWIDTH, WINHEIGHT, Backbuffer.hMemDC, changeWinView->WinViewX, changeWinView->WinViewY, SRCCOPY);
}
// ������ ��� ����� �༭ �����ֱ�

/// ���߿� �޹��ȭ�� �� �ڸ�...
void Clear()
{
	PatBlt(Backbuffer.hMemDC, 0, 0, WINWIDTH, WINHEIGHT, BLACKNESS);
}

// LoadImage ����Ͽ� ��Ʈ�� �ε�
void LoadBitmap_FromFile_LoadImage(SLBitmap* bitmap, char* filePath)
{
	BITMAP bit;

	// ����DC�� ȣȯ�Ǵ� �޸�DC����, ���Ͽ��� ��Ʈ���� �ε�
	bitmap->hMemDC = CreateCompatibleDC(g_hDCMain);
	///bitmap->hBitmap = MakeDDBFromDIB(g_hDCMain, filePath);
	bitmap->hBitmap = LoadImage(NULL, filePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	/// ��
	///SetDIBitsToDevice()

	SelectObject(bitmap->hMemDC, bitmap->hBitmap);

	// �ΰ� ������ ������ش�.
	GetObject(bitmap->hBitmap, sizeof(BITMAP), &bit);
	bitmap->Width = bit.bmWidth;
	bitmap->Height = bit.bmHeight;
	bitmap->KeyColor = COLORKEY_PINK;

	DeleteObject(bitmap->hBitmap);
}


/// �������� ��ο� ���
// �� Ÿ�ϵ� ������°� �ʱ�ȭ
void InitializeTileMapSet()
{
	for (int i = 0; i < CUTX; i++)
	{
		for (int j = 0; j < CUTY; j++)
		{
			TileRect[i][j].Tile.left = i * TILEWIDTH;						//x��ǥ
			TileRect[i][j].Tile.top = j * TILEHEIGHT;						//y��ǥ
			TileRect[i][j].Tile.right = i * TILEWIDTH + TILEWIDTH;			//WIDTH
			TileRect[i][j].Tile.bottom = j * TILEHEIGHT + TILEHEIGHT;		//HEIGHT
			TileRect[i][j].BitMapInDex = 0;
			TileRect[i][j].TileNum = j + CUTX * i;
		}
	}
}

void DrawTileLine()
{
	SelectObject(Backbuffer.hMemDC, GetStockObject(WHITE_BRUSH));	// �귯��

	for (int i = 0; i < CUTX; i++)
	{
		for (int j = 0; j < CUTY; j++)
		{
			Rectangle(Backbuffer.hMemDC, TileRect[i][j].Tile.left, TileRect[i][j].Tile.top,
				TileRect[i][j].Tile.right, TileRect[i][j].Tile.bottom);
		}
	}
}

void CheckTileBitMap(CHANGEWINVIEW* changeWinView, int tileAttr)
{
	POINT MousePT;
	GetCursorPos(&MousePT);
	ScreenToClient(g_hWnd, &MousePT);

	MousePT.x += changeWinView->WinViewX;
	MousePT.y += changeWinView->WinViewY;

	for (int i = 0; i < CUTX; i++)
	{
		for (int j = 0; j < CUTY; j++)
		{
			if (PtInRect(&TileRect[i][j].Tile, MousePT))
			{
				//üũ���ִ� �Լ�
				TileRect[i][j].BitMapInDex = tileAttr;
			}
		}
	}
}

void DrawTileBitMap(SLBitmap* brick, SLBitmap* redBrick, SLBitmap* iron)
{
	for (int i = 0; i < CUTX; i++)
	{
		for (int j = 0; j < CUTY; j++)
		{
			switch (TileRect[i][j].BitMapInDex)
			{
			case 1:
				DrawBitmap(TileRect[i][j].Tile.left,
					TileRect[i][j].Tile.top, brick, TILEWIDTH, TILEHEIGHT);
				break;
			case 2:
				DrawBitmap(TileRect[i][j].Tile.left,
					TileRect[i][j].Tile.top, redBrick, TILEWIDTH, TILEHEIGHT);
				break;
			case 3:
				DrawBitmap(TileRect[i][j].Tile.left,
					TileRect[i][j].Tile.top, iron, TILEWIDTH, TILEHEIGHT);
				break;
			}
		}
	}
}


/// ���ڿ� ������ ���
BOOL _TT(int x, int y, const char* pch, ...)
{
	// �귯�ø� ��������.
	SelectObject(Backbuffer.hMemDC, GetStockObject(NULL_BRUSH));	// �귯��
	SetTextColor(Backbuffer.hMemDC, RGB(0x00, 0xff, 0x00));			// �ؽ�Ʈ�� ��
	SetBkMode(Backbuffer.hMemDC, TRANSPARENT);						// �ؽ�Ʈ�� ����� ��������

	HFONT font = CreateFont(12, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "����");
	HFONT oldfont = (HFONT)SelectObject(Backbuffer.hMemDC, font);

	char* buffer;
	int len;

	va_list ap;			// ���� �а� �ִ� ������ ���
	va_start(ap, pch);		// ap ������ ������ ù��° �����μ��� ����Ű���� �ʱ�ȭ

	// len�� �����ϴ� ���?
	// pch�� �и� ���ڿ� ����� ���������ٵ�, strlen���� ũ�Ⱑ �ȳ�����?
	// _vscprintf doesn't count  .. ��� MSDN�� ��������. ;;

	len = _vscprintf(pch, ap) + 1;
	buffer = malloc(len * sizeof(char));

	vsprintf_s(buffer, len, pch, ap);
	va_end(ap);

	TextOut(Backbuffer.hMemDC, x, y, buffer, (int)strlen(buffer));

	free(buffer);


	SelectObject(Backbuffer.hMemDC, oldfont);
	DeleteObject(font);

	return TRUE;
}

POINT CheckMousePos_ForTOOL(CHANGEWINVIEW* changeWinView)
{
	POINT MousePT;
	GetCursorPos(&MousePT);
	ScreenToClient(g_hWnd, &MousePT);

	return	MousePT;
}

POINT CheckMousePos()
{
	//RECT rc;
	//POINT p1, p2;
	//rc.left = 0;
	//rc.top = 0;
	//rc.right = 800;
	//rc.bottom = 600;

	//GetClientRect(g_hWnd, &rc);

	//p1.x = rc.left;
	//p1.y = rc.top;
	//p2.x = rc.right;
	//p2.y = rc.bottom;

	//ClientToScreen(g_hWnd, &p1);
	//ClientToScreen(g_hWnd, &p2);

	//rc.left = p1.x;
	//rc.top = p1.y;
	//rc.right = p2.x;
	//rc.bottom = p2.y;


	//ClipCursor(&rc);

	POINT MousePT;
	GetCursorPos(&MousePT);
	ScreenToClient(g_hWnd, &MousePT);

	return	MousePT;
}



///������ ���� �׸��� �ҷ�����...
void SaveData()
{
	SaveTileMap(TileRect, "./Data/TileInfo.nda");
}
void LoadData()
{
	LoadTileMap(TileRect, "./Data/TileInfo.nda");
}

/// ���� �Ҵ� ���� ����
void DeleteAll(OneCharacterRes* character, OneCharacterRes* character2, OneCharacterRes* character3,
	OneCharacterRes* character4, OneCharacterRes* character5, OneCharacterRes* character6 , OneCharacterRes* character7,
	OneCharacterRes* character8, OneCharacterRes* character9, OneCharacterRes* character10, OneCharacterRes* character11)
{
	/////////////////////////////////////////////////////
	for (int i = 0; i < character->motionNum; i++)
	{
		free(character->motions[i].sprites);

	}
	free(character->SpritesNum);
	free(character->motions);
	/////////////////////////////////////////////////////
	for (int i = 0; i < character2->motionNum; i++)
	{
		free(character2->motions[i].sprites);

	}
	free(character2->SpritesNum);
	free(character2->motions);
	/////////////////////////////////////////////////////
	for (int i = 0; i < character3->motionNum; i++)
	{
		free(character3->motions[i].sprites);

	}
	free(character3->SpritesNum);
	free(character3->motions);
	/////////////////////////////////////////////////////
	for (int i = 0; i < character4->motionNum; i++)
	{
		free(character4->motions[i].sprites);

	}
	free(character4->SpritesNum);
	free(character4->motions);
	/////////////////////////////////////////////////////
	for (int i = 0; i < character5->motionNum; i++)
	{
		free(character5->motions[i].sprites);

	}
	free(character5->SpritesNum);
	free(character5->motions);
	/////////////////////////////////////////////////////
	for (int i = 0; i < character6->motionNum; i++)
	{
		free(character6->motions[i].sprites);

	}
	free(character6->SpritesNum);
	free(character6->motions);
	/////////////////////////////////////////////////////
	for (int i = 0; i < character7->motionNum; i++)
	{
		free(character7->motions[i].sprites);

	}
	free(character7->SpritesNum);
	free(character7->motions);
	/////////////////////////////////////////////////////
	for (int i = 0; i < character8->motionNum; i++)
	{
		free(character8->motions[i].sprites);

	}
	free(character8->SpritesNum);
	free(character8->motions);

	for (int i = 0; i < character9->motionNum; i++)
	{
		free(character9->motions[i].sprites);

	}
	free(character9->SpritesNum);
	free(character9->motions);

	for (int i = 0; i < character10->motionNum; i++)
	{
		free(character10->motions[i].sprites);

	}
	free(character10->SpritesNum);
	free(character10->motions);

	for (int i = 0; i < character11->motionNum; i++)
	{
		free(character11->motions[i].sprites);

	}
	free(character11->SpritesNum);
	free(character11->motions);




	SelectObject(Backbuffer.hMemDC, Backbuffer.hBitmap);
	DeleteDC(Backbuffer.hMemDC);
	ReleaseDC(g_hWnd, g_hDCMain);

}