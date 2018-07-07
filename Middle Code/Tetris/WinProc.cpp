#include "WinProc.h"

LRESULT CALLBACK WinProc::WndProc(HWND hWnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) {

	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

WinProc::WinProc(HINSTANCE hIn) {
	this->style = CS_OWNDC;
	this->lpfnWndProc = WndProc;
	this->cbClsExtra = 0;
	this->cbWndExtra = 0;
	this->hInstance = hIn;
	this->hIcon = LoadIcon(NULL, IDC_ICON);
	this->hCursor = LoadCursor(NULL, IDC_ARROW);
	this->hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	this->lpszMenuName = NULL;
	this->lpszClassName = TEXT("Tetris");

	RegisterClass(this);
}

WinProc::~WinProc() {}

WinProc::str WinProc::GetName() const {
	return this->lpszClassName;
}