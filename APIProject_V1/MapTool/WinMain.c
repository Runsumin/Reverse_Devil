
#include <windows.h>
#include "define.h"
#include "resource.h"
#include "../APIProject_V1/SLEngine.h"
#include "Data.h"

// �Լ� ����κ�
//void DrawTileColor(HWND hWnd, TILERECT* _sTileRect);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



///��Ʈ�� �ε�� ����
SLBitmap BrickBitmap;
SLBitmap RedBrickBitmap;
SLBitmap IronBitmap;

CHANGEWINVIEW ChangeWinView;
CHANGEWINVIEW ChangeTilePos;
static int  BrushIndexForRect = 0;					// ���� �ٲ��ִ� �Լ�


// Ű �Է�
int InputedKey = 0;


/// WinMain �Լ� : ������ ���α׷��� ���� ������ ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR	  lpCmdLine,
	int		  nCmdShow)
{
	char	  szAppName[] = "������";
	HWND	  hWnd;
	MSG      msg; 
	WNDCLASS wndclass;
	

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wndclass.lpszClassName = szAppName;

	/// ���� Ŭ���� ���
	RegisterClass(&wndclass);

	/// ���� ����
	hWnd = CreateWindow(szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		100, 100, WINDOWWIDTH, WINDOWHEIGHT, 
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	/// ������ ������ ȭ�鿡 ǥ��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	///������ �� ���溯�� �ʱ�ȭ
	ChangeWinView.WinViewX = 0;
	ChangeWinView.WinViewY = 0;
	///Ÿ�� ��ġ�� ���� ����
	ChangeTilePos.WinViewX = 0;
	ChangeTilePos.WinViewY = 0;


	///�׷��� ���̺귯�� �ʱ�ȭ
	InitilizeSLEngine(hInstance, hWnd, GetDC(hWnd));
	
	///Ÿ�� �ε� �ʱ�ȭ
	InitializeTileMapSet();


	/// ����� Ÿ�� �ε�
	LoadBitmap_FromFile_LoadImage(&BrickBitmap, (char*)"./Brick.bmp");
	LoadBitmap_FromFile_LoadImage(&RedBrickBitmap, (char*)"./RedBrick.bmp");
	LoadBitmap_FromFile_LoadImage(&IronBitmap, (char*)"./Iron.bmp");

	BrickBitmap.BitMapIndexForTool = 1;
	RedBrickBitmap.BitMapIndexForTool = 2;
	IronBitmap.BitMapIndexForTool = 3;

	/// �޽��� ����.
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		else
		{
			// �ϴ� ���������� �����.
			Clear();

			/// Ű �Է��� �޴´�.


			// ����ȿ� �׷�����
			
			// �⺻ �����ִ� ���� �׷��ֱ�
			DrawTileLine();

			if (GetAsyncKeyState(VK_LBUTTON))
			{
				// �׸�� ���콺 üũ
				CheckTileBitMap(&ChangeWinView, InputedKey);
			}
		
			// üũ�� �κп� ��Ʈ�� �׷��ֱ�
			DrawTileBitMap(&BrickBitmap, &RedBrickBitmap, &IronBitmap);

			//CheckdebugSet(&ChangeWinView);

			DrawAllToScreen(&ChangeWinView);
			
		}
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;

	switch (message)
	{
	case WM_KEYDOWN:

		switch (wParam)
		{
		case KEY_W:
			ChangeWinView.WinViewY -= 10;
			break;
		case KEY_S:
			ChangeWinView.WinViewY += 10;
			break;
		case KEY_A:
			ChangeWinView.WinViewX -= 10;
			break;
		case KEY_D:
			ChangeWinView.WinViewX += 10;
			break;
		case KEY_Q:
			SaveData();
			break;
		case KEY_E:
			LoadData();
			break;

		case KEY_ONE:		
			InputedKey = 1;				
			break;
		case KEY_TWO:		
			InputedKey = 2;				
			break;
		case KEY_TREEE:		
			InputedKey = 3;				
			break;
		}
		break;
	//�׻� �׷��ִ�...
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}