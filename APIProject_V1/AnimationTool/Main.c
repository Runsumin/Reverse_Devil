
#include <windows.h>
#include "SLEngine.h"
#include "resource.h"
#include "Main.h"
#include "SLTime.h"
// 엔진 테스트용

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


/// WinMain 함수 : 윈도즈 프로그램의 최초 진입점 ( Entry Point )
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

	/// 윈도 클래스 등록
	RegisterClass(&wndclass);

	/// 윈도 생성
	hWnd = CreateWindow(szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		100, 100, WINWIDTH, WINHEIGHT,
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	/// 생성된 윈도를 화면에 표시
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);



	///초기화 관련 함수셋팅
	InitilizeSLEngine(hInstance, hWnd, GetDC(hWnd)); // 그래픽스 라이브러리 초기화
	InitializeTime(120.F);

	// 비트맵 로드 
	SLBitmap RockManBitmap;
	SLBitmap RockBitmap;
	LoadBitmap_FromFile_LoadImage(&RockManBitmap, (char*)"./RockMan.bmp");
	LoadBitmap_FromFile_LoadImage(&RockBitmap, (char*)"./RedBrick.bmp");

	OneCharacterRes _RockMan;
	_RockMan.motionNum = 3;
	CreateCharacterRes(&_RockMan, &RockManBitmap, _RockMan.motionNum, 4);


	// 전역성을 띈 변수
	int totalFrameCount = 0;

	// 오브젝트 레벨으로 들어가야 할 변수
	int RockManPosX = 0;
	int RockManPosY = 0;

	// 키 입력을 통한 모션 변경
	int nowMotionIndex = 0;

	//화면 전환 관련 변수
	CHANGEWINVIEW ChangeView;
	ChangeView.WinViewX = 0;
	ChangeView.WinViewY = 0;

	/// 메시지 루프
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		else
		{	/// 게임 루프!
			CheckEndTime();

			// 시간 함수 연산 후, 프레임이 넘어가야겠다고 판단 되면,
			if (SLIsOK() == TRUE)
			{
				// 새로 시간 체크를 한다.
				CheckStartTime();
			}
			else
			{
				continue;
			}

			Clear();

			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				RockManPosX -= 5;
				nowMotionIndex = 0;
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				RockManPosX += 5;
				nowMotionIndex = 1;
			}

			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				RockManPosY -= 5;
				nowMotionIndex = 2;
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				RockManPosY += 5;
				nowMotionIndex = 0;
			}

			//마우스의 좌표 받아오기
			POINT  Pt = CheckMousePos();
			Pt.x -= RockManPosX;
			Pt.y -= RockManPosY;

			//int DirX = Pt.x - RockManPosX;
			//int DirY = Pt.y - RockManPosY;

			//long ddDirX = powf(DirX, 2);
			//long ddDirY = powf(DirY, 2);

			//long RoutDirX = sqrt(ddDirX);
			//long RoutDirY = sqrt(ddDirY);


			////방향값
			//long Distance = RoutDirX + RoutDirY;

			//노멀라이즈
			//long Nor = Distance / abs(Distance);

			_TT(0, 0, "TimeGetTimeTotal : %d", SLGetTime());
			_TT(0, 15, "TimeGetTimeElapsed : %d", SLGetElapsedTime());
			_TT(0, 30, "TimeGetTimeFPS : %f", SLGetFPS());
			//_TT(0, 50, "DirX : %d / DirY : %d", Pt.x, Pt.y);

			Animate_PickPos(RockManPosX, RockManPosY, &_RockMan,
				totalFrameCount, nowMotionIndex % _RockMan.motions->spriteNum);
			/// 비트맵 회전 다음에 함 조져보거나 교수님한테 질문하기
			//DrawPlgbltBitmap(0, RockManPosX, RockManPosY,&RockBitmap, 0, 0,1);

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

