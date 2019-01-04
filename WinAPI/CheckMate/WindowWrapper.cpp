#include "WindowWrapper.h"
#include "SettingValue.h"
#include "Set.hpp"

WindowWrapper::WindowWrapper()
	: m_hInstance(nullptr),
	m_hWnd(nullptr),
	m_gdiplusToken(0) {}

void WindowWrapper::Init(HINSTANCE hInstance) {
	m_hInstance = hInstance;

	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, nullptr);

	SettingValue value{};
	value.lpfnWndProc = WndProc;
	value.hInstance = hInstance;

	SettingWindow(value);

	RegisterWndClass(value);
	CreateWnd(value);
	ShowWnd(value);
}

void WindowWrapper::Release() noexcept {
	DestroyWindow(m_hWnd);
	GdiplusShutdown(m_gdiplusToken);
}

int WindowWrapper::Run(HINSTANCE hInstance) {
	Init(hInstance);
	
	MSG msg;
	memset(&msg, 0, sizeof(msg));

	SettingGame();

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
		}

		else Process();
	}

	Release();
	return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WindowWrapper::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void WindowWrapper::RegisterWndClass(const SettingValue& value) {
	WNDCLASSEX wndClass;
	memset(&wndClass, 0, sizeof(wndClass));
	
	wndClass.cbSize = value.cbSize;
	wndClass.lpszClassName = value.lpszClassName;
	wndClass.lpszMenuName = value.lpszMenuName;
	wndClass.lpfnWndProc = value.lpfnWndProc;
	wndClass.hInstance = value.hInstance;
	wndClass.style = value.style;
	wndClass.hbrBackground = value.hbrBackground;
	wndClass.hCursor = value.hCursor;
	wndClass.hIcon = value.hIcon;
	wndClass.hIconSm = value.hIcon;

	RegisterClassEx(&wndClass);
}

void WindowWrapper::CreateWnd(const SettingValue& value) {
	m_hWnd = CreateWindow(value.lpszClassName, value.lpszMenuName, value.dwStyle,
		value.x, value.y, value.width, value.height, value.hWndParent, value.hMenu, value.hInstance, value.lpParam);
}

void WindowWrapper::ShowWnd(const SettingValue& value) {
	ShowWindow(m_hWnd, value.nCmdShow);
	UpdateWindow(m_hWnd);
}

const HINSTANCE WindowWrapper::GetHInstance() const noexcept {
	return m_hInstance;
}

const HWND WindowWrapper::GetHWnd() const noexcept {
	return m_hWnd;
}