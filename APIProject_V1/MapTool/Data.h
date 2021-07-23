#pragma once
#include "../APIProject_V1/SLEngine.h"

/// 타일 정보 저장스
int SaveTileMap(TILERECT TileInfo[][CUTY], LPCTSTR filepath);
int LoadTileMap(TILERECT TileInfo[][CUTY], LPCTSTR filepath);