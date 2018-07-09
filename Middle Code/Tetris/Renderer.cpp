#include "Renderer.h"

Renderer::Renderer()
	: iCount(0), timePrev(0)
{}

Renderer::~Renderer() {}

VOID Renderer::Paint(HDC hDC) {
	timePrev = timeGetTime();

	Rectangle(hDC, 50, 50, 750, 550);

	if (iCount == iTestCount) {
		float tickRate = 1000.f / static_cast<float>((timeGetTime() - timePrev)) * static_cast<float>(iTestCount);
		sprintf(timeStr, "%f", tickRate);
		iCount = 0;
		timePrev = timeGetTime();
	}

	TextOutA(hDC, 0, 0, timeStr, strlen(timeStr));
	iCount++;
}