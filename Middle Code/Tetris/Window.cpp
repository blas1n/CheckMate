#include "Window.h"

Window::Window(const str& className, const str& winName,
	int x, int y, int width, int height,
	HINSTANCE hIn, void* pData) {

	hWnd = CreateWindow(className.c_str(), winName.c_str(),
		WS_OVERLAPPEDWINDOW, x, y, width, height,
		nullptr, nullptr, hIn, pData);
}

Window::Window(const str& className, const str& winName,
	HINSTANCE hIn, void* pData) {
	
	hWnd = CreateWindow(className.c_str(), winName.c_str(),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hIn, pData);
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