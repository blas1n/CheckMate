#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "Singleton.h"
#include <Windows.h>
#include <cstdio>

#pragma comment (lib, "winmm.lib")

class Renderer : public Singleton<Renderer> {
private:
	const UINT iTestCount = 5000;
	UINT iCount;
	DWORD timePrev;
	CHAR timeStr[20] = { 0, };
public:
	Renderer();

	virtual ~Renderer();
	
	VOID Paint(HDC hDC);
};

#endif