#ifndef __WINPROC_H__
#define __WINPROC_H__

#include <Windows.h>
#include <string>
#include "Renderer.h"

class WinProc : private WNDCLASSEX {
	typedef std::basic_string<TCHAR> str;
private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg,
		WPARAM wParam, LPARAM lParam);
public:
	WinProc();

	WinProc(HINSTANCE hIn);

	~WinProc();

	str GetName() const;
};

#endif