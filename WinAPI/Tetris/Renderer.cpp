#include "Renderer.h"

#define WHITE 0xFFFFFFFF

Renderer::Renderer()
	: timePrev(0), iCount(0) {

	memset(timeStr, 0, sizeof(timeStr));
	this->tool = new UINT[800 * 600];

	this->hDC = NULL;
	this->comDC = NULL;

	this->hBack = nullptr;
	this->hOld = nullptr;
}

VOID Renderer::Init(HDC* hDC, HDC* comDC) {
	this->hDC = *hDC;
	this->comDC = *comDC;

	this->hBack = CreateCompatibleBitmap(this->hDC, 800, 600);
	this->hOld = reinterpret_cast<HBITMAP>(SelectObject(this->comDC, hBack));
}

Renderer::~Renderer() {
	SelectObject(comDC, hOld);
	DeleteObject(hBack);
	comDC = nullptr;
	hDC = nullptr;
}

VOID Renderer::Paint() {
	memset(tool, 0, (800 * 600) << 2);

	for (int x = 0; x < 100; x++) {
#pragma omp parallel for
		for (int y = 50; y <= 550; y++)
			memset(tool + 50 + 800 * y, WHITE, 2800);
	}

	SetBitmapBits(hBack, (800 * 600) << 2, tool);

	if (iCount++ == iTestCount) {
		float tickRate = 1000.f / static_cast<float>(timeGetTime() - timePrev) * static_cast<float>(iTestCount);
		sprintf(timeStr, "%f", tickRate);
		iCount = 0;
		timePrev = timeGetTime();
	}

	TextOutA(hDC, 0, 0, timeStr, strlen(timeStr));
	BitBlt(hDC, 0, 0, 800, 600, comDC, 0, 0, SRCCOPY);
}