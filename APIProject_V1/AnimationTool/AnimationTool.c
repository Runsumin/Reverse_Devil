
#include <windows.h>
#include <math.h>
#include "../APIProject_V1/SLEngine.h"
//#include "resource.h"
//#include "Main.h"
#include "../APIProject_V1/SLTime.h"

// ���� �׽�Ʈ��

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


/// WinMain �Լ� : ������ ���α׷��� ���� ������ ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR	  lpCmdLine,
	int		  nCmdShow)
{
	char	  szAppName[] = "API_Project";
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
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	/// ���� Ŭ���� ���
	RegisterClass(&wndclass);

	/// ���� ����
	hWnd = CreateWindow(szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		100, 100, WINWIDTH, WINHEIGHT,
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	/// ������ ������ ȭ�鿡 ǥ��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);



	///�ʱ�ȭ ���� �Լ�����
	InitilizeSLEngine(hInstance, hWnd, GetDC(hWnd)); // �׷��Ƚ� ���̺귯�� �ʱ�ȭ
	InitializeTime(120.F);

	// ��Ʈ�� �ε� 
// 	SLBitmap RockManBitmap;
// 	SLBitmap RockBitmap;
// 	LoadBitmap_FromFile_LoadImage(&RockManBitmap, (char*)"./RockMan.bmp");
// 	LoadBitmap_FromFile_LoadImage(&RockBitmap, (char*)"./RedBrick.bmp");
// 
// 	OneCharacterRes _RockMan;
// 	_RockMan.motionNum = 3;
// 	CreateCharacterRes(&_RockMan, &RockManBitmap, _RockMan.motionNum, 4);


	// �������� �� ����
	int totalFrameCount = 0;

	// ������Ʈ �������� ���� �� ����
	int RockManPosX = 0;
	int RockManPosY = 0;

	// Ű �Է��� ���� ��� ����
	int nowMotionIndex = 0;

	//ȭ�� ��ȯ ���� ����
	CHANGEWINVIEW ChangeView;
	ChangeView.WinViewX = 0;
	ChangeView.WinViewY = 0;

	/// �޽��� ����
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		else
		{	/// ���� ����!
			CheckEndTime();

			// �ð� �Լ� ���� ��, �������� �Ѿ�߰ڴٰ� �Ǵ� �Ǹ�,
			if (SLIsOK() == TRUE)
			{
				// ���� �ð� üũ�� �Ѵ�.
				CheckStartTime();
			}
			else
			{
				continue;
			}


			/// �׸��⸦ �����Ѵ�.
			Clear();

			_TT(900, 0, "TimeGetTimeTotal : %d", SLGetTime());
			_TT(900, 15, "TimeGetTimeElapsed : %d", SLGetElapsedTime());
			_TT(900, 30, "TimeGetTimeFPS : %f", SLGetFPS());

			_TT(900, 50, "PlayerX : %d / PlayerY : %d", RockManPosX, RockManPosY);

			DrawAllToScreen(&ChangeView);
			totalFrameCount++;
		}
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT ps;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
