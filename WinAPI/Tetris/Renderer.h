#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "Singleton.h"
#include <Windows.h>
#include <cstdio>

#pragma comment (lib, "winmm.lib")

class Renderer : public Singleton<Renderer> {
private:
	UINT* tool;

	HDC hDC;
	HDC comDC;
	HBITMAP hBack;
	HBITMAP hOld;

	const UINT iTestCount = 1000;
	UINT iCount;
	DWORD timePrev;
	CHAR timeStr[20];
public:
	Renderer();

	VOID Init(HDC* hDC, HDC* comDC);

	virtual ~Renderer();
	
	VOID Paint();
};

#endif