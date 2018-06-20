#include <Windows.h>
#include <tchar.h>
#include <string>

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
	hWnd = CreateWindow(TEXT("MyWindow"), TEXT("그림판"),
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
	// 마우스가 클릭 중인지 확인하는 변수
	static bool bMouseDown = false;
	// 선의 굵기를 가지는 변수
	static int thickness = 3;
	// 선의 색을 가지는 변수
	static COLORREF color = RGB(0, 0, 0);

	switch (iMsg) {
	// 마우스를 누르면 선을 그리고 떼면 그리지 않는다
	case WM_LBUTTONDOWN: {
		HDC hDC = GetDC(hWnd);

		bMouseDown = true;
		MoveToEx(hDC, LOWORD(lParam), HIWORD(lParam), nullptr);
		ReleaseDC(hWnd, hDC);
		break;
	}
	case WM_LBUTTONUP:
		bMouseDown = false;
		break;
	case WM_MOUSEMOVE: {
		if (bMouseDown) {
			HDC hDC = GetDC(hWnd);
			HPEN hMyPen = nullptr;
			HPEN hOldPen = nullptr;

			hMyPen = CreatePen(PS_SOLID, thickness, color);
			hOldPen = reinterpret_cast<HPEN>(SelectObject(hDC, hMyPen));

			LineTo(hDC, LOWORD(lParam), HIWORD(lParam));
			ReleaseDC(hWnd, hDC);
		}
		break;
	}
	// 마우스 휠을 움직이면 선의 굵기를 변경한다
	case WM_MOUSEWHEEL: {
		// 휠이 움직인 것을 담는다
		int wheelMove = GET_WHEEL_DELTA_WPARAM(wParam);

		// 휠이 움짐이면 굵기를 변경한다
		thickness += wheelMove > 0 ? 1 : -1;

		// 굵기의 제한을 둔다
		if (thickness > 40) { thickness = 40; }
		else if (thickness < 1) { thickness = 1; }
		break;
	}
	// 색상을 변경하는 키
	case WM_KEYDOWN: {
		HDC hDC = GetDC(hWnd);
		TCHAR key = wParam;

		// q는 검은 색, w는 붉은 색, e는 파랑 색,  r은 초록색
		switch (key)
		{
		case 'Q':
			color = RGB(0, 0, 0);
			break;
		case 'W':
			color = RGB(255, 0, 0);
			break;
		case 'E':
			color = RGB(0, 0, 255);
			break;
		case 'R':
			color = RGB(0, 255, 0);
			break;
		}
		
		break;
	}
	// X 키를 누르면 종료한다
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}