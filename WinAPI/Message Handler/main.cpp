#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY _tWinMain(HINSTANCE hin, HINSTANCE hPrev, LPTSTR cmd, int Cshow) {
	HWND hWnd;
	WNDCLASS wnd;
	MSG msg;

	// wnd의 멤버 초기화
	wnd.style = CS_OWNDC;
	wnd.lpfnWndProc = WndProc;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hInstance = hin;
	wnd.hIcon = LoadIcon(NULL, IDC_ICON);
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = TEXT("MyWindow");

	RegisterClass(&wnd);

	// 윈도우 생성 -> hWnd에 저장
	hWnd = CreateWindow(TEXT("MyWindow"), TEXT("Message Handler"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, NULL, NULL, hin, NULL);

	// 윈도우를 보이게 함
	ShowWindow(hWnd, SW_SHOW);

	// 창이 바로 종료 되지 않도록 While로 반복
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_LBUTTONDOWN: {
		// DC를 가져온다
		HDC hDC = GetDC(hWnd);
		int nX = 0, nY = 0;

		// 마우스의 위치를 lParam에서 가져온다
		nX = LOWORD(lParam);
		nY = HIWORD(lParam);

		TextOut(hDC, nX-60, nY, TEXT("마우스 왼쪽 클릭!"), 10);
		ReleaseDC(hWnd, hDC);
		break;
	}
	case WM_MOUSEMOVE: {
		// DC를 가져온다
		HDC hDC = GetDC(hWnd);
		int nX = 0, nY = 0;

		// 마우스의 위치를 lParam에서 가져온다
		nX = LOWORD(lParam);
		nY = HIWORD(lParam);

		TextOut(hDC, nX - 20, nY, TEXT("움직"), 2);
		ReleaseDC(hWnd, hDC);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}