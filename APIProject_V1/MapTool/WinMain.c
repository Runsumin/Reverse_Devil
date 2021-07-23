
#include <windows.h>
#include "define.h"
#include "resource.h"
#include "../APIProject_V1/SLEngine.h"
#include "Data.h"

// 함수 선언부분
//void DrawTileColor(HWND hWnd, TILERECT* _sTileRect);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



///비트맵 로드용 변수
SLBitmap BrickBitmap;
SLBitmap RedBrickBitmap;
SLBitmap IronBitmap;

CHANGEWINVIEW ChangeWinView;
CHANGEWINVIEW ChangeTilePos;
static int  BrushIndexForRect = 0;					// 색깔 바꿔주는 함수


// 키 입력
int InputedKey = 0;


/// WinMain 함수 : 윈도즈 프로그램의 최초 진입점 ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR	  lpCmdLine,
	int		  nCmdShow)
{
	char	  szAppName[] = "수민판";
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

	/// 윈도 클래스 등록
	RegisterClass(&wndclass);

	/// 윈도 생성
	hWnd = CreateWindow(szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		100, 100, WINDOWWIDTH, WINDOWHEIGHT, 
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	/// 생성된 윈도를 화면에 표시
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	///윈도우 뷰 변경변수 초기화
	ChangeWinView.WinViewX = 0;
	ChangeWinView.WinViewY = 0;
	///타일 위치에 관한 변수
	ChangeTilePos.WinViewX = 0;
	ChangeTilePos.WinViewY = 0;


	///그래픽 라이브러리 초기화
	InitilizeSLEngine(hInstance, hWnd, GetDC(hWnd));
	
	///타일 로드 초기화
	InitializeTileMapSet();


	/// 사용할 타일 로드
	LoadBitmap_FromFile_LoadImage(&BrickBitmap, (char*)"./Brick.bmp");
	LoadBitmap_FromFile_LoadImage(&RedBrickBitmap, (char*)"./RedBrick.bmp");
	LoadBitmap_FromFile_LoadImage(&IronBitmap, (char*)"./Iron.bmp");

	BrickBitmap.BitMapIndexForTool = 1;
	RedBrickBitmap.BitMapIndexForTool = 2;
	IronBitmap.BitMapIndexForTool = 3;

	/// 메시지 루프.
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		else
		{
			// 일단 검은색으로 지운다.
			Clear();

			/// 키 입력을 받는다.


			// 여기안에 그려주자
			
			// 기본 보여주는 라인 그려주기
			DrawTileLine();

			if (GetAsyncKeyState(VK_LBUTTON))
			{
				// 네모와 마우스 체크
				CheckTileBitMap(&ChangeWinView, InputedKey);
			}
		
			// 체크된 부분에 비트맵 그려주기
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
	//항상 그려주는...
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