#include "MyApp.h"
#include <tchar.h>

int APIENTRY _tWinMain(HINSTANCE hIn, HINSTANCE prev, LPTSTR cmd, int cShow) {
	MyApp* winApp = new MyApp(hIn);
	winApp->Run();
	delete winApp;

	return 0;
}