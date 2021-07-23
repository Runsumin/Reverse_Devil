#pragma once

/// 8�� : Bitmap ��������� �׷��Ƚ� ���̺귯��
///
/// [11/16/2019 LeHideHome]

#include <windows.h>
#include "SLDefine.h"
#include "../MapTool/Data.h"



/// �׸���� ���� �Ϻ��� �Լ���
/// (BitBlt�ø�� �� �� ������ ��)

/// �ʱ�ȭ ���� �Լ���
// ���� �ʱ�ȭ
void InitilizeSLEngine(HINSTANCE hinst, HWND hWnd, HDC hDC);

// ���͸�Ÿ������������(�̸�����)
void LoadCharacterInfo_Player(OneCharacterRes* character, int motionNum);				// �÷��̾�
void LoadCharacterInfo_Monster_Slime(OneCharacterRes* character, int motionNum);		// ������
void LoadCharacterInfo_Monster_Magician(OneCharacterRes* character, int motionNum);		// ������
void LoadPlayerEffectInfo(OneCharacterRes* character, int motionNum);					// �÷��̾� ����Ʈ
void LoadBossMagicianEffectInfo(OneCharacterRes* character, int motionNum);				// ������ �������� ����
void LoadBossSlimeLaserInfo(OneCharacterRes* character, int motionNum);					// �����ӷ�����
void LoadMAgicianDownAttInfo(OneCharacterRes* character, int motionNum);				// ������ ū���� �ٿ����
void LoadMonsterHitEffectInfo(OneCharacterRes* character, int motionNum);				// ���� ��Ʈ ����Ʈ
void LoadTerrainObjectInfo(OneCharacterRes* character, int motionNum);					// ���
void LoadMainSceneInfo(OneCharacterRes* character, int motionNum);						// ����ȭ��
void LoadMagicianSceneInfo(OneCharacterRes* character, int motionNum);					// �������
// Ÿ�ϸ� �ʱ�ȭ
void InitializeTileMapSet();

/// �ִϸ��̼� �Լ�
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
/// �ӽ� �׷��ֱ� �Լ�
void onDraw(HRGN CollRegion, POINT Pt1, POINT Pt2, POINT Pt3, POINT Pt4);
/// ��Ʈ�� �׷��ִ� �Լ�
void DrawBitmap(int posX, int posY, SLBitmap* bitmap, int srcX, int srcY);
void DrawSpriteRotate(int x, int y, double angle, SLBitmap* sprite);
/// �浹ó�� ������ �ڽ��׸��� �Լ�
void DrawDeBugRectangle(long left, long top, long right, long bottom);

/// ȭ�鿡 ���������� Blit�� �Ѵ�. (�����->ȭ��)
void DrawAllToScreen(CHANGEWINVIEW* changeWinView);

void Clear();


/// ��Ʈ�� �ε� ����(Load Image)
void LoadBitmap_FromFile_LoadImage(SLBitmap* bitmap, char* filePath);


/// ��������Լ�
void DrawTileLine();														// ���� �׷��ش�
void CheckTileBitMap(CHANGEWINVIEW* changeWinView, int tileAttr);			// ���콺�� Ÿ��üũ
void DrawTileBitMap(SLBitmap* brick, SLBitmap* redBrick, SLBitmap* iron);	// Ÿ������ ��Ʈ�� �׷��ش�

BOOL _TT(int x, int y, const char* pch, ...);

POINT CheckMousePos_ForTOOL(CHANGEWINVIEW* changeWinView);
POINT CheckMousePos();
/// ����� ���� ���� �Լ�(�ؽ�Ʈ ȭ�鿡 ���)

// �������� �Ҵ���� �÷��̾� ������ ����
void DeleteAll(OneCharacterRes* character, OneCharacterRes* character2, OneCharacterRes* character3, OneCharacterRes* character4, OneCharacterRes* character5, OneCharacterRes* character6, OneCharacterRes* character7, OneCharacterRes* character8, OneCharacterRes* character9, OneCharacterRes* character10, OneCharacterRes* character11);
/// �ְ� �޴� �����Ϳ� ���� �Լ�
void SaveData();
void LoadData();