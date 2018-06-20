#include <Windows.h>
#include <tchar.h>
#include <string>

typedef std::basic_string<TCHAR> string;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
void Print(HWND hWnd, string tstr, int fontSize);

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
	static int fontSize = 100;
	static std::basic_string<TCHAR> tstr;

	switch (iMsg) {
	case WM_CHAR: {
		if (wParam != VK_BACK)
			tstr += static_cast<TCHAR>(wParam);
		else
			if (!(tstr.empty()))
				tstr.erase(tstr.end() - 1, tstr.end());
		Print(hWnd, tstr, fontSize);
		break;
	}
	case WM_MOUSEWHEEL: {
		// 휠이 움직인 것을 담는다
		int wheelMove = GET_WHEEL_DELTA_WPARAM(wParam);

		// 휠이 움짐이면 굵기를 변경한다
		fontSize += wheelMove > 0 ? 1 : -1;

		// 굵기의 제한을 둔다
		if (fontSize > 200) { fontSize = 200; }
		else if (fontSize < 1) { fontSize = 1; }

		// 바뀐 굵기를 적용한다
		Print(hWnd, tstr, fontSize);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

// 메모장에 출력
void Print(HWND hWnd, string tstr, int fontSize) {
	HDC hDC = GetDC(hWnd);
	HFONT hMyFont = CreateFont(fontSize, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, TEXT("consolas"));
	HFONT hOldFont = reinterpret_cast<HFONT>(SelectObject(hDC, hMyFont));

	TextOut(hDC, 10, 10, tstr.c_str(), tstr.length());

	ReleaseDC(hWnd, hDC);
}