#include "Window.h"

Window::Window(const str& className, const str& winName,
	int x, int y, int width, int height,
	HINSTANCE hIn, void* pData) {

	hWnd = CreateWindowEx(NULL, className.c_str(), winName.c_str(),
		WS_POPUP, x, y, width, height,
		nullptr, nullptr, hIn, pData);
}

Window::Window(const str& className, const str& winName,
	HINSTANCE hIn, void* pData) {
	
	hWnd = CreateWindowEx(NULL, className.c_str(), winName.c_str(),
		WS_POPUP, ((GetSystemMetrics(SM_CXSCREEN) - 800) / 2),
		((GetSystemMetrics(SM_CYSCREEN) - 600) / 2), 800, 600,
		nullptr, nullptr, hIn, pData);
}

Window::~Window() {
	if (IsWindow(hWnd))
		DestroyWindow(hWnd);
}

void Window::Show(bool isShow) {
	ShowWindow(hWnd, isShow ? SW_SHOW : SW_HIDE);
	UpdateWindow(hWnd);
}

HWND Window::GetHwnd() const {
	return hWnd;
}