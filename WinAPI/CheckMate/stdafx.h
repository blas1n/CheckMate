#pragma once

#ifdef SHOWCONSOLE
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 
#endif
#endif

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <tchar.h>
#include <Ole2.h>
#include <gdiplus.h>

using namespace Gdiplus;

template <class T>
inline void Destroy(T*& ptr) noexcept {
	delete ptr;
	ptr = nullptr;
}