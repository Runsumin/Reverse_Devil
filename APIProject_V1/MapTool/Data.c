#include "Data.h"


/// Ÿ���� ������ ���̺��Ѵ�
int SaveTileMap(TILERECT TileInfo[][CUTY] , LPCTSTR filepath)
{
	HANDLE hFile;
	hFile = CreateFile(filepath,			// ���� ���
		GENERIC_READ | GENERIC_WRITE,		// �б�/���� ���
		0,									// ���� ���. 
		NULL,								// ���� �Ӽ�. 
		CREATE_ALWAYS,						// ������ ���� & �ε�
		FILE_ATTRIBUTE_NORMAL,				// ���� �Ӽ�
		NULL);								// ���ø� ����?

	if (hFile == INVALID_HANDLE_VALUE) { // ������ �� �� ������.
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


/// Ÿ���� ������ �ε��Ѵ�
int LoadTileMap(TILERECT TileInfo[][CUTY], LPCTSTR filepath)
{
	HANDLE hFile;
	hFile = CreateFile(filepath,			// ���� ���
		GENERIC_READ | GENERIC_WRITE,		// �б�/���� ���
		0,									// ���� ���. 
		NULL,								// ���� �Ӽ�. 
		OPEN_EXISTING,						// ������ ���� & �ε�
		FILE_ATTRIBUTE_NORMAL,				// ���� �Ӽ�
		NULL);								// ���ø� ����?

	if (hFile == INVALID_HANDLE_VALUE) { // ������ �� �� ������.
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