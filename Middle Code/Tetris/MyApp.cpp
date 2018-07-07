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

	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}