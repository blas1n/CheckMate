#include "WinProc.h"

#define Render Renderer::GetInstance()

LRESULT CALLBACK WinProc::WndProc(HWND hWnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) {

	switch (iMsg)
	{
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hDC = BeginPaint(hWnd, &ps);
		Render->Paint(hDC);
		//renderer->Paint(hDC);
		EndPaint(hWnd, &ps);
		break;
	}

	case WM_DESTROY:
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