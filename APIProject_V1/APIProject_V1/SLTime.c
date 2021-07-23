#include "SLTime.h"

#pragma comment(lib, "winmm.lib")


DWORD _time_TimeGetTime = 0;
DWORD _time_StartTime = 0;
DWORD _time_EndTime = 0;
DWORD _time_ElapsedTime = 0;
DWORD _time_ElapsedTimeSum = 0;
float _FPS = 0;
float _FPSSetted = 0;

void InitializeTime(float FPSSetted)
{
	_FPSSetted = FPSSetted;

	_time_TimeGetTime = timeGetTime();

	///QueryPerformanceCounter

	CheckStartTime();
}

void CheckTime()
{
	_time_TimeGetTime = timeGetTime();
}

DWORD SLGetTime()
{
	return _time_TimeGetTime;
}

DWORD SLGetElapsedTime()
{
	return _time_ElapsedTime;
}

float SLGetFPS()
{
	return _FPS;
}

void CheckStartTime()
{
	_time_StartTime = timeGetTime();
}

DWORD CheckEndTime()
{
	_time_EndTime = timeGetTime();

	_time_ElapsedTime = _time_EndTime - _time_StartTime;
	
	_FPS = (float)1000 / (float)_time_ElapsedTime;

	return _time_ElapsedTime;
}

BOOL SLIsOK()
{
	float _time_for_one_frame = 1000.f / _FPSSetted;

	if (_time_for_one_frame <= (float)_time_ElapsedTime)
	{
		return TRUE;
	}

	return FALSE;
}