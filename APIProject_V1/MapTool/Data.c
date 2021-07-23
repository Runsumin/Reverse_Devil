#include "Data.h"


/// 타일의 정보를 세이브한다
int SaveTileMap(TILERECT TileInfo[][CUTY] , LPCTSTR filepath)
{
	HANDLE hFile;
	hFile = CreateFile(filepath,			// 파일 경로
		GENERIC_READ | GENERIC_WRITE,		// 읽기/쓰기 모드
		0,									// 공유 모드. 
		NULL,								// 보안 속성. 
		CREATE_ALWAYS,						// 파일을 생성 & 로드
		FILE_ATTRIBUTE_NORMAL,				// 파일 속성
		NULL);								// 템플릿 파일?

	if (hFile == INVALID_HANDLE_VALUE) { // 파일을 열 때 에러면.
		return 0;
	}

	DWORD dwWritten;

	TILERECT DumpRect;

	for (int i = 0; i < CUTX; i++)
	{
		for (int j = 0; j < CUTY; j++)
		{
			DumpRect = TileInfo[i][j];
			WriteFile(hFile, &DumpRect, sizeof(TILERECT), &dwWritten, NULL);
		}
	}

	CloseHandle(hFile);

	return 0;
}


/// 타일의 정보를 로드한다
int LoadTileMap(TILERECT TileInfo[][CUTY], LPCTSTR filepath)
{
	HANDLE hFile;
	hFile = CreateFile(filepath,			// 파일 경로
		GENERIC_READ | GENERIC_WRITE,		// 읽기/쓰기 모드
		0,									// 공유 모드. 
		NULL,								// 보안 속성. 
		OPEN_EXISTING,						// 파일을 생성 & 로드
		FILE_ATTRIBUTE_NORMAL,				// 파일 속성
		NULL);								// 템플릿 파일?

	if (hFile == INVALID_HANDLE_VALUE) { // 파일을 열 때 에러면.
		return 0;
	}

	DWORD dwWritten;

	TILERECT DumpRect;

	for (int i = 0; i < CUTX; i++)
	{
		for (int j = 0; j < CUTY; j++)
		{
			ReadFile(hFile, &DumpRect, sizeof(TILERECT), &dwWritten, NULL);
			TileInfo[i][j] = DumpRect;
			
		}
	}
	CloseHandle(hFile);

	return 0;
}