#pragma once

#include "stdafx.h"
#include "SettingValue.h"

class WindowWrapper {
private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	ULONG_PTR m_gdiplusToken;

protected:
	WindowWrapper();
	virtual ~WindowWrapper() = default;

public:
	int Run(HINSTANCE);

private:
	void Init(HINSTANCE);
	void Release() noexcept;

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
	virtual void Process() = 0;

private:
	void RegisterWndClass(const SettingValue& value);
	void CreateWnd(const SettingValue& value);
	void ShowWnd(const SettingValue& value);

public:
	const HINSTANCE GetHInstance() const noexcept;
	const HWND GetHWnd() const noexcept;
};

