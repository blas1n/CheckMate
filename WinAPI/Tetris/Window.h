#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <Windows.h>
#include <string>

class Window {
	typedef std::basic_string<TCHAR> str;
private:
	HWND hWnd = nullptr;
public:
	Window(const str& className, const str& winName,
		int x, int y, int width, int height,
		HINSTANCE hIn, void* pData = nullptr);

	Window(const str& className, const str& winName,
		HINSTANCE hIn, void* pData = nullptr);

	virtual ~Window();

	void Show(bool isShow);
	
	HWND GetHwnd() const;
};

#endif