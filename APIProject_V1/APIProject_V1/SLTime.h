#pragma once

#include <windows.h>


void InitializeTime(float FPSSetted);

void CheckTime();

DWORD SLGetTime();

DWORD SLGetElapsedTime();

float SLGetFPS();

void CheckStartTime();

DWORD CheckEndTime();
BOOL SLIsOK();