#include "SLEngine.h"
#include <stdio.h>
#include <math.h>

#pragma comment(lib, "Msimg32.lib")


/// 모듈 레벨에서 전역인 변수들

HINSTANCE g_hInst;	// 인스턴스 핸들
HWND g_hWnd;		// 그리기를 할 윈도 (1개라고 가정)
HDC g_hDCMain;		// 메인DC. 화면에 그리는 용도
SLBitmap Backbuffer;// 백버퍼

/// 타일 정보 저장용 구조체
TILERECT TileRect[CUTX][CUTY];

/// 초기화 관련

// 그래픽스 라이브러리에 필요한 전역 변수들을 얻어온다.
// 이 때, 윈도는 1개라고 가정한다. 그리기 화면도 1개라고 가정함
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

/// 캐릭터 리소스 메타정보 셋팅
void LoadCharacterInfo_Player(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
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
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
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
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
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
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
	character->SpritesNum[0] = 5;
	character->SpritesNum[1] = 6;
	character->SpritesNum[2] = 5;
}
void LoadBossMagicianEffectInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
	character->SpritesNum[0] = 8;
	character->SpritesNum[1] = 1;
	character->SpritesNum[2] = 8;
}

void LoadBossSlimeLaserInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
	character->SpritesNum[0] = 7;


}
void LoadMAgicianDownAttInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
	character->SpritesNum[0] = 6;


}

void LoadMonsterHitEffectInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
	character->SpritesNum[0] = 6;


}

void LoadTerrainObjectInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
	character->SpritesNum[0] = 8;


}

void LoadMainSceneInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
	character->SpritesNum[0] = 5;


}
void LoadMagicianSceneInfo(OneCharacterRes* character, int motionNum)
{
	/// motnionNum : 파일에서 전체 모션의 갯수를 읽어 온 것이다.
	character->motionNum = motionNum;

	/// 모션 갯수를 기반으로, 각 모션당 스프라이트의 갯수를 담는 배열을 동적할당한다.
	character->SpritesNum = (int*)malloc(sizeof(int) * motionNum);

	/// 파일에서 각 모션당 스프라이트의 갯수를 로드한다.
	character->SpritesNum[0] = 4;


}

/// 케릭터 리소스 셋팅
void CreateCharacterRes(OneCharacterRes* character, SLBitmap* sheet, int DelayFrame, int maxSpriteNum)
{
	// 원본 시트
	character->sheet = sheet;

	// 모션을 동적할당한다.
	character->motions = (OneMotion*)malloc(sizeof(OneMotion) * character->motionNum);

	// 동적 할당 한 모션 들을 초기화 한다.
	for (int i = 0; i < character->motionNum; i++)
	{
		// 매 모션을 초기화
		character->motions[i].sheet = sheet;
		character->motions[i].spriteNum = character->SpritesNum[i];

		// 모션에 다수의 스프라이트들을 동적할당 및 초기화를 해 준다.
		CreateSprites(&character->motions[i], sheet, i, character->motionNum, DelayFrame, maxSpriteNum);
	}
}

/// 모션을 셋팅해준다. 스프라이트 들을 만들어준다.
void CreateSprites(OneMotion* motion, SLBitmap* sheet, int motionIndex,
	int MotionNum, int DelayFrame, int maxSpriteNum)
{
	motion->sheet = sheet;

	// 스프라이트 정보를 동적으로 할당한다.
	motion->sprites = (OneSprite*)malloc(sizeof(OneSprite) * motion->spriteNum);

	//free(motion->sprites);
	for (int i = 0; i < motion->spriteNum; i++)
	{
		// 폭은 전체 시트를 스프라이트의 갯수로 나눈 균일한 값
		motion->sprites[i].width = (sheet->Width / maxSpriteNum);
		motion->sprites[i].height = (sheet->Height / MotionNum);

		// 시작 위치는 인덱스별로 폭과 높이를 감안한 위치
		motion->sprites[i].oriX = motion->sprites[i].width * i;
		motion->sprites[i].oriY = motion->sprites[i].height * motionIndex;

		motion->sprites[i].delayFrame = DelayFrame;
	}
}

/// 에니매이션 셋팅
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

	// 이미지 교체용 핸들 추가
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


	/// 원본 이펙트 이미지
	BitBlt(MemDC, 0, 0, _width, _height,
		character->sheet->hMemDC,
		character->motions[motionIndex].sprites[NowFrame].oriX,
		character->motions[motionIndex].sprites[NowFrame].oriY, SRCCOPY);


	/// memDC2에 배경색을 컬러키로 먼저 깔아준다.
	newBrush = CreateSolidBrush(RGB(0, 255, 0));
	oldBrush = SelectObject(MemDC2, newBrush);
	Rectangle(MemDC2, -1, -1, memDC2Size + 1, memDC2Size + 1);
	
	/// 회전시켜서 MemDC2로
	PlgBlt(MemDC2, pt, MemDC, 0, 0,
		_width, _height, NULL, 0, 0);

	/// MemDC2를 백버퍼에 단순히 Trans블릿
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

	// 이미지 교체용 핸들 추가
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


	/// 원본 이펙트 이미지
	BitBlt(MemDC, 0, 0, _width, _height,
		character->sheet->hMemDC,
		character->motions[motionIndex].sprites[NowFrame].oriX,
		character->motions[motionIndex].sprites[NowFrame].oriY, SRCCOPY);


	//// memDC2에 배경색을 컬러키로 먼저 깔아준다.
	newBrush = CreateSolidBrush(RGB(0, 255, 0));
	oldBrush = SelectObject(MemDC2, newBrush);
	Rectangle(MemDC2, -1, -1, memDC2Size + 1, memDC2Size + 1);

	/// 회전시켜서 MemDC2로
	PlgBlt(MemDC2, pt, MemDC, 0, 0,
		_width, _height, NULL, 0, 0);
		
		

	/// MemDC2를 백버퍼에 단순히 Trans블릿
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
///그리기 함수
void DrawBitmap_PickPos(int dstX, int dstY, SLBitmap* sheet, int oriX, int oriY, int width, int height)
{
	TransparentBlt(Backbuffer.hMemDC, dstX, dstY, width, height,
		sheet->hMemDC, oriX, oriY, width, height, sheet->KeyColor);

}

///그리기 함수
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
	// 이미지 교체용 핸들 추가
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



//임시 그리기 변수
void onDraw(HRGN CollRegion, POINT Pt1, POINT Pt2, POINT Pt3, POINT Pt4)
{
	SelectObject(Backbuffer.hMemDC, GetStockObject(WHITE_BRUSH));	// 브러시

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

// 하나의 스프라이트를 그린다. 블릿 방식은 Solid(SRCCOPY)
void DrawBitmap(int posX, int posY, SLBitmap* bitmap, int srcX, int srcY)
{
	BitBlt(Backbuffer.hMemDC, posX, posY, bitmap->Width, bitmap->Height,
		bitmap->hMemDC, srcX, srcY, SRCCOPY);
}

/// 디버깅용 충돌박스 그리기 함수
void DrawDeBugRectangle(long left, long top, long right, long bottom)
{
	SelectObject(Backbuffer.hMemDC, GetStockObject(WHITE_BRUSH));	// 브러시
	Rectangle(Backbuffer.hMemDC, left, top, right, bottom);
}

//가상의 버퍼에 블릿
void DrawAllToScreen(CHANGEWINVIEW* changeWinView)
{
	BitBlt(g_hDCMain, 0, 0, WINWIDTH, WINHEIGHT, Backbuffer.hMemDC, changeWinView->WinViewX, changeWinView->WinViewY, SRCCOPY);
}
// 검은색 배경 만들어 줘서 지워주기

/// 나중에 뒷배경화면 들어갈 자리...
void Clear()
{
	PatBlt(Backbuffer.hMemDC, 0, 0, WINWIDTH, WINHEIGHT, BLACKNESS);
}

// LoadImage 사용하여 비트맵 로드
void LoadBitmap_FromFile_LoadImage(SLBitmap* bitmap, char* filePath)
{
	BITMAP bit;

	// 메인DC와 호환되는 메모리DC생성, 파일에서 비트맵을 로드
	bitmap->hMemDC = CreateCompatibleDC(g_hDCMain);
	///bitmap->hBitmap = MakeDDBFromDIB(g_hDCMain, filePath);
	bitmap->hBitmap = LoadImage(NULL, filePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	/// ※
	///SetDIBitsToDevice()

	SelectObject(bitmap->hMemDC, bitmap->hBitmap);

	// 부가 정보를 만들어준다.
	GetObject(bitmap->hBitmap, sizeof(BITMAP), &bit);
	bitmap->Width = bit.bmWidth;
	bitmap->Height = bit.bmHeight;
	bitmap->KeyColor = COLORKEY_PINK;

	DeleteObject(bitmap->hBitmap);
}


/// 툴에서의 드로우 기능
// 각 타일들 정보담는것 초기화
void InitializeTileMapSet()
{
	for (int i = 0; i < CUTX; i++)
	{
		for (int j = 0; j < CUTY; j++)
		{
			TileRect[i][j].Tile.left = i * TILEWIDTH;						//x좌표
			TileRect[i][j].Tile.top = j * TILEHEIGHT;						//y좌표
			TileRect[i][j].Tile.right = i * TILEWIDTH + TILEWIDTH;			//WIDTH
			TileRect[i][j].Tile.bottom = j * TILEHEIGHT + TILEHEIGHT;		//HEIGHT
			TileRect[i][j].BitMapInDex = 0;
			TileRect[i][j].TileNum = j + CUTX * i;
		}
	}
}

void DrawTileLine()
{
	SelectObject(Backbuffer.hMemDC, GetStockObject(WHITE_BRUSH));	// 브러시

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
				//체크해주는 함수
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


/// 문자열 디버깅용 출력
BOOL _TT(int x, int y, const char* pch, ...)
{
	// 브러시를 투명으로.
	SelectObject(Backbuffer.hMemDC, GetStockObject(NULL_BRUSH));	// 브러시
	SetTextColor(Backbuffer.hMemDC, RGB(0x00, 0xff, 0x00));			// 텍스트의 색
	SetBkMode(Backbuffer.hMemDC, TRANSPARENT);						// 텍스트의 배경을 투명으로

	HFONT font = CreateFont(12, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, "굴림");
	HFONT oldfont = (HFONT)SelectObject(Backbuffer.hMemDC, font);

	char* buffer;
	int len;

	va_list ap;			// 현재 읽고 있는 번지를 기억
	va_start(ap, pch);		// ap 포인터 변수가 첫번째 가변인수를 가리키도록 초기화

	// len을 산출하는 방법?
	// pch는 분명 문자열 상수의 포인터일텐데, strlen으로 크기가 안나오나?
	// _vscprintf doesn't count  .. 라고 MSDN에 나와있음. ;;

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



///데이터 저장 그리고 불러오기...
void SaveData()
{
	SaveTileMap(TileRect, "./Data/TileInfo.nda");
}
void LoadData()
{
	LoadTileMap(TileRect, "./Data/TileInfo.nda");
}

/// 동적 할당 정보 해제
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