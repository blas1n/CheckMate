#include "WinProc.h"

#define Render Renderer::GetInstance()

LRESULT CALLBACK WinProc::WndProc(HWND hWnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) {
	HDC hDC = nullptr;
	HDC comDC = nullptr;

	switch (iMsg) {
	case WM_CREATE:
		hDC = GetDC(hWnd);
		comDC = CreateCompatibleDC(hDC);
		Render->Init(&hDC, &comDC);

	case WM_PAINT:
		Render->Paint();
		break;

	case WM_DESTROY:
		Render->~Renderer();
		DeleteDC(comDC);
		ReleaseDC(hWnd, hDC);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

WinProc::WinProc() {}

WinProc::WinProc(HINSTANCE hIn) {
	this->cbSize = sizeof(WNDCLASSEX);
	this->style = CS_OWNDC;
	this->lpfnWndProc = WndProc;
	this->hInstance = hIn;
	this->hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	this->hCursor = LoadCursor(NULL, IDC_ARROW);
	this->hIcon = LoadIcon(NULL, IDC_ICON);
	this->hIconSm = this->hIcon;
	this->cbClsExtra = 0;
	this->cbWndExtra = 0;
	this->lpszMenuName = NULL;
	this->lpszClassName = TEXT("Tetris");

	RegisterClassEx(this);
}

WinProc::~WinProc() {}

WinProc::str WinProc::GetName() const {
	return this->lpszClassName;
}