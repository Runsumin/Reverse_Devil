#pragma once

/// 8강 : Bitmap 과제제출용 그래픽스 라이브러리
///
/// [11/16/2019 LeHideHome]

#include <windows.h>
#include "SLDefine.h"
#include "../MapTool/Data.h"



/// 그리기용 가장 하부의 함수들
/// (BitBlt시리즈를 한 번 래핑할 뿐)

/// 초기화 관련 함수들
// 엔진 초기화
void InitilizeSLEngine(HINSTANCE hinst, HWND hWnd, HDC hDC);

// 몬스터메타정보가져오기(미리저장)
void LoadCharacterInfo_Player(OneCharacterRes* character, int motionNum);				// 플레이어
void LoadCharacterInfo_Monster_Slime(OneCharacterRes* character, int motionNum);		// 슬라임
void LoadCharacterInfo_Monster_Magician(OneCharacterRes* character, int motionNum);		// 마법사
void LoadPlayerEffectInfo(OneCharacterRes* character, int motionNum);					// 플레이어 이펙트
void LoadBossMagicianEffectInfo(OneCharacterRes* character, int motionNum);				// 마법사 작은가시 공격
void LoadBossSlimeLaserInfo(OneCharacterRes* character, int motionNum);					// 슬라임레이저
void LoadMAgicianDownAttInfo(OneCharacterRes* character, int motionNum);				// 마법사 큰가시 다운공격
void LoadMonsterHitEffectInfo(OneCharacterRes* character, int motionNum);				// 몬스터 히트 이펙트
void LoadTerrainObjectInfo(OneCharacterRes* character, int motionNum);					// 계단
void LoadMainSceneInfo(OneCharacterRes* character, int motionNum);						// 메인화면
void LoadMagicianSceneInfo(OneCharacterRes* character, int motionNum);					// 마법사방
// 타일맵 초기화
void InitializeTileMapSet();

/// 애니메이션 함수
void CreateCharacterRes(OneCharacterRes* character, SLBitmap* sheet, int DelayFrame, int maxSpriteNum);
void CreateSprites(OneMotion* motion, SLBitmap* sheet, int motionIndex, int MotionNum, int DelayFrame, int maxSpriteNum);
void DrawBitmap_PickPos_And_Play(int dstX, int dstY, OneCharacterRes* character, int motionIndex, int spriteIndex);

void Animate_PickPos_Monster(int dstX, int dstY, OneCharacterRes* character, int totalFrame, int motionIndex, int NowFrame);
void Animate_PickPos(int dstX, int dstY, OneCharacterRes* character, int totalFrame, int motionIndex);


void Animate_PickPos_PlayerEffect(int dstX, int dstY, OneCharacterRes* character, int totalFrame, int motionIndex);


void DrawSpriteRotate_ForPlayerEffect(int x, int y, double angle, OneCharacterRes* character, int totalFrame, int motionIndex);
void DrawSpriteRotate_ForPlayerEffect2(int x, int y, double angle, OneCharacterRes* character, int totalFrame, int motionIndex, int NowFrame);
void DrawBitmap_PickPos(int dstX, int dstY,
	SLBitmap* sheet, int oriX, int oriY, int width, int height);

void DrawBitmap_PickPos2(int dstX, int dstY, SLBitmap* sheet, HDC MemDc, int oriX, int oriY, int width, int height);


void DrawCurSur(int x, int y, SLBitmap* sheet);
/// 임시 그려주기 함수
void onDraw(HRGN CollRegion, POINT Pt1, POINT Pt2, POINT Pt3, POINT Pt4);
/// 비트맵 그려주는 함수
void DrawBitmap(int posX, int posY, SLBitmap* bitmap, int srcX, int srcY);
void DrawSpriteRotate(int x, int y, double angle, SLBitmap* sprite);
/// 충돌처리 디버깅용 박스그리기 함수
void DrawDeBugRectangle(long left, long top, long right, long bottom);

/// 화면에 최종적으로 Blit을 한다. (백버퍼->화면)
void DrawAllToScreen(CHANGEWINVIEW* changeWinView);

void Clear();


/// 비트맵 로드 관련(Load Image)
void LoadBitmap_FromFile_LoadImage(SLBitmap* bitmap, char* filePath);


/// 맵툴사용함수
void DrawTileLine();														// 라인 그려준다
void CheckTileBitMap(CHANGEWINVIEW* changeWinView, int tileAttr);			// 마우스와 타일체크
void DrawTileBitMap(SLBitmap* brick, SLBitmap* redBrick, SLBitmap* iron);	// 타일위에 비트맵 그려준다

BOOL _TT(int x, int y, const char* pch, ...);

POINT CheckMousePos_ForTOOL(CHANGEWINVIEW* changeWinView);
POINT CheckMousePos();
/// 디버그 정보 관련 함수(텍스트 화면에 출력)

// 동적으로 할당받은 플레이어 데이터 제거
void DeleteAll(OneCharacterRes* character, OneCharacterRes* character2, OneCharacterRes* character3, OneCharacterRes* character4, OneCharacterRes* character5, OneCharacterRes* character6, OneCharacterRes* character7, OneCharacterRes* character8, OneCharacterRes* character9, OneCharacterRes* character10, OneCharacterRes* character11);
/// 주고 받는 데이터에 관한 함수
void SaveData();
void LoadData();