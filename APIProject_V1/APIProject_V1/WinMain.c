#include "Main.h"


// ���� �׽�Ʈ��

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

BOOL g_AttCheck;
BOOL DebugCheck;

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

	g_AttCheck = FALSE;
	DebugCheck = FALSE;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, NULL);
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
	InitializeTime(120.f);
	timeBeginPeriod(1);

	/// Debug�� ���� ����
	InitCrtCheck();

	/// ��� ���� �ʱ�ȭ
	initialize();

	SetCursor(NULL);
	int a = 0;
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

			CheckTime();

			GameLoop();

		}
	}

	DeleteREsourceHeap();
	EndCrtCheck(); 
	soundCloseAll();

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
	case WM_MOUSEMOVE:
		
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

