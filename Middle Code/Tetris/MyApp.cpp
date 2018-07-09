#include "MyApp.h"

MyApp::MyApp(HINSTANCE hIn) {
	procPtr = new WinProc(hIn);
	winPtr= new Window(procPtr->GetName(), TEXT("Tetris"), hIn);
}

MyApp::~MyApp() {
	delete winPtr;
	delete procPtr;
}

VOID MyApp::Run() {
	MSG msg = {};
	winPtr->Show(true);

	while (true) {
		bool haveMessage = PeekMessage(&msg, nullptr, NULL, NULL, PM_REMOVE);

		if (haveMessage && msg.message == WM_QUIT)
			break;

		else if (!haveMessage)
			InvalidateRect(winPtr->GetHwnd(), NULL, false);

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}