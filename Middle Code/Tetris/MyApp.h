#ifndef __MYAPP_H__
#define __MYAPP_H__

#include <Windows.h>
#include "Window.h"
#include "WinProc.h"

class MyApp
{
private:
	Window* winPtr = nullptr;
	WinProc* procPtr = nullptr;
public:
	MyApp(HINSTANCE hIn);

	~MyApp();

	VOID Run();
};

#endif